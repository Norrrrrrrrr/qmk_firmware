
#s nn_rev01
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes
AUDIO_ENABLE = no           # Audio output

# LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes		# Enable Tap Dance
#e nn_rev01
COMBO_ENABLE = yes			# Enable Combo

DEBOUNCE_TYPE = sym_eager_pk	# Enable different debounce algorithm

# Reduce code size
LTO_ENABLE = yes		    # Link Time Optimization
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no
