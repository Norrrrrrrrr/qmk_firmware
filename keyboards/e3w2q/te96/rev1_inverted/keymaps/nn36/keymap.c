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
#include "keycode.h"
#include "quantum_keycodes.h"

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-------------------------------------------
   *  | XXXX XXXX Ctrl/Esc Q    W    E    R     T
   *  | XXXX XXXX Shft/Tab A    S    D    F     G
   *  | XXXX XXXX XXXX     Z    X    C    V     B
   *  | XXXX XXXX XXXX  XXXX XXXX XXXX XXXX  XXXX
   *  | XXXX XXXX XXXX  XXXX XXXX XXXX MO(1) Spce
   *  | XXXX XXXX XXXX  XXXX XXXX XXXX XXXX  XXXX
   *  `-------------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,---------------------------------------------
   *  |    Y    U     I    O    P GUI/Del XXXX XXXX
   *  |    H    J     K    L    - Alt/BS  XXXX XXXX
   *  |    N    M     ,    .    / XXXX    XXXX XXXX
   *  | XXXX XXXX  XXXX XXXX XXXX XXXX    XXXX XXXX
   *  | Entr MO(2) XXXX XXXX XXXX XXXX    XXXX XXXX
   *  | XXXX XXXX  XXXX XXXX XXXX XXXX    XXXX XXXX
   *  `---------------------------------------------
   *  ,-----------------------------------------
   *  |   XX   XX   XX   E6   D6   C6   B6   A6
   *  |   XX   XX   XX   E5   D5   C5   B5   A5
   *  |   XX   XX   XX   E4   D4   C4   B4   A4
   *  |   XX   XX   F3   XX   XX   XX   B3   A3
   *  |   XX   XX   XX   XX   XX   XX   XX   XX
   *  |   XX   XX   XX   XX   XX   XX   XX   XX
   *  `-----------------------------------------
   */

  [_BASE] = LAYOUT( /* Base */
    XXXXXXX,  XXXXXXX,  XXXXXXX, KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
    XXXXXXX,  XXXXXXX,  XXXXXXX, SF_A,     CT_S,     GU_D,     AL_F,     KC_G,
    XXXXXXX,  XXXXXXX,  XXXXXXX, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
    XXXXXXX,  XXXXXXX,  LO2_SFT, XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO  ,  LOW_SPC,
    XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,

    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     MT(MOD_LGUI, KC_DEL),  XXXXXXX,  XXXXXXX,
    KC_H,     KC_J,     KC_K,     KC_L,     KC_MINS,  MT(MOD_LALT, KC_BSPC), XXXXXXX,  XXXXXXX,
    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,               XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,               XXXXXXX,  XXXXXXX,
    KC_ENT,   MO(2),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,               XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,               XXXXXXX,  XXXXXXX
  ),

  /* Lower Layer */
  [_LOWER] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ESC,   KC_TILD,  KC_LCBR,  KC_RCBR,  KC_NO  ,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO,    KC_GRV,   KC_LBRC,  KC_RBRC,  KC_NO  ,
    XXXXXXX,  XXXXXXX,  KC_ADJ ,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO  ,  LOW_SPC,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,

    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,  XXXXXXX,  XXXXXXX,
    KC_COLN,  KC_DQUO,  KC_GT,    KC_LCBR,  KC_RCBR,  _______,  XXXXXXX,  XXXXXXX,
    KC_SCLN,  KC_QUOT,  KC_LT,    KC_LBRC,  KC_RBRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  MO(3),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  /* Lower2 Layer */
  [_LOWER2] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F11,   KC_F12,   XXXXXXX,  KC_PLUS,  KC_MINS,
    XXXXXXX,  XXXXXXX,  LO2_SFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO  ,  KC_ADJ ,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,

    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,  XXXXXXX,  XXXXXXX,
    KC_COLN,  KC_DQUO,  KC_GT,    KC_LCBR,  KC_RCBR,  _______,  XXXXXXX,  XXXXXXX,
    KC_SCLN,  KC_QUOT,  KC_LT,    KC_LBRC,  KC_RBRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  MO(3),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  /* Raise Layer */
  [_RAISE] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  CG_LEFT,  CG_RGHT,  SG_LEFT,  SG_RGHT,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LANG2,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_NO  ,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO  ,  KC_SPC ,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,

    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,  XXXXXXX,  XXXXXXX,
    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NO  ,  _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,

    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case LO2_SFT:
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
    /* Typing layer quickly */
    case LOW_SPC:
    case LO2_SFT:
    case RAI_ENT:
        return 130;
    default:
      return 150;
  }
}

