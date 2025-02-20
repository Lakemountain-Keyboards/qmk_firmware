#pragma once

#include "quantum.h"

#define LAYOUT_60( \
  LA1, LA2, LA3, LA4, LA5, LA6, LA7, RA1, RA2, RA3, RA4, RA5, RA6,      RA8, \
  LB1, LB2, LB3, LB4, LB5, LB6,      RB1, RB2, RB3, RB4, RB5, RB6, RB7,      \
  LC1, LC2, LC3, LC4, LC5, LC6,      RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD1, RD2, RD3, RD4, RD5,      RD7, RD8, \
  LE1, LE2, LE3, LE4,      LE6,           RE2,      RE4, RE5, RE6, RE7, RE8  \
  ) \
  { \
    { LA1,   LA2,   LA3,   LA4,   LA5,   LA6,   LA7,   KC_NO, KC_NO }, \
    { LB1,   LB2,   LB3,   LB4,   LB5,   LB6,   KC_NO, KC_NO, KC_NO }, \
    { LC1,   LC2,   LC3,   LC4,   LC5,   LC6,   KC_NO, KC_NO, KC_NO }, \
    { LD1,   LD2,   LD3,   LD4,   LD5,   LD6,   LD7,   KC_NO, KC_NO }, \
    { LE1,   LE2,   LE3,   LE4,   KC_NO, LE6,   KC_NO, KC_NO, KC_NO }, \
    { RA1,   RA2,   RA3,   RA4,   RA5,   RA6,   KC_NO, RA8,   KC_NO }, \
    { RB1,   RB2,   RB3,   RB4,   RB5,   RB6,   RB7,   KC_NO, KC_NO }, \
    { RC1,   RC2,   RC3,   RC4,   RC5,   RC6,   RC7,   RC8,   KC_NO }, \
    { RD1,   RD2,   RD3,   RD4,   RD5,   KC_NO, RD7,   RD8,   KC_NO }, \
    { KC_NO, RE2,   KC_NO, RE4,   RE5,   RE6,   RE7,   RE8,   KC_NO }  \
  }

#define LAYOUT_65( \
  LA1, LA2, LA3, LA4, LA5, LA6, LA7, RA1, RA2, RA3, RA4, RA5, RA6,      RA8, RA9, \
  LB1, LB2, LB3, LB4, LB5, LB6,      RB1, RB2, RB3, RB4, RB5, RB6, RB7,      RB9, \
  LC1, LC2, LC3, LC4, LC5, LC6,      RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, RC9, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, RD1, RD2, RD3, RD4, RD5,      RD7, RD8, RD9, \
  LE1, LE2, LE3, LE4,      LE6,           RE2,      RE4, RE5, RE6, RE7, RE8, RE9 \
  ) \
  { \
    { LA1,   LA2,   LA3,   LA4,   LA5,   LA6,   LA7,   KC_NO, KC_NO }, \
    { LB1,   LB2,   LB3,   LB4,   LB5,   LB6,   KC_NO, KC_NO, KC_NO }, \
    { LC1,   LC2,   LC3,   LC4,   LC5,   LC6,   KC_NO, KC_NO, KC_NO }, \
    { LD1,   LD2,   LD3,   LD4,   LD5,   LD6,   LD7,   KC_NO, KC_NO }, \
    { LE1,   LE2,   LE3,   LE4,   KC_NO, LE6,   KC_NO, KC_NO, KC_NO }, \
    { RA1,   RA2,   RA3,   RA4,   RA5,   RA6,   KC_NO, RA8,   RA9 }, \
    { RB1,   RB2,   RB3,   RB4,   RB5,   RB6,   RB7,   KC_NO, RB9 }, \
    { RC1,   RC2,   RC3,   RC4,   RC5,   RC6,   RC7,   RC8,   RC9 }, \
    { RD1,   RD2,   RD3,   RD4,   RD5,   KC_NO, RD7,   RD8,   RD9 }, \
    { KC_NO, RE2,   KC_NO, RE4,   RE5,   RE6,   RE7,   RE8,   RE9 } \
  }
