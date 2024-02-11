#include "s21_tests.h"

START_TEST(is_not_equal1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal6) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal7) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal8) {
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

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal9) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal10) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal11) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal12) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal13) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal14) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal15) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal16) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal17) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal18) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal19) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal20) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

START_TEST(is_not_equal21) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  ck_assert_int_eq(s21_is_not_equal(decimal1, decimal2), check);
}

Suite *suite_is_not_equal(void) {
  Suite *s = suite_create("suite_is_not_equal");
  TCase *tc = tcase_create("case_is_not_equal");

  tcase_add_test(tc, is_not_equal1);
  tcase_add_test(tc, is_not_equal2);
  tcase_add_test(tc, is_not_equal3);
  tcase_add_test(tc, is_not_equal4);
  tcase_add_test(tc, is_not_equal5);
  tcase_add_test(tc, is_not_equal6);
  tcase_add_test(tc, is_not_equal7);
  tcase_add_test(tc, is_not_equal8);
  tcase_add_test(tc, is_not_equal9);
  tcase_add_test(tc, is_not_equal10);
  tcase_add_test(tc, is_not_equal11);
  tcase_add_test(tc, is_not_equal12);
  tcase_add_test(tc, is_not_equal13);
  tcase_add_test(tc, is_not_equal14);
  tcase_add_test(tc, is_not_equal15);
  tcase_add_test(tc, is_not_equal16);
  tcase_add_test(tc, is_not_equal17);
  tcase_add_test(tc, is_not_equal18);
  tcase_add_test(tc, is_not_equal19);
  tcase_add_test(tc, is_not_equal20);
  tcase_add_test(tc, is_not_equal21);

  suite_add_tcase(s, tc);
  return s;
}