/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QUICK_TAP_TERM 0
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_ONLY_FROM_LAYER 0

#define COMBO_TERM 30
#define TAPPING_TERM 220
// Home-row mods (see keymap.c for the per-key hooks):
#define TAPPING_TERM_PER_KEY // Shift mod-taps settle faster (175 ms).
#define PERMISSIVE_HOLD      // Tapping another key inside the hold = modifier, so a fast Shift isn't lost.
#define CHORDAL_HOLD         // Only opposite-hand chords hold; same-hand rolls stay letters.
#define FLOW_TAP_TERM 150    // A mod-tap pressed mid-burst is a letter (Shift excluded).

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif

// Board default caps brightness at 120/255. Single-colour fills draw about a
// third of white's current, so 170 stays within what USB ports supply.
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 170

#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_HINT // Miss hints light right-half keys too.

#define LAYER_STATE_8BIT // 4 layers in use; 8-bit layer state saves flash
