// Copyright 2022 QMK / James Young (@noroadsleft)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layer_names {
    _QWERTZ,
    _LOWER,
    _RAISE,
    _SPECIAL
};

#define LOWER TL_LOWR
#define RAISE TL_UPPR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTZ (DE)
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ESC│ Q │ W │ E │ R │ T │ Z │ U │ I │ O │ P │DEL│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │TAB│ A │ S │ D │ F │ G │ H │ J │ K │ L │ # │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤ENT│
     * │ 1 │ 2 │ 3 │SFT│ Y │ X │ C │ V │ B │ N │ M │ , │ . │ < │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┼───┤
     * │ , │ 0 │CTL│CTL│Alt│GUI│AGr│ ↑ │ SPACE │ ↓ │Lft│Dwn│ Up│RGT│
     * └───┴───┴───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┴───┘
     */
    [_QWERTZ] = LAYOUT_ortho_4x15(
        KC_P7,   KC_P8,  KC_P9,    KC_ESC,   DE_Q,     DE_W,     DE_E,     DE_R,   DE_T,   DE_Z,   DE_U,   DE_I,     DE_O,     DE_P,     KC_DEL,
        KC_P4,   KC_P5,  KC_P6,    KC_TAB,   DE_A,     DE_S,     DE_D,     DE_F,   DE_G,   DE_H,   DE_J,   DE_K,     DE_L,     DE_HASH,
        KC_P1,   KC_P2,  KC_P3,    KC_LSFT,  DE_Y,     DE_X,     DE_C,     DE_V,   DE_B,   DE_N,   DE_M,   DE_COMM,  DE_DOT,   DE_LABK,  KC_ENT,
        KC_PCMM, KC_P0,  KC_LCTL,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_ALGR,  RAISE,  KC_SPC,         LOWER,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
    ),

    /* Lower
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤   │
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │ ↑ │ SPACE │ ↓ │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┴───┘
     */
    [_LOWER] = LAYOUT_ortho_4x15(
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,     _______,
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,
        _______,   _______,  _______,    _______,  _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,  _______,   _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,    _______
    ),

    /* Raise
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤   │
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │ ↑ │ SPACE │ ↓ │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┴───┘
     */
    [_RAISE] = LAYOUT_ortho_4x15(
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,     _______,
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,
        _______,   _______,  _______,    _______,  _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,  _______,   _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,    _______
    ),


    /* Special
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤   │
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┼───┼───┴───┼───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │   │ ↑ │ SPACE │ ↓ │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┴───────┴───┴───┴───┴───┴───┴───┘
     */
     [_SPECIAL] = LAYOUT_ortho_4x15(
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,     _______,
        _______,   _______,  _______,    _______,   _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,     _______,     _______,
        _______,   _______,  _______,    _______,  _______,     _______,     _______,     _______,   _______,   _______,   _______,   _______,  _______,   _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,    _______
    ),
};
