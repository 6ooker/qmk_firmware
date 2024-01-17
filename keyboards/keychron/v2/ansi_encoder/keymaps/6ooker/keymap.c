/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "sendstring_german.h"

// clang-format off

enum custom_keycodes {
    CODE = SAFE_RANGE,
};

enum layers{
    MAC_BASE,
    WIN_BASE,
    TYPING,
    CUSTOM_ALT,
    _FN3
};

#define OPT_PIPE S(KC_BSLS)


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    static bool code_is_held = false;
    switch (keycode) {

        case KC_BSPC:
            {
                // Initialize a bool var that keeps track of the delete key status: registered or not?
                static bool delkey_registered;
                if (record->event.pressed) {
                    // Detect the activation of either shift keys
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that it isn't applied to the KC_DEL keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        // Update the bool var to reflect the status of KC_DEL
                        delkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s) still work even after having tapped the Backspace/Del Key
                        set_mods(mod_state);
                        return false;
                    }
                } else { // on release of KC_BSPC
                    // In case KC_DEL is still being sent even after the release of KC_BSPC
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
          // Let QMK process the KC_BSPC keycode as usual outside of shift
          return true;
      }
        case CODE:
            {
                code_is_held = record->event.pressed;
                break;
            }

        case KC_W:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("|");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_Q:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("\\");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_X:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("#");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_C:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("&");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_V:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("@");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_B:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("{");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_N:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("}");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_F:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("[");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_G:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        SEND_STRING("]");
                        set_mods(mod_state);
                        return false;
                    }
                }
                return true;
            }

        case KC_GRV:
            {
                static bool esc_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(KC_ESC);
                        esc_registered = true;
                        return false;
                    } else {
                        if (esc_registered) {
                            unregister_code(KC_ESC);
                            esc_registered = false;
                            return false;
                        }
                    }
                }
                return true;
            }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                             KC_SPC,                             KC_RCMD,  _______,  _______ , KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Y,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(TYPING), CODE  , KC_LEFT, KC_DOWN, KC_RGHT),

    [TYPING] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Y,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  _______,   CODE  , KC_LEFT, KC_DOWN, KC_RGHT),

    [CUSTOM_ALT] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  OPT_PIPE, KC_W,     KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Y,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  _______,   CODE  , KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN3] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [TYPING]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [CUSTOM_ALT]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3]   = { ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
