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
// #include "keycode.h"
#include "quantum_keycodes.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY = 0,
    _LOWER,
    _LOWER2,
    _RAISE,
    _ADJUST
};

// Tap Dance declarations
enum {
    TD_F1_F6,
    TD_F2_F7,
    TD_F3_F8,
    TD_F4_F9,
    TD_F5F10,
    TD_F1112,
};

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
#define TT_F5F10 TD(TD_F5F10)
#define TT_F1112 TD(TD_F1112)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define LO2_SFT LT(_LOWER2, KC_LSFT)
#define KC_ADJ MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
,-----------------------------------------.  ,-----------------------------------------.
| Esc  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |   -  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | A Sft| S Ctl| D Win| F Alt|   G  |  |   H  | J Alt| K Win| L Ctl| ; Sft|   '  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |   =  |
`------+------+------+------+------+------|  |------+------+------+------+------+------'
                     |      |LowSpc|Lo2Sft|  |  BS  |RaiEnt|      |
                     `--------------------'  `--------------------'
   */
  [_QWERTY] = LAYOUT_split_3x6_3(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_TAB,  SF_A,    CT_S,    GU_D,    AL_F,     KC_G,         KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,   KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                                 XXXXXXX, LOW_SPC,  LO2_SFT,      KC_BSPC, RAI_ENT, XXXXXXX
  ),

  /* Lower
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  |  ESC |   ~  |   {  |   }  |ImeOff|  |ImeOn |   _  |   +  |   "  |   |  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |   `  |   [  |   ]  |      |  |      |   -  |   =  |   '  |   \  |   +  |
`------+------+------+------+------+------|  |------+------+------+------+------+------'
                     |      |LowSpc|Adjust|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_LOWER] = LAYOUT_split_3x6_3(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
      _______, KC_ESC,  KC_TILD, KC_LCBR, KC_RCBR, KC_LNG2,       KC_LNG1, KC_UNDS, KC_PLUS, KC_DQT,  KC_PIPE, KC_BSLS,
      _______, XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, XXXXXXX,       XXXXXXX, KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS, KC_PLUS,
                                 XXXXXXX, LOW_SPC, KC_ADJ,        _______, KC_ENT,  XXXXXXX
  ),

  /* Lower2
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | CLK_R| CLK_M| CLK_L| Wh_D | Wh_U |  |      |   +  |   -  |   *  |   /  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift| F1 F6| F2 F7| F3 F8| F4 F9|F5 F10|  |F11F12|      |   ,  |   .  |   =  |   +  |
`------+------+------+------+------+------|  |------+------+------+------+------+------'
                     |      |Adjust|Lo2Sft|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_LOWER2] = LAYOUT_split_3x6_3(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,
      _______, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_D, KC_WH_U,       XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_BSLS,
      _______, TT_F1F6, TT_F2F7, TT_F3F8, TT_F4F9, TT_F5F10,     TT_F1112, XXXXXXX, KC_COMM, KC_DOT,  KC_EQL , KC_PLUS,
                                 XXXXXXX, KC_ADJ,  LO2_SFT,       _______, KC_ENT,  XXXXXXX
  ),

  /* Raise
,-----------------------------------------.  ,-----------------------------------------.
| Esc  |CtWn<-|CtWn->|SfWn<-|SfWn->|      |  |      | Home |PageDn|PageUp| End  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | Shift| Ctrl |  Gui |  Alt |      |  |      | Left | Down | Up   | Right|      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |      |      |      |      |  |  App |  BS  |SftTab| Tab  | Del  |      |
`------+------+------+------+------+------|  |------+------+------+------+------+------'
                     |      | Space|      |  |  BS  |RaiEnt|      |
                     `--------------------'  `--------------------'
   */
  [_RAISE] = LAYOUT_split_3x6_3(
      KC_ESC,  CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
      _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_APP,  KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,  XXXXXXX,
                                 XXXXXXX, KC_SPC,  XXXXXXX,       _______, RAI_ENT, XXXXXXX
  ),

  /* Adjust
,-----------------------------------------.  ,-----------------------------------------.
|      | Reset|      |      |      |      |  |      |      |      |Print | Ins  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |      |      |  |      |      |      |ScLock|Pause |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |      |      |  |      |      |      |      |      |      |
`------+------+------+------+------+------|  |------+------+------+------+------+------'
                     |      |LowSpc|Lo2Sft|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_ADJUST] = LAYOUT_split_3x6_3(
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,  XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, KC_PAUS, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, _______, _______,       _______, KC_ENT,  XXXXXXX
  )
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case LO2_SFT:
        case RAI_ENT:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* Avoid mis-type */
    case GU_D:
    case GU_K:
        return 400;
    /* Typing layer quickly */
    case LOW_SPC:
    case LO2_SFT:
    case RAI_ENT:
        return 130;
    /* Easier for Tap Dance */
    case TT_F1F6:
    case TT_F2F7:
    case TT_F3F8:
    case TT_F4F9:
    case TT_F5F10:
    case TT_F1112:
      return 200;
    default:
      return 150;
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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F6),
    [TD_F2_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F7),
    [TD_F3_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F8),
    [TD_F4_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F9),
    [TD_F5F10] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
};
