#include <stdlib.h>

#include "s21_decimal.h"

int s21_is_equal(s21_work_decimal a, s21_work_decimal b) {
  int result = 1;
  int sign1 = s21_get_sign(a.bits[6]);
  int sign2 = s21_get_sign(b.bits[6]);
  s21_set_sign(&a.bits[6], sign1);
  s21_set_sign(&b.bits[6], sign2);
  for (int i = 0; i < 7 && result; i++) {
    result = (a.bits[i] == b.bits[i]);
  }

  return result;
}