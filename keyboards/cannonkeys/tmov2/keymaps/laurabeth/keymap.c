#include QMK_KEYBOARD_H

enum TMOv2_layers {
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _NAVIGATE,
    _ADJUST
};

enum TMOv2_keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    LOWER,
    RAISE,
    NAVIGATE,
    ADJUST
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

	[_QWERTY] = LAYOUT_default(
		KC_HOME, KC_ESC,  KC_Q,    KC_W,  KC_E, KC_R, KC_T, KC_Y,    KC_U,  KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_END,  TAB_NAV,          KC_A,  KC_S, KC_D, KC_F, KC_G,    KC_H,  KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
		KC_PGUP, KC_LSFT, KC_LSFT, KC_Z,  KC_X, KC_C, KC_V, KC_B,    KC_N,  KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,
		KC_PGDN,                   KC_LCTL, KC_LALT,        ENT_LOW, SPC_UPR,     KC_RGUI, KC_RCTL
    ),

    [_GAMING] = LAYOUT_default(
		KC_HOME, KC_ESC,  KC_Q,    KC_W,    KC_E,   KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_END,  KC_TAB,           KC_A,    KC_S,   KC_D, KC_F,   KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
		KC_PGUP, KC_LSFT, KC_LSFT, KC_Z,    KC_X,   KC_C, KC_V,   KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI, KC_RGUI,
		KC_PGDN,                   KC_LCTL, RAISE,        KC_SPC, KC_ENT,           NAV, KC_RALT
    ),

    [_RAISE] = LAYOUT_default(
		KC_TRNS, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
		KC_TRNS, KC_TRNS,          KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,                   KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS
    ),

    [_LOWER] = LAYOUT_default(
		KC_NO, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_VOLD, KC_VOLU, KC_TRNS,
		KC_NO, KC_TRNS,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
		KC_NO, KC_TRNS, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,                   KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS
    ),

    [_NAVIGATE] = LAYOUT_default(
		KC_NO, KC_NO, T_QWRT, KC_NO, KC_NO, RESET, KC_NO,         KC_NO,   KC_NO,   KC_UP,    KC_NO, KC_NO, KC_NO, KC_NO, DEBUG,
		KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, T_GMNG, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,        KC_NO,  KC_NO,        KC_NO, KC_NO,         KC_NO,   KC_NO
    )
};
