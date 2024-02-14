#include "s21_decimal.h"

int s21_floor(s21_decimal number, s21_decimal *result) {
  if (!s21_truncate(number, s21_set_zeroes(result)) && s21_get_sign(number) &&
      !s21_is_equal(*result, number))
    s21_sub(*result, ((s21_decimal){{BIT_ONE, BIT_NONE, BIT_NONE, BIT_NONE}}),
            result);
  return OK;
}

int s21_round(s21_decimal number, s21_decimal *result) {
  if (!s21_truncate(number, result) && !s21_is_equal(number, *result)) {
    if (s21_get_sign(number))
      s21_sub(number, ((s21_decimal){{5, BIT_NONE, BIT_NONE, 65536}}), &number);
    else
      s21_add(number, ((s21_decimal){{5, BIT_NONE, BIT_NONE, 65536}}), &number);
    s21_truncate(number, result);
  }
  return 0;
}

int s21_truncate(s21_decimal number, s21_decimal *result) {
  int err = OK;
  if (s21_copy(result, number) == OK) {
    if (s21_set_zeroes(&result) == OK) {
      if (s21_get_scale(number)) {
        s21_set_scale(&number, s21_get_scale(number));
      }
      s21_copy(result, number);
    }
  } else {
    err = ANY_ERROR;
  }
  return OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = OK;
  if (s21_copy(result, value) == OK) {
    if (s21_get_sign(value)) {
      s21_set_sign(result, 0);
    } else {
      s21_set_sign(result, 1);
    }
  } else {
    error = ANY_ERROR;
  }
  return error;
}

void s21_set_sign(s21_decimal *number, int sign) {
  s21_set_bit(number, SIGN_INDEX, sign);
}

int s21_copy(s21_decimal *to, s21_decimal from) {
  int error = OK;
  if (to == NULL) {
    error = ANY_ERROR;
  } else {
    for (int i = 0; i < S21_DEC_BIT_LEN; i++) {
      to->bits[i] = from.bits[i];
    }
  }
  return error;
}

int s21_set_zeroes(s21_decimal *number) {
  int error = OK;
  if (number == NULL) {
    error = ANY_ERROR;
  } else {
    for (int i = 0; i < S21_DEC_BIT_LEN; i++) number->bits[i] = 0;
  }
  return error;
}

s21_decimal *s21_decrease_scale(s21_decimal *number, int by) {
  for (int y = 0; y < by; y += 1) {
    unsigned long long overflow = number->bits[2];
    for (int x = 2; x >= 0; x -= 1) {
      number->bits[x] = overflow / 10;
      overflow =
          (overflow % 10) * (4294967295 + 1) + number->bits[x ? x - 1 : x];
    }
  }
  s21_set_scale(number, (s21_get_scale(*number) - by));
  return number;
}

// int s21_get_pow(s21_decimal number) {
//   int res = 0;
//   for (int i = 16; i <= 23; i++) {
//     res += s21_get_bit(number, 96 + i) * ((int)pow(2, i - 16));
//   }
//   return res;
// }