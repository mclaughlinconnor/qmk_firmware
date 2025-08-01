#include "keymap_steno.h"
#include "qmk-vim/src/vim.h"
#include QMK_KEYBOARD_H
#include "print.h"
#include "sendstring_uk.h"

// Mouse jiggler
// https://www.reddit.com/r/olkb/comments/t4imri/comment/hz2w67i/?context=3
bool no_sleep_enabled = false;
static uint16_t no_sleep_timer;

void no_sleep_enable(void) {
  no_sleep_timer = timer_read();
  no_sleep_enabled = !no_sleep_enabled;
}

enum custom_keycodes {
    NO_SLEEP = SAFE_RANGE,
    VIM_TOG,
    MERGE,
    STAGING,
    DEPLOY,
};

enum layers {
    _QWERTY = 0,
    _NUM,
    _SYM,
    _NAV,
    _STENO,
};

#define SPC_NAV LT(_NAV, KC_SPC)
#define BSPC_SYM LT(_SYM, KC_BSPC)
#define SYSREQ LALT(KC_PSCR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_8(
        KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,              KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        S(KC_SCLN),
        KC_ESC,      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,              KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,
        KC_NUBS,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,              KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_NUHS,
                                  MO(1),       KC_LSFT,     KC_SPC,      KC_LCTL,           KC_RCTL,     BSPC_SYM,    KC_RSFT,     MO(2),
                                                            KC_LGUI,     KC_LALT,           KC_ENT,      KC_PSCR
        ),
    [_NUM] = LAYOUT_split_3x6_8(
        KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,            KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        MERGE,
        KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,             KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        STAGING,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     DEPLOY,
                                  _______,     _______,     _______,     _______,           _______,     _______,     VIM_TOG,     NO_SLEEP,
                                                            _______,     _______,           _______,     _______
    ),
    [_SYM] = LAYOUT_split_3x6_8(
        KC_GRAVE,    KC_LBRC,     KC_RBRC,     S(KC_LBRC),  S(KC_RBRC),  XXXXXXX,           S(KC_6),     S(KC_7),     S(KC_8),     S(KC_9),     S(KC_0),     XXXXXXX,
        KC_NO,       XXXXXXX,     KC_MINS,     S(KC_EQL),   KC_EQL,      XXXXXXX,           S(KC_1),     S(KC_2),     S(KC_3),     S(KC_4),     S(KC_5),     XXXXXXX,
        DF(3),       XXXXXXX,     XXXXXXX,     XXXXXXX,     S(KC_MINS),  XXXXXXX,           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     CG_TOGG,
                                  _______,     KC_LCTL,     _______,     _______,           _______,     _______,     _______,     _______,
                                                            _______,     KC_CAPS,           _______,     _______
    ),
    [_NAV] = LAYOUT_split_3x6_8(
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,           KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    XXXXXXX,     XXXXXXX,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,           XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
                                  _______,     _______,     _______,     _______,           _______,     _______,     _______,     KC_NO,
                                                            _______,     _______,           _______,     _______
    ),
    [_STENO] = LAYOUT_split_3x6_8(
        STN_N1,      STN_N2,      STN_N3,      STN_N4,      STN_N5,      STN_N6,            STN_N7,      STN_N8,      STN_N9,      STN_NA,      STN_NB,      STN_NC,
        KC_NO,       STN_S1,      STN_TL,      STN_PL,      STN_HL,      STN_ST1,           STN_ST3,     STN_FR,      STN_PR,      STN_LR,      STN_TR,      STN_DR,
        DF(0),       STN_S2,      STN_KL,      STN_WL,      STN_RL,      STN_ST2,           STN_ST4,     STN_RR,      STN_BR,      STN_GR,      STN_SR,      STN_ZR,
                                  KC_NO,       STN_A,       STN_O,       KC_NO,             KC_NO,       STN_E,       STN_U,       KC_NO,
                                                            KC_NO,       KC_NO,             KC_NO,       KC_NO
  )
};

#define COMBO_LEN 6

const uint16_t PROGMEM numbers_combo[] = {KC_RCTL, KC_ENT, COMBO_END};
combo_t key_combos[] = {
    COMBO(numbers_combo, MO(1))
};

// Add double tap keys to go to weird layers like Vim or F keys
// Could also add layer switches to number layer so two keys are required to be pressed in a certain order
//   Use escape to go back again

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }

    switch (keycode) {
        #if MACOS
        case BSPC_SYM:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LGUI)) {
                    unregister_code(KC_LGUI);
                    register_code(KC_LALT);
                    register_code(KC_BSPC);
                    unregister_code(KC_BSPC);
                    unregister_code(KC_LALT);
                    register_code(KC_LGUI);
                    return false;
                } else if (get_mods() & MOD_BIT(KC_LALT)) {
                    unregister_code(KC_LALT);
                    register_code(KC_LGUI);
                    register_code(KC_BSPC);
                    unregister_code(KC_BSPC);
                    unregister_code(KC_LGUI);
                    register_code(KC_LALT);
                    return false;
                }
            }
            break;
        #endif

        case NO_SLEEP:
            if (record->event.pressed) {
                no_sleep_enable();

                SEND_STRING("No sleep: ");

                if (no_sleep_enabled) {
                    SEND_STRING("on");
                } else {
                    SEND_STRING("off");
                }
            }
            return false;
        case VIM_TOG:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;

        case MERGE:
            if (record->event.pressed) {
                SEND_STRING("/approve \n/merge");
            }
            return false;
        case STAGING:
            if (record->event.pressed) {
                SEND_STRING("/unlabel ~\"under MR review\" \n/label ~\"Test on staging\" \n/close");
            }
            return false;
        case DEPLOY:
            if (record->event.pressed) {
                SEND_STRING("/unlabel ~\"under MR review\" \n/label ~\"Added to the deploy doc\" \n/close");
            }
            return false;
        default:
            return true;
    }

    return true;
}

// void keyboard_post_init_user(void) {
//     debug_enable=true;
//     debug_matrix=true;
//     debug_keyboard=true;
//     debug_mouse=true;
// }

void matrix_scan_user(void) {
    if (no_sleep_enabled && timer_elapsed(no_sleep_timer) > 59000) {
        SEND_STRING(SS_TAP(X_F13));
        no_sleep_timer = timer_read();
    };
}
