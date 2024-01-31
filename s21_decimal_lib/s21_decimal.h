#ifndef MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
#define MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

#include <stdio.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int sum(int a, int b);

void removeTrailingZeros(s21_decimal* d);
void setBinary(s21_decimal* d, unsigned long long num);
int s21_get_bit(s21_decimal a, int index);
int s21_get_scale(s21_decimal a);
int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

#endif  // MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
