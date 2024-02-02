#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "s21_decimal.h"

work_decimal conversion(s21_decimal v_1) {
  work_decimal res;
  for (int i = 0; i < 7; i++) {
    if (i < 3)
      res.bits[i] = v_1.bits[i] & MAX4BITE;
    else
      res.bits[i] &= 0x00000000;
  }
  res.scale = (v_1.bits[3] & SC) >> 16;
  return res;
}

s21_decimal reverseConversion(work_decimal num) {
  s21_decimal res;
  res.bits[3] &= MINUS;
  for (int i = 0; i < 3; i++) {
    res.bits[i] = num.bits[i] & MAX4BITE;
  }
  res.bits[3] &= (num.scale << 16);
  return res;
}

bool equalToZero(s21_decimal num) {
  bool res = true;
  for (int i = 0; i < 3; i++) {
    if (num.bits[i] & MAX4BITE) {
      res = false;
    }
  }
  return res;
}

bool getoverflow(work_decimal* num) {
  uint64_t overflow = 0;
  for (int i = 0; i < 7; i++) {
    num->bits[i] += overflow;
    overflow = num->bits[i] >> 32;
    num->bits[i] &= MAX4BITE;
  }
  return overflow;
}

void pointleft(work_decimal* num) {
  for (int i = 0; i < 7; i++) {
    num->bits[i] *= 10;
  }
  if (!getoverflow(num)) {
    num->scale += 1;
  }
}

uint64_t pointright(work_decimal* num) {
  uint64_t remainder = 0;
  for (int i = 7; i >= 0; i--) {
    num->bits[i] += remainder << 32;
    remainder = num->bits[i] % 10;
    num->bits[i] /= 10;
  }
  num->scale--;
  return remainder;
}

bool normalization(work_decimal* num) {
  for (int i = 6; i > 2; i--) {
    while (num->bits[i] != 0) {
      if (num->scale > 0) {
        pointright(num);
      } else {
        return true;
      }
    }
  }
  // -------------------------------------------------------- ТУТ ДОЛЖНО БЫТЬ
  // ОКРУГЛЕНИЕ!!!!
  return false;
}

void incompleteSubtraction(work_decimal work_num_1, work_decimal work_num_2,
                           work_decimal* work_res) {
  uint64_t perevod = 0x0;
  for (int i = 0; i < 7; i++) {
    if (work_num_1.bits[i] >= work_num_2.bits[i] &&
        !(work_num_1.bits[i] == work_num_2.bits[i] && perevod)) {
      printf("for: i = %d\n", i);
      work_res->bits[i] = work_num_1.bits[i] - work_num_2.bits[i];
      if (perevod) work_res->bits[i] -= 0x1;
      perevod = 0x0;
    } else {
      work_num_1.bits[i] |= 0x100000000;
      work_res->bits[i] = work_num_1.bits[i] - work_num_2.bits[i];
      if (perevod) work_res->bits[i] -= 1;
      perevod = 0x1;
    }
  }
}

bool addition(s21_decimal num_1, s21_decimal num_2, s21_decimal* res) {
  bool error = false;
  if (equalToZero(num_1)) {
    *res = num_2;
  } else if (equalToZero(num_2)) {
    *res = num_1;
  } else {
    bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
    if (num_1.bits[3] & MINUS) sign_num_1 = 1;
    if (num_2.bits[3] & MINUS) sign_num_2 = 1;
    work_decimal work_num_1 = conversion(num_1);
    work_decimal work_num_2 = conversion(num_2);
    while (work_num_1.scale > work_num_2.scale) pointleft(&work_num_2);
    while (work_num_2.scale > work_num_1.scale) pointleft(&work_num_1);
    work_decimal work_res;

    if ((!sign_num_1 && !sign_num_2) || (sign_num_1 && sign_num_2)) {
      // opericion num_1 + num_1
      for (int i = 0; i < 7; i++) {
        work_res.bits[i] = work_num_1.bits[i] + work_num_1.bits[i];
      }
      getoverflow(&work_res);
      if (sign_num_1) {
        sign = 1;
      }
    } else {
      // if (num_1 > num_2) num_1 - num_2 sign = sign_num_1
      if (1) {
        sign = sign_num_1;
        incompleteSubtraction(work_num_1, work_num_2, &work_res);
      } else {
        // else num_2 - num_1  sign = sign_num_2
        sign = sign_num_2;
        incompleteSubtraction(work_num_2, work_num_1, &work_res);
      }
      getoverflow(&work_res);
    }
    if (!normalization(&work_res)) {
      // конвертируем в исходный decimal
      *res = reverseConversion(work_res);
      if (sign) {
        res->bits[3] |= MINUS;
      } else {
        res->bits[3] &= ~MINUS;
      }
    } else {
      error = true;
    }
    if (equalToZero(*res)) {
      res->bits[3] &= ~MINUS;
    }
  }
  return error;
}

bool subtraction(s21_decimal num_1, s21_decimal num_2, s21_decimal* res) {
  bool error = false;
  num_2.bits[3] ^= MINUS;
  if (addition(num_1, num_2, res)) {
    error = true;
  }
  return error;
}
