#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _APT,
    _CANARY,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_APT] = LAYOUT_split_3x5_2(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_W,     KC_F,     KC_G,     KC_D,     KC_V,                              KC_Q,     KC_L,     KC_U,     KC_O,     KC_Y,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_R,     KC_S,     KC_T,     KC_H,     KC_B,                              KC_J,     KC_N,     KC_E,     KC_A,     KC_I,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_X,     KC_C,     KC_M,     KC_P,     KC_K,                              KC_Z,     KC_COMM,  KC_DOT,   KC_QUOT,  KC_SLSH,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼                        ┼─────────┼─────────┼─────────┼─────────┴─────────╯
                                  LOWER,    KC_LSFT,                           KC_SPC,   RAISE
//                              ╰─────────┴─────────╯                        ╰─────────┴─────────╯
),

[_CANARY] = LAYOUT_split_3x5_2(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_W,     KC_L,     KC_Y,     KC_P,     KC_B,                              KC_Z,     KC_F,     KC_O,     KC_U,     KC_SCLN,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_C,     KC_R,     KC_S,     KC_T,     KC_G,                              KC_M,     KC_N,     KC_E,     KC_I,     KC_A,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_Q,     KC_J,     KC_V,     KC_D,     KC_K,                              KC_X,     KC_H,     KC_SLSH,  KC_COMM,  KC_DOT,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼                        ┼─────────┼─────────┼─────────┼─────────┴─────────╯
                                  LOWER,    KC_SPC,                            KC_SPC,   RAISE
//                              ╰─────────┴─────────╯                        ╰─────────┴─────────╯
),

[_LOWER] = LAYOUT_split_3x5_2(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_ESC,   KC_TAB,   _______,  _______,  _______,                           KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_DEL,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,                           KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  _______,                           _______,  _______,  _______,  _______,  _______,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼                        ┼─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  _______,                           _______,  _______
//                              ╰─────────┴─────────╯                        ╰─────────┴─────────╯
),

[_RAISE] = LAYOUT_split_3x5_2(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_GRV,                            KC_BSLS,  KC_SCLN,  _______,  KC_LPRN,  KC_RPRN,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼                        ┼─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  _______,                           _______,  _______
//                              ╰─────────┴─────────╯                        ╰─────────┴─────────╯
),

[_ADJUST] =  LAYOUT_split_3x5_2(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_MOD,                           _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_RMOD,                          KC_CAPS,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  RGB_TOG,                           KC_INS,   KC_F9,    KC_F10,   KC_F11,   KC_F12,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼                        ┼─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  _______,                           _______,  _______
//                              ╰─────────┴─────────╯                        ╰─────────┴─────────╯
)

};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
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
