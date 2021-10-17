/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "keycode.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  KC_NOT_USED = SAFE_RANGE,
};

// Tap Dance declarations
enum {
    TD_F1_F6,
    TD_F2_F7,
    TD_F3_F8,
    TD_F4_F9,
    TD_F5_F10,

    TD_EX_11,
    TD_AT_12,
    TD_HS_ES,
    TD_DL_GR,
    TD_PR_TL,

    TD_CR_AP,
    TD_AM_L2,
    TD_AS_R2,
    TD_LB13,
    TD_RB13,

    TD_MI_UN,
    TD_EQ_PL,
    TD_QU_DQ,
    TD_BL_PI,

    TD_BRCSET
};

//Macros
#define SF_A SFT_T(KC_A)
#define CT_S CTL_T(KC_S)
#define GU_D GUI_T(KC_D)
#define AL_F ALT_T(KC_F)

#define AL_J ALT_T(KC_J)
#define GU_K GUI_T(KC_K)
#define CT_L CTL_T(KC_L)
#define SF_SC SFT_T(KC_SCLN)

#define CG_LEFT C(G(KC_LEFT))
#define CG_RGHT C(G(KC_RGHT))
#define SG_LEFT S(G(KC_LEFT))
#define SG_RGHT S(G(KC_RGHT))

#define TT_F1F6 TD(TD_F1_F6)
#define TT_F2F7 TD(TD_F2_F7)
#define TT_F3F8 TD(TD_F3_F8)
#define TT_F4F9 TD(TD_F4_F9)
#define TT_F5F10 TD(TD_F5_F10)

#define TT_EX_11 TD(TD_EX_11)
#define TT_AT_12 TD(TD_AT_12)
#define TT_HS_ES TD(TD_HS_ES)
#define TT_DL_GR TD(TD_DL_GR)
#define TT_PR_TL TD(TD_PR_TL)

#define TT_CR_AP TD(TD_CR_AP)
#define TT_AM_L2 TD(TD_AM_L2)
#define TT_AS_R2 TD(TD_AS_R2)
#define TT_LB13 TD(TD_LB13)
#define TT_RB13 TD(TD_RB13)

#define TT_MI_UN TD(TD_MI_UN)
#define TT_EQ_PL TD(TD_EQ_PL)
#define TT_QU_DQ TD(TD_QU_DQ)
#define TT_BL_PI TD(TD_BL_PI)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define ADJ_SFT LT(_ADJUST, KC_LSFT)

#define KC_BRCSET TD(TD_BRCSET)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,   SF_A,    CT_S,    GU_D,    AL_F,    KC_G,                         KC_H,    AL_J,    GU_K,    CT_L,   SF_SC,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, LOW_SPC, ADJ_SFT,    KC_BSPC, RAI_ENT, KC_BRCSET
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, TT_EX_11,TT_AT_12,TT_HS_ES,TT_DL_GR,TT_PR_TL,                     TT_CR_AP,TT_AM_L2,TT_AS_R2,TT_LB13, TT_RB13, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, TT_F1F6, TT_F2F7, TT_F3F8, TT_F4F9, TT_F5F10,                     TT_MI_UN,TT_EQ_PL,TT_QU_DQ,_______, TT_BL_PI,KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, LOW_SPC, _______,   KC_BRCSET, KC_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_GESC, CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_LANG2,                     KC_LANG1,KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BSPC,S(KC_TAB), KC_TAB,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX,  KC_SPC, _______,    KC_BSPC, RAI_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX,  RESET,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,  KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX,  KC_SPC, _______,    KC_BSPC,  KC_ENT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_ENT:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* Aoid to mistake mod */
    case GU_D:
    case GU_K:
      return 200;
    /* Easier for Tap Dance */
    case TT_F1F6:
    case TT_F2F7:
    case TT_F3F8:
    case TT_F4F9:
    case TT_F5F10:

    case TT_EX_11:
    case TT_AT_12:
    case TT_HS_ES:
    case TT_DL_GR:
    case TT_PR_TL:

    case TT_CR_AP:
    case TT_AM_L2:
    case TT_AS_R2:
    case TT_LB13:
    case TT_RB13:

    case TT_MI_UN:
    case TT_EQ_PL:
    case TT_QU_DQ:
    case TT_BL_PI:
      return 200;
    case KC_BRCSET:
      return 300;
    default:
      return TAPPING_TERM;
  }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  #ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
  #endif // OLED_DRIVER_ENABLE
  }
  return true;
}


void dance_brackets_set(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("()"SS_TAP(X_LEFT));
  }
  else if (state->count == 2) {
    SEND_STRING("[]"SS_TAP(X_LEFT));
  }
  else if (state->count >= 3) {
    SEND_STRING("{}"SS_TAP(X_LEFT));
    reset_tap_dance(state);
  }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F6),
    [TD_F2_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F7),
    [TD_F3_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F8),
    [TD_F4_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F9),
    [TD_F5_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),

    [TD_EX_11] = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_F11),
    [TD_AT_12] = ACTION_TAP_DANCE_DOUBLE(KC_AT, KC_F12),
    [TD_HS_ES] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_ESC),
    [TD_DL_GR] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_GRV),
    [TD_PR_TL] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_TILD),

    [TD_CR_AP] = ACTION_TAP_DANCE_DOUBLE(KC_CIRC, KC_APP),
    [TD_AM_L2] = ACTION_TAP_DANCE_DOUBLE(KC_AMPR, KC_LBRC),
    [TD_AS_R2] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR, KC_RBRC),
    [TD_LB13] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
    [TD_RB13] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),

    [TD_MI_UN] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_EQ_PL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [TD_QU_DQ] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_BL_PI] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),

    [TD_BRCSET] = ACTION_TAP_DANCE_FN(dance_brackets_set)
};
