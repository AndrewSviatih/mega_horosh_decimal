#ifndef SRC_TESTS_INCLUDES_S21_TESTS_H_
#define SRC_TESTS_INCLUDES_S21_TESTS_H_

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define U_MAX_INT 4294967295          // 0b11111111111111111111111111111111
#define MAX_INT 2147483647            // 0b01111111111111111111111111111111     
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F
#define S21_MAX_UINT 4294967295

#define S21_TRUE 1
#define S21_FALSE 0
#define CONVERTERS_S21_TRUE 0
#define CONVERTERS_S21_FALSE 1     
#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000

#include "../s21_decimal_lib/s21_decimal.h"

#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

// TODO: tests convertation
Suite *suite_from_decimal_to_float(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_float_to_decimal(void);

// TODO: tests comprasion
Suite *suite_is_equal(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_less(void);
Suite *suite_is_not_equal(void);

//*****************************
// TODO: tests arithmetic
Suite* suite_add(void);
Suite *add_suite1(void);

Suite* suite_sub(void);
Suite *suite_div(void);
Suite *suite_mul(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testcase);
float s21_rand_r(float a, float b);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_