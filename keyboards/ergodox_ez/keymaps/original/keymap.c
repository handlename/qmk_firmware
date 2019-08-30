#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define L_BASE 0 // base layer
#define L_SYMB 1 // symbol layer
#define L_MOUS 2 // mouse & cursor layer
#define L_SYST 3 // system layer

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | +L3  |           |  `   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | +L2  |           | +L2  |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  B   |           | Ent  |------+------+------+------+------+--------|
 * | LShift |   Z  |   Z  |   X  |   C  |   V  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | Back |  Fwd | Left | Right|                                       | Down |  Up  | VolD | VolU |  RAlt  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | LGui | Space|------|       |------|Sft/Bs| RGui |
 *                                 |      |      | +L1  |       | +L1  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_BASE] = KEYMAP(
        // left hand
        KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      MO(L_SYST),
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      MO(L_MOUS),
        KC_LCTL,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,
        KC_LALT,    KC_WBAK,  KC_WFWD,  KC_LEFT,  KC_RGHT,

                                                            KC_HOME,   KC_END,
                                                                       KC_LALT,
                                                  KC_LGUI,  KC_SPC,    MO(L_SYMB),

        // right hand
        KC_GRAVE,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,      KC_MINS,
        MO(L_MOUS), KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_LBRC,
                    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCOLON, KC_QUOTE,
        KC_ENT,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT,
                              KC_DOWN,  KC_UP,    KC_VOLD,  KC_VOLU,   KC_RALT,

        KC_PGUP,    KC_PGDN,
        KC_RALT,
        MO(L_SYMB), SFT_T(KC_BSPC),  KC_RGUI
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    *   |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |    ]   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |    \   |
 * |--------+------+------+------+------+------|  *   |           |  *   |------+------+------+------+------+--------|
 * |    *   |      |      |      |      |      |      |           |      |      |      |      |      |      |    *   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   *  |      |      |      |      |                                       |      |      |      |      |   *  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  *   |  *   |       |   *  |   *  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  *   |       |   *  |      |      |
 *                                 |  *   |  *   |------|       |------|   *  |   *  |
 *                                 |      |      |  *   |       |   *  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_SYMB] = KEYMAP(
    // left hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                        KC_TRNS, KC_TRNS,
                                        KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,

    // right hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_EQUAL,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RBRC,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLASH,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Mouse & Cursor layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    *   |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    *   |      |      |  Up  |      |      |  *   |           |  *   |      | LClk | MsU  | RClk |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    *   |      | Left | Down | Right|      |------|           |------|      | MsL  | MsD  | MsR  |      |        |
 * |--------+------+------+------+------+------|  *   |           |  *   |------+------+------+------+------+--------|
 * |    *   |      |      |      |      |      |      |           |      |      |      |      |      |      |    *   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   *  |      |      |      |      |                                       |      |      |      |      |   *  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  *   |  *   |       |   *  |   *  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  *   |       |   *  |      |      |
 *                                 |  *   |  *   |------|       |------|   *  |   *  |
 *                                 |      |      |  *   |       |   *  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_MOUS] = KEYMAP(
       // left hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_NO,
                KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 3: System Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  *   |           |  *   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |  *   |       |  *   |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_SYST] = KEYMAP(
       // left hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                                    KC_NO,   KC_NO,
                                                             KC_NO,
                                           KC_NO,   KC_NO,   KC_TRNS,
       // right hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_TRNS, KC_NO,   KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
