#include QMK_KEYBOARD_H

enum elise_layers {
    _QWERTY,
	_GAMING,
	_LOWER,
	_RAISE,
    _NAVIGATE,
    _ADJUST
};

// Combination codes
#define ENT_LOW LT(_LOWER, KC_ENT)
#define SPC_UPR LT(_RAISE, KC_SPC)
#define SFT_SLS MT(MOD_RSFT, KC_SLSH)
#define TAB_NAV LT(_NAVIGATE, KC_TAB)

// Layer switch
#define ADJUST MO(_ADJUST)
#define NAV MO(_NAVIGATE)
#define RAISE MO(_RAISE)

//Layer toggle
#define T_GMNG DF(_GAMING)
#define T_QWRT DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
		KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,    KC_U,     KC_I, KC_O,    KC_P,    KC_DEL, KC_BSPC,
		TAB_NAV,  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,    KC_J,     KC_K, KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          KC_B,    KC_N,     KC_M, KC_COMM, KC_DOT,  SFT_SLS, ADJUST,
		KC_LCTL,  KC_LALT,                    KC_LGUI,   ENT_LOW,	      SPC_UPR, KC_RGUI,                          KC_HOME, KC_END
    ),

    [_GAMING] = LAYOUT(
		KC_ESC,   KC_Q,     KC_W,     KC_E,   KC_R,       KC_T,          KC_Y,    KC_U,     KC_I, KC_O,    KC_P,    KC_DEL, KC_BSPC,
		KC_TAB,   KC_A,     KC_S,     KC_D,   KC_F,       KC_G,          KC_H,    KC_J,     KC_K, KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,       KC_B,          KC_B,   KC_N,     KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI,
		KC_LCTL,  KC_LALT,                    RAISE,      KC_SPC,	       KC_ENT,  NAV,                              KC_RALT, KC_RCTL
    ),

    [_LOWER] = LAYOUT(
		KC_GRV,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_VOLD,   KC_VOLU,
		KC_TRNS,   KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, KC_PIPE,           KC_TILDE,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,
		KC_CAPS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
		KC_TRNS,   KC_TRNS,                   KC_TRNS, KC_TRNS,	          KC_TRNS,   KC_TRNS,                            KC_TRNS,   KC_TRNS
    ),

    [_RAISE] = LAYOUT(
		KC_TRNS,  KC_1,      KC_2,      KC_3,      KC_4,       KC_5,             KC_6,      KC_7,     KC_8,    KC_9,    KC_0,     KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,            KC_NO,     KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC,  KC_BSLS,
		KC_TRNS,  KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,           KC_END,    KC_F12,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,  KC_TRNS,                         KC_TRNS,    KC_TRNS,	         KC_TRNS,   KC_PDOT,                              KC_TRNS,  KC_TRNS
    ),

    [_NAVIGATE] = LAYOUT(
		KC_NO,  T_QWRT, KC_NO,   KC_NO,   RESET,    KC_NO,          KC_NO,   KC_NO,   KC_UP,   KC_NO,    KC_PSCR, KC_NO,  KC_NO,
		KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    T_GMNG,         KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_NO,
		KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
		KC_NO,  KC_NO,                    KC_NO,    KC_NO,	        KC_NO,   KC_NO,                               KC_NO,  KC_NO
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
