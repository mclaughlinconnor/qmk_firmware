// Copyright 2022 Connor McLaughlin (@mclaughlinconnor)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EE_HANDS

#define SOFT_SERIAL_PIN D2

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 10000

#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#define USB_SUSPEND_WAKEUP_DELAY 500

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
