#ifndef MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
#define MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

#include <stdio.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

int sum(int a, int b);

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);

#endif  // MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
