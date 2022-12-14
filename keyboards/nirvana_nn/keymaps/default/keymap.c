/* Copyright 2021 Norrrrrrrrr
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
#include "keycode.h"
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
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Lo2Sft|  |  BS  |RaiEnt|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_TAB,  SF_A,    CT_S,    GU_D,    AL_F,     KC_G,         KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,   KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOW_SPC,  LO2_SFT,      KC_BSPC, RAI_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  /* Lower
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  |  ESC |   ~  |   {  |   }  |ImeOff|  |ImeOn |   _  |   +  |   "  |   |  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |   `  |   [  |   ]  |      |  |      |   -  |   =  |   '  |   \  |   +  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Adjust|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_LOWER] = LAYOUT(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
      _______, KC_ESC,  KC_TILD, KC_LCBR, KC_RCBR, KC_LNG2,       KC_LNG1, KC_UNDS, KC_PLUS, KC_DQT,  KC_PIPE, KC_BSLS,
      _______, XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, XXXXXXX,       XXXXXXX, KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS, KC_PLUS,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOW_SPC, KC_ADJ,        _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  /* Lower2
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | CLK_R| CLK_M| CLK_L| Wh_D | Wh_U |  |      |   +  |   -  |   *  |   /  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift| F1 F6| F2 F7| F3 F8| F4 F9|F5 F10|  |F11F12|      |   ,  |   .  |   =  |   +  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |Adjust|Lo2Sft|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_LOWER2] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,
      _______, KC_BTN2, KC_BTN3, KC_BTN1, KC_WH_D, KC_WH_U,       XXXXXXX, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_BSLS,
      _______, TT_F1F6, TT_F2F7, TT_F3F8, TT_F4F9, TT_F5F10,     TT_F1112, XXXXXXX, KC_COMM, KC_DOT,  KC_EQL , KC_PLUS,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ADJ,  LO2_SFT,       _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  /* Raise
,-----------------------------------------.  ,-----------------------------------------.
| Esc `|CtWn<-|CtWn->|SfWn<-|SfWn->|      |  |      | Home |PageDn|PageUp| End  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | Shift| Ctrl |  Gui |  Alt |      |  |      | Left | Down | Up   | Right|      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |      |      |      |      |  |  App |  BS  |SftTab| Tab  | Del  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      | Space|      |  |  BS  |RaiEnt|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_RAISE] = LAYOUT(
      KC_ESC,  CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
      _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_APP,  KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,  XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX,       _______, RAI_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  /* Adjust
,-----------------------------------------.  ,-----------------------------------------.
|      | Reset|      |      |      |      |  |      |      |      |Print | Ins  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |      |      |  |      |      |      |ScLock|Pause |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |      |      |  |      |      |      |      |      |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Lo2Sft|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT(
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,  XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, KC_PAUS, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,       _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F6),
    [TD_F2_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F7),
    [TD_F3_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F8),
    [TD_F4_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F9),
    [TD_F5F10] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F10),
    [TD_F1112] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
};
