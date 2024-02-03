#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  double temp = *dst;

  if (!dst) {
    error = 1;
  } else {
    for (int i = 0; i < 96; i++) {
      temp += s21_get_bit(src, i) * pow(2, i);
    }

    int scale = s21_get_scale(src);
    temp *= pow(10, -scale);

    if (s21_get_bit(src, 127)) temp = temp * (-1);
    *dst = temp;
  }
  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_zero_decimal(dst);
  int error = 0;
  if (src < 0) {
    s21_set_sign(dst);
    src *= -1;
  }
  if (src > INT_MAX)
    error = 1;
  else
    dst->bits[0] = src;

  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {

  int error = 0;

  if (!dst) {
    error = 1;
  } else {  
    int scale = s21_get_scale(src);

    if (src.bits[1] || src.bits[2]) {
      error = 1;
    } else {
      *dst = src.bits[0];
      if (scale > 0 && scale <= 28) {
        *dst /= pow(10, scale);
      }
    }
    if (s21_get_bit(src, 127)) *dst = *dst * (-1);
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

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {

// }

//void print_bits(int value) {
//  for (int i = 31; i >= 0; i--) {
//    int bit = (value >> i) & 1;
//    printf("%d", bit);
//    if (i % 4 == 0) { // Для лучшей читаемости можно добавить пробел после каждых 4 бит
//      printf(" ");
//    }
//  }
//  printf("\n");
//}


//int main () {
//  s21_decimal val = {{123456789, 0, 0, 0}};
//  s21_set_scale(&val, 5);
//  float res = 1234.56789;
//  float tmp = 0;
//  float *dst = &tmp;
//  s21_from_decimal_to_float(val, dst);
//
//  printf("%f\n", res);
//  printf("%f\n", *dst);
//
//  for (int i = 0; i < 4; i++) {
//    printf("bits[%d]: ", i);
//
//    print_bits(val.bits[i]);
//  }
//}

//int main(void) {
//  s21_decimal num;
//  num.bits[0] = 0x0;
//  num.bits[1] = 0x10;
//  num.bits[2] = 0x40000;
//  num.bits[3] = MINUS;
//  for (int i = 0; i < 128; i++) {
//    printf("%d = ", i);
//    if (s21_get_bit(num, i)) {
//      printf("%d\n", 1);
//    } else {
//      printf("%d\n", 0);
//    }
//  }
//  return 0;
//}