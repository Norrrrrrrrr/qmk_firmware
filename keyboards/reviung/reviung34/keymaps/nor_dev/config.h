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

#pragma once

// #define DEBUG_MATRIX_SCAN_RATE  //Output Scan rate [scans/sec]
                                // '22/06/01: 2427[scans/sec] at Normal debounce
                                // '22/06/01: 1941[scans/sec] at eager_pk debounce

// place overrides here

//s nn_rev01
#undef TAPPING_TERM
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
//e nn_rev01
#define QUICK_TAP_TERM_PER_KEY

// 押しっぱなしの時の反応までのインターバル
#undef  MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// カーソルの移動スピード
#undef  MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 2
// マウス操作がトップスピードになるまでの時間
#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30

#define WS2812_DI_PIN D3
  #define RGBLIGHT_LED_COUNT 9
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_SLEEP
// /*== all animations enable ==*/
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
