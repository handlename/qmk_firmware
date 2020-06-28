/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

// LAYERS

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _GAMING 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define GAMING TG(_GAMING)

// KEY MACROS

#define MT_SNS MT(MOD_LSFT, KC_SPACE) // SandS

// KEY COMBO

typedef const uint16_t comb_keys_t[];

static PROGMEM comb_keys_t
  comb_keys_ECS = {KC_H, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(comb_keys_ECS, KC_ESC),
};

// KEY MAPS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_5x6(
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_DEL ,
     KC_TAB ,KC_QUOT,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,                        KC_F   ,KC_G   ,KC_K   ,KC_R   ,KC_L   ,KC_SLSH,
     KC_LCTL,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,                        KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS,
     KC_LSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_C   ,KC_X   ,                        KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,KC_RSFT,
                     KC_LEFT,KC_RGHT,                                                        KC_DOWN,KC_UP  ,
                                             KC_LGUI,MT_SNS ,        KC_BSPC,KC_RGUI,
                                   LT(RAISE, KC_ESC),GAMING ,        XXXXXXX,LT(RAISE, KC_ENT),
                                             KC_LALT,LOWER  ,        LOWER  ,KC_RALT
  ),

  [_RAISE] = LAYOUT_5x6(

     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                        KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     _______,_______,_______,_______,_______,_______,                        _______,KC_LBRC,KC_RBRC,_______,KC_PIPE,KC_BSLS,
     _______,_______,_______,_______,_______,_______,                        _______,KC_LCBR,KC_RCBR,_______,KC_PLUS,KC_EQL ,
     _______,_______,_______,_______,_______,_______,                        _______,KC_9   ,KC_0   ,_______,_______,_______,
                     _______,_______,                                                        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______

  ),

  [_LOWER] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        KC_MUTE,_______,_______,_______,_______,_______,
     _______,_______,_______,KC_UP  ,_______,KC_VOLD,                        KC_VOLU,KC_P1  ,KC_P2  ,KC_P3  ,_______,_______,
     _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_BRID,                        KC_BRIU,KC_P4  ,KC_P5  ,KC_P6  ,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,KC_P7  ,KC_P8  ,KC_P9  ,_______,_______,
                     _______,_______,                                                        KC_P0  ,KC_PDOT,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),

  [_GAMING] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     KC_T   ,KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______,
     KC_G   ,KC_LCTL,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_COLN,_______,
     KC_B   ,KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,_______,
                     _______,_______,                                                        _______,_______,
                                             XXXXXXX,KC_SPC ,        _______,XXXXXXX,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),
};

// RGB LED

void keyboard_post_init_user(void) {
    rgblight_disable();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAMING:
            uprintf("_GAMING!!");
            rgblight_enable();
            break;
        default:
            uprintf("DEFAULT!!");
            rgblight_disable();
            break;
    }

    return state;
}
