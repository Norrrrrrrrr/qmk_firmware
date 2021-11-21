/* Copyright 2021 gtips
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

enum layer_names {
  _BASE = 0,
  _LOWER,
  _F_KEY,
  _RAISE,
  _ADJUST
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

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define FKY_SFT LT(_F_KEY, KC_LSFT)
#define ADJ_BS LT(_ADJUST, KC_BSPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE
,----------------------------------.  ,----------------------------------.
|   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |
|------+------+------+------+------|  |------+------+------+------+------|
| A Sft| S Ctl| D Win| F Alt|   G  |  |   H  | J Alt| K Win| L Ctl| ; Sft|
|------+------+------+------+------|  |------+------+------+------+------|
|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |
`------+------+------+------+------|  |------+------+------+------+------'
                     |LowSpc|FkySft|  | AdjBS|RaiEnt|
                     `-------------'  `-------------'
   */
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    SF_A,    CT_S,    GU_D,    AL_F,    KC_G,          KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               LOW_SPC, FKY_SFT,       ADJ_BS, RAI_ENT
  ),

  /* LOWER
,----------------------------------.  ,----------------------------------.
|   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |
+------+------+------+------+------|  |------+------+------+------+------|
|   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |
+------+------+------+------+------|  |------+------+------+------+------|
|      |      |      |      |      |  |   [  |   ]  |   {  |   .  |   }  |
`------+------+------+------+------|  |------+------+------+------+------'
                     |LowSpc|      |  |  BS  | Enter|
                     `-------------'  `-------------'
   */
  [_LOWER] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_LBRC, KC_RBRC, KC_LCBR, KC_DOT,  KC_RCBR,
                               LOW_SPC, XXXXXXX,       KC_BSPC, KC_ENT
  ),

  /* F_Key
,----------------------------------.  ,----------------------------------.
|   F1 |   F2 |   F3 |   F4 |   F5 |  |   F6 |   F7 |   F8 |   F9 |  F10 |
|------+------+------+------+------|  |------+------+------+------+------|
|  F11 |  F12 |  ESC |   `  |   ~  |  |   _  |   +  |   "  |  App |   |  |
|------+------+------+------+------|  |------+------+------+------+------|
|      |      |      |      |      |  |   -  |   =  |   '  |      |   \  |
`------+------+------+------+------|  |------+------+------+------+------'
                     | Space|FkySft|  |  BS  | Enter|
                     `-------------'  `-------------'
   */
  [_F_KEY] = LAYOUT_reviung34(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  KC_ESC,  KC_GRV,  KC_TILD,       KC_UNDS, KC_PLUS, KC_DQT,  KC_APP,  KC_PIPE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MINS, KC_EQL,  KC_QUOT, XXXXXXX, KC_BSLS,
                               KC_SPC,  FKY_SFT,       KC_BSPC, KC_ENT
  ),

  /* RAISE
,----------------------------------.  ,----------------------------------.
|CtWn<-|CtWn->|SfWn<-|SfWn->|      |  |      | Home |PageDn|PageUp| End  |
|------+------+------+------+------|  |------+------+------+------+------|
| Shift| Ctrl |  Gui |  Alt |ImeOff|  |ImeOn | Left | Down | Up   | Right|
|------+------+------+------+------|  |------+------+------+------+------|
|      |      |      |      |      |  |      |  BS  |SftTab| Tab  | Del  |
`------+------+------+------+------|  |------+------+------+------+------'
                     | Space|      |  |  BS  |RaiEnt|
                     `-------------'  `-------------'
   */
  [_RAISE] = LAYOUT_reviung34(
    CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_LANG2,      KC_LANG1,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,
                               KC_SPC,  XXXXXXX,       KC_BSPC, RAI_ENT
  ),

  /* ADJUST
,----------------------------------.  ,----------------------------------.
| Reset| VAL+ | SAT+ | HUE+ | MODE+|  |      |      |      |Print | Ins  |
+------+------+------+------+------|  |------+------+------+------+------|
|      | BtnR | BtnM | BtnL |      |  |      |      |      |ScLock|Pause |
|------+------+------+------+------|  |------+------+------+------+------|
|RGB ON| VAL- | SAT- | HUE- | MODE-|  |      |      |      |      |      |
`------+------+------+------+------|  |------+------+------+------+------'
                     | Space|      |  | AdjBS| Enter|
                     `-------------'  `-------------'
   */
  [_ADJUST] = LAYOUT_reviung34(
    RESET,   RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,
    XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, KC_PAUS,
    RGB_TOG, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_SPC,  _______,       ADJ_BS, KC_ENT
  ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_ENT:
            return true;
            break;
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
    case ADJ_BS:
        return 500;
    /* Typing layer quickly */
    case LOW_SPC:
    case RAI_ENT:
    case FKY_SFT:
        return 130;
    default:
      return 160;
  }
}

