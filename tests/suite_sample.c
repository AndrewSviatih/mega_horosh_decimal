#include "s21_tests.h"

START_TEST(based) {

    int a = 0;
    int b = 0;

    ck_assert_int_eq(a, b);
} END_TEST

Suite *sample(void) {
  Suite *s = suite_create("suite_eq_matrix");
  TCase *tc = tcase_create("case_eq_matrix");

  tcase_add_test(tc, based);

  suite_add_tcase(s, tc);
  return s;
}