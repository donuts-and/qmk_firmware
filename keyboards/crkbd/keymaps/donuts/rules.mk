MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

VPATH += keyboards/gboards/
SRC += users/callum/oneshot.c
COMBO_ENABLE = yes

WPM_ENABLE = yes