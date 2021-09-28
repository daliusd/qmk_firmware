#include QMK_KEYBOARD_H

#include "oneshot.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _NUMB 3
#define _TMUX 4
#define _MOUSE 5

enum custom_keycodes {
  TM_NEXT = SAFE_RANGE,
  TM_PREV,
  TM_LEFT,
  TM_RIGHT,
  TM_NEW,
  TM_SLCT,
  TM_SRCH,
  TM_URL,
  OS_CTRL,
  OS_ALT,
  OS_GUI,
};

// Shortcut to make keymap more readable

#define L_SYM       MO(_SYMB)
#define L_NAV       MO(_NAV)
#define L_NUMB      MO(_NUMB)
#define L_TMUX      MO(_TMUX)
#define L_MOUSE     TG(_MOUSE)

#define K_PRINT     (QK_LCTL | QK_LSFT | QK_LGUI | KC_4)

enum unicode_names {
    SNEK,
    EURO,
    LT_S_A,
    LT_L_A,
    LT_S_C,
    LT_L_C,
    LT_S_E1,
    LT_L_E1,
    LT_S_E2,
    LT_L_E2,
    LT_S_I,
    LT_L_I,
    LT_S_S,
    LT_L_S,
    LT_S_U1,
    LT_L_U1,
    LT_S_U2,
    LT_L_U2,
    LT_S_Z,
    LT_L_Z,
    LT_OB,
    LT_CB,
};

const uint32_t PROGMEM unicode_map[] = {
    [SNEK]  = 0x1F40D, // 🐍
    [EURO]  = 0x20ac, // €
    [LT_S_A] = 0x105, // ą
    [LT_L_A] = 0x104, // Ą
    [LT_S_C] = 0x10d, // č
    [LT_L_C] = 0x10c, // Č
    [LT_S_E1] = 0x119, // ę
    [LT_L_E1] = 0x118, // Ę
    [LT_S_E2] = 0x117, // ė
    [LT_L_E2] = 0x116, // Ė
    [LT_S_I] = 0x12f, // į
    [LT_L_I] = 0x12e, // Į
    [LT_S_S] = 0x161, // š
    [LT_L_S] = 0x160, // Š'
    [LT_S_U1] = 0x173, // ų
    [LT_L_U1] = 0x172, // Ų
    [LT_S_U2] = 0x16b, // ū
    [LT_L_U2] = 0x16a, // Ū
    [LT_S_Z] = 0x17e, // ž
    [LT_L_Z] = 0x17d, // Ž
    [LT_OB] = 0x201e, // „
    [LT_CB] = 0x201c, // “
};

#define K_SNEK      X(SNEK)
#define K_EURO      X(EURO)
#define K_LT_A      XP(LT_S_A, LT_L_A)
#define K_LT_C      XP(LT_S_C, LT_L_C)
#define K_LT_E1     XP(LT_S_E1, LT_L_E1)
#define K_LT_E2     XP(LT_S_E2, LT_L_E2)
#define K_LT_I      XP(LT_S_I, LT_L_I)
#define K_LT_S      XP(LT_S_S, LT_L_S)
#define K_LT_U1     XP(LT_S_U1, LT_L_U1)
#define K_LT_U2     XP(LT_S_U2, LT_L_U2)
#define K_LT_Z      XP(LT_S_Z, LT_L_Z)
#define K_LT_OB     X(LT_OB)
#define K_LT_CB     X(LT_CB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T,                              KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_ESC  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_NAV   ,    KC_SPC  ,        KC_LSFT ,    L_SYM
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_PLUS ,KC_LBRC ,KC_RBRC ,KC_SCLN ,                          KC_MINS ,OS_ALT  ,OS_CTRL ,OS_GUI  ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_TILDE,KC_EQL  ,KC_LCBR ,KC_RCBR ,KC_COLN ,                          KC_UNDS ,KC_QUOT ,KC_DQT  ,K_EURO  ,KC_BSLS ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_NUMB  ,    _______ ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_TILDE,XXXXXXX ,KC_BRID ,KC_BRIU ,L_TMUX  ,                          XXXXXXX ,KC_PGDN ,KC_PGUP ,KC_PSCR ,K_PRINT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,OS_GUI  ,OS_CTRL ,OS_ALT  ,KC_ENT  ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_MPLY ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DELT ,KC_BSPC ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,L_MOUSE ,KC_VOLD ,KC_VOLU ,KC_MNXT ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        _______ ,    L_NUMB
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NUMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     RESET   ,K_LT_S  ,K_LT_U1 ,K_LT_U2 ,K_LT_Z  ,                          XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     K_LT_A  ,K_LT_C  ,K_LT_E1 ,K_LT_E2 ,K_LT_I  ,                          XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DELT ,KC_BSPC ,K_LT_OB ,K_LT_CB ,UC_MOD  ,                          XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    KC_0
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_TMUX] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,TM_URL  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          TM_LEFT ,TM_NEXT ,TM_PREV ,TM_RIGHT,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          TM_NEW  ,TM_SLCT ,XXXXXXX ,XXXXXXX ,TM_SRCH ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,                          XXXXXXX ,KC_LALT ,KC_LCTL ,KC_LGUI ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,L_MOUSE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_BTN1 ,    KC_BTN2 ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  )
};

#define TMUX_PREFIX SS_DOWN(X_LCTL) "b" SS_UP(X_LCTL)

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
    case KC_LSFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    switch (keycode) {
        case TM_LEFT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "<");
            return false;
        case TM_RIGHT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX ">");
            return false;
        case TM_NEXT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "n");
            return false;
        case TM_PREV:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "p");
            return false;
        case TM_NEW:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "c");
            return false;
        case TM_SLCT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "[");
            return false;
        case TM_SRCH:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX SS_DOWN(X_TAB) SS_UP(X_TAB));
            return false;
        case TM_URL:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX SS_DOWN(X_LCTL) "u" SS_UP(X_LCTL));
            return false;
    }
    return true;
}
