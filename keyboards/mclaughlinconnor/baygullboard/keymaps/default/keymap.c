#include QMK_KEYBOARD_H
#include "keymap_steno.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_8(
        KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,              KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_BSPC,
        KC_ESC,      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,              KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,
        KC_NUBS,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,              KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     KC_NUHS,
                                  MO(1),       KC_LSFT,     KC_SPC,      KC_LCTL,           KC_RCTL,     KC_BSPC,     KC_RSFT,     MO(2),
                                                            KC_LGUI,     KC_LALT,           KC_ENT,      KC_BSPC
        ),
    [1] = LAYOUT_split_3x6_8(
        KC_NO,       S(KC_1),     S(KC_2),     S(KC_3),     S(KC_4),     S(KC_5),           S(KC_6),     S(KC_7),     S(KC_8),     S(KC_9),     S(KC_0),     KC_NO,
        KC_NO,       KC_1,        KC_2,        KC_3,        KC_4,        KC_5,              KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_NO,
        KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,             KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,
                                  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_NO,
                                                            KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS
    ),
    [2] = LAYOUT_split_3x6_8(
        KC_GRAVE,    KC_LBRC,     KC_RBRC,     S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,           KC_NO,       S(KC_LBRC),  S(KC_RBRC),  KC_LBRC,     KC_RBRC,     KC_NO,
        KC_NO,       KC_TRNS,     KC_MINS,     S(KC_EQL),   KC_EQL,      KC_TRNS,           KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    KC_TRNS,     QK_REBOOT,
        DF(3),       KC_TRNS,     KC_TRNS,     KC_TRNS,     S(KC_MINS),  KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     CG_TOGG,
                                  KC_TRNS,     KC_LCTL,     KC_TRNS,     KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_NO,
                                                            KC_TRNS,     KC_CAPS,           KC_TRNS,     KC_TRNS
    ),
    [3] = LAYOUT_split_3x6_8(
        STN_N1,      STN_N2,      STN_N3,      STN_N4,      STN_N5,      STN_N6,            STN_N7,      STN_N8,      STN_N9,      STN_NA,      STN_NB,      STN_NC,
        KC_NO,       STN_S1,      STN_TL,      STN_PL,      STN_HL,      STN_ST1,           STN_ST3,     STN_FR,      STN_PR,      STN_LR,      STN_TR,      STN_DR,
        DF(0),       STN_S2,      STN_KL,      STN_WL,      STN_RL,      STN_ST2,           STN_ST4,     STN_RR,      STN_BR,      STN_GR,      STN_SR,      STN_ZR,
                                  KC_NO,       STN_A,       STN_O,       KC_NO,             KC_NO,       STN_E,       STN_U,       KC_NO,
                                                            KC_NO,       KC_NO,             KC_NO,       KC_NO
  )
};

// Add double tap keys to go to weird layers like Vim or F keys
// Could also add layer switches to number layer so two keys are required to be pressed in a certain order
//   Use escape to go back again
