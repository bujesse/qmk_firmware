# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_userspace.md
# this gets loaded AFTER keymaps' rules.mk

CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

SRC += bujesse.c
SRC += swapper.c
