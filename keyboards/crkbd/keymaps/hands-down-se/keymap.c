/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "features/custom_shift_keys.h"
#include "keymap_swedish.h"

enum custom_keycodes {
  CKC_GH = SAFE_RANGE,
  CKC_TH,
  CKC_CH,
  CKC_SH,
  CKC_WH,
  CKC_PH,
  CKC_C_BSP,
  CKC_E_SL
};

const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMMA,  SE_EXLM},
    {KC_DOT,    SE_QUES},
    {SE_COLN,   SE_SCLN},
    {SE_QUOT,   SE_DQUO},
    {SE_UNDS,   SE_DLR},
    {SE_MINS,   SE_PLUS},
    {SE_LPRN,   SE_LCBR},
    {SE_RPRN,   SE_RCBR},
    {SE_LBRC,   SE_LABK},
    {SE_RBRC,   SE_RABK},
    {SE_ASTR,   SE_HASH},
    {CKC_C_BSP, KC_DELETE},
    {CKC_E_SL,  SE_BSLS}
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum combos {
  COMBO_AE, //Ä
  COMBO_Q,
  COMBO_Z,
  COMBO_CTL_Z,
  COMBO_CTL_X,
  COMBO_CTL_C,
  COMBO_CTL_V,
  COMBO_CTL_A,
  COMBO_CTL_Y,
  COMBO_GH,
  COMBO_TH,
  COMBO_CH,
  COMBO_SH,
  COMBO_WH,
  COMBO_PH,
  COMBO_B_PAREN,
  COMBO_E_PAREN,
  COMBO_B_BRACKET,
  COMBO_E_BRACKET,
  COMBO_MINUS,
  COMBO_ASTERISK,
  COMBO_UNDERSCORE,
  COMBO_AMPERSAND,
  COMBO_LAYER_NAV,
  COMBO_LAYER_HOME,
  COMBO_LAYER_MOUSE,
  COMBO_ENTER,
  COMBO_TAB,
  COMBO_AT
};

