/*
Copyright 2021 Dalius Dobravolskas <dalius.dobravolskas@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
// Do not enable as this breaks ONESHOT_TAP_TOGGLE
// #define TAPPING_FORCE_HOLD

#define UNICODE_SELECTED_MODES UC_MAC, UC_LNX

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define COMBO_COUNT 11
#define COMBO_TERM 20

// // Set the mouse settings to a comfortable speed/accuracy trade-off,
// // assuming a screen refresh rate of 60 Htz or higher
// // The default is 50. This makes the mouse ~3 times faster and more accurate
// #define MOUSEKEY_INTERVAL 16
// // The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// // give it more time to accelerate to max speed to retain precise control over short distances.
// #define MOUSEKEY_TIME_TO_MAX 40
// // The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
// #define MOUSEKEY_DELAY 100

#define MOUSEKEY_INTERVAL 12
#define MOUSEKEY_MAX_SPEED 6
#define MOUSEKEY_TIME_TO_MAX 50

#define MOUSEKEY_DELAY 20
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
