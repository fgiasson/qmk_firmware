# Enable more layers than the default which is 4
OPT_DEFS += -DDYNAMIC_KEYMAP_LAYER_COUNT=7

# Ref: https://docs.qmk.fm/#/feature_space_cadet
# disable it such that it doesn't conflict with Space Cadet shifts behaviours
COMMAND_ENABLE = no

# Ref: https://docs.qmk.fm/#/feature_dynamic_macros
DYNAMIC_MACRO_ENABLE = yes

# Ref: https://docs.qmk.fm/#/feature_tap_dance
TAP_DANCE_ENABLE = yes

# Ref: https://docs.qmk.fm/#/feature_mouse_keys
MOUSEKEY_ENABLE = yes
