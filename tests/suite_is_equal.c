#include "s21_tests.h"

START_TEST(is_equal_test1) {
  // 79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x0;
  // 79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x0;
  int check = 1;
  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test2) {
  // 79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x0;
  // 79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x0;
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test3) {
  // 79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x0;
  // -79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x80000000;
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test4) {
  // -79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x80000000;
  // 79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x0;
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test5) {
  // 79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x0;
  // 52818775009509558395695966890
  s21_decimal decimal2;
  decimal2.bits[0] = 0xAAAAAAAA;
  decimal2.bits[1] = 0xAAAAAAAA;
  decimal2.bits[2] = 0xAAAAAAAA;
  decimal2.bits[3] = 0x0;
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test6) {
  // 52818775009509558395695966890
  s21_decimal decimal1;
  decimal1.bits[0] = 0xAAAAAAAA;
  decimal1.bits[1] = 0xAAAAAAAA;
  decimal1.bits[2] = 0xAAAAAAAA;
  decimal1.bits[3] = 0x0;
  // 79228162514264337593543950335
  s21_decimal decimal2;
  decimal2.bits[0] = 0xFFFFFFFF;
  decimal2.bits[1] = 0xFFFFFFFF;
  decimal2.bits[2] = 0xFFFFFFFF;
  decimal2.bits[3] = 0x0;
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test7) {
  // 79228162514264337593543950335
  s21_decimal decimal1;
  decimal1.bits[0] = 0xFFFFFFFF;
  decimal1.bits[1] = 0xFFFFFFFF;
  decimal1.bits[2] = 0xFFFFFFFF;
  decimal1.bits[3] = 0x0;
  // -52818775009509558395695966890
  s21_decimal decimal2;
  decimal2.bits[0] = 0xAAAAAAAA;
  decimal2.bits[1] = 0xAAAAAAAA;
  decimal2.bits[2] = 0xAAAAAAAA;
  decimal2.bits[3] = 0x80000000;
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test8) {
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
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test11) {
  // -5077779.6717425679610094186071
  s21_decimal decimal1 = {{0xA15E6E57, 0xC0C562E8, 0xA41268B3, 0x80160000}};
  // -20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test12) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // -20786105945010.405849433600269
  s21_decimal decimal2 = {{0x48D7710D, 0x279AE1C0, 0x4329DD25, 0x800F0000}};
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test13) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 0;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test14) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test15) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test16) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test17) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test18) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test19) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test20) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

START_TEST(is_equal_test21) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = 1;

  ck_assert_int_eq(s21_is_equal(decimal1, decimal2), check);
}

Suite *suite_is_equal(void) {
  Suite *s = suite_create("suite_is_equal");
  TCase *tc = tcase_create("case_is_equal");

  tcase_add_test(tc, is_equal_test1);
  tcase_add_test(tc, is_equal_test2);
  tcase_add_test(tc, is_equal_test3);
  tcase_add_test(tc, is_equal_test4);
  tcase_add_test(tc, is_equal_test5);
  tcase_add_test(tc, is_equal_test6);
  tcase_add_test(tc, is_equal_test7);
  tcase_add_test(tc, is_equal_test8);
  tcase_add_test(tc, is_equal_test9);
  tcase_add_test(tc, is_equal_test10);
  tcase_add_test(tc, is_equal_test11);
  tcase_add_test(tc, is_equal_test12);
  tcase_add_test(tc, is_equal_test13);
  tcase_add_test(tc, is_equal_test14);
  tcase_add_test(tc, is_equal_test15);
  tcase_add_test(tc, is_equal_test16);
  tcase_add_test(tc, is_equal_test17);
  tcase_add_test(tc, is_equal_test18);
  tcase_add_test(tc, is_equal_test19);
  tcase_add_test(tc, is_equal_test20);
  tcase_add_test(tc, is_equal_test21);

  suite_add_tcase(s, tc);
  return s;
}