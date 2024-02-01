#ifndef MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
#define MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

#include "stdio.h"
#include "stdlib.h"

#define MINUS 0x80000000
#define SC 0x00ff0000 // scale
#define BIT_MASK(index) (1u << ((index) % 32)) // bit in index[0:95]

typedef struct {
  int bits[4];
} s21_decimal;

#endif //MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

/* 
--------------------------------------------------------------
bit operations (supp funcs)
--------------------------------------------------------------
*/

//@params !!! index from 0 to 95 (not bits[i] from 0 to 3)
int s21_get_bit (s21_decimal dst, int index);