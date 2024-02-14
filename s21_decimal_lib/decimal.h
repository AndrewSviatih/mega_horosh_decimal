//
// Created by Sonse on 18.01.2024.
//

#ifndef S21_DECIMAL_DECIMAL_H
#define S21_DECIMAL_DECIMAL_H

#include "math.h"
#include "stdlib.h"

typedef struct {
  int bits[4];
} s21_decimal;

// bits
#define BIT_ONE 1
#define BIT_NONE 0
#define S21_DEC_BIT_LEN 4

#define SIGN_INDEX 127

// macro definition of decimal parts
#define S21_DEC_INDEX(index) (index / 32)
#define S21_DEC_BIT_FOR_INDEX(index) (index % 32)

// error messages
#define ANY_ERROR 1
#define OK 0

int s21_floor(s21_decimal number, s21_decimal *result);
int s21_round(s21_decimal number, s21_decimal *result);
int s21_truncate(s21_decimal number, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// bit manipulations
int s21_get_bit(s21_decimal number, int index);
void s21_set_bit(s21_decimal *number, int index, int bit);
// sign operations
int s21_get_sign(s21_decimal number);
void s21_set_sign(s21_decimal *number, int sign);

int s21_copy(s21_decimal *to, s21_decimal from);
// set all bits to 0
int s21_set_zeroes(s21_decimal *number);

// scale operations with decimal
int s21_get_scale(s21_decimal number);
void s21_set_scale(s21_decimal *number, int scale);
s21_decimal *s21_decrease_scale(s21_decimal *number, int by);

// int s21_get_pow(s21_decimal number);

#endif  // S21_DECIMAL_DECIMAL_H
