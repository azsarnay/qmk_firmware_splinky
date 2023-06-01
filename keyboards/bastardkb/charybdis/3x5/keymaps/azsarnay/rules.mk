
# MCU name
# Elite-C
MCU = atmega32u4
# Splinky
# MCU = kb2040

# Bootloader selection
# Elite-C chip:
BOOTLOADER = atmel-dfu
# Splinky Chip:
# BOOTLOADER = rp2040

RGBLIGHT_ENABLE = no    # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE  = yes
# # RGBLIGHT_STARTUP_ANIMATION = yes

EXTRAKEY_ENABLE = no      # Audio control and System control
MIDI_ENABLE = no           # MIDI support
UNICODE_ENABLE = yes        # Unicode

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = yes    # RGB underglow is supported, but not enabled by default

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
# Enable link-time optimization by default.  The Charybdis packs a lot of
# features (RGB, Via, trackball) in a small atmega32u4 package.
LTO_ENABLE = yes

# Charybdis nano is a split 3x5 keyboard with a maximum of 3 thumb keys (2 on
# the trackball side).
SPLIT_KEYBOARD = yes
LAYOUTS = split_3x5_3 # Support community layout, in particular Manna-Harbour's Miryoku layout

POINTING_DEVICE_ENABLE = yes # Enable trackball
POINTING_DEVICE_DRIVER = pmw3360
# https://qmk.fm/changes/2018-11-16-use-a-single-endpoint-for-hid-reports
MOUSE_SHARED_EP = no # Unify multiple HID interfaces into a single Endpoint


# SWAP_HANDS_ENABLE = yes
