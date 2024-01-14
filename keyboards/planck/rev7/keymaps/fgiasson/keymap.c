/* Copyrigh
t 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _PLOVER, /*_ADJUST*/, _EMACS };

enum planck_keycodes { QWERTY = SAFE_RANGE, COLEMAK, DVORAK, PLOVER, BACKLIT, EXT_PLV };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


enum custom_keycodes {
    VIM_SEL_QUOTE = SAFE_RANGE + 101,
    VIM_SEL_DOUBLE_QUOTES = SAFE_RANGE + 102,
    VIM_SEL_PARENTHESES = SAFE_RANGE + 103,
    VIM_SEL_BRACKETS = SAFE_RANGE + 104,
    VIM_SEL_CURLY_BRACKETS = SAFE_RANGE + 105,
    VIM_SEL_ANGLE_BRACKETS = SAFE_RANGE + 106,
    VIM_MOVE_WINDOW_SWITCH = SAFE_RANGE + 107,
    VIM_SPLIT_WINDOW_HORIZONTALLY = SAFE_RANGE + 108,
    VIM_SPLIT_WINDOW_VERTICALLY = SAFE_RANGE + 109,
    VIM_WINDOW_QUIT = SAFE_RANGE + 110,
    VIM_WINDOW_CLOSE_OTHERS = SAFE_RANGE + 111,
    VIM_NORMAL_MODE_ENTER = SAFE_RANGE + 112,
    EMACS_DISTRATION_FREE = SAFE_RANGE + 113,
    EMACS_SWAP_BUFFERS = SAFE_RANGE + 114,
    ORG_INSERT_DATE = SAFE_RANGE + 115,
    ORG_INSERT_PAGE_REF = SAFE_RANGE + 116,
    EMACS_DAP_START_DEBUGGER = SAFE_RANGE + 117,
    EMACS_DAP_CONTINUE = SAFE_RANGE + 118,
    EMACS_DAP_TOGGLE_BREAKPOINT = SAFE_RANGE + 119,
    EMACS_DAP_NEXT = SAFE_RANGE + 120,
    EMACS_DAP_DISCONNECT = SAFE_RANGE + 121,
    EMACS_DAP_STEP_OUT = SAFE_RANGE + 122,
    EMACS_DAP_STEP_IN = SAFE_RANGE + 123,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_RSFT, KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [_ADJUST] = LAYOUT_planck_grid( */
/*     _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL , */
/*     _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______, */
/*     _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/*                                ), */


/* Emacs (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |W-Quit|D Free|      |      |      |      |      |+P Ref|      |      |KC_DEL|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |S Buff|+ Date|      |      |SWinH |      |DAP D |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |DAP C |SWinV |DAP B |DAP N |      |      |      |      |NM Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EMACS] = LAYOUT_planck_grid(
                               _______, VIM_WINDOW_QUIT, EMACS_DISTRATION_FREE, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
                               _______, _______, EMACS_SWAP_BUFFERS, ORG_INSERT_DATE, _______, _______, VIM_SPLIT_WINDOW_HORIZONTALLY, _______, EMACS_DAP_DISCONNECT, _______, _______, _______,
                               _______, _______, _______, EMACS_DAP_CONTINUE, VIM_SPLIT_WINDOW_VERTICALLY, EMACS_DAP_TOGGLE_BREAKPOINT, EMACS_DAP_NEXT, _______, _______, _______, _______, VIM_NORMAL_MODE_ENTER,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, /*_ADJUST*/ _EMACS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                /* layer_off(_ADJUST); */
                layer_off(_EMACS);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
        case VIM_MOVE_WINDOW_SWITCH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("w");
            }
            break;
        case VIM_SPLIT_WINDOW_HORIZONTALLY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("s");
            }
            break;
        case VIM_SPLIT_WINDOW_VERTICALLY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("v");
            }
            break;
        case VIM_WINDOW_QUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("q");
            }
            break;
        case VIM_WINDOW_CLOSE_OTHERS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("w"));
                SEND_STRING("o");
            }
            break;
        case VIM_SEL_QUOTE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi'"); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_SEL_DOUBLE_QUOTES:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi\""); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_SEL_PARENTHESES:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi("); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_SEL_BRACKETS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi["); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_SEL_CURLY_BRACKETS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi{"); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_SEL_ANGLE_BRACKETS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("vi<"); // enter VISUAL mode, select everything between the next quotes
            }
            break;
        case VIM_NORMAL_MODE_ENTER:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("i"); // go in insert mode
                SEND_STRING(SS_TAP(X_ENTER)); // press Enter
                SEND_STRING(SS_TAP(X_ESC)); // go back to NORMAL mode
            }
            break;
        case EMACS_DISTRATION_FREE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("wcC");
            }
            break;
        case EMACS_SWAP_BUFFERS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("X"));
                SEND_STRING("/");
            }
            break;
        case ORG_INSERT_DATE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(",dt");
            }
            break;
        case ORG_INSERT_PAGE_REF:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING("aori");
            }
            break;
        case EMACS_DAP_START_DEBUGGER:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("di");
            }
            break;
        case EMACS_DAP_CONTINUE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("dc");
            }
            break;
        case EMACS_DAP_TOGGLE_BREAKPOINT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("dbb");
            }
            break;
        case EMACS_DAP_NEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("ds");
            }
            break;
        case EMACS_DAP_DISCONNECT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("da");
            }
            break;
        case EMACS_DAP_STEP_OUT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("do");
            }
            break;
        case EMACS_DAP_STEP_IN:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC)); // make sure we are in NORMAL mode
                SEND_STRING(SS_TAP(X_SPACE));
                SEND_STRING("di");
            }
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                /* layer_on(_ADJUST); */
                layer_on(_EMACS);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                /* layer_off(_ADJUST); */
                layer_off(_EMACS);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
