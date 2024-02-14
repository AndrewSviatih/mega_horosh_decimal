#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  double temp = 0.0;

  if (!dst) {
    error = 1;
  } else {
    for (int i = 0; i < 96; i++) {
      temp += s21_get_bit(src, i) * pow(2, i);
    }

    int scale = s21_get_scale(src);
    if (scale < 0 || scale > 28) {
      error = 1;
    } else {
      temp *= pow(10, -scale);

      if (s21_get_bit(src, 127)) temp = temp * (-1);
      *dst = temp;
    }
  }
  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_zero_decimal(dst);
  int error = 0;

  if (!dst) {
    error = 1;
  } else {
    if (src < 0) {
      s21_swap_sign(dst);
      src *= -1;
    }
    if (src > INT_MAX)
      error = 1;
    else
      dst->bits[0] = src;
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;

  if (!dst) {
    error = 1;
  } else {
    int scale = s21_get_scale(src);

    if (src.bits[1] || src.bits[2] || scale < 0 || scale > 28) {
      error = 1;
    } else {
      *dst = src.bits[0];
      if (scale > 0 && scale <= 28) {
        *dst /= pow(10, scale);
      }
      if (s21_get_bit(src, 127)) *dst = *dst * (-1);
    }
  }
  return error;
}

int s21_from_decimal_to_double(s21_decimal src, long double *dst) {
  int error = 0;
  long double temp = (double)*dst;

  if (!dst) {
    error = 1;
  } else {
    for (int i = 0; i < 96; i++) {
      temp += s21_get_bit(src, i) * pow(2, i);
    }

    temp = temp * pow(10, -s21_get_scale(src));
    if (s21_get_bit(src, 127)) temp = temp * (-1);
    *dst = temp;
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_zero_decimal(dst);
  int error = 0;

  if (isinf(src) || isnan(src)) {
    error = 1;
  } else {
    if (src != 0) {
      int exp = GET_EXP(src);
      if (exp < -94 || exp > 96) {
        error = 1;
      } else {
        double temp = (double)fabs(src);
        int i = 0;
        temp = s21_normalize_28_signs(temp, &i);
        if (i <= 28) {
          temp = round(temp);
          long long intPart = (long long)temp;
          dst->bits[0] = intPart & 0xFFFFFFFF;
          dst->bits[1] = (intPart >> 32) & 0xFFFFFFFF;
          dst->bits[3] |= i << 16;
          if (signbit(src)) s21_swap_sign(dst);
        }
      }
    }
  }
  return error;
}