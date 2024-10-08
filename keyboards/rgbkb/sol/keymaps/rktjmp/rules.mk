# Default keymap does not have any overridden options from the rev1 / rev2 rules.mk files.
# Example:
#     if you wanted to disable EXTRAKEY_ENABLE, you would copy the line from the rev1/rules.mk file
#     and paste it in to this file, changing the yes to no. Like so:
# EXTRAKEY_ENABLE         = no       # Audio control and System control
#
# To keep things clean and tidy, as well as make upgrades easier, only place overrides from the defaults in this file.

#LED_MIRRORED = no
RGBLIGHT_ENABLE = yes
RGBLIGHT_ANIMATIONS = no

#RGB_MATRIX_ENABLE = yes
#RGB_MATRIX_KEYPRESSES = yes

# CONSOLE_ENABLE = yes
MOUSEKEY_ENABLE = yes
LTO_ENABLE = yes


# Do not edit past here
include keyboards/$(KEYBOARD)/post_rules.mk
