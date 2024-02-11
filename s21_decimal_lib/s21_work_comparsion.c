#include "s21_decimal.h"

bool s21_is_work_less(work_decimal num_1, work_decimal num_2) {
  bool res = true;
  if (s21_is_work_greater(num_1, num_2) || s21_is_work_equal(num_1, num_2)) {
    res = false;
  }
  return res;
}

bool s21_is_work_less_or_equal(work_decimal num_1, work_decimal num_2) {
  bool res = false;
  if (s21_is_work_less(num_1, num_2) || s21_is_work_equal(num_1, num_2)) {
    res = true;
  }
  return res;
}

bool s21_is_work_greater(work_decimal num_1, work_decimal num_2) {
  bool res = true, flag = true;
  if (s21_is_work_equal(num_1, num_2)) {
    res = false;
  } else {
    while (num_1.scale > num_2.scale) pointleft(&num_2);
    while (num_2.scale > num_1.scale) pointleft(&num_1);
    for (int i = 6; i >= 0 && flag; i--) {
      if (num_1.bits[i] < num_2.bits[i]) {
        res = false;
        flag = false;
      } else if (num_1.bits[i] > num_2.bits[i]) {
        flag = false;
      }
    }
  }
  return res;
}

bool s21_is_work_greater_or_equal(work_decimal num_1, work_decimal num_2) {
  bool res = false;
  if (s21_is_work_greater(num_1, num_2) || s21_is_work_equal(num_1, num_2)) {
    res = true;
  }
  return res;
}

bool s21_is_work_equal(work_decimal num_1, work_decimal num_2) {
  bool res = true;
  while (num_1.scale > num_2.scale) pointleft(&num_2);
  while (num_2.scale > num_1.scale) pointleft(&num_1);
  for (int i = 6; i >= 0 && res; i--) {
    if (num_1.bits[i] != num_2.bits[i]) {
      res = false;
    }
  }
  return res;
}
