/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _BASE 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_5x6(
     KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
     KC_TAB ,KC_QUOT,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,                        KC_F   ,KC_G   ,KC_K   ,KC_R   ,KC_L   ,KC_SLSH,
     KC_LCTL,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,                        KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS,
     KC_LSFT,KC_SCLN,KC_Q   ,KC_J   ,KC_C   ,KC_X   ,                        KC_B   ,KC_M   ,KC_W   ,KC_V   ,KC_Z   ,KC_RSFT,
                     KC_F5  ,KC_F9  ,                                                        KC_F10 ,KC_F11 ,
                                             KC_LGUI,KC_SPC ,        KC_BSPC,KC_RGUI,
                                             RAISE  ,LOWER  ,        LOWER  ,RAISE  ,
                                             KC_ESC ,KC_LALT,        KC_RALT,KC_ENT
  ),

  [_RAISE] = LAYOUT_5x6(

     _______,_______,_______,_______,KC_LBRC,_______,                        _______,KC_RBRC,_______,_______,_______,_______,
     _______,_______,_______,_______,KC_9   ,KC_ESC ,                        KC_ENT ,KC_0   ,_______,_______,_______,_______,
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                        KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
     _______,_______,_______,_______,KC_LCBR,_______,                        _______,KC_RCBR,_______,_______,_______,_______,
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
};
