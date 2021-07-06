#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _QUICK 2
#define _NAV 3
#define _TMUX 4

enum custom_keycodes {
  TM_NEXT = SAFE_RANGE,
  TM_PREV,
  TM_LEFT,
  TM_RIGHT,
  TM_NEW,
  TM_SLCT,
};

enum ferris_tap_dances {
  TD_SC_ESC
};

// Shortcut to make keymap more readable

#define KC_QUITA    LT(_QUICK, KC_TAB)
#define KC_NAVEN    LT(_NAV, KC_ENT)
#define KC_SYMBS    LT(_SYMB, KC_BSPC)
#define KC_TMUXT    LT(_TMUX, KC_T)

#define K_SPC_SF    MT(MOD_LSFT, KC_SPC)

#define HOME_S      MT(MOD_LGUI, KC_S)
#define HOME_D      MT(MOD_LALT, KC_D)
#define HOME_F      MT(MOD_LCTL, KC_F)

#define HOME_J      MT(MOD_LCTL, KC_J)
#define HOME_K      MT(MOD_LALT, KC_K)
#define HOME_L      MT(MOD_LGUI, KC_L)

#define KGUI_W      LGUI(KC_W)
#define KGUI_TLD    LGUI(KC_TILDE)

#define K_PRINT     (QK_LCTL | QK_LSFT | QK_LGUI | KC_4)

#define KC_SC_ES    TD(TD_SC_ESC)

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
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_TMUXT,XXXXXXX ,                          XXXXXXX ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_A    ,HOME_S  ,HOME_D  ,HOME_F  ,KC_G    ,XXXXXXX ,                          XXXXXXX ,KC_H    ,HOME_J  ,HOME_K  ,HOME_L  ,KC_SC_ES,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_QUITA,    K_SPC_SF,XXXXXXX ,        XXXXXXX ,KC_NAVEN,    KC_SYMBS,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,XXXXXXX ,                          XXXXXXX ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_GRV  ,K_SNEK  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_MINS ,KC_EQL  ,KC_QUOT ,K_LT_OB ,KC_BSLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_TILDE,K_EURO  ,KC_LCBR ,KC_RCBR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_UNDS ,KC_PLUS ,KC_DQT  ,K_LT_CB ,KC_PIPE ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    _______ ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QUICK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KGUI_W  ,XXXXXXX ,XXXXXXX ,KGUI_TLD,XXXXXXX ,                          XXXXXXX ,K_LT_A  ,K_LT_C  ,K_LT_E1 ,K_LT_E2 ,K_LT_I  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,XXXXXXX ,                          XXXXXXX ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_ENT  ,KC_DELT ,XXXXXXX ,XXXXXXX ,KC_BSPC ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,K_LT_S  ,K_LT_U1 ,K_LT_U2 ,K_LT_Z  ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,KC_LSFT ,    KC_BSPC ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_PGDN ,KC_PGUP ,XXXXXXX ,K_PRINT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_MPLY ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_M_P ,RGB_TOG ,RGB_MOD ,XXXXXXX ,UC_MOD  ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_BRID ,KC_BRIU ,KC_VOLD ,KC_VOLU ,KC_MNXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_TMUX] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,TM_LEFT ,TM_NEXT ,TM_PREV ,TM_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,TM_NEW  ,TM_SLCT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

#define TMUX_PREFIX SS_DOWN(X_LCTL) "b" SS_UP(X_LCTL)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case TM_LEFT:
            SEND_STRING(TMUX_PREFIX "<");
            return false;
        case TM_RIGHT:
            SEND_STRING(TMUX_PREFIX ">");
            return false;
        case TM_NEXT:
            SEND_STRING(TMUX_PREFIX "n");
            return false;
        case TM_PREV:
            SEND_STRING(TMUX_PREFIX "p");
            return false;
        case TM_NEW:
            SEND_STRING(TMUX_PREFIX "c");
            return false;
        case TM_SLCT:
            SEND_STRING(TMUX_PREFIX "[");
            return false;
    }
    return true;
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_SC_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ESC)
};
