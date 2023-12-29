#pragma once

#define EE_HANDS

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_TX_PIN GP0
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral

#define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP27

#define ANALOG_JOYSTICK_AUTO_AXIS

#define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,28,29,29,30,31,33,34,35,36,37,40,41,43,44,48,49,51,56,58,60,65,68,70,73,79,82,85,89,96,100}
#define ANALOG_JOYSTICK_CUTOFF

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
