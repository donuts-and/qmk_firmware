
#pragma once

#include "quantum.h"

// clang-format off
#define LAYOUT( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,\
  k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
	{ k00, k01, k02, k03, k04, k25, k05, k06, k07, k08, k09 }, \
	{ k10, k11, k12, k13, k14, k35, k15, k16, k17, k18, k19 }, \
	{ k20, k21, k22, k23, k24, k26, k25, k26, k27, k28, k29 }, \
	{ k30, k31, k32, k33, k34, k36, k37, k38, k39, k3a, k3b } \
}

#define LAYOUT_split_3x5_3( \
  k00, k01, k02, k03, k04,           k05, k06, k07, k08, k09, \
  k10, k11, k12, k13, k14,           k15, k16, k17, k18, k19, \
  k20, k21, k22, k23, k24,           k25, k26, k27, k28, k29,\
  k33, k34, k35, k36, k37, k38 \
) \
{ \
	{ k00,   k01,   k02, k03, k04, KC_NO, k05, k06, k07,   k08,   k09 }, \
	{ k10,   k11,   k12, k13, k14, KC_NO, k15, k16, k17,   k18,   k19 }, \
	{ k20,   k21,   k22, k23, k24, KC_NO, k25, k26, k27,   k28,   k29 }, \
	{ KC_NO, KC_NO, k33, k34, k35, KC_NO, k36, k37, k38, KC_NO, KC_NO } \
}
// clang-format on
