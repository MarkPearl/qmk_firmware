#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define VIM 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |   =      |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |----------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab      |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  OSL |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |----------+------+------+------+------+------|      |           |  L1  |------+------+------+------+------+--------|
 * | Esc      |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |----------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `----------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LGUI-L2 |   ~  |   /  | PRNT |      |                                       |  INS | PAUS |   [  |   ]  | RGUI |
 *   `------------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LCTRL | LALT |       | RAlt |RCTRL|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | BKSP |  DEL |------|       |------|  Enter |Space |
 *                                 |      |	 | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
// layer 0 : default
[BASE] = KEYMAP(  

        // left hand
        KC_EQL,            KC_1,     KC_2,        KC_3,     KC_4,   KC_5,   KC_LEFT,
        KC_TAB,            KC_Q,     KC_W,        KC_E,     KC_R,   KC_T,   TG(VIM),
        KC_ESC,            KC_A,     KC_S,        KC_D,     KC_F,   KC_G,
        KC_LSFT,           KC_Z,     KC_X,        KC_C,     KC_V,   KC_B,   ALL_T(KC_NO),
        LT(MDIA, KC_LGUI), KC_GRAVE, KC_SLASH,    KC_PSCR,  KC_NO,

	// left thumb area
        KC_LCTRL, KC_LALT,
        KC_HOME,
        KC_BSPC, KC_DELETE, KC_END,

        // right hand
            KC_RGHT, KC_6,   KC_7,   KC_8,     KC_9,              KC_0,     KC_MINS,
           OSL(VIM), KC_Y,   KC_U,   KC_I,     KC_O,              KC_P,     KC_BSLS,
               KC_H, KC_J,   KC_K,   KC_L,     KC_SCLN,           KC_QUOT,
       MEH_T(KC_NO), KC_N,   KC_M,   KC_COMM,  KC_DOT,            KC_SLSH,  KC_RSFT,
                             KC_INS, KC_PAUSE, KC_LBRC,           KC_RBRC,  KC_RGUI,

	// right thumb area
        KC_RALT, KC_RCTRL,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  L1  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L1     |      |      |      |      |      |------|           |------| left | down |  up  | right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | DEL  |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LCTRL | LALT |       | RAlt |RCTRL|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | BKSP |  DEL |------|       |------|  Enter |Space |
 *                                 |      |	 | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// VIMOLS
[VIM] = KEYMAP(

       // left hand
       KC_NO  , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       TG(VIM), KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_DEL , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,

	// left thumb area
	KC_LCTRL, KC_LALT,
        KC_HOME,
        KC_BSPC, KC_DELETE, KC_END,

       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_NO  ,
       KC_NO  , KC_NO  , KC_NO,   TG(VIM),  KC_NO,    KC_NO  , KC_NO  ,
                KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT, KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  ,
                         KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  ,

	// right thumb area
        KC_RALT, KC_RCTRL,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPACE
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | 	 |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |	  |	 |	|      |------|           |------|mleft |mdown | mup  |mright|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |Lclk  |      |      |Rclk  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

	// left thumb area
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_BTN1, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       // right thumb area
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(VIM)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
