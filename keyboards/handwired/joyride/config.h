#pragma once

#define EE_HANDS

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_TX_PIN GP0
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral

#define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP27

#define POINTING_DEVICE_ROTATION_270

#define ANALOG_JOYSTICK_SPEED_REGULATOR 15

#define ANALOG_JOYSTICK_AUTO_AXIS

// > JSON.stringify(Array.from(Array(101).keys()).map(x => x > 8 ? 54 - Math.floor(Math.cbrt(Math.abs((x - 54) / 46)) * 46) * (x < 54 ? 1 : -1) : 0))
// #define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,9,9,10,10,10,11,11,11,12,12,13,13,13,14,14,15,15,16,16,16,17,17,18,19,19,20,20,21,21,22,23,24,24,25,26,27,28,29,30,31,33,34,36,38,42,54,66,70,72,74,75,77,78,79,80,81,82,83,84,84,85,86,87,87,88,88,89,89,90,91,91,92,92,92,93,93,94,94,95,95,95,96,96,97,97,97,98,98,98,99,99,100};

// Simple linear
// #define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,0,0,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}

// for ANALOG_JOYSTICK_SPEED_REGULATOR 12
// #define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,0,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,100}

#define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,0,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}

#define ANALOG_JOYSTICK_CUTOFF

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
