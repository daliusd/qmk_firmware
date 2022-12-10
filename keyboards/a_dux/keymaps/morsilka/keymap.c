/* Copyright 2022 @daliusd
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
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T,                              KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    KC_SPC  ,        KC_LSFT ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

};

#define DIT_DURATION 100
#define SHORT_GAP (DIT_DURATION * 3)

uint16_t timer_started = 0;
uint16_t timer_ended = 0;
uint8_t  code_length = 0;
uint16_t code = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        timer_started = timer_read();
        timer_ended = 0;
    } else {
        timer_ended = timer_read();
        code <<= 1;
        code_length += 1;
        if (timer_elapsed(timer_started) > DIT_DURATION * 2) {
            code += 1;
        }
        timer_started = 0;
    }

    return false;
}

void process_1(void) {
    switch (code) {
        case 0b0:
            tap_code16(KC_E);
            break;
        case 0b1:
            tap_code16(KC_T);
            break;
    }
}

void process_2(void) {
    switch (code) {
        case 0b00:
            tap_code16(KC_I);
            break;
        case 0b01:
            tap_code16(KC_A);
            break;
        case 0b10:
            tap_code16(KC_N);
            break;
        case 0b11:
            tap_code16(KC_M);
            break;
    }
}

void process_3(void) {
    switch (code) {
        case 0b000:
            tap_code16(KC_S);
            break;
        case 0b001:
            tap_code16(KC_U);
            break;
        case 0b010:
            tap_code16(KC_R);
            break;
        case 0b011:
            tap_code16(KC_W);
            break;
        case 0b100:
            tap_code16(KC_D);
            break;
        case 0b101:
            tap_code16(KC_K);
            break;
        case 0b110:
            tap_code16(KC_G);
            break;
        case 0b111:
            tap_code16(KC_O);
            break;
    }
}

void process_4(void) {
    switch (code) {
        case 0b0000:
            tap_code16(KC_H);
            break;
        case 0b0001:
            tap_code16(KC_V);
            break;
        case 0b0010:
            tap_code16(KC_F);
            break;
        case 0b0011:
            tap_code16(KC_BSPC);
            break;
        case 0b0100:
            tap_code16(KC_L);
            break;
        case 0b0101:
            tap_code16(KC_SPC);
            break;
        case 0b0110:
            tap_code16(KC_P);
            break;
        case 0b0111:
            tap_code16(KC_J);
            break;
        case 0b1000:
            tap_code16(KC_B);
            break;
        case 0b1001:
            tap_code16(KC_X);
            break;
        case 0b1010:
            tap_code16(KC_C);
            break;
        case 0b1011:
            tap_code16(KC_Y);
            break;
        case 0b1100:
            tap_code16(KC_Z);
            break;
        case 0b1101:
            tap_code16(KC_Q);
            break;
        case 0b1111:
            tap_code16(KC_ENT);
            break;
    }
}

void process_5(void) {
    switch (code) {
        case 0b00000:
            tap_code16(KC_5);
            break;
        case 0b00001:
            tap_code16(KC_4);
            break;
        case 0b00011:
            tap_code16(KC_3);
            break;
        case 0b00111:
            tap_code16(KC_2);
            break;
        case 0b01000:
            tap_code16(KC_AMPR);
            break;
        case 0b01111:
            tap_code16(KC_1);
            break;
        case 0b10000:
            tap_code16(KC_6);
            break;
        case 0b10010:
            tap_code16(KC_SLSH);
            break;
        case 0b10110:
            tap_code16(KC_LPRN);
            break;
        case 0b11000:
            tap_code16(KC_7);
            break;
        case 0b11100:
            tap_code16(KC_8);
            break;
        case 0b11110:
            tap_code16(KC_9);
            break;
        case 0b11111:
            tap_code16(KC_0);
            break;
    }
}

void process_6(void) {
    switch (code) {
        case 0b001100:
            tap_code16(KC_QUES);
            break;
        case 0b010000:
            tap_code16(KC_HASH); // reset does not trigger alone. So I have added hash here.
            reset_keyboard();
            break;
        case 0b010010:
            tap_code16(KC_DQT);
            break;
        case 0b010101:
            tap_code16(KC_DOT);
            break;
        case 0b011110:
            tap_code16(KC_QUOT);
            break;
        case 0b101010:
            tap_code16(KC_SCLN);
            break;
        case 0b101011:
            tap_code16(KC_EXLM);
            break;
        case 0b101101:
            tap_code16(KC_RPRN);
            break;
        case 0b110011:
            tap_code16(KC_COMM);
            break;
        case 0b111000:
            tap_code16(S(KC_SCLN));
            break;

    }
}

void process_9(void) {
    switch (code) {
        case 0b000111000:
            tap_code16(KC_S);
            tap_code16(KC_O);
            tap_code16(KC_S);
            break;
    }
}

void matrix_scan_user(void) {
    if (timer_started == 0 && timer_ended != 0 && timer_elapsed(timer_ended) > DIT_DURATION * 3) {
        switch (code_length) {
            case 1:
                process_1();
                break;
            case 2:
                process_2();
                break;
            case 3:
                process_3();
                break;
            case 4:
                process_4();
                break;
            case 5:
                process_5();
                break;
            case 6:
                process_6();
                break;
            case 9:
                process_9();
                break;
        }

        timer_ended = 0;
        code_length = 0;
        code = 0;
    }
}