const uint16_t PROGMEM combo_ae[] = {RSFT_T(KC_A), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_q[] = {KC_G, KC_P, COMBO_END};
const uint16_t PROGMEM combo_z[] = {KC_G, KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ctl_z[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ctl_x[] = {KC_W, KC_L, COMBO_END};
const uint16_t PROGMEM combo_ctl_c[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo_ctl_v[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ctl_a[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ctl_y[] = {KC_W, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo_gh[] = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM combo_th[] = {LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_ch[] = {LGUI_T(KC_C), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_sh[] = {LALT_T(KC_S), LCTL_T(KC_N), COMBO_END};
const uint16_t PROGMEM combo_wh[] = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ph[] = {KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM combo_b_paren[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_e_paren[] = {KC_DOT, LSFT(KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_b_bracket[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_e_bracket[] = {KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_COMMA, LSFT(KC_DOT), COMBO_END};
const uint16_t PROGMEM combo_asterisk[] = {LSFT(KC_DOT), KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_U, KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ampersand[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_layer_nav[] = {RSFT_T(KC_A), KC_DOT, RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_layer_home[] = {LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_layer_mouse[] = {RSFT_T(KC_A), RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_enter[] = {RALT_T(KC_I), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_tab[] = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_LBRC, RCTL_T(KC_E), COMBO_END};

combo_t key_combos[] = {
    [COMBO_AE] = COMBO(combo_ae, SE_ADIA),  //Ä
    [COMBO_Q] = COMBO(combo_q, KC_Q),
    [COMBO_Z] = COMBO(combo_z, KC_Z),
    [COMBO_CTL_Z] = COMBO(combo_ctl_z, LCTL(KC_Z)),
    [COMBO_CTL_X] = COMBO(combo_ctl_x, LCTL(KC_X)),
    [COMBO_CTL_C] = COMBO(combo_ctl_c, LCTL(KC_C)),
    [COMBO_CTL_V] = COMBO(combo_ctl_v, LCTL(KC_V)),
    [COMBO_CTL_A] = COMBO(combo_ctl_a, LCTL(KC_A)),
    [COMBO_CTL_Y] = COMBO(combo_ctl_y, LCTL(KC_Y)),
    [COMBO_GH] = COMBO(combo_gh, CKC_GH),
    [COMBO_TH] = COMBO(combo_th, CKC_TH),
    [COMBO_CH] = COMBO(combo_ch, CKC_CH),
    [COMBO_SH] = COMBO(combo_sh, CKC_SH),
    [COMBO_WH] = COMBO(combo_wh, CKC_WH),
    [COMBO_PH] = COMBO(combo_ph, CKC_PH),
    [COMBO_B_PAREN] = COMBO(combo_b_paren, SE_LPRN),
    [COMBO_E_PAREN] = COMBO(combo_e_paren, SE_RPRN),
    [COMBO_B_BRACKET] = COMBO(combo_b_bracket, SE_LBRC),
    [COMBO_E_BRACKET] = COMBO(combo_e_bracket, SE_RBRC),
    [COMBO_MINUS] = COMBO(combo_minus, SE_MINS),
    [COMBO_ASTERISK] = COMBO(combo_asterisk, SE_ASTR),
    [COMBO_UNDERSCORE] = COMBO(combo_underscore, SE_UNDS),
    [COMBO_AMPERSAND] = COMBO(combo_ampersand, SE_AMPR),
    [COMBO_LAYER_NAV] = COMBO(combo_layer_nav, DF(2)),
    [COMBO_LAYER_HOME] = COMBO(combo_layer_home, DF(0)),
    [COMBO_LAYER_MOUSE] = COMBO(combo_layer_mouse, DF(3)),
    [COMBO_ENTER] = COMBO(combo_enter, KC_ENTER),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_AT] = COMBO(combo_at, SE_AT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    switch (keycode) {
    case CKC_E_SL:
        if (!record->tap.count && record->event.pressed) {
            // Intercept tap function
            tap_code16(SE_SLSH);
        } else if (record->event.pressed) {
            // Intercept hold function
            tap_code(KC_ESC);
        }
        return false;
    case CKC_C_BSP:
        if (record->event.pressed) {
            // Check if c Control is held down
            if (get_mods() & (MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_RIGHT_CTRL))) {
                // Send Backspace if Control is held
                const uint8_t mods = get_mods();
                del_weak_mods(MOD_MASK_CTRL);
                del_oneshot_mods(MOD_MASK_CTRL);
                unregister_mods(MOD_MASK_CTRL);
                tap_code(KC_BSPC);
                set_mods(mods);

            } else {
                // Send LCTRL(Backspace) if no Control is held
                register_mods(MOD_BIT(KC_LEFT_CTRL));
                tap_code(KC_BSPC);
                unregister_mods(MOD_BIT(KC_LEFT_CTRL));
            }
        }
        return false; // Skip further processing of this key
    case CKC_GH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_G) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    case CKC_TH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_T) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    case CKC_CH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_C) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    case CKC_SH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_S) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    case CKC_WH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_W) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    case CKC_PH:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_P) SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
        } else {

        }
        break;
    }
    return true;
};

bool get_must_tap(uint16_t index, combo_t *combo) {
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_VOLU,          KC_X,          KC_G,           KC_M,          KC_P,          KC_J,                                        SE_QUOT,      KC_COMMA,        KC_DOT,   LSFT(KC_DOT),      CKC_E_SL,       KC_BRIU,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_MUTE,  LGUI_T(KC_C),  LALT_T(KC_S),   LCTL_T(KC_N),  LSFT_T(KC_T),          KC_K,                                        KC_LBRC,  RSFT_T(KC_A),  RCTL_T(KC_E),   RALT_T(KC_I), RGUI_T(KC_H),KC_PRINT_SCREEN,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_VOLD,          KC_W,          KC_F,           KC_L,          KC_D,          KC_V,                                        KC_SCLN,          KC_U,          KC_O,           KC_Y,          KC_B,       KC_BRID,
  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                          KC_ENTER,          KC_R,        MO(1),           KC_TAB,      KC_SPACE,       CKC_C_BSP
                                                                //`--------------------------------------------'  `--------------------------------------------'
  ),
  [1] = LAYOUT_split_3x6_3(
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,  LGUI_T(KC_8),  LALT_T(KC_9),   LCTL_T(KC_2),  LSFT_T(KC_3),          KC_4,                                           KC_5,  RSFT_T(KC_1),  RCTL_T(KC_0),   RALT_T(KC_6),  RGUI_T(KC_7),       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                          KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,       KC_TRNS
                                                                //`--------------------------------------------'  `--------------------------------------------'
  ),
  [2] = LAYOUT_split_3x6_3(
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_TRNS,         KC_UP,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_LEFT,       KC_DOWN,       KC_RIGHT,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                          KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_TRNS,       KC_TRNS
                                                                //`--------------------------------------------'  `--------------------------------------------'
  ),
  [3] = LAYOUT_split_3x6_3(
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_WH_U,       KC_TRNS,       KC_MS_U,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_WH_D,       KC_MS_L,       KC_MS_D,        KC_MS_R,       KC_BTN2,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,                                        KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                          KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,       KC_BTN1,       KC_BTN3
                                                                //`--------------------------------------------'  `--------------------------------------------'
  )
};
