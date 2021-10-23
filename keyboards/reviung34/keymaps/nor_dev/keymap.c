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
// #include "keycode.h"
#include "quantum_keycodes.h"

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
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

    TD_BRCSET,
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
  /* BASE
,----------------------------------.  ,----------------------------------.
|   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |
|------+------+------+------+------|  |------+------+------+------+------|
| A Sft| S Ctl| D Win| F Alt|   G  |  |   H  | J Alt| K Win| L Ctl| ; Sft|
|------+------+------+------+------|  |------+------+------+------+------|
|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |
`------+------+------+------+------|  |------+------+------+------+------'
                     |LowSpc|AdjSft|  |  BS  |RaiEnt|
                     `-------------'  `-------------'
   */
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    SF_A,    CT_S,    GU_D,    AL_F,    KC_G,          KC_H,    AL_J,    GU_K,    CT_L,    SF_SC,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                               LOW_SPC, ADJ_SFT,       KC_BSPC, RAI_ENT
  ),

  /* LOWER
,----------------------------------.  ,----------------------------------.
|   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |
+------+------+------+------+------|  |------+------+------+------+------|
| ! F11| @ F12| # ESC| $  ` | %  ~ |  | ^ App| &  [ | *  ] | (  { | )  } |
+------+------+------+------+------|  |------+------+------+------+------|
| F1 F6| F2 F7| F3 F8| F4 F9|F5 F10|  | -  _ | =  + | '  " |   .  | \  | |
`------+------+------+------+------|  |------+------+------+------+------'
                     |LowSpc|AdjSft|  |()[]{}| Enter|
                     `-------------'  `-------------'
   */
  [_LOWER] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    TT_EX_11,TT_AT_12,TT_HS_ES,TT_DL_GR,TT_PR_TL,      TT_CR_AP,TT_AM_L2,TT_AS_R2,TT_LB13, TT_RB13,
    TT_F1F6, TT_F2F7, TT_F3F8, TT_F4F9, TT_F5F10,      TT_MI_UN,TT_EQ_PL,TT_QU_DQ,_______, TT_BL_PI,
                               LOW_SPC, _______,      KC_BRCSET,KC_ENT
  ),

  /* RAISE
,----------------------------------.  ,----------------------------------.
|CtWn<-|CtWn->|SfWn<-|SfWn->|      |  |      | Home |PageDn|PageUp| End  |
|------+------+------+------+------|  |------+------+------+------+------|
| Shift| Ctrl |  Gui |  Alt |ImeOff|  |ImeOn | Left | Down | Up   | Right|
|------+------+------+------+------|  |------+------+------+------+------|
|      |      |      |      |      |  |      |  BS  |SftTab| Tab  | Del  |
`------+------+------+------+------|  |------+------+------+------+------'
                     | Space|AdjSft|  |  BS  |RaiEnt|
                     `-------------'  `-------------'
   */
  [_RAISE] = LAYOUT_reviung34(
    CG_LEFT, CG_RGHT, SG_LEFT, SG_RGHT, XXXXXXX,       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_LANG2,     KC_LANG1, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_BSPC,S(KC_TAB),KC_TAB,  KC_DEL,
                               KC_SPC,  _______,       KC_BSPC, RAI_ENT
  ),

  /* ADJUST
,----------------------------------.  ,----------------------------------.
| Reset| VAL+ | SAT+ | HUE+ | MODE+|  |      |      |      |Print | Ins  |
+------+------+------+------+------|  |------+------+------+------+------|
|      | BtnR | BtnM | BtnL |      |  |      |      |      |ScLock|Pause |
|------+------+------+------+------|  |------+------+------+------+------|
|RGB ON| VAL- | SAT- | HUE- | MODE-|  |      |      |      |      |      |
`------+------+------+------+------|  |------+------+------+------+------'
                     | Space|AdjSft|  |  BS  | Enter|
                     `-------------'  `-------------'
   */
  [_ADJUST] = LAYOUT_reviung34(
    RESET,   RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,       XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_INS,
    XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, KC_SLCK, KC_PAUS,
    RGB_TOG, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_SPC,  _______,       _______, KC_ENT
  ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

//s nn_rev02
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
//e nn_rev02

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

    [TD_BRCSET] = ACTION_TAP_DANCE_FN(dance_brackets_set),
};
