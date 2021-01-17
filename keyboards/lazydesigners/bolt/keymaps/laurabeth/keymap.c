/* Copyright 2020 LAZYDESIGNERS
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


enum bolt_layers {
    _QWERTY,
	  _GAMING,
	  _LOWER,
	  _RAISE,
    _NAVIGATE,
    _ADJUST
};

enum bolt_keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    LOWER,
    RAISE,
    NAVIGATE,
    ADJUST,
    VS_CMNT,
    VS_UCMNT
};

// Left enter on tap, LOWER on hold
#define ENT_LOW LT(_LOWER, KC_ENT)
// Left space on tap, RAISE on hold
#define SPC_UPR LT(_RAISE, KC_SPC)
// Right shift on hold, forward slash on tap
#define SFT_SLS MT(MOD_RSFT, KC_SLSH)
// Nav layer on hold, esc on tap
#define ESC_NAV LT(_NAVIGATE, KC_ESC)

#define LT2_TAB LT(2, KC_TAB)
#define LT1_SPC LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
               KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
               ESC_NAV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
               KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  SFT_SLS, SFT_SLS,
               KC_LCTL,  KC_LALT,                   KC_LGUI, ENT_LOW,          SPC_UPR, KC_RGUI,                    KC_HOME, KC_END,  KC_PSCR
             ),
    [_GAMING] = LAYOUT(
               KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,                    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
               KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,       KC_G,                    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
               KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,            KC_B,   KC_N,    KC_M,    KC_COMM,  KC_DOT,  SFT_SLS, MO(_NAVIGATE),
               KC_LCTL,  KC_LALT,                   MO(_RAISE), KC_SPC,          KC_ENT, KC_RGUI,                  KC_HOME, KC_END,  KC_PSCR
             ),
    [_LOWER] = LAYOUT(
               KC_GRV,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
               KC_INS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
               KC_CAPS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,                     KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,                     KC_NO,   KC_NO,   KC_NO
             ),
    [_RAISE] = LAYOUT(
               KC_NO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
               KC_NO,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
               KC_CAPS,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               VS_CMNT,  VS_UCMNT,                  KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,                     KC_NO,   KC_NO,   KC_NO
             ),
    [_NAVIGATE] = LAYOUT(
               KC_NO,    DF(_QWERTY), RGB_HUI, KC_NO,     RESET,   KC_NO,                   KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO,   KC_NO,
               KC_NO,    RGB_SAI,     RGB_HUD, RGB_SAD,   KC_NO,   DF(_GAMING),             KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,
               KC_NO,    RGB_VAI,     KC_NO,   RGB_VAD,   KC_NO,   KC_NO,          RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X,
               RGB_TOG,  KC_NO,                           KC_NO,   KC_NO,          KC_NO,   KC_NO,                     RGB_M_G,  RGB_M_T, KC_NO
             ),
    [_ADJUST] = LAYOUT(
               RESET,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO,    KC_NO,                     KC_NO,   KC_NO,            KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
             ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch(keycode){
    case VS_CMNT:
      if(record -> event.pressed) {
        SEND_STRING(SS_LCTL("kc"));
      } else {
        // key released
      }
      break;

    case VS_UCMNT:
     if(record -> event.pressed) {
        SEND_STRING(SS_LCTL("ku"));
      } else {
        // key released
      }
      break;
  }
  return true;
};
