#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../s21_decimal_lib/s21_decimal.h"

// Suite *suite_memchr(void);
Suite *sample(void);
Suite *suite_is_equal(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_less(void);
Suite *suite_is_not_equal(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);
double get_rand(double min, double max);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_