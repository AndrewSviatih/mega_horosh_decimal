#include "s21_decimal.h"

void s21_decimal_to_work(s21_decimal dec1, s21_decimal dec2, s21_work_decimal* dec_work1, s21_work_decimal* dec_work2) {
  for (int i = 0; i < 7; i++) {
    if (i < 3) {
      dec_work1->bits[i] = dec1.bits[i];
      dec_work2->bits[i] = dec2.bits[i];
    } else {
      dec_work1->bits[i] = 0x0;
      dec_work2->bits[i] = 0x0;
    }
  }
  
}


void setBinary(s21_decimal* d, unsigned long long num) {
  int j = 0;
  for (int i = 3; i > -1; --i) {
    d->bits[j] = (num >> (24 - i * 8)) & 0xFF;
    j++;
  }
}

void removeTrailingZeros(s21_decimal* d) {
  for (int i = 3; i >= 0; --i) {
    unsigned int value = d->bits[i];
    while (value != 0 && (value & 1) == 0) {
      value >>= 1;
    }
    d->bits[i] = value;
  }
}

int s21_get_sign(unsigned int x) {
  return s21_get_bit(x, 31);
}

int s21_get_bit(unsigned int x, int i) {
  int y = 1 << i;
  return (x & y) ? 1 : 0;
}

void s21_set_sign(unsigned int* x, int sign) {
  s21_set_bit(x, 31, sign);
}

void s21_set_bit(unsigned int* x, int i, int bit) {
  int y = 1 << i;
  *x = bit ? *x | y : *x & (~y);
}

int s21_get_scale(s21_decimal a) {
  return a.bits[3] >> 16;
}