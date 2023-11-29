#include QMK_KEYBOARD_H
#include "bujesse.h"
#include "layers.h"
#include "features/caps_word.h"

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {}
    return true;
};

const uint16_t PROGMEM alttab_combo[]     = {LALT_T(KC_DEL), KC_TAB, COMBO_END};
const uint16_t PROGMEM caps[]             = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM capsword_combo[]   = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM camel_case_combo[] = {KC_C, KC_COMM, COMBO_END};
const uint16_t PROGMEM snake_case_combo[] = {KC_V, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(alttab_combo, LALT(KC_TAB)),

    COMBO(caps, KC_CAPS_LOCK),

    COMBO(capsword_combo, BU_CAPS_WORD),

    COMBO(camel_case_combo, BU_CW_CAMEL_CASE),

    COMBO(snake_case_combo, BU_CW_SNAKE_CASE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_BASE]   = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, LCTL_T(KC_ESC), KC_A, KC_S, LSFT_T(KC_D), KC_F, KC_G, KC_H, KC_J, RSFT_T(KC_K), KC_L, KC_SCLN, KC_QUOT, C_S_T(KC_GRV), LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL, LALT_T(KC_DEL), LT(3, KC_BSPC), LT(2, KC_ENT), LT(2, KC_ENT), LT(4, KC_SPC), LT(5, KC_TAB)),
                                                              [_ISRT]   = LAYOUT_split_3x6_3(KC_TRNS, KC_Y, KC_C, KC_L, KC_M, KC_K, KC_Z, KC_F, KC_U, KC_COMM, KC_SCLN, KC_TRNS, KC_TRNS, KC_I, KC_S, LSFT_T(KC_R), KC_T, KC_G, KC_P, KC_N, RSFT_T(KC_E), KC_A, KC_O, KC_TRNS, KC_TRNS, KC_Q, KC_V, KC_W, KC_D, KC_J, KC_B, KC_H, KC_SLSH, KC_TRNS, KC_X, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_NAVFN]  = LAYOUT_split_3x6_3(KC_TRNS, LCTL(KC_F4), RCS(KC_TAB), KC_UP, LCTL(KC_TAB), KC_SPC, KC_F10, KC_F7, KC_F7, KC_F9, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, BU_SW_WIN, KC_F11, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, LCAG(KC_5), LCAG(KC_4), LCAG(KC_3), LCAG(KC_2), LCAG(KC_1), KC_F12, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_SYMNUM] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_UNDS, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_6, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO, KC_TRNS, KC_TILD, KC_DOT, KC_COMM, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_ARROWS] = LAYOUT_split_3x6_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, TO(0), TO(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [_EXTRA]  = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUD, RGB_HUI, KC_NO, BU_MOST_PASS, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_VAD, RGB_VAI, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, RCS(KC_ESC), KC_CALC, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_ln_P(PSTR("Default"), false);
                break;
            case _ISRT:
                oled_write_ln_P(PSTR("ISRT"), false);
                break;
            case _NAVFN:
                oled_write_ln_P(PSTR("NAV+FN"), false);
                break;
            case _SYMNUM:
                oled_write_ln_P(PSTR("SYM+NUM"), false);
                break;
            case _ARROWS:
                oled_write_ln_P(PSTR("ARROWS"), false);
                break;
            case _EXTRA:
                oled_write_ln_P(PSTR("EXTRA"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_ln_P(PSTR(" "), false);
        oled_write_ln_P(led_state.caps_lock ? PSTR("CAPSLOCK ON") : PSTR("           "), false);

        const char *caps_word_status = get_caps_word_status();
        oled_write_ln_P(PSTR(caps_word_status), false);
    } else {
        // Right side
        oled_write_P(PSTR("CAPS WORD: "), false);
        const char *caps_word_status = get_caps_word_status();
        oled_write_P(PSTR(caps_word_status), false);
    }
    return false;
}
#endif
