#ifndef MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
#define MEGA_HOROSH_DECIMAL_S21_DECIMAL_H

#include "stdio.h"
#include "stdlib.h"

#define MINUS 0x80000000
#define SC 0x00ff0000

typedef struct {
  int bits[4];
} s21_decimal;

#endif //MEGA_HOROSH_DECIMAL_S21_DECIMAL_H
