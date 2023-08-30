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
#include "debug.h"

// Set Parameters
uint16_t minAxisValue = ANALOG_JOYSTICK_AXIS_MIN;
uint16_t maxAxisValue = ANALOG_JOYSTICK_AXIS_MAX;

uint8_t maxCursorSpeed = ANALOG_JOYSTICK_SPEED_MAX;
int16_t speedRegulator = 20; // ANALOG_JOYSTICK_SPEED_REGULATOR; // Lower Values Create Faster Movement

int16_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

int16_t axisCoordinate(pin_t pin, uint16_t origin) {
    int16_t position = analogReadPin(pin);
    int16_t diff = position - origin;
    int16_t range = diff < 0 ? (origin - minAxisValue) : (maxAxisValue - origin);

    //dprintf("position origin: %d %d\n", position, origin);
    float   fraction    = (float)diff / range;
    int16_t coordinate = (int16_t)(fraction * 100);

    return coordinate > 100 ? 100 : coordinate < -100 ? -100 : coordinate;
}

report_analog_joystick_t analog_joystick_barrett_read(void) {
    report_analog_joystick_t report = {0};

    if (timer_elapsed(lastCursor) > ANALOG_JOYSTICK_READ_INTERVAL) {
        lastCursor = timer_read();

        int16_t x = axisCoordinate(ANALOG_JOYSTICK_X_AXIS_PIN, xOrigin);
        int16_t y = axisCoordinate(ANALOG_JOYSTICK_Y_AXIS_PIN, yOrigin);

        int16_t ax = abs(x);
        int16_t ay = abs(y);

        // dprintf("ax: %d\n", ax);
        // dprintf("ay: %d\n", ay);
        int16_t xC = (ax == 100 ? 100 : ax == 0 ? 0 : 30) * (x < 0 ? -1 : 1) * maxCursorSpeed / speedRegulator;
        int16_t yC = (ay == 100 ? 100 : ay == 0 ? 0 : 30) * (y < 0 ? -1 : 1) * maxCursorSpeed / speedRegulator;

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
