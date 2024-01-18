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
#include "keymap_german.h"
#include "sendstring_german.h"

// clang-format off

enum custom_keycodes {
    CODE = SAFE_RANGE,
    CUST_DIA,
    CUST_MULT,
    CUST_DIV,
    CUST_CURRENCY,
    CUST_UACC,
};

enum layers{
    PRIVATE,
    WIN_BASE,
    TYPING,
    FN
};

// Tap Dance declarations
enum {
    TD_LOS, // OS/UNLOCK
    TD_LCK, // OS/LOCK
    TD_TC, // TAB/VSCODE COMMAND PALETTE
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for OS, twice for Ctrl+Alt+Del
    [TD_LOS] = ACTION_TAP_DANCE_DOUBLE(KC_LWIN, LCA(KC_DEL)),
    // Tap once for OS, twice for WIN+L
    [TD_LCK] = ACTION_TAP_DANCE_DOUBLE(KC_LWIN, LWIN(KC_L)),
    // Tap once for TAB, twice for Ctrl+Shift+P (vs code command palette)
    [TD_TC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, RCS(KC_P)),
};

void leader_start_user(void) {
    // Do smthing when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_U, KC_D)) {
        // Leader, u, d
        SEND_STRING("sudo apt update\n");
    } else if (leader_sequence_two_keys(KC_U, KC_G)) {
        // Leader, u, g
        SEND_STRING("sudo apt upgrade -y\n");
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        // Leader, i, i
        SEND_STRING("if () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_I, KC_F)) {
        // Leader, i, f
        SEND_STRING("for () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_two_keys(KC_I, KC_W)) {
        // Leader, i, w
        SEND_STRING("while () {}" SS_TAP(X_LEFT) SS_TAP(X_ENT));
    } else if (leader_sequence_one_key(KC_M)) {
        // Leader, m
        SEND_STRING("erik.katzenberger@exclusive-networks.de");
    }
}

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
                        return false;
                    }
                }
                return true;
            }

        case KC_E:
            {
                if (record->event.pressed) {
                    if (code_is_held) {
                        clear_mods();
                        register_code16(DE_EURO);
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
                        return false;
                    }
                }
                return true;
            }

        case KC_U:
            {
                static bool udia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_UDIA);
                        udia_registered = true;
                        return false;
                    }
                } else {
                    if (udia_registered) {
                        unregister_code(DE_UDIA);
                        udia_registered = false;
                        return false;
                    }
                }
                return true;
            }

        case KC_A:
            {
                static bool adia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_ADIA);
                        adia_registered = true;
                        return false;
                    }
                } else {
                    if (adia_registered) {
                        unregister_code(DE_ADIA);
                        adia_registered = false;
                        return false;
                    }
                }
                return true;
            }

        case KC_O:
            {
                static bool odia_registered;
                if (record->event.pressed) {
                    if (code_is_held) {
                        register_code(DE_ODIA);
                        odia_registered = true;
                        return false;
                    }
                } else {
                    if (odia_registered) {
                        unregister_code(DE_ODIA);
                        odia_registered = false;
                        return false;
                    }
                }
                return true;
            }

    }
    return true;
};


const key_override_t ansi_one_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_1, DE_EXLM, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_two_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, DE_AT, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_three_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, DE_HASH, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_four_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, DE_DLR, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_five_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, DE_PERC, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_six_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, DE_CIRC, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_seven_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, DE_AMPR, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_eight_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, DE_ASTR, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_nine_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, DE_LPRN, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_zero_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, DE_RPRN, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_grv_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_GRV, DE_TILD, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_mins_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_MINS, DE_UNDS, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_eql_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_EQL, DE_PLUS, 1<<WIN_BASE|1<<PRIVATE);

const key_override_t ansi_lbrc_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_LBRC, DE_LCBR, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_rbrc_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_RBRC, DE_RCBR, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_bsls_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_BSLS, DE_PIPE, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_scln_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_COLN, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_quot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_comm_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_LABK, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_dot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_RABK, 1<<WIN_BASE|1<<PRIVATE);
const key_override_t ansi_slsh_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, DE_QUES, 1<<WIN_BASE|1<<PRIVATE);

