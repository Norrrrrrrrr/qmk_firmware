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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_split_3x5_sqmtrx( \
  L14, L03, L02, L01, L00,           R50, R51, R52, R53, R64, \
  L24, L23, L12, L11, L10,           R60, R61, R62, R73, R74, \
  L34, L33, L32, L21, L20,           R70, R71, R82, R83, R84, \
                 L42, L41, L30, R80, R91, R92 \
  ) \
  { \
    { L00,  L01,  L02,  L03,  KC_NO }, \
    { L10,  L11,  L12,  KC_NO,L14 }, \
    { L20,  L21,  KC_NO,L23,  L24 }, \
    { L30,  KC_NO,L32,  L33,  L34 }, \
    { KC_NO,L41,  L42,  KC_NO,KC_NO }, \
    { R50,  R51,  R52,  R53,  KC_NO }, \
    { R60,  R61,  R62,  KC_NO,R64 }, \
    { R70,  R71,  KC_NO,R73,  R74 }, \
    { R80,  KC_NO,R82,  R83,  R84 }, \
    { KC_NO,R91,  R92,  KC_NO,KC_NO } \
  }
