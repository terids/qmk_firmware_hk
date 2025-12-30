/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "users/holykeebs/holykeebs.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

enum layer_names {
    BASE,
    SYMBOLS,
    NUMPAD,
    SYSTEM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_COMM,    KC_O,    KC_U,    KC_L,    KC_J,                         KC_V,    KC_F,    KC_D,    KC_G,   KC_Q,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_I,    KC_A,    KC_E,    KC_R,    KC_W,                         KC_Y,    KC_H,    KC_T,    KC_S,    KC_N,   KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_DOT,    KC_QUOT,    KC_SLSH,    KC_X,    KC_Z,                         KC_K,    KC_P, KC_M,  KC_C, KC_B,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, OSM(MOD_LSFT),  LT(1, KC_ESC),     MO(2), KC_SPC, KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,  S(KC_1), S(KC_LBRC), S(KC_RBRC), S(KC_EQL),  S(KC_GRV),      XXXXXXX,    KC_HOME,    KC_UP,    KC_END,    XXXXXXX, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, S(KC_6), S(KC_9), S(KC_0), KC_EQL, KC_GRV,                    S(KC_5), KC_LEFT,   KC_DOWN,KC_RIGHT, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, RALT(KC_3), KC_LBRC, KC_RBRC, S(KC_4), S(KC_7),                S(KC_2), S(KC_SCLN), S(KC_8), KC_PGUP, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     MO(3), KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_PAST, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      KC_P0,  KC_P4, KC_P5, KC_P6, KC_PDOT,  S(KC_5),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                      KC_PPLS, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, MO(3),  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [SYSTEM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------.                   ,-----------------------------------------------------------------------------.
          QK_BOOT,     HK_DUMP,     HK_SAVE,     HK_RESET,     XXXXXXX, HK_C_SCROLL,                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     QK_BOOT,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
      QK_C_EEPROM,  HK_P_SET_D,  HK_P_SET_S, HK_P_SET_BUF,     XXXXXXX, HK_S_MODE_T,                           KC_UP,     KC_DOWN,     XXXXXXX,     XXXXXXX,     XXXXXXX, QK_C_EEPROM,
  //|------------+------------+------------+-------------+------------+------------|                   |------------+------------+------------+------------+------------+------------|
          KC_LSFT,     XXXXXXX,     XXXXXXX,      XXXXXXX,     XXXXXXX, HK_D_MODE_T,                         XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
  //|------------+------------+------------+-------------+------------+------------+--------| |--------+------------+------------+------------+------------+------------+------------|
                                                               KC_LGUI,     _______,  KC_SPC,    KC_ENT,     _______,     KC_RALT
                                                       //`----------------------------------' `----------------------------------'
  )
};
