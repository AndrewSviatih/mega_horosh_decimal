#include "s21_decimal.h"


int s21_get_bit (s21_decimal dst, int index) {

  int mask = BIT_MASK(index); // BIT_MASK s21_decimal.h

  return dst.bits[index / 32] & mask != 0; 
} // sample: bit index = 40. 40 / 32 = 1. mask = bit from curr index.


