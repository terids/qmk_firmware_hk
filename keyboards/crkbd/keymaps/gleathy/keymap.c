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
#include "quantum/color.h"
#include "quantum/quantum.h"
#include "users/holykeebs/holykeebs.h"
#include "drivers/sensors/pimoroni_trackball.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

// The hue must be normalised to 0-255
#define BASE_HSV 0, 255, 255
#define SYMBOLS_HSV 180, 255, 255
#define NUMPAD_HSV 148, 255, 255
#define SYSTEM_HSV 20, 255, 255
#define OTHER_HSV 40, 255, 255

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
                                          KC_TRNS, KC_TRNS,  MO(3),     KC_TRNS, KC_TRNS, KC_TRNS
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

void set_trackball_colour(int h, int s, int v) {
    HSV colour = { .h = h, .s = s, .v = v };
    RGB rgb = hsv_to_rgb(colour);
    pimoroni_trackball_set_rgbw(rgb.r, rgb.g, rgb.b, 0);
}

void keyboard_post_init_kb(void) {
    set_trackball_colour(OTHER_HSV);
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            set_trackball_colour(BASE_HSV);
            break;
        case SYMBOLS:
            set_trackball_colour(SYMBOLS_HSV);
            break;
        case NUMPAD:
            set_trackball_colour(NUMPAD_HSV);
            break;
        case SYSTEM:
            set_trackball_colour(SYSTEM_HSV);
            break;
        default:
            set_trackball_colour(OTHER_HSV);
            break;
    }

    return state;
}
