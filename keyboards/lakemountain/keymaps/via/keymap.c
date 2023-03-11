#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

#define _DEFAULT 0
#define _MOUSE 1
#define _MOVE 2
#define _SPEC 3

#define COPY     C(KC_INS)    // CTRL+INSERT
#define PASTE    S(KC_INS)    // SHIFT+INSERT
#define C_TAB    C(KC_TAB)    // CTRL+TAB
#define CS_TAB   C(S(KC_TAB)) // SHIFT+CTRL+TAB
#define ALT_TAB  A(KC_TAB)
#define C_PGUP   C(KC_PGUP)
#define C_PGDN   C(KC_PGDN)


static bool scrolling_mode = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _MOVE:  // If we're on the _MOVE layer enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(2000);
            break;
        default:
            if (scrolling_mode) {  // check if we were scrolling before and set disable if so
                scrolling_mode = false;
                pointing_device_set_cpi(8000);
            }
            break;
    }
    return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_65(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          //┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,  KC_EQL,      KC_BSPC,     KC_HOME, \
//|────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘      //┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┬────────|
    KC_TAB,       KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC,   KC_ENT,     KC_END,  \
//|─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐        //└─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐          |────────|
       KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,  KC_DEL,            KC_PGUP, \
//|──────────┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┐      //└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴─┬────────|────────|
    KC_LSFT,  KC_SLSH,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,     KC_UP,  KC_PGDN, \
//|──────────|────────┴─┬──────┴───┬────┴─────┬──┴────────┴────────|          //|────────┴────────┴──────┬─┴──────┬─┴──────┬─┴──────┬────────|────────|────────|
    BL_BRTG,   KC_LGUI,   KC_LALT,  MO(_MOVE), LT(_MOUSE, KC_SPC),                  LT(_SPEC, KC_SPC),    KC_ALGR, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
//└──────────┴──────────┴──────────┴──────────┴────────────────────┘          //└────────────────────────┴────────┴────────┴────────┴────────┴────────┴────────|
  ),

  [_MOUSE] = LAYOUT_65(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          //┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
    KC_ESC, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_DEL,      KC_INS,  \
//|────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘      //┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┬────────|
      _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, \
//|─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐        //└─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐          |────────|
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  XXXXXXX, \
//|──────────┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┐      //└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴─┬────────|────────|
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX, \
//|──────────|────────┴─┬──────┴───┬────┴─────┬──┴────────┴────────|          //|────────┴────────┴──────┬─┴──────┬─┴──────┬─┴──────┬────────|────────|────────|
    _______,  _______,   _______,    XXXXXXX,       XXXXXXX,                             XXXXXXX,         _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//└──────────┴──────────┴──────────┴──────────┴────────────────────┘          //└────────────────────────┴────────┴────────┴────────┴────────┴────────┴────────|
  )
  ,
  [_MOVE] = LAYOUT_65(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          //┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
    KC_ESC, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_DEL,      KC_INS,  \
//|────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘      //┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┬────────|
      _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, \
//|─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐        //└─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐          |────────|
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  XXXXXXX, \
//|──────────┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┐      //└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴─┬────────|────────|
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX, \
//|──────────|────────┴─┬──────┴───┬────┴─────┬──┴────────┴────────|          //|────────┴────────┴──────┬─┴──────┬─┴──────┬─┴──────┬────────|────────|────────|
    _______,  _______,   _______,    XXXXXXX,       XXXXXXX,                             XXXXXXX,         _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//└──────────┴──────────┴──────────┴──────────┴────────────────────┘          //└────────────────────────┴────────┴────────┴────────┴────────┴────────┴────────|
  )
  ,
  [_SPEC] = LAYOUT_65(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          //┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
    KC_ESC, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      KC_DEL,      KC_INS,  \
//|────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘      //┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┬────────|
      _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, \
//|─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐        //└─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐          |────────|
    _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,  XXXXXXX, \
//|──────────┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┐      //└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴─┬────────|────────|
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, XXXXXXX, \
//|──────────|────────┴─┬──────┴───┬────┴─────┬──┴────────┴────────|          //|────────┴────────┴──────┬─┴──────┬─┴──────┬─┴──────┬────────|────────|────────|
    _______,  _______,   _______,    XXXXXXX,       XXXXXXX,                             XXXXXXX,         _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//└──────────┴──────────┴──────────┴──────────┴────────────────────┘          //└────────────────────────┴────────┴────────┴────────┴────────┴────────┴────────|
  )
};

/*
  [_DUMMY] = LAYOUT_65(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐          //┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┬────────┐
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,   _______,        _______,\
//|────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘      //┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬────────────┬────────|
      _______,    _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,              _______,\
//|─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐        //└─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐          |────────
    _______,        _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,  _______,  _______,\
//|──────────┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┐      //└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴─┬────────|────────|
    _______,   _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______,    _______,     _______, _______,\
//|──────────|────────┴─┬──────┴───┬────┴─────┬──┴────────┴────────|          //|────────┴────────┴──────┬─┴──────┬─┴──────┬─┴──────┬────────|────────|────────|
    _______,   _______,   _______,   _______,        _______,                             _______,         _______, _______, _______, _______, _______, _______
//└──────────┴──────────┴──────────┴──────────┴────────────────────┘          //└────────────────────────┴────────┴────────┴────────┴────────┴────────┴────────|
  )*/

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
    set_auto_mouse_enable(true);
    set_auto_mouse_enable(true);
}
