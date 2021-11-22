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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KC_NOT_USED = SAFE_RANGE,
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

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define LO2_SFT LT(_LOWER2, KC_LSFT)
#define KC_ADJ MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* Qwerty
,-----------------------------------------.  ,-----------------------------------------.
| Esc `|   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |   -  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | A Sft| S Ctl| D Win| F Alt|   G  |  |   H  | J Alt| K Win| L Ctl| ; Sft|   '  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |   =  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Lo2Sft|  |  BS  |RaiEnt|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
      KC_TAB,  SF_A,    CT_S,    GU_D,    AL_F,     KC_G,                     KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,   KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOW_SPC,  LO2_SFT,                  KC_BSPC, RAI_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  /* Lower
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |      |      |      |      |  |   [  |   ]  |   {  |   .  |   }  |   +  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Adjust|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS, \
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LBRC, KC_RBRC, KC_LCBR, KC_DOT,  KC_RCBR, KC_PLUS, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOW_SPC, KC_ADJ,                    _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  /* Lower2
,-----------------------------------------.  ,-----------------------------------------.
|   `  |   F1 |   F2 |   F3 |   F4 |   F5 |  |   F6 |   F7 |   F8 |   F9 |  F10 |   _  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  |  F11 |  F12 |  ESC |   `  |   ~  |  |   _  |   +  |   "  |  App |   |  |   \  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |      |      |      |      |  |   -  |   =  |   '  |      |   \  |   +  |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |Adjust|Lo2Sft|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_LOWER2] = LAYOUT( \
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_UNDS, \
      _______, KC_F11,  KC_F12,  KC_ESC,  KC_GRV,  KC_TILD,                   KC_UNDS, KC_PLUS, KC_DQT,  KC_APP,  KC_PIPE, KC_BSLS, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_EQL,  KC_QUOT, XXXXXXX, KC_BSLS, KC_PLUS, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ADJ,  LO2_SFT,                   _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  /* Raise
,-----------------------------------------.  ,-----------------------------------------.
| Esc `|CtWn<-|CtWn->|SfWn<-|SfWn->|      |  |      | Home |PageDn|PageUp| End  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Tab  | Shift| Ctrl |  Gui |  Alt |ImeOff|  |ImeON | Left | Down | Up   | Right|      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
| Shift|      |      |      |      |      |  |      |  BS  |SftTab| Tab  | Del  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      | Space|      |  |  BS  |RaiEnt|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GESC, CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, \
      _______, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_LANG2,                  KC_LANG1,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,  XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX,                   _______, RAI_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

  /* Adjust
,-----------------------------------------.  ,-----------------------------------------.
|      | Reset|      |      |      |      |  |      |      |      |Print | Ins  |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      | BtnR | BtnM | BtnL |      |  |      |      |      |ScLock|Pause |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |      |      |  |      |      |      |      |      |      |
|------+------+------+------+------+------|  |------+------+------+------+------+------|
|      |      |      |      |LowSpc|Lo2Sft|  |  BS  | Enter|      |      |      |      |
`-----------------------------------------'  `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT( \
      XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,  XXXXXXX, \
      XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, KC_PAUS, XXXXXXX,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                   _______, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX\
      )
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_ENT:
        case LO2_SFT:
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
        return 200;
    /* Typing layer quickly */
    case LOW_SPC:
    case RAI_ENT:
    case LO2_SFT:
        return 130;
    default:
      return 160;
  }
}

