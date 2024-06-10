// Copyright 2022 Connor McLaughlin (@mclaughlinconnor)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MACOS 1

#define SPLIT_WATCHDOG_TIMEOUT 5000
#define SPLIT_USB_TIMEOUT 1000
#define EE_HANDS
#define SOFT_SERIAL_PIN D2
#define SPLIT_USB_DETECT

#define MANUFACTURER    baygull
#define PRODUCT         seagull

#define MATRIX_ROWS 4 * 2  //double for split
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COLS 6
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3 }
#define MATRIX_COL_PINS_RIGHT { B3, B1, F7, F6, F5, F4 }

#define DIODE_DIRECTION COL2ROW

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Change?
#define BOOTMAGIC_LITE_ROW_RIGHT 5
#define BOOTMAGIC_LITE_COLUMN_RIGHT 6

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD

#define USE_VIM // comment this out to disable vim
#define BETTER_VISUAL_MODE // takes more space but behaves more like vim
#define VIM_I_TEXT_OBJECTS
#define VIM_A_TEXT_OBJECTS
#define VIM_G_MOTIONS
#define VIM_COLON_CMDS
#define VIM_PASTE_BEFORE
#define VIM_REPLACE
#define VIM_DOT_REPEAT
#define VIM_W_BEGINNING_OF_WORD
#define VIM_NUMBERED_JUMPS
#define ONESHOT_VIM

#if MACOS
  #define VIM_FOR_MAC
#endif
