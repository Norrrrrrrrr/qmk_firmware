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

#include "crkbd_m.h"

const matrix_row_t matrix_mask[MATRIX_ROWS] = {
  0b0000000000001111,
  0b0000000000010111,
  0b0000000000011011,
  0b0000000000011101,
  0b0000000000000110,   // Not Connected, Not Connected, Key, Key, Column Diode

  0b0000000000001111,
  0b0000000000010111,
  0b0000000000011011,
  0b0000000000011101,
  0b0000000000000110,   // Not Connected, Not Connected, Key, Key, Column Diode
};
