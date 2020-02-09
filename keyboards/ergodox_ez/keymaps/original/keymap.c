#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRV,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , XXXXXXX,                   XXXXXXX, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , XXXXXXX,                   XXXXXXX, KC_F   , KC_G   , KC_K   , KC_R   , KC_L   , KC_SLSH,
    KC_LCTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,                                     KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_C   , KC_X   , XXXXXXX,                   XXXXXXX, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSFT,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, MO(2)  ,                                                       MO(2)  , KC_DOWN, KC_UP  , XXXXXXX, XXXXXXX,
                                                 XXXXXXX, KC_HOME,                   KC_END , XXXXXXX,
                                                          KC_LALT,                   KC_RALT,
                                        KC_LGUI, KC_SPC , LT(1,KC_ESCAPE),    LT(1,KC_ENTER), KC_BSPC, KC_RGUI
  ),
  [1] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_BSLS,
    _______, _______, _______, _______, _______, _______,                                     _______, KC_LCBR, KC_RCBR, _______, _______, KC_EQL ,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_9   , KC_0   , _______, _______, _______,
    _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                 _______, _______,                   _______, _______,
                                                          _______,                   _______,
                                        _______, _______, _______,                   _______, _______, _______
  ),
  [2] = LAYOUT_ergodox_pretty(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4,   KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, _______, KC_PGDN, KC_UP  , KC_PGUP, _______, _______,                   _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______,
                                                 _______, _______,                   _______, _______,
                                                          _______,                   _______,
                                        _______, _______, _______,                   _______, _______, _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
