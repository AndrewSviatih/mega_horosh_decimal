#include "s21_decimal.h"

int s21_get_bit(s21_decimal dst, int index) {
  int mask = 1u << ((index) % 32);  // BIT_MASK s21_decimal.h

  return (dst.bits[index / 32] & mask) != 0;
}  // sample: bit index = 40. 40 / 32 = 1. mask = bit from curr index.

int s21_get_scale(s21_decimal dst) {
  int scale = (SCALE & dst.bits[3]) >> 16;
  return scale;
}

int s21_get_sign(s21_decimal dst) {
  return (dst.bits[3] & MINUS) != 0;
}

void s21_set_sign(s21_decimal *dst) { dst->bits[3] = dst->bits[3] | MINUS; }

void s21_set_scale(s21_decimal *dst, int scale) {
  int sign = 0;
  sign = s21_get_sign(*dst);
  dst->bits[3] = 0;
  scale <<= 16;
  dst->bits[3] = scale | dst->bits[3];
  if (sign) s21_set_sign(dst);
}

void s21_set_bit(s21_decimal *dst, int index, int bit) {
  int mask = BIT_MASK(index);
  if (bit == 0)
    dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
  else
    dst->bits[index / 32] = dst->bits[index / 32] | mask;
}

void s21_zero_decimal(s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
}



