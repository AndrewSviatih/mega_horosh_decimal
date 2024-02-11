#include "s21_tests.h"

START_TEST(is_less_test1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test6) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test7) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test8) {
  // -52818775009509558395695966890
  s21_decimal decimal1;
  decimal1.bits[0] = 0xAAAAAAAA;
  decimal1.bits[1] = 0xAAAAAAAA;
  decimal1.bits[2] = 0xAAAAAAAA;
  decimal1.bits[3] = 0x80000000;
  // 79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x0;
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test9) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test10) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test11) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test12) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test13) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test14) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test15) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test17) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test18) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test19) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test20) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

START_TEST(is_less_test21) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_less(decimal1, decimal2), check);
}

Suite *suite_is_less(void) {
  Suite *s = suite_create("suite_is_less");
  TCase *tc = tcase_create("case_is_less");

  tcase_add_test(tc, is_less_test1);
  tcase_add_test(tc, is_less_test2);
  tcase_add_test(tc, is_less_test3);
  tcase_add_test(tc, is_less_test4);
  tcase_add_test(tc, is_less_test5);
  tcase_add_test(tc, is_less_test6);
  tcase_add_test(tc, is_less_test7);
  tcase_add_test(tc, is_less_test8);
  tcase_add_test(tc, is_less_test9);
  tcase_add_test(tc, is_less_test10);
  tcase_add_test(tc, is_less_test11);
  tcase_add_test(tc, is_less_test12);
  tcase_add_test(tc, is_less_test13);
  tcase_add_test(tc, is_less_test14);
  tcase_add_test(tc, is_less_test15);
  tcase_add_test(tc, is_less_test16);
  tcase_add_test(tc, is_less_test17);
  tcase_add_test(tc, is_less_test18);
  tcase_add_test(tc, is_less_test19);
  tcase_add_test(tc, is_less_test20);
  tcase_add_test(tc, is_less_test21);

  suite_add_tcase(s, tc);
  return s;
}