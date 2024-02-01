#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {

  double temp = (double)*dst;

  for (int i = 0; i < 96; i++) {
    temp += s21_get_bit(src, temp);
  }

  printf("%lf", temp);
  return temp;
}

int main () {

  s21_decimal src = {0};
  int err = 0;

  float num = 2.567;
  int decimal = 12434;

  err = s21_from_decimal_to_float(src, &num);

  return 0;
}