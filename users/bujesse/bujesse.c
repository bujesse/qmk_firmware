// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_userspace.md
#include "bujesse.h"
#include "features/swapper.h"
#include "features/caps_word.h"
#include QMK_KEYBOARD_H

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, BU_SW_WIN, keycode, record);
    switch (keycode) {
        case BU_CAPS_WORD:
            if (record->event.pressed) {
                toggle_caps_word_mode(CAPS_WORD_MODE_DEFAULT);
                return false;
            }
            break;
        case BU_CW_CAMEL_CASE:
            if (record->event.pressed) {
                toggle_caps_word_mode(CWMODE_CAMEL_CASE);
                return false;
            }
            break;
        case BU_CW_SNAKE_CASE:
            if (record->event.pressed) {
                toggle_caps_word_space_sub(KC_UNDERSCORE);
                return false;
            }
            break;
        case BU_MOST_PASS:
            if (record->event.pressed) {
                return false;
            }
            break;
    }
    return process_record_keymap(keycode, record);
};
