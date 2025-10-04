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
    _NAVIGATION,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOW_SPC,
  RAI_ENT,
  NAVI,
//   ADJUST,
};

// Tap Dance declarations
enum {
    TD_LBRCS,
    TD_RBRCS,
    TD_BRCSET,
    // TD_QUOT_APP,
    TD_H_APP,
    TD_MI_UD,
    TD_EQ_PL,
    // TD_E_ESC,
    // TD_R_GRV,
    // TD_Y_QUO,
    // TD_U_MIN,
    // TD_I_EQL,
    // TD_O_BSL,
    TD_F1_F6,
    TD_F2_F7,
    TD_F3_F8,
    TD_F4_F9,
    TD_F5_F10,
    TD_F11_F12,
};

#define MT_A_SFT SFT_T(KC_A)
#define MT_S_CTL CTL_T(KC_S)
#define MT_D_GUI GUI_T(KC_D)
#define MT_F_ALT ALT_T(KC_F)
// #define MT_G_SFT SFT_T(KC_G)

// #define MT_H_SFT SFT_T(KC_H)
#define MT_J_ALT ALT_T(KC_J)
#define MT_K_GUI GUI_T(KC_K)
#define MT_L_CTL CTL_T(KC_L)
#define MT_SC_SFT SFT_T(KC_SCLN)

#define CG_LEFT C(G(KC_LEFT))
#define CG_RGHT C(G(KC_RGHT))
#define SG_LEFT S(G(KC_LEFT))
#define SG_RGHT S(G(KC_RGHT))

#define KC_LBRCS TD(TD_LBRCS)
#define KC_RBRCS TD(TD_RBRCS)
#define KC_BRCSET TD(TD_BRCSET)
// #define KC_QTAPP TD(TD_QUOT_APP)
#define KC_H_APP TD(TD_H_APP)
#define KC_MI_UD TD(TD_MI_UD)
#define KC_EQ_PL TD(TD_EQ_PL)

#define KC_F1F6 TD(TD_F1_F6)
#define KC_F2F7 TD(TD_F2_F7)
#define KC_F3F8 TD(TD_F3_F8)
#define KC_F4F9 TD(TD_F4_F9)
#define KC_F5F10 TD(TD_F5_F10)
#define KC_F1112 TD(TD_F11_F12)

// #define LOW_SPC LT(_LOWER, KC_SPC)
// #define RAI_ENT LT(_RAISE, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,MT_A_SFT,MT_S_CTL,MT_D_GUI,MT_F_ALT,    KC_G,                     KC_H_APP,MT_J_ALT,MT_K_GUI,MT_L_CTL,MT_SC_SFT,KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             NAVI, KC_LSFT, LOW_SPC,    RAI_ENT, KC_BSPC,KC_BRCSET
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,KC_LBRCS,KC_RBRCS, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F1F6, KC_F2F7, KC_F3F8, KC_F4F9,KC_F5F10,                     KC_F1112,KC_MI_UD,KC_EQ_PL, _______, _______, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      CG_LEFT, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, CG_RGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,                    C(KC_INS), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,S(KC_INS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      SG_LEFT, KC_BSPC,S(KC_TAB), KC_TAB,  KC_DEL, SG_RGHT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,                      _______, _______, _______, _______, _______, _______,

  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,  KC_INS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     KC_LANG2, XXXXXXX, XXXXXXX, KC_SLCK, KC_PAUS,KC_LANG1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

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
// #define L_ADJUST 8
#define L_ADJUST 16

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

// Setting ADJUST
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

static bool is_lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool is_raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  #ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
  #endif // OLED_DRIVER_ENABLE
  }
  switch (keycode) {
    case LOW_SPC:
      if (record->event.pressed) {
        is_lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        if (is_lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_SPC);
        }
        is_lower_pressed = false;
      }
      return false;
      break;

    case RAI_ENT:
      if (record->event.pressed) {
        is_raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        if (is_raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_ENT);
        }
        is_raise_pressed = false;
      }
      return false;
      break;
    
    case NAVI:
      if (record->event.pressed) {
        layer_on(_NAVIGATION);
      } else {
        layer_off(_NAVIGATION);
      }
      return false;
      break;

    default:
      if (record->event.pressed) {
        is_lower_pressed = false;
        is_raise_pressed = false;
      }
      break;
  }
  return true;
}


void dance_lbrackets(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING("(");
  }
  else if (state->count == 2) {
    SEND_STRING("[");
  }
  else if (state->count >= 3) {
    SEND_STRING("{");
    reset_tap_dance(state);
  }
}

void dance_rbrackets(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    SEND_STRING(")");
  }
  else if (state->count == 2) {
    SEND_STRING("]");
  }
  else if (state->count >= 3) {
    SEND_STRING("}");
    reset_tap_dance(state);
  }
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
    [TD_LBRCS] = ACTION_TAP_DANCE_FN(dance_lbrackets),
    [TD_RBRCS] = ACTION_TAP_DANCE_FN(dance_rbrackets),
    [TD_BRCSET] = ACTION_TAP_DANCE_FN(dance_brackets_set),
    // [TD_QUOT_APP] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_APP),
    [TD_H_APP] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_APP),
    [TD_MI_UD] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, S(KC_MINS)),
    [TD_EQ_PL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, S(KC_EQL)),
    // [TD_E_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_ESC),
    // [TD_R_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_GRV),
    // [TD_Y_QUO] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_QUOT),
    // [TD_U_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_MINS),
    // [TD_I_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_EQL),
    // [TD_O_BSL] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_BSLS),
    [TD_F1_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F6),
    [TD_F2_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F7),
    [TD_F3_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F8),
    [TD_F4_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F9),
    [TD_F5_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),
    [TD_F11_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
};
