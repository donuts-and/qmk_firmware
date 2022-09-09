#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _SEMI,
    _CANARY,
    _APT,
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
#define SH_SPC LSFT_T(KC_SPC)

#include "g/keymap_combo.h"
#include "users/callum/oneshot.h"

#define LAYOUT_sweeeeep_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_sweeeeep( \
        K01,            K02,            K03,            K04,                K05,                K06,                K07,                K08,              K09,            K0A, \
        LALT_T(K11),    LGUI_T(K12),    LSFT_T(K13),    LCTL_T(K14),        K15,                K16,                RCTL_T(K17),        RSFT_T(K18),      RGUI_T(K19),    RALT_T(K1A), \
        K21,            K22,            K23,            K24,                K25,                K26,                K27,                K28,              K29,            K2A, \
                                        K33,            K34,                K35,                K36,                K37,                K38 \
    )

#define LAYOUT_sweeeeep_pinky_shift( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_sweeeeep( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_SEMI] = LAYOUT_sweeeeep_pinky_shift(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_F,     KC_L,     KC_H,     KC_V,     KC_Z,                              KC_QUOT,  KC_W,     KC_U,     KC_O,     KC_Y,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_S,     KC_R,     KC_N,     KC_T,     KC_K,                              KC_C,     KC_D,     KC_E,     KC_A,     KC_I,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_X,     KC_J,     KC_B,     KC_M,     KC_Q,                              KC_P,     KC_G,     KC_COMM,  KC_DOT,   KC_SLSH,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  LOWER,    KC_LSFT,  KC_TAB,        KC_SCLN,  KC_SPC,   RAISE
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
),

[_APT] = LAYOUT_sweeeeep_pinky_shift(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_W,     KC_F,     KC_G,     KC_D,     KC_V,                              KC_Q,     KC_L,     KC_U,     KC_O,     KC_Y,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_R,     KC_S,     KC_T,     KC_H,     KC_B,                              KC_J,     KC_N,     KC_E,     KC_A,     KC_I,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_X,     KC_C,     KC_M,     KC_P,     KC_K,                              KC_Z,     KC_COMM,  KC_DOT,   KC_QUOT,  KC_SLSH,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  LOWER,    KC_LSFT,  KC_TAB,        KC_SCLN,  KC_SPC,   RAISE
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
),

[_CANARY] = LAYOUT_sweeeeep_pinky_shift(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_W,     KC_L,     KC_Y,     KC_P,     KC_B,                              KC_Z,     KC_F,     KC_O,     KC_U,     KC_SCLN,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_C,     KC_R,     KC_S,     KC_T,     KC_G,                              KC_M,     KC_N,     KC_E,     KC_I,     KC_A,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_Q,     KC_J,     KC_V,     KC_D,     KC_K,                              KC_X,     KC_H,     KC_SLSH,  KC_COMM,  KC_DOT,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  LOWER,    KC_SPC,   KC_TAB,        KC_QUOT,  KC_SPC,   RAISE
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
),

[_LOWER] = LAYOUT_sweeeeep(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_ESC,   _______,  _______,  _______,  _______,                           KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_DEL,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_LALT,  KC_LGUI,  KC_LSFT,  KC_LCTL,  _______,                           KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  _______,                           _______,  _______,  _______,  _______,  _______,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  _______,  _______,       _______,  _______,  _______
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
),

[_RAISE] = LAYOUT_sweeeeep(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_MINS,  KC_EQL,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_GRV,                            KC_BSLS,  KC_LPRN,  KC_RPRN,  _______,  _______,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  _______,  KC_RTAB,       _______,  _______,  _______
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
),

[_ADJUST] =  LAYOUT_sweeeeep(
//╭─────────┬─────────┬─────────┬─────────┬─────────╮                        ╭─────────┬─────────┬─────────┬─────────┬─────────╮
    RGB_SPI,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_MOD,                           _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    RGB_SPD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_RMOD,                          KC_CAPS,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
//├─────────┼─────────┼─────────┼─────────┼─────────┼                        ├─────────┼─────────┼─────────┼─────────┼─────────┼
    OS_ALT,   OS_CMD,   OS_SHFT,  OS_CTRL,  RGB_TOG,                           KC_INS,   KC_F9,    KC_F10,   KC_F11,   KC_F12,
//╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────╮    ╭─────────├─────────┼─────────┼─────────┼─────────┴─────────╯
                                  _______,  DF(_SEMI),DF(_APT),      RESET,    _______,  _______
//                              ╰─────────┴─────────┴─────────╯    ╰─────────┴─────────┴─────────╯
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

#ifdef OLED_ENABLE

void render_mod_indicator(const char *data, oneshot_state state) {
    oled_write(data, state == os_down_unused || state == os_up_queued);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _CANARY:
            oled_write("CNARY", false);
            break;
        case _SEMI:
            oled_write("SEMI ", false);
            break;
        case _APT:
            oled_write("APT  ", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _CANARY:
        case _SEMI:
            oled_write("BASE ", false);
            break;
        case _RAISE:
            oled_write("SYM  ", false);
            break;
        case _LOWER:
            oled_write("EXT  ", false);
            break;
        case _ADJUST:
            oled_write("ADJ  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    render_mod_indicator("A", os_alt_state);
    render_mod_indicator("G", os_cmd_state);
    render_mod_indicator("S", os_shft_state);
    render_mod_indicator("C", os_ctrl_state);
}

bool oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (is_keyboard_master()) {
        print_status_narrow();
    } else if (true) {
        for (int i = 0; i < 8 ; i++) {
            oled_write_P(PSTR("sweeeeep "), false);
        }
        oled_write_P(PSTR("sweeeeep"), false);
    } else {
        //render_logo_text();
    }
    return true;
}

#endif

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