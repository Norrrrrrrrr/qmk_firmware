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

