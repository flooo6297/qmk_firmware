#include QMK_KEYBOARD_H

enum layer_names {
    _DEFAULT,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,             MT(MOD_LALT | MOD_RALT, KC_RALT), MO(1), KC_LEFT, KC_DOWN,   KC_RIGHT
    ),


    [_FN] = LAYOUT(
        KC_TRNS, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,  KC_TRNS,
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, RGB_HUI, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   RGB_VAI,             KC_TRNS, KC_TRNS, RGB_VAI, RGB_SAI,   RGB_MODE_FORWARD
    )
};

bool caps = false;
bool fn = false;

void rgb_matrix_indicators_kb(void) {
    if (caps) {
        rgb_matrix_set_color(28, 255, 0, 0);
    }
    if (fn) {
        rgb_matrix_set_color(1, 0, 128, 255);
        rgb_matrix_set_color(2, 0, 128, 255);
        rgb_matrix_set_color(3, 0, 128, 255);
        rgb_matrix_set_color(4, 0, 128, 255);
        rgb_matrix_set_color(5, 0, 128, 255);
        rgb_matrix_set_color(6, 0, 128, 255);
        rgb_matrix_set_color(7, 0, 128, 255);
        rgb_matrix_set_color(8, 0, 128, 255);
        rgb_matrix_set_color(9, 0, 128, 255);
        rgb_matrix_set_color(10, 0, 128, 255);
        rgb_matrix_set_color(11, 0, 128, 255);
        rgb_matrix_set_color(12, 0, 128, 255);
        rgb_matrix_set_color(52, 0, 128, 255);
        rgb_matrix_set_color(60, 0, 128, 255);
        rgb_matrix_set_color(61, 0, 128, 255);
        rgb_matrix_set_color(62, 0, 128, 255);
    }
}

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        caps = true;
    } else {
        caps = false;
    }
    //rgb_matrix_indicators_kb();
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    fn = layer_state_cmp(state, _FN);
    return state;
}

void keyboard_post_init_user(void) {

}
