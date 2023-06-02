# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no         # Console for debug
# CONSOLE_ENABLE = yes         # Output DEBUG_MATRIX_SCAN_RATE
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

TAP_DANCE_ENABLE = yes		# Enable Tap Dance

DEBOUNCE_TYPE = sym_eager_pk	# Enable different debounce algorithm

# Reduce code size
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no
