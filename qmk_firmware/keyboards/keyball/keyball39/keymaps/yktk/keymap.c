/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  // Eucalyn base layer
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_MINS  , KC_COMM  , KC_DOT   ,                            KC_M     , KC_R     , KC_D     , KC_Y     , KC_P     ,
    KC_A     , KC_O     , KC_E     , KC_I     , KC_U     ,                            KC_G     , KC_T     , KC_K     , KC_S     ,LT(4,KC_N),
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_F     ,                            KC_B     , KC_H     , KC_J     , KC_L     , KC_SLSH  ,
    KC_TAB   , KC_LALT  , KC_LCTL  ,LSFT_T(KC_LNG2),LT(4,KC_SPC),LT(2,KC_LNG1),LT(5,KC_BSPC),LT(3,KC_ENT),KC_RSFT,KC_RCTL,KC_RALT,KC_LGUI
  ),
  // qwer base layer
  [1] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_TAB   , KC_LALT  , KC_LCTL  ,LSFT_T(KC_LNG2),LT(4,KC_SPC),LT(2,KC_LNG1),LT(5,KC_BSPC),LT(3,KC_ENT),KC_RSFT,KC_RCTL,KC_RALT,KC_LGUI
  )
  // number/fn/move
  [2] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_F2    , KC_F3    , KC_PGUP  , KC_F4    , KC_F5    ,                            KC_F8    , KC_F8    , KC_UP    , KC_F9    , KC_F10   ,
    KC_F1    , KC_HOME  , KC_PGDN  , KC_END   , KC_F6    ,                            KC_F7    , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_F11   ,
    KC_ESC   , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , KC_F12
  ),
  // symbol
  [3] = LAYOUT_universal(
    KC_ESC   , S(KC_1)  , S(KC_3)  , S(KC_4)  , KC_RBRC  ,                            KC_BSLS  , S(KC_5)  , S(KC_6)  , KC_EQL   , KC_DEL   ,
    S(KC_EQL),S(KC_LBRC), S(KC_7)  , S(KC_2)  , S(KC_8)  ,                            S(KC_9)  , KC_LBRC  ,S(KC_INT1), KC_QUOT  , KC_SCLN  ,
   S(KC_SCLN),S(KC_QUOT),S(KC_MINS),S(KC_COMM),S(KC_RCBR),                           S(KC_BSLS),S(KC_DOT) ,S(KC_INT3), KC_INT1  ,S(KC_SLSH),
    KC_TAB   , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  // mouse
  [4] = LAYOUT_universal(
    _______  , KC_PSCR  , KC_SCRL  , KC_PAUS  , _______  ,                            _______  , _______  , KC_BTN3  , _______  , _______  ,
    KC_CAPS  , KC_INS   , _______  , _______  , _______  ,                            _______  , KC_BTN1  , KC_PGUP  , KC_BTN2  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , MO(5)    , KC_PGDN  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
  // extra custom
  [5] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , CM_TOGG  ,                            CM_OFF   , CM_ON    , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , DF(0)    , DF(1)    , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 5);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef COMBO_ENABLE
// eucalyn combos
const uint16_t PROGMEM my_keyz1[] = {KC_COMM, KC_DOT,  COMBO_END};
const uint16_t PROGMEM my_keyz2[] = {KC_L,    KC_SLSH, COMBO_END};
const uint16_t PROGMEM my_keyz3[] = {KC_T,    KC_K,    COMBO_END};
const uint16_t PROGMEM my_keyz4[] = {KC_K,    KC_S,    COMBO_END};
const uint16_t PROGMEM my_keyz5[] = {KC_Y,    KC_P,    COMBO_END};

combo_t key_combos[] = {
     COMBO(my_keyz1, KC_ESC)
    ,COMBO(my_keyz2, KC_LGUI)
    ,COMBO(my_keyz3, KC_LNG2)
    ,COMBO(my_keyz4, KC_LNG1)
    ,COMBO(my_keyz5, KC_PSCR)
};
#endif
