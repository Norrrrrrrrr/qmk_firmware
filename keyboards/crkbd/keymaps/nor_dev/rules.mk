OLED_DRIVER_ENABLE  = yes

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE = no        # Enable one-hand typing

TAP_DANCE_ENABLE = yes		# Enable Tap Dance

IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

DEBOUNCE_TYPE = sym_eager_pk	# Enable different debounce algorithm

# Reduce code size
# LTO_ENABLE = yes		    # Link Time Optimization
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
GRAVE_ESC_ENABLE = no
