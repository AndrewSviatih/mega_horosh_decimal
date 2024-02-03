#ifndef MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
#define MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

#define MINUS 0x80000000
#define SCALE 0x00ff0000
#define BIT_MASK(index) (1u << ((index) % 32))  // bit in index[0:95]

typedef struct {
  int bits[4];
} s21_decimal;

#endif  // MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

/*
--------------------------------------------------------------
bit operations (supp funcs)
--------------------------------------------------------------
*/
//@params !!! index == from 0 to 95 (not bits[i] from 0 to 3)
int s21_get_bit(s21_decimal dst, int index);
int s21_get_scale(s21_decimal dst);
int s21_get_sign(s21_decimal dst);

void s21_set_scale(s21_decimal *dst, int scale);
void s21_set_sign(s21_decimal *dst);
void s21_set_bit(s21_decimal *dst, int index, int bit);

void s21_zero_decimal(s21_decimal *dst);
/*
--------------------------------------------------------------
converters
--------------------------------------------------------------
*/
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_double(s21_decimal src, long double *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

