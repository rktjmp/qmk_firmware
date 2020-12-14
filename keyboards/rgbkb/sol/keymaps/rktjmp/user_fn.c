#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

void keyboard_post_init_user(void) {
  rgblight_disable_noeeprom();
  default_layer_set(1UL << 1); // default to qwerty layer
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
