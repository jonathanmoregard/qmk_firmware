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
#include "raw_hid.h"

enum custom_keycodes { CKC_GH = SAFE_RANGE, CKC_TH, CKC_CH, CKC_SH, CKC_WH, CKC_PH, CKC_C_BSP, CKC_E_SL, CKC_HOME, CKC_MUTE };

const custom_shift_key_t custom_shift_keys[] = {
    // single keys
    {KC_COMMA, SE_EXLM},    // , !
    {KC_DOT, SE_QUES},      // . ?
    {SE_SCLN, SE_COLN},     // ; :
    {SE_QUOT, SE_DQUO},     // ' "
    {CKC_E_SL, SE_BSLS},    // slash backslash
    {CKC_C_BSP, KC_DELETE}, // backspace delete

    // top row combos
    {SE_MINS, SE_PLUS}, // - +
    {SE_ASTR, SE_HASH}, // * #
    {SE_LPRN, SE_LCBR}, // ( {
    {SE_RPRN, SE_RCBR}, // ) }

    // middle row combos
    {SE_AT, SE_EQL}, // @ =

    // bottom row combos
    {SE_AMPR, SE_DLR},  // & $
    {SE_UNDS, SE_PIPE}, // _ |
    {SE_LBRC, SE_LABK}, // [ <
    {SE_RBRC, SE_RABK}  // ] >
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

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
    COMBO_PERCENT,
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

const uint16_t PROGMEM combo_ae[]          = {RSFT_T(KC_A), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_q[]           = {KC_G, KC_P, COMBO_END};
const uint16_t PROGMEM combo_z[]           = {KC_G, KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ctl_z[]       = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ctl_x[]       = {KC_W, KC_L, COMBO_END};
const uint16_t PROGMEM combo_ctl_c[]       = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo_ctl_v[]       = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ctl_a[]       = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ctl_y[]       = {KC_W, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo_gh[]          = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM combo_th[]          = {LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_ch[]          = {LGUI_T(KC_C), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_sh[]          = {LALT_T(KC_S), LCTL_T(KC_N), COMBO_END};
const uint16_t PROGMEM combo_wh[]          = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM combo_ph[]          = {KC_M, KC_P, COMBO_END};
const uint16_t PROGMEM combo_percent[]     = {SE_QUOT, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_b_paren[]     = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_e_paren[]     = {KC_DOT, SE_SCLN, COMBO_END};
const uint16_t PROGMEM combo_b_bracket[]   = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_e_bracket[]   = {KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_minus[]       = {KC_COMMA, SE_SCLN, COMBO_END};
const uint16_t PROGMEM combo_asterisk[]    = {SE_SCLN, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_underscore[]  = {KC_U, KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ampersand[]   = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_layer_nav[]   = {RSFT_T(KC_A), KC_DOT, RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_layer_home[]  = {LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM combo_layer_mouse[] = {RSFT_T(KC_A), RCTL_T(KC_E), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_enter[]       = {RALT_T(KC_I), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM combo_tab[]         = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_at[]          = {KC_LBRC, RCTL_T(KC_E), COMBO_END};

combo_t key_combos[] = {[COMBO_AE]          = COMBO(combo_ae, SE_ADIA), //Ä
                        [COMBO_Q]           = COMBO(combo_q, KC_Q),
                        [COMBO_Z]           = COMBO(combo_z, KC_Z),
                        [COMBO_CTL_Z]       = COMBO(combo_ctl_z, LCTL(KC_Z)),
                        [COMBO_CTL_X]       = COMBO(combo_ctl_x, LCTL(KC_X)),
                        [COMBO_CTL_C]       = COMBO(combo_ctl_c, LCTL(KC_C)),
                        [COMBO_CTL_V]       = COMBO(combo_ctl_v, LCTL(KC_V)),
                        [COMBO_CTL_A]       = COMBO(combo_ctl_a, LCTL(KC_A)),
                        [COMBO_CTL_Y]       = COMBO(combo_ctl_y, LCTL(KC_Y)),
                        [COMBO_GH]          = COMBO(combo_gh, CKC_GH),
                        [COMBO_TH]          = COMBO(combo_th, CKC_TH),
                        [COMBO_CH]          = COMBO(combo_ch, CKC_CH),
                        [COMBO_SH]          = COMBO(combo_sh, CKC_SH),
                        [COMBO_WH]          = COMBO(combo_wh, CKC_WH),
                        [COMBO_PH]          = COMBO(combo_ph, CKC_PH),
                        [COMBO_PERCENT]     = COMBO(combo_percent, SE_PERC),
                        [COMBO_B_PAREN]     = COMBO(combo_b_paren, SE_LPRN),
                        [COMBO_E_PAREN]     = COMBO(combo_e_paren, SE_RPRN),
                        [COMBO_B_BRACKET]   = COMBO(combo_b_bracket, SE_LBRC),
                        [COMBO_E_BRACKET]   = COMBO(combo_e_bracket, SE_RBRC),
                        [COMBO_MINUS]       = COMBO(combo_minus, SE_MINS),
                        [COMBO_ASTERISK]    = COMBO(combo_asterisk, SE_ASTR),
                        [COMBO_UNDERSCORE]  = COMBO(combo_underscore, SE_UNDS),
                        [COMBO_AMPERSAND]   = COMBO(combo_ampersand, SE_AMPR),
                        [COMBO_LAYER_NAV]   = COMBO(combo_layer_nav, TO(2)),
                        [COMBO_LAYER_HOME]  = COMBO(combo_layer_home, CKC_HOME),
                        [COMBO_LAYER_MOUSE] = COMBO(combo_layer_mouse, TO(3)),
                        [COMBO_ENTER]       = COMBO(combo_enter, KC_ENTER),
                        [COMBO_TAB]         = COMBO(combo_tab, KC_TAB),
                        [COMBO_AT]          = COMBO(combo_at, SE_AT)};

#define IDLE_TIMEOUT_MS 20000 // Idle timeout in milliseconds: layers and Caps Lock reset.

// Back to a clean state: base layer, no mods, Caps Word and Caps Lock off.
// Used by the idle timeout and the home combo.
static void reset_keyboard_state(void) {
    layer_clear();
    clear_mods();
    clear_oneshot_mods();
    send_keyboard_report();
    caps_word_off();
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

static void stats_flush(void);

static uint32_t idle_callback(uint32_t trigger_time, void *cb_arg) {
    // If execution reaches here, the keyboard has gone idle.
    reset_keyboard_state();
    stats_flush();
    return 0;
}

// Slash/Esc key state (see CKC_E_SL in process_record_user).
static uint16_t e_sl_timer;
static bool     e_sl_held = false;
static bool     e_sl_esc  = false;

// Hold both Ctrls + a Shift to toggle Caps Lock (fires once per chord).
// Also sends Esc once the slash/Esc key has been held past TAPPING_TERM.
void housekeeping_task_user(void) {
    if (!is_keyboard_master()) return;
    if (e_sl_held && !e_sl_esc && timer_elapsed(e_sl_timer) >= TAPPING_TERM) {
        tap_code(KC_ESC);
        e_sl_esc = true;
    }
    static bool  chord_held = false;
    const uint8_t mods      = get_mods();
    const bool    chord     = (mods & MOD_BIT(KC_LCTL)) && (mods & MOD_BIT(KC_RCTL)) && (mods & MOD_MASK_SHIFT);
    if (chord && !chord_held) {
        clear_mods(); // Send a bare Caps Lock, not Ctrl+Shift+Caps.
        send_keyboard_report();
        tap_code(KC_CAPS);
        set_mods(mods);
        send_keyboard_report();
    }
    chord_held = chord;
}

// Underglow colour, first match wins: Caps Lock red, Caps Word orange-red,
// then per layer: base green, numbers purple, nav blue, mouse teal.
static bool miss_flashing = false; // A miss blink owns the LEDs until it ends.
static bool miss_muted    = false; // CKC_MUTE: no blink or ting; the mute key glows red.

static void set_layer_color(uint8_t layer) {
    if (miss_flashing) return;
    const uint8_t val = RGB_MATRIX_MAXIMUM_BRIGHTNESS; // Ignore the stored (dim) value.
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_sethsv_noeeprom(0, 255, val); // red
        return;
    }
    if (is_caps_word_on()) {
        rgb_matrix_sethsv_noeeprom(10, 255, val); // orange-red
        return;
    }
    switch (layer) {
        case 1: rgb_matrix_sethsv_noeeprom(191, 255, val); break; // purple
        case 2: rgb_matrix_sethsv_noeeprom(170, 255, val); break; // blue
        case 3: rgb_matrix_sethsv_noeeprom(128, 255, val); break; // teal
        default: rgb_matrix_sethsv_noeeprom(85, 255, val); break; // green
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    set_layer_color(0);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_layer_color(get_highest_layer(state));
    return state;
}

// Host toggled Caps Lock (our chord, the idle reset, or another keyboard): recolour.
bool led_update_user(led_t led_state) {
    set_layer_color(get_highest_layer(layer_state));
    return true;
}

// Caps Word turned on or off: recolour.
void caps_word_set_user(bool active) {
    set_layer_color(get_highest_layer(layer_state));
}

// Type <key>h, uppercase when Caps Word is on.
static void send_h_bigram(uint16_t keycode) {
    if (is_caps_word_on()) {
        tap_code16(LSFT(keycode));
        tap_code16(LSFT(KC_H));
    } else {
        tap_code(keycode);
        SEND_STRING(SS_UP(X_LEFT_SHIFT) SS_UP(X_RIGHT_SHIFT) SS_TAP(X_H));
    }
}

// Adaptive keys (Hands Down style): rolling FIRST then TRIGGER within
// ADAPTIVE_TERM types FIRST then OUTPUT, removing a same-finger pair or
// scissor. Triggers are pairs that almost never occur in real text; type them
// slower than ADAPTIVE_TERM to get the literal letters.
#define ADAPTIVE_TERM 150

typedef struct {
    uint16_t first, trigger, output;
} adaptive_key_t;

static const adaptive_key_t adaptive_keys[] = {
    {KC_A, KC_E, KC_U}, // ae -> au (same finger A/U); A+E chord is still Ä
    {KC_P, KC_X, KC_L}, // px -> pl (scissor)
    {KC_N, KC_W, KC_L}, // nw -> nl (same finger N/L)
};

static uint16_t adaptive_prev      = KC_NO;
static uint16_t adaptive_prev_time = 0;

// Returns false if the press was replaced by an adaptive output.
static bool process_adaptive_key(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed || get_repeat_key_count()) return true;
    uint16_t key = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count == 0) { // Held as a modifier, not a letter.
            adaptive_prev = KC_NO;
            return true;
        }
        key = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    const uint16_t prev    = adaptive_prev;
    const bool     in_time = TIMER_DIFF_16(record->event.time, adaptive_prev_time) < ADAPTIVE_TERM;
    adaptive_prev          = key;
    adaptive_prev_time     = record->event.time;
    if (!in_time || (get_mods() & ~MOD_MASK_SHIFT)) return true;

    for (uint8_t i = 0; i < ARRAY_SIZE(adaptive_keys); i++) {
        if (adaptive_keys[i].first == prev && adaptive_keys[i].trigger == key) {
            const uint16_t out = adaptive_keys[i].output;
            tap_code16(is_caps_word_on() ? LSFT(out) : out);
            set_last_keycode(out); // Repeat key repeats the output.
            adaptive_prev = out;
            return false;
        }
    }
    return true;
}

// Training hint: blink the underglow when a pair was typed the long way
// instead of with its roll, H combo or the Repeat key. Only the produced
// pair is checked, so roll triggers (px, ae...) never blink.
#define MISS_WINDOW_MS 1000 // Pairs further apart than this aren't flagged.
#define MISS_FLASH_MS 250

static const uint16_t missed_pairs[][2] = {
    {KC_P, KC_L}, {KC_A, KC_U}, {KC_N, KC_L}, // rolls
    {KC_T, KC_H}, {KC_C, KC_H}, {KC_S, KC_H}, {KC_W, KC_H}, {KC_P, KC_H}, {KC_G, KC_H}, // H combos
};

// Pairs never flagged. Doubles listed here won't ask for the Repeat key.
static const uint16_t miss_exceptions[][2] = {
    {KC_R, KC_R}, // R and Repeat share the left thumb, so Repeat doesn't help.
};

static bool is_letter(uint16_t key) {
    return (key >= KC_A && key <= KC_Z) || key == KC_LBRC || key == KC_QUOT || key == KC_SCLN; // + å ä ö
}

// Left outer thumb: mute miss warnings (blink + host ting) for 30 minutes;
// press again to unmute early.
#define MISS_MUTE_MS (30UL * 60 * 1000)
static deferred_token miss_mute_token = INVALID_DEFERRED_TOKEN;

static uint32_t miss_mute_end(uint32_t trigger_time, void *cb_arg) {
    miss_muted      = false;
    miss_mute_token = INVALID_DEFERRED_TOKEN;
    set_layer_color(get_highest_layer(layer_state));
    return 0;
}

static void toggle_miss_mute(void) {
    cancel_deferred_exec(miss_mute_token);
    miss_mute_token = INVALID_DEFERRED_TOKEN;
    miss_muted      = !miss_muted;
    if (miss_muted) miss_mute_token = defer_exec(MISS_MUTE_MS, miss_mute_end, NULL);
    set_layer_color(get_highest_layer(layer_state));
}

// While muted, only the mute key itself is red (drawn over the layer colour).
bool rgb_matrix_indicators_user(void) {
    if (!miss_muted || miss_flashing) return true;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led = g_led_config.matrix_co[row][col];
            if (led == NO_LED) continue;
            if (keymap_key_to_keycode(0, (keypos_t){.row = row, .col = col}) == CKC_MUTE) {
                rgb_matrix_set_color(led, RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);
            }
        }
    }
    return true;
}

static uint32_t miss_flash_end(uint32_t trigger_time, void *cb_arg) {
    miss_flashing = false;
    set_layer_color(get_highest_layer(layer_state));
    return 0;
}

// Typing stats for the host (corne-miss-beep logs them; `corne-accuracy`
// summarises). Counts only, never which keys. Report: 'Q' 'S', then
// keystrokes, backspaces, misses as little-endian uint16, since the last report.
#define STATS_BATCH 50
static uint16_t stat_keys = 0, stat_bsp = 0, stat_miss = 0;

static void stats_flush(void) {
    if (!stat_keys && !stat_bsp && !stat_miss) return;
    uint8_t report[32] = {'Q', 'S', stat_keys & 0xFF, stat_keys >> 8, stat_bsp & 0xFF, stat_bsp >> 8, stat_miss & 0xFF, stat_miss >> 8};
    raw_hid_send(report, sizeof(report));
    stat_keys = stat_bsp = stat_miss = 0;
}

// Count a typing keystroke or a backspace (Ctrl+Backspace counts once).
static void count_keystroke(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return;
    if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && record->tap.count == 0) return; // held
    if (IS_QK_MOMENTARY(keycode) || IS_QK_TO(keycode) || keycode == KC_HYPR || keycode == CKC_MUTE) return;
    if (get_mods() & ~MOD_MASK_SHIFT) return; // shortcuts aren't typing
    if (keycode == CKC_C_BSP || keycode == KC_BSPC) {
        stat_bsp++;
    } else {
        stat_keys++;
    }
    if (stat_keys + stat_bsp >= STATS_BATCH) stats_flush();
}

static void flash_miss(void) {
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    stat_miss++; // Still counted while muted.
    if (miss_muted) return;
    cancel_deferred_exec(token);
    miss_flashing = true;
    rgb_matrix_sethsv_noeeprom(0, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS); // red
    // Tell the host too: the corne-miss-beep user service plays a soft beep.
    // Report: 'Q' 'M' 0x01 (miss), rest zero. Costs at most ~10 ms if nothing reads it.
    uint8_t report[32] = {'Q', 'M', 0x01};
    raw_hid_send(report, sizeof(report));
    token = defer_exec(MISS_FLASH_MS, miss_flash_end, NULL);
}

// Call on every press that wasn't swallowed by an adaptive key.
static void check_missed_shortcut(uint16_t keycode, keyrecord_t *record) {
    static uint16_t prev      = KC_NO;
    static uint16_t prev_time = 0;
    if (!record->event.pressed) return;

    uint16_t key = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count == 0) return; // Held as a modifier.
        key = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }
    if (keycode >= CKC_GH && keycode <= CKC_PH) { // H combo: used correctly, ends in h.
        prev      = KC_H;
        prev_time = record->event.time;
        return;
    }

    const uint16_t first  = prev;
    const bool     recent = TIMER_DIFF_16(record->event.time, prev_time) < MISS_WINDOW_MS;
    prev_time             = record->event.time;

    // Repeat key, shortcuts (Ctrl/Alt/GUI held) and other layers aren't typing,
    // so they neither warn nor count as the first half of a pair (Ctrl+S, s).
    if (get_repeat_key_count() || (get_mods() & ~MOD_MASK_SHIFT) || get_highest_layer(layer_state) != 0) {
        prev = KC_NO;
        return;
    }
    prev = (is_letter(key) || key == KC_H) ? key : KC_NO;
    if (first == KC_NO || !recent || !is_letter(key)) return;

    for (uint8_t i = 0; i < ARRAY_SIZE(miss_exceptions); i++) {
        if (miss_exceptions[i][0] == first && miss_exceptions[i][1] == key) return;
    }
    bool missed = first == key; // A double that Repeat could have typed.
    for (uint8_t i = 0; !missed && i < ARRAY_SIZE(missed_pairs); i++) {
        missed = missed_pairs[i][0] == first && missed_pairs[i][1] == key;
    }
    if (missed) flash_miss();
}

// Left inner thumb: hold for layer 1, tap for Repeat. Repeat sits on the left
// thumb (next to R), not beside Space, so words ending in a double letter
// don't become a same-thumb Repeat+Space pair. KC_F24 is a placeholder.
#define LT_REP LT(1, KC_F24)

// The tapped LT_REP must not become the "last key" itself.
bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    return keycode != LT_REP && keycode != CKC_MUTE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // On every key event, start or extend the deferred execution to call
    // `idle_callback()` after IDLE_TIMEOUT_MS.
    static deferred_token idle_token = INVALID_DEFERRED_TOKEN;
    if (!extend_deferred_exec(idle_token, IDLE_TIMEOUT_MS)) {
        idle_token = defer_exec(IDLE_TIMEOUT_MS, idle_callback, NULL);
    }

    if (keycode == LT_REP && record->tap.count) {
        repeat_key_invoke(&record->event); // Re-enters with the repeated key.
        return false;
    }

    count_keystroke(keycode, record);

    if (!process_adaptive_key(keycode, record)) {
        return false;
    }
    check_missed_shortcut(keycode, record);

    if (record->tap.count == 1 && !record->event.pressed) {
        // Go to base layer if modtap char is typed
        switch (keycode) {
            case LGUI_T(KC_C):
            case LALT_T(KC_S):
            case LCTL_T(KC_N):
            case LSFT_T(KC_T):
            case RSFT_T(KC_A):
            case RCTL_T(KC_E):
            case RALT_T(KC_I):
            case RGUI_T(KC_H):
                layer_clear();
        }
    }

    if (record->event.pressed) {
        // Go to base layer if char is typed
        switch (keycode) {
            case KC_A ... KC_Z:
            case SE_ODIA:
            case SE_ADIA:
            case SE_ARNG:
            case SE_MINS:
            case CKC_GH ... CKC_PH:
            case SE_UNDS:
                layer_clear();
        }
    }

    // Shift + % combo -> ~ (Swedish ~ is a dead key, so follow with space).
    static bool tilde_sent = false;
    if (keycode == SE_PERC) {
        if (record->event.pressed && (get_mods() & MOD_MASK_SHIFT)) {
            const uint8_t mods = get_mods();
            del_weak_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16(SE_TILD);
            tap_code(KC_SPC);
            set_mods(mods);
            tilde_sent = true;
            return false;
        }
        if (!record->event.pressed && tilde_sent) {
            tilde_sent = false; // Swallow release so held Shift isn't dropped.
            return false;
        }
    }

    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CKC_HOME:
            if (record->event.pressed) {
                reset_keyboard_state();
            }
            return false;
        case CKC_MUTE:
            if (record->event.pressed) {
                toggle_miss_mute();
            }
            return false;
        case CKC_E_SL:
            // Tap: /. Hold: Esc, sent by housekeeping_task_user as soon as
            // TAPPING_TERM passes, so it doesn't wait for the release.
            if (record->event.pressed) {
                e_sl_timer = timer_read();
                e_sl_held  = true;
                e_sl_esc   = false;
            } else {
                if (e_sl_held && !e_sl_esc) {
                    tap_code16(SE_SLSH);
                }
                e_sl_held = false;
            }
            return false; // We handled this keypress
        case CKC_C_BSP:
            // Check if c Control is held down
            if (get_mods() & (MOD_BIT(KC_LEFT_CTRL) | MOD_BIT(KC_RIGHT_CTRL))) {
                if (record->event.pressed) {
                    // Send Backspace if Control is held
                    const uint8_t mods = get_mods();
                    del_weak_mods(MOD_MASK_CTRL);
                    del_oneshot_mods(MOD_MASK_CTRL);
                    unregister_mods(MOD_MASK_CTRL);
                    register_code(KC_BSPC);
                    set_mods(mods);
                } else {
                    unregister_code(KC_BSPC);
                }

            } else {
                if (record->event.pressed) {
                    // Send LCTRL(Backspace) if no Control is held
                    register_mods(MOD_BIT(KC_LEFT_CTRL));
                    register_code(KC_BSPC);
                    unregister_mods(MOD_BIT(KC_LEFT_CTRL));
                } else {
                    unregister_code(KC_BSPC);
                }
            }
            return false; // Skip further processing of this key
        case CKC_GH:
            if (record->event.pressed) {
                send_h_bigram(KC_G);
            }
            break;
        case CKC_TH:
            if (record->event.pressed) {
                send_h_bigram(KC_T);
            }
            break;
        case CKC_CH:
            if (record->event.pressed) {
                send_h_bigram(KC_C);
            }
            break;
        case CKC_SH:
            if (record->event.pressed) {
                send_h_bigram(KC_S);
            }
            break;
        case CKC_WH:
            if (record->event.pressed) {
                send_h_bigram(KC_W);
            }
            break;
        case CKC_PH:
            if (record->event.pressed) {
                send_h_bigram(KC_P);
            }
            break;
    }
    return true;
};

// --- Home-row mod tuning ---------------------------------------------------

static bool is_shift_mod_tap(uint16_t keycode) {
    return keycode == LSFT_T(KC_T) || keycode == RSFT_T(KC_A);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return is_shift_mod_tap(keycode) ? 175 : TAPPING_TERM;
}

// Split board: the first half of the matrix rows is the left hand.
char chordal_hold_handedness(keypos_t key) {
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

// The layer/Repeat thumb must hold with left-hand keys too (layer 1 spans both).
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    if (tap_hold_keycode == LT_REP) return true;
    return get_chordal_hold_default(tap_hold_record, other_record);
}

// Letters (incl. å ä ö), space and punctuation count as "typing" for Flow Tap.
static bool is_typing_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_LBRC: // å
        case KC_QUOT: // ä
        case KC_SCLN: // ö
        case KC_DOT:
        case KC_COMM:
        case KC_SLSH:
            return true;
    }
    return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    // Never for Shift: a capital right after a fast space must still work.
    if (is_shift_mod_tap(keycode)) return 0;
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) return 0; // hotkeys
    return is_typing_key(keycode) && is_typing_key(prev_keycode) ? FLOW_TAP_TERM : 0;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // All Mod-Tap/Layer-Tap/Momentary keys is tap-only
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case SE_ODIA:
        case SE_ADIA:
        case SE_ARNG:
        case CKC_GH ... CKC_PH:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case SE_MINS: // Unshifted: custom shift keys would turn a shifted - into +.
        case SE_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_VOLU, KC_X, KC_G, KC_M, KC_P, KC_J, SE_QUOT, KC_COMMA, KC_DOT, SE_SCLN, CKC_E_SL, KC_BRIU,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_MUTE, LGUI_T(KC_C), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), KC_K, KC_LBRC, RSFT_T(KC_A), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_H), KC_PRINT_SCREEN,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_VOLD, KC_W, KC_F, KC_L, KC_D, KC_V, KC_SCLN, KC_U, KC_O, KC_Y, KC_B, KC_BRID,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                  CKC_MUTE, KC_R, LT_REP, KC_HYPR, KC_SPACE, CKC_C_BSP
                                                                  //`--------------------------------------------'  `--------------------------------------------'
                                                                  ),
                                                              [1] = LAYOUT_split_3x6_3(
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_F2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, LGUI_T(KC_8), LALT_T(KC_9), LCTL_T(KC_2), LSFT_T(KC_3), KC_4, KC_5, RSFT_T(KC_1), RCTL_T(KC_0), RALT_T(KC_6), RGUI_T(KC_7), KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                                                  //`--------------------------------------------'  `--------------------------------------------'
                                                                  ),
                                                              [2] = LAYOUT_split_3x6_3(
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_UP, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_DOWN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                                                  //`--------------------------------------------'  `--------------------------------------------'
                                                                  ),
                                                              [3] = LAYOUT_split_3x6_3(
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_WHLU, KC_TRNS, MS_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN2, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------|                                |--------------+--------------+--------------+---------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  // |--------------+--------------+--------------+---------------+--------------+--------------+--------------|  |--------------+--------------+--------------+---------------+--------------+--------------+--------------|
                                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN3
                                                                  //`--------------------------------------------'  `--------------------------------------------'
                                                                  )};
