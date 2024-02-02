/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK_DH,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_RTAB LSFT(KC_TAB)

#include "g/keymap_combo.h"
#include "users/callum/oneshot.h"

#define LAYOUT_HRM( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
    LAYOUT( \
        L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
        L12, ALT_T(L13), GUI_T(L14), SFT_T(L15), CTL_T(L16), L17,                     R18, CTL_T(R19), SFT_T(R20), GUI_T(R21), ALT_T(R22), R23, \
        L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                    L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK_DH] = LAYOUT(
//╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮                                            ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
    _______,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                                                  KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,  _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼                                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,                                                  KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┬─────────╮    ╭─────────┬─────────├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     A(KC_A),  A(KC_V),       _______,  _______,  KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
//╰─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼    ┼─────────├─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────╯
                                  _______,   _______, LOWER,    KC_LSFT,  KC_TAB,        KC_SCLN,  KC_SPC,   RAISE,    _______,  _______
//                              ╰─────────┴─────────┴─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────┴─────────┴─────────╯
),

[_LOWER] = LAYOUT(
//╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮                                            ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
    _______,  KC_ESC,   _______,  _______,  KC_ENT,   _______,                                               KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_DEL,   _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼                                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,                                               KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,  _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┬─────────╮    ╭─────────┬─────────├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  _______,  _______,  _______,       _______,  _______,  _______, S(KC_TAB), KC_TAB,   _______,  _______,  _______,
//╰─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼    ┼─────────├─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────╯
                                  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______
//                              ╰─────────┴─────────┴─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────┴─────────┴─────────╯
),

[_RAISE] = LAYOUT_HRM(
//╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮                                            ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                                               KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,   _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼                                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┬─────────╮    ╭─────────┬─────────├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_GRV,   _______,  _______,       _______,  _______,  KC_BSLS,  KC_LPRN,  KC_RPRN, _______,  _______,   _______,
//╰─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼    ┼─────────├─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────╯
                                  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______
//                              ╰─────────┴─────────┴─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────┴─────────┴─────────╯
),

[_ADJUST] =  LAYOUT(
//╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮                                            ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
    _______,  RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_MOD,                                               _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼                                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_RMOD,                                              KC_CAPS,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┬─────────╮    ╭─────────┬─────────├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼
    _______,  OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  RGB_TOG,  _______,  _______,       _______,  _______,  KC_INS,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
//╰─────────┴─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼    ┼─────────├─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────╯
                                  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______
//                              ╰─────────┴─────────┴─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────┴─────────┴─────────╯
)

};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );
    return true;
}


/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif