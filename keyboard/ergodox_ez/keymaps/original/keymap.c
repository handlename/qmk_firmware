#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define L_BASE 0 // default layer
#define L_FUNC 1 // functions layer
#define L_SYST 2 // system layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  6   |           |  5   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | +L2  |           | +L2  |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| +L1  |           | +L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | Left | Right|   `  |   \  |                                       |   [  |   ]  | Down |  Up  |  RAlt  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | Ent  |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Tab  |       | Tab  |      |      |
 *                                 | LGui | Space|------|       |------|Backsp| RGui |
 *                                 |      |      | Esc  |       | Ent  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[L_BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESCAPE,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,      KC_6,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,      TG(L_SYST),
        KC_LCTRL,   KC_A,     KC_S,     KC_D,     KC_F,    KC_G,
        KC_LSHIFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,      TG(L_FUNC),
        KC_LALT,    KC_LEFT,  KC_RGHT,  KC_GRAVE, KC_BSLASH,

                                                           KC_HOME,   KC_END,
                                                                      KC_TAB,
                                                 KC_LGUI,  KC_SPC,    KC_ESC,

        // ritht hand
        KC_5,       KC_6,     KC_7,     KC_8,    KC_9,     KC_0,      KC_MINS,
        TG(L_SYST), KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,      KC_EQUAL,
                    KC_H,     KC_J,     KC_K,    KC_L,     KC_SCOLON, KC_QUOTE,
        TG(L_FUNC), KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_SLSH,   KC_RSFT,
                              KC_LBRC,  KC_RBRC, KC_DOWN,  KC_UP,     KC_RALT,

        KC_PGUP,    KC_PGDN,
        KC_TAB,
        KC_ENT,     KC_BSPC,  KC_RGUI
    ),
/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      | LClk | MsU  | RClk |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |------|           |------|      | MsL  | MsD  | MsR  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function keys
[L_FUNC] = KEYMAP(
       // left hand
       KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                                    KC_NO,   KC_NO,
                                                             KC_NO,
                                           KC_NO,   KC_NO,   KC_NO,

       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,
       KC_NO,   KC_NO,   KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   KC_NO,
                KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO,   KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// System
[L_SYST] = KEYMAP(
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       RESET,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN2,

                                                    KC_NO,   KC_NO,
                                                             KC_NO,
                                           KC_NO,   KC_NO,   KC_NO,
    // right hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_NO,   KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(L_FUNC),
    [2] = ACTION_LAYER_TAP_TOGGLE(L_SYST)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
