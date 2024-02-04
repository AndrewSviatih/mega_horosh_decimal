#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;
  int sign_num_1 = 0, sign_num_2 = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;

  if (sign_num_1 == sign_num_2 && sign_num_1 == 0) {
    work_decimal work_value_1 = conversion(value_1);
    work_decimal work_value_2 = conversion(value_2);
    result = s21_is_work_less(work_value_1, work_value_2);
  } else if (sign_num_1 == sign_num_2 && sign_num_1 == 1) {
    work_decimal work_value_1 = conversion(value_1);
    work_decimal work_value_2 = conversion(value_2);
    result = !s21_is_work_less(work_value_1, work_value_2);
  } else if (sign_num_1 < sign_num_2) {
    result = 0;
  }

  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (s21_is_equal(value_1, value_2) || s21_is_less(value_1, value_2)) {
    result = 1;
  }
  return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;
  if (s21_is_less_or_equal(value_1, value_2)) {
    result = 0;
  }
  return result;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  if (s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2)) {
    result = 1;
  }
  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;
  int sign_num_1 = 0, sign_num_2 = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  if (sign_num_1 != sign_num_2) {
    result = 0;
  } else {
    work_decimal work_value_1 = conversion(value_1);
    work_decimal work_value_2 = conversion(value_2);
    result = s21_is_work_equal(work_value_1, work_value_2);
  }
  return result;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !(s21_is_equal(value_1, value_2));
}