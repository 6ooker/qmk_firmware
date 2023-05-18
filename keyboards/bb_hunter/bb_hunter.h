#pragma once

#include "quantum.h"

#define LAYOUT_default(\
    k00,           k03, k04,\
    k10, k11, k12, k13, k14,\
    k20, k21, k22, k23, k24 \
) { \
    {k00, KC_NO, KC_NO, k03, k04}, \
    {k10, k11, k12, k13, k14}, \
    {k20, k21, k22, k23, k24} \
}
