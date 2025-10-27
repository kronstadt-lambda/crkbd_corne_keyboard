/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version. 

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more tails.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
  OS_WIN = SAFE_RANGE,  // tecla para fijar "modo Windows"
  OS_LIN,               // tecla para fijar "modo Linux"
  ENE,                  // ñ
  ENE_UP                // Ñ
};

static bool os_is_win = true;  // modo por defecto

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_SCLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_ESC),   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,RSFT_T(KC_MINS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_QUOT,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,LT(5,KC_SLSH),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    LT(5,KC_LGUI),   MO(1),  KC_SPC,  LT(3,KC_SPC), LT(2,KC_ENT), LT(6,KC_RALT)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,LCTL(KC_Z),LCTL(KC_C),LCTL(KC_V),LCTL(KC_F),XXXXXXX,               XXXXXXX,  KC_DEL,   KC_UP, XXXXXXX, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_F,  KC_TAB, KC_LSFT, KC_LCTL, KC_LALT, KC_PGUP,                      KC_VOLU, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PSCR, XXXXXXX, XXXXXXX, KC_HOME,  KC_END, KC_PGDN,                      KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_SPC,   MO(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_SLSH,    KC_1,    KC_2,    KC_3, KC_MINS,                     RALT(KC_S), RALT(KC_1),RALT(KC_2),RALT(KC_3),RALT(KC_E), KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS,                     RALT(KC_R), RALT(KC_4),RALT(KC_5),RALT(KC_6),RALT(KC_B), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,  KC_EQL,                     RALT(KC_N), RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_0,   MO(4),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_LPRN, KC_RPRN, XXXXXXX,                      KC_PERC, KC_TILD, KC_DLR,  KC_AMPR,   KC_NO, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  KC_EQL, KC_LCBR, KC_RCBR, XXXXXXX,                      KC_EXLM, KC_HASH, KC_SLSH, KC_BSLS, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      XXXXXXX,  KC_GRV, KC_CIRC, XXXXXXX,    ENE ,  ENE_UP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, OS_LIN , XXXXXXX,                      XXXXXXX,RALT(KC_X),RALT(KC_Y),RALT(KC_Z), XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, OS_WIN , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),  

    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX , XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                   RALT(KC_I),RSFT(KC_F1),RSFT(KC_F2),RSFT(KC_F3),RSFT(KC_F10), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_KP_PLUS), XXXXXXX, KC_F4,  KC_F5,   KC_F6,  KC_F11,    RCTL(RALT(RSFT(KC_PLUS))),RSFT(KC_F4),RSFT(KC_F5),RSFT(KC_F6),RSFT(KC_F11), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   LALT(KC_A), XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12,   RCTL(RALT(RSFT(KC_MINUS))),RSFT(KC_F7),RSFT(KC_F8),RSFT(KC_F9),RSFT(KC_F12), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),   

    [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LCTL(KC_COMM),XXXXXXX,LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_QUOT),            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_DOT),XXXXXXX,LCTL(KC_4),LCTL(KC_5),LCTL(KC_6),LCTL(KC_LBRC),             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_BSLS),XXXXXXX,LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_RBRC),            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),   

};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // Elige la rotación de la pantalla
}

bool oled_task_user(void) {
    oled_write_P(PSTR("Hola,\n"), false); // Mensaje en la primera línea
    oled_write_P(PSTR("mundo!"), false);  // Mensaje en la segunda línea

    return false;
}

#define L_DVORAK 0
#define L_NAVIGATE 1
#define L_NUMPAD 2
#define L_SYMBOLS 3
#define L_ADJUST 4
#define L_F 5

void oled_render_layer_state(void) {
    oled_set_cursor(0, 0);
    switch (get_highest_layer(layer_state)) {
        case L_DVORAK:
            oled_write_P(PSTR("Dvorak"), false);
            break;
        case L_NAVIGATE:
            oled_write_P(PSTR("Navigate"), false);
            break;
        case L_SYMBOLS:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case L_NUMPAD:
            oled_write_P(PSTR("Numpad"), false);
            break;
        case L_ADJUST:
            oled_write_P(PSTR("Adjust"), false);
            break;
        case L_F:
            oled_write_P(PSTR("F"), false);
            break;
        default:
            oled_write_P(PSTR("Default"), false);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;

  switch (keycode) {
    case OS_WIN:
      os_is_win = true;
      return false;
    case OS_LIN:
      os_is_win = false;
      return false;

    case ENE:     // ñ
      if (os_is_win) {
        SEND_STRING(SS_LALT("164"));                // Alt+164 → ñ (teclado numérico)
      } else {
        SEND_STRING(SS_LCTL(SS_LSFT("u")) "00f1" SS_TAP(X_SPACE)); // Ctrl+Shift+U 00f1 (Linux)
      }
      return false;

    case ENE_UP:  // Ñ
      if (os_is_win) {
        SEND_STRING(SS_LALT("165"));                // Alt+165 → Ñ
      } else {
        SEND_STRING(SS_LCTL(SS_LSFT("u")) "00d1" SS_TAP(X_SPACE)); // Ctrl+Shift+U 00d1
      }
      return false;
  }
  return true;
}