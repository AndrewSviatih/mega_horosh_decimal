#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 0;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);

  if (less(work_value_1, work_value_2)) res = 1;

  if (sign_num_1 && !sign_num_2) {
    res = 1;
  } else if (sign_num_1 && sign_num_2 && notEqual(work_value_1, work_value_2)) {
    res = !res;
  } else if (!sign_num_1 && sign_num_2) {
    res = 0;
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 0;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);
  if (lessOrEqual(work_value_1, work_value_2)) res = 1;

  if (sign_num_1 && !sign_num_2) {
    res = 1;
  } else if (sign_num_1 && sign_num_2 && notEqual(work_value_1, work_value_2)) {
    res = !res;
  } else if (!sign_num_1 && sign_num_2) {
    res = 0;
  }
  return res;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 0;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);
  if (more(work_value_1, work_value_2)) res = 1;

  if (sign_num_1 && !sign_num_2) {
    res = 0;
  } else if (sign_num_1 && sign_num_2 && notEqual(work_value_1, work_value_2)) {
    res = !res;
  } else if (!sign_num_1 && sign_num_2) {
    res = 1;
  }
  return res;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 0;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);
  if (moreOrEqual(work_value_1, work_value_2)) res = 1;

  if (sign_num_1 && !sign_num_2) {
    res = 0;
  } else if (sign_num_1 && sign_num_2 && notEqual(work_value_1, work_value_2)) {
    res = !res;
  } else if (!sign_num_1 && sign_num_2) {
    res = 1;
  }
  return res;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 0;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);
  if (equally(work_value_1, work_value_2)) res = 1;

  if (sign_num_1 != sign_num_2) {
    res = 0;
  }
  return res;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
  if (value_1.bits[3] & MINUS) sign_num_1 = 1;
  if (value_2.bits[3] & MINUS) sign_num_2 = 1;
  int res = 1;
  work_decimal work_value_1 = conversion(value_1);
  work_decimal work_value_2 = conversion(value_2);
  while (work_value_1.scale > work_value_2.scale) pointleft(&work_value_2);
  while (work_value_2.scale > work_value_1.scale) pointleft(&work_value_1);
  if (equally(work_value_1, work_value_2) && sign_num_1 == sign_num_2) res = 0;
  return res;
}

bool equally(work_decimal num_1, work_decimal num_2) {
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

bool notEqual(work_decimal num_1, work_decimal num_2) {
  return (!equally(num_1, num_2));
}

bool more(work_decimal num_1, work_decimal num_2) {
  bool res = true, gg = true;
  if (equally(num_1, num_2)) {
    res = false;
  } else {
    while (num_1.scale > num_2.scale) pointleft(&num_2);
    while (num_2.scale > num_1.scale) pointleft(&num_1);
    for (int i = 6; i >= 0 && gg; i--) {
      if (num_1.bits[i] < num_2.bits[i]) {
        res = false;
        gg = false;
      } else if (num_1.bits[i] > num_2.bits[i]) {
        gg = false;
      }
    }
  }
  return res;
}

bool less(work_decimal num_1, work_decimal num_2) {
  bool res = true;
  if (more(num_1, num_2) || equally(num_1, num_2)) {
    res = false;
  }
  return res;
}

bool moreOrEqual(work_decimal num_1, work_decimal num_2) {
  bool res = false;
  if (more(num_1, num_2) || equally(num_1, num_2)) {
    res = true;
  }
  return res;
}

bool lessOrEqual(work_decimal num_1, work_decimal num_2) {
  bool res = false;
  if (less(num_1, num_2) || equally(num_1, num_2)) {
    res = true;
  }
  return res;
}
