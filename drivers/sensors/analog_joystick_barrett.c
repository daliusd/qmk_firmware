/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "analog_joystick.h"
#include "analog.h"
#include "gpio.h"
#include "wait.h"
#include "timer.h"
#include <stdlib.h>

// Set Parameters
uint16_t minAxisValue = ANALOG_JOYSTICK_AXIS_MIN;
uint16_t maxAxisValue = ANALOG_JOYSTICK_AXIS_MAX;

uint8_t maxCursorSpeed = ANALOG_JOYSTICK_SPEED_MAX;
int16_t speedRegulator = 20; // ANALOG_JOYSTICK_SPEED_REGULATOR; // Lower Values Create Faster Movement
int16_t stepsToMax = 20;

int16_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

int16_t axisCoordinate(pin_t pin, uint16_t origin) {
    int16_t position = analogReadPin(pin);
    int16_t diff = position - origin;
    int16_t range = diff < 0 ? (origin - minAxisValue) : (maxAxisValue - origin);

    float   fraction    = (float)diff / range;
    int16_t coordinate = (int16_t)(fraction * 100);

    return coordinate > 100 ? 100 : coordinate < -100 ? -100 : coordinate;
}

float xC = 0;
float yC = 0;

report_analog_joystick_t analog_joystick_barrett_read(void) {
    report_analog_joystick_t report = {0};

    if (timer_elapsed(lastCursor) > ANALOG_JOYSTICK_READ_INTERVAL) {
        lastCursor = timer_read();

        int16_t x = axisCoordinate(ANALOG_JOYSTICK_X_AXIS_PIN, xOrigin);
        if (abs(x) < 5) {
            xC = 0;
        } else {
            float maxX = (float)x / 100 * abs(x) * maxCursorSpeed / speedRegulator;
            if (abs(xC) < abs(maxX)) {
                xC += maxX / stepsToMax;
            } else {
                xC = maxX;
            }
        }
        int16_t y = axisCoordinate(ANALOG_JOYSTICK_Y_AXIS_PIN, yOrigin);
        if (abs(y) < 5) {
            yC = 0;
        } else {
            float maxY = (float)y / 100 * abs(y) * maxCursorSpeed / speedRegulator;
            if (abs(yC) < abs(maxY)) {
                yC += maxY / stepsToMax;
            } else {
                yC = maxY;
            }
        }

        report.x   = (int8_t)xC;
        report.y   = (int8_t)yC;
    }
#ifdef ANALOG_JOYSTICK_CLICK_PIN
    report.button = !readPin(ANALOG_JOYSTICK_CLICK_PIN);
#endif
    return report;
}

void analog_joystick_barrett_init(void) {
#ifdef ANALOG_JOYSTICK_CLICK_PIN
    setPinInputHigh(ANALOG_JOYSTICK_CLICK_PIN);
#endif
    // Account for drift
    xOrigin = analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN);
    yOrigin = analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN);
}