const key_override_t type_comm_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_QUES, 1<<TYPING);
const key_override_t type_dot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_COLN, 1<<TYPING);
const key_override_t type_mins_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_MINS, DE_UNDS, 1<<TYPING);
const key_override_t type_dlr_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_DLR, DE_DQUO, 1<<TYPING);
const key_override_t type_ss_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SS, DE_EXLM, 1<<TYPING);
const key_override_t type_dlr_alt_ovrd = ko_make_with_layers(MOD_MASK_ALT, DE_DLR, DE_UDIA, 1<<TYPING);
const key_override_t type_ss_alt_ovrd = ko_make_with_layers(MOD_MASK_ALT, DE_SS, DE_SECT, 1<<TYPING);
const key_override_t type_scln_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_DEG, 1<<TYPING);
const key_override_t type_slsh_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, CUST_UACC, 1<<TYPING);
const key_override_t type_lprn_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_LPRN, DE_RPRN, 1<<TYPING);
const key_override_t type_quot_ovrd = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, CUST_DIA, 1<<TYPING);
const key_override_t type_slsh_alt_ovrd = ko_make_with_layers(MOD_MASK_ALT, DE_SLSH, CUST_DIV, 1<<TYPING);
const key_override_t type_lprn_alt_ovrd = ko_make_with_layers(MOD_MASK_ALT, DE_LPRN, CUST_MULT, 1<<TYPING);
const key_override_t type_quot_alt_ovrd = ko_make_with_layers(MOD_MASK_ALT, DE_QUOT, CUST_CURRENCY, 1<<TYPING);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ansi_one_ovrd,
    &ansi_two_ovrd,
    &ansi_three_ovrd,
    &ansi_four_ovrd,
    &ansi_five_ovrd,
    &ansi_six_ovrd,
    &ansi_seven_ovrd,
    &ansi_eight_ovrd,
    &ansi_nine_ovrd,
    &ansi_zero_ovrd,
    &ansi_grv_ovrd,
    &ansi_mins_ovrd,
    &ansi_eql_ovrd,
    &ansi_lbrc_ovrd,
    &ansi_rbrc_ovrd,
    &ansi_bsls_ovrd,
    &ansi_scln_ovrd,
    &ansi_quot_ovrd,
    &ansi_comm_ovrd,
    &ansi_dot_ovrd,
    &ansi_slsh_ovrd,

    &type_comm_ovrd,
    &type_dot_ovrd,
    &type_mins_ovrd,
    &type_dlr_ovrd,
    &type_ss_ovrd,
    &type_dlr_alt_ovrd,
    &type_ss_alt_ovrd,
    &type_scln_ovrd,
    &type_slsh_ovrd,
    &type_lprn_ovrd,
    &type_quot_ovrd,
    &type_slsh_alt_ovrd,
    &type_lprn_alt_ovrd,
    &type_quot_alt_ovrd,
    NULL // Null terminate the array!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [PRIVATE] = LAYOUT_ansi_67(
        KC_ESC,  DE_1,     DE_2,     DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,     DE_MINS,  DE_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  DE_Q,     DE_W,     DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,     DE_LBRC,  DE_RBRC,  DE_BSLS,          KC_DEL,
        QK_LEAD, DE_A,     DE_S,     DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_SCLN,  DE_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           DE_Y,     DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,   DE_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(FN),   CODE,     KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        DE_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     DE_MINS,  DE_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,     DE_LBRC,  DE_RBRC,  DE_BSLS,          KC_PGUP,
        QK_LEAD, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_SCLN,  DE_QUOT,            KC_ENT,           KC_PGDN,
        KC_LSFT,           DE_Y,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,   DE_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, TD(TD_LOS),KC_LALT,                            KC_SPC,                             KC_RALT,  MO(FN),   CODE,     KC_LEFT, KC_DOWN, KC_RGHT),

    [TYPING] = LAYOUT_ansi_67(
        DE_SCLN, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     DE_PERC,  _______,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,     DE_SLSH,  DE_LPRN,  DE_QUOT,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    DE_DLR,   DE_SS,              KC_ENT,           KC_HOME,
        KC_LSFT,           DE_Y,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    DE_COMM, DE_DOT,   DE_MINS,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,                             KC_SPC,                             KC_RALT,  _______,  CODE,     KC_LEFT, KC_DOWN, KC_RGHT),

    [FN] = LAYOUT_ansi_67(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   RGB_SAD,          RGB_TOG,
        RGB_SPI, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          TG(TYPING),
        RGB_SPD, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            RGB_SAI,          TG(WIN_BASE),
        _______,           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,            _______, RGB_HUI,
        _______, TD(TD_LCK),_______,                            XXXXXXX,                            _______,  _______,  XXXXXXX,  RGB_RMOD,RGB_HUD, RGB_MOD)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [PRIVATE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [TYPING]   = { ENCODER_CCW_CW(_______, _______)},
    [FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(layer) {
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 3:

                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, RGB_GREEN);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    return false;
}
