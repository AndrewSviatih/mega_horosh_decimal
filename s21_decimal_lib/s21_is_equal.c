#include <stdlib.h>

#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int result = 1;
  s21_decimal temp1, temp2;
  int bit_1 = 0;
  int bit_2 = 0;
  if (s21_get_scale(a) <= s21_get_scale(b)) {
    temp1 = a;
    temp2 = b;
  } else {
    temp1 = b;
    temp2 = a;
  }
  int tmp_razn = s21_get_scale(temp1) - s21_get_scale(temp2);
  for (int i = 95; i >= tmp_razn && result == 1; i--) {
    if (i < 0) {
      bit_1 = 0;
    } else {
      bit_1 = s21_get_bit(temp1, i);
    }
    if (i - tmp_razn > 95) {
      bit_2 = 0;
    } else {
      bit_2 = s21_get_bit(temp2, i - tmp_razn);
    }
    if (bit_1 != bit_2) {
      result = 0;
    }
  }

  return result;
}