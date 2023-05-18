// Copyright 2023 Rik (@6ooker)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROW_PINS { GP5, GP6, GP4 }
#define MATRIX_COL_PINS { GP27, GP26, GP24, GP25, GP20 }

#define DIODE_DIRECTION COL2ROW


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
