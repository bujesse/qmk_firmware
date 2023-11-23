#pragma once

#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM 0

// #define COMBO_TERM 50
#define COMBO_TERM 40
// Combos only have to be defined on layer 0 and will work on all layers
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md#layer-independent-combos
#define COMBO_ONLY_FROM_LAYER 0

// #define TAPPING_TERM 200
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
