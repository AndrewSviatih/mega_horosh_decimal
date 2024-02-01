#include "s21_decimal.h"

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

int s21_get_sign(s21_decimal d) {
  return (d.bits[3] && (1u << 31));
}

int s21_get_bit(s21_decimal a, int index) {
  int num_int = index / 32;
  int num_bit = index % 32;
  return (a.bits[num_int] & (1u << num_bit)) >> num_bit;
}

int s21_get_scale(s21_decimal a) {
  return a.bits[3] >> 16;
}