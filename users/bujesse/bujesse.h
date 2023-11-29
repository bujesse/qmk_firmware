#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

enum custom_keycodes {
    BU_CAPS_WORD = SAFE_RANGE,
    BU_CW_CAMEL_CASE,
    BU_CW_SNAKE_CASE,
    BU_MOST_PASS,
    BU_SW_WIN,
    NEW_SAFE_RANGE // use "NEW_SAFE_RANGE" for keymap specific codes
};
