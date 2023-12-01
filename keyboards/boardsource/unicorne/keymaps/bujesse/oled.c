#include "features/caps_word.h"

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
