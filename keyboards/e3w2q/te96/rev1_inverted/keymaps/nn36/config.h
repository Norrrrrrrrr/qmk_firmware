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

#pragma once

// place overrides here

/* Select hand configuration */
#define EE_HANDS

//s nn_rev01
#undef TAPPING_TERM
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
//e nn_rev01
//s nn_rev02
// #undef TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
//e nn_rev02

// 押しっぱなしの時の反応までのインターバル
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// カーソルの移動スピード
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 2
// マウス操作がトップスピードになるまでの時間
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30


/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_nn36( \
    l54, l53, l52, l51, l50,           r00, r01, r02, r03, r04, \
    l44, l43, l42, l41, l40,           r10, r11, r12, r13, r14, \
    l34, l33, l32, l31, l30,           r20, r21, r22, r23, r24, \
                   l21, l20, l25, r35, r30, r31 \
  ) \
  { \
    { l20,   l21,   KC_NO, KC_NO, KC_NO, l25   }, \
    { l30,   l31,   l32,   l33,   l34,   KC_NO }, \
    { l40,   l41,   l42,   l43,   l44,   KC_NO }, \
    { l50,   l51,   l52,   l53,   l54,   KC_NO }, \
    { r00,   r01,   r02,   r03,   r04,   KC_NO }, \
    { r10,   r11,   r12,   r13,   r14,   KC_NO }, \
    { r20,   r21,   r22,   r23,   r24,   KC_NO }, \
    { r30,   r31,   KC_NO, KC_NO, KC_NO, r35   } \
  }
