// cajal keymap created by me
// www.github.com/laurabeth

#include QMK_KEYBOARD_H

enum cajal_layers {
  _QWERTY,
  _GAMING,
  _MAC,
  _LOWER,
  _RAISE,
  _NAVIGATE,
  _ADJUST,
};

enum cajal_keycodes {
    QWERTY,
    GAMING,
    MAC,
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
#define LOWER MO(_LOWER)
#define NAV MO(_NAVIGATE)
#define RAISE MO(_RAISE)

//Layer toggle
#define T_GMNG DF(_GAMING)
#define T_MAC DF(_MAC)
#define T_QWRT DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_stagger(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL, KC_BSPC, KC_TRNS,
        TAB_NAV, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, SFT_SLS, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, ENT_LOW, SPC_UPR, ADJUST, KC_RCTL,                           KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_GAMING] = LAYOUT_stagger(
        KC_ESC,  KC_Q,    KC_W,  KC_E,   KC_R,   KC_T, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL, KC_BSPC, KC_TRNS,
        KC_TAB,  KC_A,    KC_S,  KC_D,   KC_F,   KC_G, KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,  KC_C,   KC_V,   KC_B, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_LSFT, KC_UP,
        KC_LCTL, KC_LALT, RAISE, KC_SPC, KC_SPC, NAV,  LOWER,                            KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC] = LAYOUT_stagger(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_DEL, KC_BSPC, KC_TRNS,
        TAB_NAV, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, SFT_SLS, KC_UP,
        KC_LGUI, KC_LCTL, KC_LALT, ENT_LOW, SPC_UPR, ADJUST, KC_RGUI,                           KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_stagger(
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS, KC_PIPE, KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_HOME, KC_PGDN, KC_END
    ),

    [_RAISE] = LAYOUT_stagger(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,  KC_8,  KC_9,  KC_0,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_P5, KC_P6, KC_P7, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_P1, KC_P2, KC_P3, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_NAVIGATE] = LAYOUT_stagger(
        KC_TRNS, T_QWRT,  KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, T_GMNG,  KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, T_MAC, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_ADJUST] = LAYOUT_stagger(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAI, KC_TRNS, KC_PSCR, KC_TRNS, RGB_TOG,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            RGB_HUD, RGB_VAD, RGB_HUI
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        writePinHigh(B7);
        writePinLow(B6);
        break;
    case _GAMING:
        writePinLow(B7);
        writePinHigh(B6);
        break;
    case _MAC:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    default:
        writePinLow(B7);
        writePinLow(B6);
        break;
    }
    return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if(IS_LAYER_ON(_MAC)) {
            if (clockwise) {
                tap_code(KC_AGIN);
            } else {
                tap_code(KC_UNDO);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
    }
}

