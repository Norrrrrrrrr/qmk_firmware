RGBLIGHT_ENABLE = yes

#s nn_rev01
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
# CONSOLE_ENABLE = yes         # Output DEBUG_MATRIX_SCAN_RATE
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

# LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes		# Enable Tap Dance
#e nn_rev01

DEBOUNCE_TYPE = sym_eager_pk	# Enable different debounce algorithm

# Reduce code size
# LTO_ENABLE = yes		    # Link Time Optimization
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no

