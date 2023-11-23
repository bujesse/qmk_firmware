// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_userspace.md
#include "bujesse.h"
#include "swapper.h"
#include QMK_KEYBOARD_H

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, keycode, record);
    switch (keycode) {
        case CAPS_WORD:
            if (record->event.pressed) {
                caps_word_on();
            }
            return false;
        case MOST_PASS:
            if (record->event.pressed) {
            }
            break;
    }
    return process_record_keymap(keycode, record);
};
