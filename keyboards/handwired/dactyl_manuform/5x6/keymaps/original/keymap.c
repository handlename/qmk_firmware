/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _QWERTY 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define QWERTY TG(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_5x6(
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
     KC_TAB ,KC_QUOT,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,                        KC_F   ,KC_G   ,KC_K   ,KC_R   ,KC_L   ,KC_SLSH,
     KC_LCTL,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,                        KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS,
     KC_LSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_C   ,KC_X   ,                        KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,QWERTY ,
                     KC_LEFT,KC_RGHT,                                                        KC_DOWN,KC_UP  ,
                                             KC_LGUI,KC_SPC ,        KC_BSPC,KC_RGUI,
                                   LT(RAISE, KC_ESC),LOWER  ,        LOWER  ,LT(RAISE, KC_ENT),
                                             KC_LALT,KC_ESC ,        KC_ENT ,KC_RALT
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

  [_QWERTY] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                        KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,_______,
     _______,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                        KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_COLN,_______,
     _______,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                        KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,_______,
                     _______,_______,                                                        _______,_______,
                                             _______,KC_SPC ,        _______,_______,
                                             _______,_______,        _______,_______,
                                             _______,_______,        _______,_______
  ),
};
