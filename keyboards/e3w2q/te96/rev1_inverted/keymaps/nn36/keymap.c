/* Copyright 2020 e3w2q
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

enum layer_names {
  _BASE = 0,
  _LOWER,
  _LOWER2,
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
#define LO2_SFT LT(_LOWER2, KC_LSFT)
#define KC_ADJ MO(_ADJUST)

/* Combo */
const uint16_t PROGMEM fg_combo[] = {AL_F, KC_G, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, AL_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};

combo_t key_combos[] = {
  COMBO(fg_combo, KC_LNG2),
  COMBO(hj_combo, KC_LNG1),
  COMBO(nm_combo, KC_APP),
  COMBO(mcom_combo, KC_MINS),
  COMBO(xc_combo, KC_BTN2),
  COMBO(cv_combo, KC_BTN1),
  COMBO(zx_combo, KC_WH_U),
  COMBO(vb_combo, KC_WH_D),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE
,----------------------------------.                ,----------------------------------.
|   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |
|------+------+------+------+------|                |------+------+------+------+------|
| A Sft| S Ctl| D Win| F Alt|   G  |                |   H  | J Alt| K Win| L Ctl| ; Sft|
|      |      |      |   ^ImeOff^  |                |   ^ImeOn^   |      |      |      |
|------+------+------+------+------|                |------+------+------+------+------|
|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  |
|    ^WH_U^^CLK_R^^CLK_L^ ^WH_D^   |                |    ^App^  ^ - ^    |      |      |
`------+------+------+------+------+------.  ,------+------+------+------+------+------'
                     |      |LowSpc|Lo2Sft|  |  BS  |RaiEnt|      |
                     `--------------------'  `--------------------'
   */
  [_BASE] = LAYOUT_nn36(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    SF_A,    CT_S,    GU_D,    AL_F,    KC_G,          KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      XXXXXXX, LOW_SPC, LO2_SFT,       KC_BSPC, RAI_ENT, XXXXXXX
  ),

  /* LOWER
,----------------------------------.                ,----------------------------------.
|   !  |   @  |   #  |   $  |   %  |                |   ^  |   &  |   *  |   (  |   )  |
|------+------+------+------+------|                |------+------+------+------+------|
|  ESC |   ~  |   {  |   }  |      |                |      |   _  |   +  |   "  |   |  |
|------+------+------+------+------|                |------+------+------+------+------|
|      |   `  |   [  |   ]  |      |                |      |   -  |   =  |   '  |   \  |
`------+------+------+------+------+------.  ,------+------+------+------+------+------'
                     |      |LowSpc|Adjust|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_LOWER] = LAYOUT_nn36(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_ESC,  KC_TILD, KC_LCBR, KC_RCBR, XXXXXXX,       XXXXXXX, KC_UNDS, KC_PLUS, KC_DQT,  KC_PIPE,
    XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, XXXXXXX,       XXXXXXX, KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS,
                      XXXXXXX, LOW_SPC, KC_ADJ,        _______, KC_ENT,  XXXXXXX
  ),

  /* LOWER2
,----------------------------------.                ,----------------------------------.
|   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |
|------+------+------+------+------|                |------+------+------+------+------|
|  F6  |  F7  |  F8  |  F9  |  F10 |                |  F12 |   +  |   -  |   *  |   /  |
|------+------+------+------+------|                |------+------+------+------+------|
|  F1  |  F2  |  F3  |  F4  |  F5  |                |  F11 |      |   ,  |   .  |   =  |
`------+------+------+------+------+------.  ,------+------+------+------+------+------'
                     |      |Adjust|Lo2Sft|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_LOWER2] = LAYOUT_nn36(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F12,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F11,  XXXXXXX, KC_COMM, KC_DOT,  KC_EQL ,
                      XXXXXXX, KC_ADJ,  LO2_SFT,       _______, KC_ENT,  XXXXXXX
  ),

  /* RAISE
,----------------------------------.                ,----------------------------------.
|CtWn<-|CtWn->|SfWn<-|SfWn->|      |                |      | Home |PageDn|PageUp| End  |
|------+------+------+------+------|                |------+------+------+------+------|
| Shift| Ctrl |  Gui |  Alt |      |                |      | Left | Down | Up   | Right|
|------+------+------+------+------|                |------+------+------+------+------|
|      |      |      |      |      |                |  App |  BS  |SftTab| Tab  | Del  |
`------+------+------+------+------+------.  ,------+------+------+------+------+------'
                     |      | Space|      |  |  BS  |RaiEnt|      |
                     `--------------------'  `--------------------'
   */
  [_RAISE] = LAYOUT_nn36(
    CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_APP,  KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,
                      XXXXXXX, KC_SPC,  XXXXXXX,       _______, RAI_ENT, XXXXXXX
  ),

  /* ADJUST
,----------------------------------.                ,----------------------------------.
| Reset|      |      |      |      |                |      |      |      |Print | Ins  |
+------+------+------+------+------|                |------+------+------+------+------|
|      |      |      |      |      |                |      |      |      |ScLock|Pause |
|------+------+------+------+------|                |------+------+------+------+------|
|      |      |      |      |      |                |      |      |      |      |      |
`------+------+------+------+------+------.  ,------+------+------+------+------+------'
                     |      |LowSpc|Lo2Sft|  |  BS  | Enter|      |
                     `--------------------'  `--------------------'
   */
  [_ADJUST] = LAYOUT_nn36(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_SCRL, KC_PAUS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      XXXXXXX, _______,  _______,      _______, KC_ENT,  XXXXXXX
  ),
};

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case LO2_SFT:
        case RAI_ENT:
            return 0;
            break;
        default:
            return QUICK_TAP_TERM;
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
    default:
      return 150;
  }
}
