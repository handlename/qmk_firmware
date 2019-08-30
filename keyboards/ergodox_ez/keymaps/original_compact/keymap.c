#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define L_BASE 0 // base layer
#define L_SYMB 1 // symbol layer
#define L_MOUS 2 // mouse & cursor layer
#define L_SYST 3 // system layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | +L3  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | +L2  |           | +L2  |   Y  |   U  |   I  |   O  |   P  |   -    |
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
        KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     MO(L_SYST),
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      MO(L_MOUS),
        KC_LCTL,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,    KC_Z,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,
        KC_LALT,    KC_WBAK,  KC_WFWD,  KC_LEFT,  KC_RGHT,

                                                            KC_HOME,   KC_END,
                                                                       KC_LALT,
                                                  KC_LGUI,  KC_SPC,    MO(L_SYMB),

        // right hand
        KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        MO(L_MOUS), KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_MINS,
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
 * |    *   |      |      |      |      |      |  *   |           |  *   |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Esc  |      |      |      |      |      |  *   |           |  *   |      |      |      |   [  |   ]  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    *   |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |    `   |
 * |--------+------+------+------+------+------|  *   |           |  *   |------+------+------+------+------+--------|
 * |    *   |      |      |      |      |      |      |           |      |      |      |      |      |   \  |    *   |
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
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,

                                        KC_TRNS, KC_TRNS,
                                        KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,

    // right hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC,   KC_EQUAL,
             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_GRAVE,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSLASH, KC_TRNS,
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

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(L_MOUS),
    [2] = ACTION_LAYER_TAP_TOGGLE(L_SYMB),
    [3] = ACTION_LAYER_TAP_TOGGLE(L_SYST)
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
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
