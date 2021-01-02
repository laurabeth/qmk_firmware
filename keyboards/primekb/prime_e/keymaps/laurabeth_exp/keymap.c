#include QMK_KEYBOARD_H

enum elise_layers {
    _QWERTY,
	_GAMING,
	_LOWER,
	_RAISE,
    _NAVIGATE,
    _ADJUST
};

enum elise_keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    LOWER,
    RAISE,
    NAVIGATE,
    ADJUST
};

// Left enter on tap, LOWER on hold
#define ENT_LOW LT(_LOWER, KC_ENT)
// Left space on tap, RAISE on hold
#define SPC_UPR LT(_RAISE, KC_SPC)
// Right shift on hold, forward slash on tap
#define SFT_SLS MT(MOD_RSFT, KC_SLSH)
// Nav layer on hold, esc on tap
#define TAB_NAV LT(_NAVIGATE, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
		KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U,     KC_I, KC_O,    KC_P,    KC_DEL, KC_BSPC,
		TAB_NAV,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J,     KC_K, KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          KC_B,   KC_N,     KC_M, KC_COMM, KC_DOT,  SFT_SLS, SFT_SLS,
		KC_LCTL,  KC_LALT,                    KC_NO,   LOWER,	      RAISE,  KC_RGUI,                          KC_RALT, KC_RCTL
    ),

    [_GAMING] = LAYOUT(
		KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,       KC_T,          KC_Y,    KC_U,     KC_I, KC_O,    KC_P,    KC_DEL, KC_BSPC,
		KC_TAB,   KC_A,     KC_S,     KC_D,   KC_F,       KC_G,          KC_H,    KC_J,     KC_K, KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,       KC_B,          KC_NO,   KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, MO(_NAVIGATE),
		KC_LCTL,  KC_LALT,                    MO(_RAISE), KC_SPC,	     KC_ENT,  KC_RGUI,                          KC_RALT, KC_RCTL
    ),

    [_LOWER] = LAYOUT(
		KC_GRV,    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,     KC_PERC,          KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_VOLD,   KC_VOLU,
		KC_TRNS,   KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE,
		KC_CAPS,   KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,           KC_HOME,   KC_F12,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		BL_TOGG,   BL_STEP,                         KC_TRNS,    KC_TRNS,	        KC_TRNS,   KC_TRNS,                                    KC_TRNS,   KC_TRNS
    ),

    [_RAISE] = LAYOUT(
		KC_TRNS,  KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,     KC_8,    KC_9,    KC_0,      KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_F6,     KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC,   KC_BSLS,
		KC_TRNS,  KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,           KC_END,    KC_F12,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_PDOT,                               KC_TRNS,  KC_TRNS
    ),

    [_NAVIGATE] = LAYOUT(
		KC_NO,  DF(_QWERTY), KC_NO,   KC_NO,   RESET,    KC_NO,          KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
		KC_NO,  KC_NO,       KC_NO,   KC_NO,   KC_NO,    DF(_GAMING),    KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,
		KC_NO,  KC_NO,       KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
		KC_NO,  KC_NO,                         KC_NO,    KC_NO,	         KC_NO,   KC_NO,                               KC_NO,  KC_NO
    ),

    [_ADJUST] = LAYOUT(
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
		KC_NO,  KC_NO,                     KC_NO,    KC_NO,	         KC_NO,   KC_NO,                               KC_NO,  KC_NO
    ),
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B1);
  writePinLow(B1);
  // set NumLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set ScrollLock LED to output and low
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == 1) {
    writePinHigh(B3);
	} else {
		writePinLow(B3);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t timer;
    switch(keycode) {
        case LOWER:
            if (record->event.pressed) {
                timer = timer_read();
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if(timer_elapsed(timer) < TAPPING_TERM){
                    register_code(KC_ENT);
                }
                unregister_code(KC_ENT);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                timer = timer_read();
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
                if(timer_elapsed(timer) < TAPPING_TERM){
                    register_code(KC_SPC);
                }
                unregister_code(KC_SPC);
            }
            return false;
    }
    return true;
}
