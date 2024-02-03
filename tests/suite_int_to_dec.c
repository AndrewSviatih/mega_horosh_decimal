#include "s21_tests.h"

START_TEST(from_int_to_decimal_0) {
    s21_decimal val = {{0, 0, 0, 0}};
    int res = 0;
    int tmp = -2147483648;
    s21_from_int_to_decimal(tmp, &val);
    s21_from_decimal_to_int(val, &res);
    ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 2147483647;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_1) {
  s21_decimal val = {0};

  s21_from_int_to_decimal(0, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_zero_decimal(&val);
  s21_from_int_to_decimal(-128, &val);
  int a = 0;
  s21_from_decimal_to_int(val, &a);
  ck_assert_int_eq(a, -128);
  ck_assert_int_eq(val.bits[0], 128);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
//  ck_assert_int_eq(val.bits[3], 2147483648);

  s21_zero_decimal(&val);
  s21_from_int_to_decimal(127, &val);
  ck_assert_int_eq(val.bits[0], 127);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  s21_zero_decimal(&val);
  s21_from_int_to_decimal(-2147483648, &val);
  int n = 0;
  s21_from_decimal_to_int(val, &n);
  ck_assert_int_eq(n, -2147483648);
//  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
//  ck_assert_int_eq(val.bits[3], 2147483648);

  s21_zero_decimal(&val);
  s21_from_int_to_decimal(2147483647, &val);
  ck_assert_int_eq(val.bits[0], 2147483647);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest1) {
  // 6412
  int src1 = 1;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest2) {
  // 6428
  int src1 = -1;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest3) {
  // 6444
  int src1 = 0;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest4) {
  // 6460
  int src1 = 0;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest5) {
  // 6476
  int src1 = -987879878;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00111010111000011101100111000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest6) {
  // 6492
  int src1 = -2147483646;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest7) {
  // 6508
  int src1 = 2147483646;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest8) {
  // 6524
  int src1 = 796132784;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00101111011101000000010110110000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimalTest9) {
  // 6540
  int src1 = -12345677;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

  Suite *suite_from_int_to_decimal(void) {
  Suite *s = suite_create("from_int_to_decimal");
  TCase *tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, from_int_to_decimal_0);
  tcase_add_test(tc, from_int_to_decimal_1);
  tcase_add_test(tc, from_int_to_decimal_2);
  
  tcase_add_test(tc, s21_from_int_to_decimal_1);
  tcase_add_test(tc, s21_from_int_to_decimalTest1);
  tcase_add_test(tc, s21_from_int_to_decimalTest2);
  tcase_add_test(tc, s21_from_int_to_decimalTest3);
  tcase_add_test(tc, s21_from_int_to_decimalTest4);
  tcase_add_test(tc, s21_from_int_to_decimalTest5);
  tcase_add_test(tc, s21_from_int_to_decimalTest6);
  tcase_add_test(tc, s21_from_int_to_decimalTest7);
  tcase_add_test(tc, s21_from_int_to_decimalTest8);
  tcase_add_test(tc, s21_from_int_to_decimalTest9);
  tcase_add_test(tc, from_int_to_decimal_0);
  tcase_add_test(tc, from_int_to_decimal_1);

  suite_add_tcase(s, tc);
  return s;
}
