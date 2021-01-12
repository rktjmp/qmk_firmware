#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// LAYOUT_kc automatically prepends KC_ to anything given, but not all QMK keys
// are prefixed as such, so make some sneaky maps to fix that.
#define KC_RESET RESET
#define KC_MO MO
#define KC_OSL OSL
#define KC_DF DF
#define KC_MT MT
#define KC_TG TG
#define KC_RGB_TOG RGB_TOG

#define KC_VOL_M KC_AUDIO_MUTE
#define KC_VOL_D KC_AUDIO_VOL_DOWN
#define KC_VOL_U KC_AUDIO_VOL_UP

enum layer_number {
  _BSE = 0,
  _QWR,
  _CLM,
  _SYM,
  _NAV,
  _NUM,
  _SYS,
  _GQW, // gaming qwerty, with no special holds, return goes to GCL
  _GCL, // gaming colemak, with esc and return going to GQW
};

#define KC_SPC_SYM LT(_SYM, KC_SPC)
#define KC_ENT_NAV LT(_NAV, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BSE] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     GESC   , 1      , 2      , 3      , 4      , 5      ,MO(_SYS),  NO     , 6      , 7      , 8      , 9      , 0      , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TAB    , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , DEL    ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL   , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , BSPC   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LSFT   , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , MEH    , LGUI   , LALT   ,OSL(_SYM),SPC_SYM,MO(_NUM),  NO     , ENT_NAV,MO(_NAV), NO     , NO     , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  SPC_SYM,MO(_NUM),  NO     , ENT_NAV\
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_QWR] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,  TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , Q      , W      , E      , R      , T      , TRNS   ,  TRNS   , Y      , U      , I      , O      , P      , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , A      , S      , D      , F      , G      , TRNS   ,  TRNS   , H      , J      , K      , L      , SCLN   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , Z      , X      , C      , V      , B      , TRNS   ,  TRNS   , N      , M      , COMM   , DOT    , SLSH   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , TRNS   , TRNS   , TRNS   , TRNS ,   TRNS   , TRNS   ,  TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  TRNS   , TRNS   ,  TRNS   , TRNS   \
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_CLM] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,  TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , Q      , W      , F      , P      , B      , TRNS   ,  TRNS   , J      , L      , U      , Y      , QUOT   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , A      , R      , S      , T      , G      , TRNS   ,  TRNS   , M      , N      , E      , I      , O      , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , Z      , X      , C      , D      , V      , TRNS   ,  TRNS   , K      , H      , COMM   , DOT    , SLSH   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS    , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  TRNS   , TRNS   ,  TRNS   , TRNS   \
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_SYM] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , BSLS   , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , EXLM   , AT     , HASH   , DLR    , PERC   , NO     ,  NO     , CIRC   , AMPR   , ASTR   , SCLN   , GRV    , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , TILD   , MINS   , PLUS   , EQL    , NO     , NO     ,  NO     , NO     , UNDS   , NO     , PIPE   , COLN   , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , LT     , LCBR   , LBRC   , LPRN   , NO     , NO     ,  NO     , BSLS   , RPRN   , RBRC   , RCBR   , GT     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   , TRNS   ,  TRNS   , TRNS   , TRNS   , NO     , NO     , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  TRNS   , TRNS   ,  TRNS   , TRNS   \
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_NAV] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , PSCR   , SLCK   , PAUS   , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , INS    , HOME   , PGUP   , NO     , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , LEFT   , DOWN   , UP     , RGHT   , NO     , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , DEL    , END    , PGDN   , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , TRNS   , TRNS   , NO     , NO     , NO     , NO     ,  NO     , TRNS   , TRNS   , NO     , NO     , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  NO     , NO     ,  NO     , TRNS   \
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_NUM] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , F7     , F8     , F9     , F12    , NO     , NO     ,  NO     , NO     , 7      , 8      , 9      , NO     , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , F4     , F5     , F6     , F11    , NO     , NO     ,  NO     , NO     , 4      , 5      , 6      , 0      , TRNS   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TRNS   , F1     , F2     , F3     , F10    , NO     , NO     ,  NO     , NO     , 1      , 2      , 3      , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , TRNS   , TRNS   , NO     , NO     , NO     , TRNS   ,  NO     , TRNS   , NO     , NO     , DOT    , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  NO     , TRNS   ,  NO     , TRNS   \
 //                                             └────────┴────────┘└────────┴────────┘
  ),
  [_SYS] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     RESET  , NO     , NO     , NO     , NO     , NO     , TRNS   , TG(_GQW), NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , VOL_U  , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     ,DF(_CLM),  NO     , NO     , VOL_D  , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     ,DF(_QWR),  NO     , NO     , VOL_M  , NO     , NO     , NO     , RGB_TOG,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , RGB_MOD,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  NO     , NO     ,  NO     , NO     \
 //                                             └────────┴────────┘└────────┴────────┘
 ),
 [_GQW] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     GESC   , 1      , 2      , 3      , 4      , 5      , NO     ,TG(_GQW) , 6      , 7      , 8      , 9      , 0      , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     TAB    , Q      , W      , E      , R      , T      , F5     ,  F6     , Y      , U      , I      , O      , P      , DEL    ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LCTL   , A      , S      , D      , F      , G      , F4     ,  F10    , H      , J      , K      , L      , SCLN   , BSPC   ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LSFT   , Z      , X      , C      , V      , B      , F1     ,  F2     , N      , M      , COMM   , DOT    , SLSH   , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GRV    , BSLS   , LGUI   , LALT   , SPC    , SPC    , MINS   ,  EQL    , ENT    , NO     , NO     , NO     , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  SPC    , MINS   ,  EQL    , ENT    \
 //                                             └────────┴────────┘└────────┴────────┘
 )
};
/*
 [] = LAYOUT_kc(\
 //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NO     , NO     , NO     , NO     , NO     , NO     , NO     ,  NO     , NO     , NO     , NO     , NO     , NO     , NO     ,\
 //└────────┴────────┴────────┴────────┴────────┤        │        ││        │        ├────────┴────────┴────────┴────────┴────────┘
                                                  NO     , NO     ,  NO     , NO     \
 //                                             └────────┴────────┘└────────┴────────┘
 ),
*/

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
  default_layer_set(1UL << 2); // default to colemak layer
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
  case RESET:
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
