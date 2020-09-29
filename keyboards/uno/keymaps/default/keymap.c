#include QMK_KEYBOARD_H

enum uno_keycode
{
  UNO = SAFE_RANGE
};

const uint8_t PROGMEM RGBLED_RAINBOW_MOOD_INTERVALS[] = { 10, 25, 50 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            UNO
      )
};

bool media_playing = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case UNO:
        if (record->event.pressed) {
            if (media_playing == false) {
                media_playing = true;
                tap_code(KC_MEDIA_PLAY_PAUSE);
                rgblight_sethsv_noeeprom(255, 255, 255);
                rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
            } else {
                media_playing = false;
                tap_code(KC_MEDIA_PLAY_PAUSE);
                rgblight_sethsv_noeeprom(0, 0, 0);
                rgblight_mode(1);
            }
        }
        break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();

    rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode(1);
}
