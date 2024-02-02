#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_decimal_lib/s21_decimal.h"

Suite *suite_from_decimal_to_float(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);
float s21_rand_r(float a, float b);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_