/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/select_word.h"

// Some useless macros to eventually delete
enum custom_keycodes {
    VIM_SEL_QUOTE = SAFE_RANGE + 100,
    VIM_SEL_QUOTE_I = SAFE_RANGE + 101,
    SELWORD = SAFE_RANGE + 102,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    switch (keycode) {
        case VIM_SEL_QUOTE:
            if (record->event.pressed) {
                SEND_STRING("l"); // Move one space to the right, this is to make sure that we can do it multiple times in a row
                SEND_STRING("/'");
                SEND_STRING(SS_TAP(X_ENTER));
                SEND_STRING("lvt'd");
            }
            break;
        case VIM_SEL_QUOTE_I:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("l"); // Move one space to the right, this is to make sure that we can do it multiple times in a row
                SEND_STRING("/'");
                SEND_STRING(SS_TAP(X_ENTER));
                SEND_STRING("lvt'di");
            }
            break;
    }
    return true;
};


// Some type dances for the party
// Tap Dance declarations
enum {
    TD_DOT_GT,
    TD_COMMA_LT,
    TD_SEMICOLON_COLON,
    TD_SLASH_QM,
    TD_QUOTE_DQUOTE,
    TD_BACKSLASH_PIPE,
    TD_LBRC_LCBR,
    TD_RBRC_RCBR,
    TD_PLUS_EQUAL,
    TD_MINUS_UNDERSCORE,
    TD_ZERO_CLOSEPAR,
    TD_NINE_OPENPAR,
    TD_EIGHT_ASTERISK,
    TD_SEVEN_AMPERSAND,
    TD_SIX_CARET,
    TD_FIVE_PERCENT,
    TD_FOUR_DOLLAR,
    TD_THREE_HASH,
    TD_TWO_AT,
    TD_ONE_EXCLAMATION,
    TD_BACKTICK_TILDE,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_DOT_GT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_GT),
    [TD_COMMA_LT] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_LT),
    [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_SLASH_QM] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION),
    [TD_QUOTE_DQUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_BACKSLASH_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BACKSLASH, KC_PIPE),
    [TD_LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_PLUS_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_MINUS_UNDERSCORE] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDS),
    [TD_ZERO_CLOSEPAR] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RIGHT_PAREN),
    [TD_NINE_OPENPAR] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LEFT_PAREN),
    [TD_EIGHT_ASTERISK] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTERISK),
    [TD_SEVEN_AMPERSAND] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPERSAND),
    [TD_SIX_CARET] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRCUMFLEX),
    [TD_FIVE_PERCENT] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERCENT),
    [TD_FOUR_DOLLAR] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DOLLAR),
    [TD_THREE_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
    [TD_TWO_AT] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
    [TD_ONE_EXCLAMATION] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXCLAIM),
    [TD_BACKTICK_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
};

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  MOUSE,
  ACCENTS,
  VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │Esc    ││F1     ││F2     ││F3     ││F4     ││F5     ││F6     ││F7     ││F8     ││F9     ││F10    ││F11    ││F12    ││Del    ││Mute   │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │`      ││1      ││2      ││3      ││4      ││5      ││6      ││7      ││8      ││9      ││0      ││-      ││=      ││Bksp   ││PgUp   │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │Tab    ││Q      ││W      ││E      ││R      ││T      ││Y      ││U      ││I      ││O      ││P      ││[      ││]      ││\      ││PgDn   │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │Caps   ││A      ││S      ││D      ││F      ││G      ││H      ││J      ││K      ││L      ││;      ││'      ││Enter           ││Home   │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │LShift          ││Z      ││X      ││C      ││V      ││B      ││N      ││M      ││,      ││.      ││/      ││RShift          ││Up     │
        └────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌────────────────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │LCtrl  ││LAlt   ││LGui   ││Space                                               ││Accents││Fn     ││Vim    ││Left   ││Down   ││Right  │
        └───────┘└───────┘└───────┘└────────────────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
    */

    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,             KC_MUTE,
        KC_GRAVE,   TD(TD_ONE_EXCLAMATION),     TD(TD_TWO_AT),     TD(TD_THREE_HASH),     TD(TD_FOUR_DOLLAR),     TD(TD_FIVE_PERCENT),     TD(TD_SIX_CARET),     TD(TD_SEVEN_AMPERSAND),     TD(TD_EIGHT_ASTERISK),     TD(TD_NINE_OPENPAR),     TD(TD_ZERO_CLOSEPAR),     TD(TD_MINUS_UNDERSCORE),  TD(TD_PLUS_EQUAL),   KC_BACKSPACE,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     TD(TD_LBRC_LCBR),  TD(TD_RBRC_RCBR),  TD(TD_BACKSLASH_PIPE),            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     TD(TD_SEMICOLON_COLON),  TD(TD_QUOTE_DQUOTE),            KC_ENT,             KC_HOME,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     TD(TD_COMMA_LT),  TD(TD_DOT_GT),   TD(TD_SLASH_QM),            SC_RSPC,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               LT(MOUSE, KC_SPC),                                 MO(ACCENTS),MO(MAC_FN),MO(VIM),  KC_LEFT,  KC_DOWN,  KC_RGHT),

    /*
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││Bri-   ││Bri+   ││M Ctrl ││L Pad  ││RGB -  ││RGB +  ││M Prev ││M Play ││M Next ││Mute   ││Vol -  ││Vol +  ││       ││RGB T  │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││BT H1  ││BT H2  ││BT H3  ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │RGB T  ││RGB Md ││RGB +  ││RGB H+ ││RGB S+ ││RGB Sp ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │       ││RGB RM ││RGB -  ││RGB H- ││RGB S- ││RGB Sp ││       ││       ││       ││       ││Play 2 ││MediaR ││                ││End    │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │                ││       ││       ││       ││       ││BatLvl ││NumLck ││       ││       ││Play 1 ││MediaR ││MediaS          ││       │
        └────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌────────────────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││                                                    ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└────────────────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
    */

    [MAC_FN] = LAYOUT_ansi_82(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            RGB_TOG,
        KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_PLY2,  DM_REC2,            KC_TRNS,            KC_END,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  DM_PLY1,  DM_REC1,            DM_RSTP,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            SC_RSPC,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                  MO(ACCENTS), MO(WIN_FN),MO(VIM),  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            RGB_TOG,
        KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_END,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    /*
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │Esc    ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││Mute   │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││Btn 1  ││Btn 2  ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││Left   ││Down   ││Up     ││Right  ││       ││       ││                ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐
        │                ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││                │
        └────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘
        ┌───────┐┌───────┐┌───────┐┌────────────────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││                                                    ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└────────────────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
    */

    [MOUSE] = LAYOUT_ansi_82(
        KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_MUTE,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MS_BTN1,  KC_MS_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_UP,  KC_MS_RIGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                               XXXXXXX,                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),


    /*
        Note: this layer only works when using the US International keybord

        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││SELWORD││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││                ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐
        │                ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││                │
        └────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘
        ┌───────┐┌───────┐┌───────┐┌────────────────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││                                                    ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└────────────────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
    */

    [ACCENTS] = LAYOUT_ansi_82(
        XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  SELWORD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                               XXXXXXX,                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    /*
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
        ┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐┌───────┐
        │       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││                ││       │
        └───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘└───────┘
        ┌────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌────────────────┐
        │                ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││       ││                │
        └────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘└────────────────┘
        ┌───────┐┌───────┐┌───────┐┌────────────────────────────────────────────────────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐┌───────┐
        │       ││       ││       ││                                                    ││       ││       ││       ││       ││       ││       │
        └───────┘└───────┘└───────┘└────────────────────────────────────────────────────┘└───────┘└───────┘└───────┘└───────┘└───────┘└───────┘
    */

    [VIM] = LAYOUT_ansi_82(
        KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            RGB_TOG,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                               KC_SPC,                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MOUSE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [ACCENTS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [VIM] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE
