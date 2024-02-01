#include <stdlib.h>

#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int result = 1;
  if (s21_get_sign(a) == s21_get_sign(a)) {
    for (int i = 95; i >= 0 && result == 1; i--) {
      if (s21_get_bit(a, i) != s21_get_bit(b, i)) {
        result = 0;
      }
    }
  } else {
    result = 0;
  }

  return result;
}