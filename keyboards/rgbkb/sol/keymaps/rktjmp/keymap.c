#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// shorten codes for slimmer keymap definitions
#define KC_VOL_M KC_AUDIO_MUTE
#define KC_VOL_D KC_AUDIO_VOL_DOWN
#define KC_VOL_U KC_AUDIO_VOL_UP

// for linux x11 crash swap to term
// #define KC_XREQ LALT(KC_PSCREEN | KC_R)
// #define KC_XKIL LALT(KC_PSCREEN | KC_K)

enum layer_number {
  _BSE = 0,
  _QWR,
  _CLM,
  _SYM,
  _NAV,
  _NUM,
  _NUL,
  _SYS,
  _GQW, // gaming qwerty, with no special holds, return goes to GCL
};

#define KC_SPC_SYM LT(_SYM, KC_SPC)
#define KC_ENT_NAV LT(_NAV, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BSE] = LAYOUT(\
    KC_GESC, KC_1,   KC_2,    KC_3,    KC_4,      KC_5,       MO(_SYS), /**/ KC_NO,  KC_6,       KC_7,     KC_8,  KC_9,  KC_0,  KC_NO,   \
     KC_TAB, KC_NO,  KC_NO,   KC_NO,   KC_NO,     KC_NO,      KC_NO,    /**/ KC_NO,  KC_NO,      KC_NO,    KC_NO, KC_NO, KC_NO, KC_DEL,  \
    KC_LCTL, KC_NO,  KC_NO,   KC_NO,   KC_NO,     KC_NO,      KC_NO,    /**/ KC_NO,  KC_NO,      KC_NO,    KC_NO, KC_NO, KC_NO, KC_BSPC, \
    KC_LSFT, KC_NO,  KC_NO,   KC_NO,   KC_NO,     KC_NO,      KC_NO,    /**/ KC_NO,  KC_NO,      KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   \
    KC_LGUI, KC_MEH, KC_LGUI, KC_LALT, OSL(_SYM), KC_SPC_SYM, MO(_NUL), /**/ KC_SPC, KC_ENT_NAV, MO(_NUM), KC_NO, KC_NO, KC_NO, KC_NO,   \
                                                  KC_SPC_SYM, MO(_NUL), /**/ KC_SPC, KC_ENT_NAV\
  ),
  [_QWR] = LAYOUT(\
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS, /**/ KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS, \
     KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS, /**/ KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS, \
     KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS, /**/ KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                                                  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS\
  ),
  [_CLM] = LAYOUT(\
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
     KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_TRNS, /**/ KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_TRNS, \
     KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_TRNS, /**/ KC_TRNS, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_TRNS, \
     KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TRNS, /**/ KC_TRNS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                                                  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS   \
  ),
  [_SYM] = LAYOUT(\
     KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_SPC,  KC_NO,   KC_NO,   KC_NO,   \
     KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,   /**/ KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_QUES, KC_TRNS, \
     KC_TRNS, KC_TILD, KC_MINS, KC_PLUS, KC_EQL,  KC_SLSH, KC_NO,   /**/ KC_NO,   KC_BSLS, KC_UNDS, KC_DQUO, KC_QUOT, KC_COLN, KC_TRNS, \
     KC_TRNS, KC_LCBR, KC_LT,   KC_LBRC, KC_LPRN, KC_GRV,  KC_NO,   /**/ KC_NO,   KC_PIPE, KC_RPRN, KC_RBRC, KC_GT,   KC_RCBR, KC_NO,   \
     KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_SPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
                                                  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS   \
  ),
  [_NAV] = LAYOUT(\
     KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,         /**/ KC_NO, KC_NO, KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_NO,   \
     KC_NO,   KC_NO,      KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1,  KC_MS_WH_UP,   /**/ KC_NO, KC_NO, KC_NO,   KC_INS,  KC_HOME, KC_PGUP, KC_NO, KC_TRNS, \
     KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT, KC_MS_WH_DOWN, /**/ KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO, KC_TRNS, \
     KC_TRNS, KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,         /**/ KC_NO, KC_NO, KC_NO,   KC_DEL,  KC_END,  KC_PGDN, KC_NO, KC_NO,   \
     KC_NO,   KC_TRNS,    KC_TRNS,    KC_NO,      KC_NO,       KC_NO,         /**/ KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO, KC_NO,   \
                                                  KC_NO,       KC_NO,         /**/ KC_NO, KC_TRNS   \
  ),
  [_NUM] = LAYOUT(\
     KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO, KC_NO,   /**/ KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO,  KC_NO,   \
     KC_NO,   KC_F7,   KC_F8,   KC_F9, KC_F12, KC_NO, KC_NO,   /**/ KC_NO, KC_NO,   KC_7,    KC_8,  KC_9,   KC_NO,  KC_TRNS, \
     KC_TRNS, KC_F4,   KC_F5,   KC_F6, KC_F11, KC_NO, KC_NO,   /**/ KC_NO, KC_NO,   KC_4,    KC_5,  KC_6,   KC_0,   KC_TRNS, \
     KC_TRNS, KC_F1,   KC_F2,   KC_F3, KC_F10, KC_NO, KC_NO,   /**/ KC_NO, KC_NO,   KC_1,    KC_2,  KC_3,   KC_DOT, KC_NO,   \
     KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_TRNS, /**/ KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_DOT, KC_NO,  KC_NO,   \
                                               KC_NO, KC_TRNS, /**/ KC_NO, KC_TRNS\
  ),
 [_NUL] = LAYOUT(\
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F11,  KC_F12,  \
     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   /**/ KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS, \
     KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   /**/ KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, \
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DOT,  KC_NO,   KC_TRNS, \
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                                                  KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS \
     ),
  [_SYS] = LAYOUT(\
     QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,  TG(_GQW), /**/ KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,   \
     KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    /**/ KC_NO, KC_VOL_U, KC_NO, KC_NO, KC_NO, KC_NO,   \
     KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_CLM), KC_NO,    /**/ KC_NO, KC_VOL_D, KC_NO, KC_NO, KC_NO, KC_NO,   \
     KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_QWR), KC_NO,    /**/ KC_NO, KC_VOL_M, KC_NO, KC_NO, KC_NO, RGB_TOG, \
     KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    /**/ KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, RGB_MOD, \
                                                 KC_NO,    KC_NO,    /**/ KC_NO, KC_NO \
 ),
 [_GQW] = LAYOUT(\
     KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_NO,   /**/ TG(_GQW), KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_NO,   \
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_F5,   /**/ KC_F6,    KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_DEL,  \
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_F4,   /**/ KC_F10,   KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_BSPC, \
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_F1,   /**/ KC_F2,    KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_NO,   \
     KC_GRV,  KC_BSLS, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_MINS, /**/ KC_EQL,   KC_ENT, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   \
                                                 KC_SPC, KC_MINS, /**/ KC_EQL,   KC_ENT \
 )
};

// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 6, HSV_PURPLE});
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 6, HSV_GREEN});
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 6, HSV_AZURE});
const rgblight_segment_t PROGMEM sys_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 36, HSV_RED});
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    sym_layer,
    num_layer,
    nav_layer,
    sys_layer
);

void keyboard_post_init_user(void) {
  rgblight_disable_noeeprom();
  default_layer_set(1UL << _CLM); // default to colemak layer
  rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // Both layers will light up if both kb layers are active
  rgblight_set_layer_state(0, layer_state_cmp(state, _SYM));
  rgblight_set_layer_state(1, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
  rgblight_set_layer_state(3, layer_state_cmp(state, _SYS));
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
//    case RGBRST:
//#if defined(RGBLIGHT_ENABLE)
//        if (record->event.pressed) {
//          eeconfig_update_rgblight_default();
//          rgblight_enable();
//        }
//#elif defined(RGB_MATRIX_ENABLE)
//        if (record->event.pressed) {
//          eeconfig_update_rgb_matrix_default();
//        }
//#endif
//      return false;
  case QK_BOOT:
    // reset only if we hold for half a second
    if (record->event.pressed) {
      reset_timer = timer_read();
    } else {
      if (timer_elapsed(reset_timer) >= 500) {
        reset_keyboard();
      }
    }
    return false;
  }
  return true;
}
