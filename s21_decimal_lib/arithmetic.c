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
  res.bits[3] = 0x0;
  for (int i = 0; i < 3; i++) {
    res.bits[i] = num.bits[i] & MAX4BITE;
  }
  res.bits[3] |= (num.scale << 16) & SC;
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
  for (int i = 6; i >= 0; i--) {
    num->bits[i] += remainder << 32;
    remainder = num->bits[i] % 10;
    num->bits[i] /= 10;
  }
  num->scale -= 1;
  return remainder;
}

bool isRoundPosebal(work_decimal num) {
  uint64_t remainder_i = pointright(&num);
  return (remainder_i == 0);
}

bool normalization(work_decimal* num) {
  bool res = false;
  for (int i = 6; i > 2 && !res; i--) {
    while (num->bits[i] != 0 && !res) {
      if (num->scale > 0) {
        pointright(num);
      } else {
        res = true;
      }
    }
  }
  while (isRoundPosebal(*num) && num->scale > 0) {
    pointright(num);
  }

  return res;
}

void incompletes21_sub(work_decimal work_num_1, work_decimal work_num_2,
                       work_decimal* work_res) {
  uint64_t perevod = 0x0;
  for (int i = 0; i < 7; i++) {
    if (work_num_1.bits[i] >= work_num_2.bits[i] &&
        !(work_num_1.bits[i] == work_num_2.bits[i] && perevod)) {
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

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  if (equalToZero(value_1)) {
    *result = value_2;
  } else if (equalToZero(value_2)) {
    *result = value_1;
  } else {
    bool sign_num_1 = 0, sign_num_2 = 0, sign = 0;
    if (value_1.bits[3] & MINUS) sign_num_1 = 1;
    if (value_2.bits[3] & MINUS) sign_num_2 = 1;
    work_decimal work_num_1 = conversion(value_1);
    work_decimal work_num_2 = conversion(value_2);
    while (work_num_1.scale > work_num_2.scale) pointleft(&work_num_2);
    while (work_num_2.scale > work_num_1.scale) pointleft(&work_num_1);
    work_decimal work_res;
    setToZero(&work_res);
    work_res.scale = work_num_1.scale;

    if ((!sign_num_1 && !sign_num_2) || (sign_num_1 && sign_num_2)) {
      // opericion num_1 + num_1
      for (int i = 0; i < 7; i++) {
        work_res.bits[i] = work_num_1.bits[i] + work_num_2.bits[i];
      }
      getoverflow(&work_res);
      if (sign_num_1) {
        sign = 1;
      }
    } else {
      // if (num_1 > num_2) num_1 - num_2 sign = sign_num_1
      if (s21_is_work_greater(work_num_1, work_num_2)) {
        sign = sign_num_1;
        incompletes21_sub(work_num_1, work_num_2, &work_res);
      } else {
        // else num_2 - num_1  sign = sign_num_2
        sign = sign_num_2;
        incompletes21_sub(work_num_2, work_num_1, &work_res);
      }
      getoverflow(&work_res);
    }
    if (s21_checkScale(&work_res)) {
      error = 2;
    } else if (!normalization(&work_res)) {
      // конвертируем в исходный decimal
      *result = reverseConversion(work_res);
      if (sign) {
        result->bits[3] |= MINUS;
      } else {
        result->bits[3] &= ~MINUS;
      }
    } else {
      if (!sign) {
        error = 1;
      } else {
        error = 2;
      }
    }
    if (equalToZero(*result)) {
      result->bits[3] = 0x0;
    }
  }
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  value_2.bits[3] ^= MINUS;
  error = s21_add(value_1, value_2, result);
  if (equalToZero(*result)) result->bits[3] = 0x0;
  return error;
}

bool s21_checkScale(work_decimal* value) {
  bool error = false;
  if (value->scale > 28) {
    for (int i = 0; i < 7; i++) {
      value->bits[i] = 0x0;
    }
    error = true;
  }
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  if (equalToZero(value_1) || equalToZero(value_2)) {
    for (int i = 0; i < 4; i++) result->bits[i] = 0x0;
  } else {
    int sign_value_1 = value_1.bits[3] & MINUS;
    int sign_value_2 = value_2.bits[3] & MINUS;
    work_decimal work_value_1 = conversion(value_1);
    work_decimal work_value_2 = conversion(value_2);
    work_decimal work_result;
    setToZero(&work_result);

    work_result.scale = work_value_1.scale + work_value_2.scale;

    work_result.bits[0] = work_value_1.bits[0] * work_value_2.bits[0];
    work_result.bits[1] = work_value_1.bits[1] * work_value_2.bits[0] +
                          work_value_1.bits[0] * work_value_2.bits[1];
    work_result.bits[2] = work_value_1.bits[0] * work_value_2.bits[2] +
                          work_value_1.bits[1] * work_value_2.bits[1] +
                          work_value_1.bits[2] * work_value_2.bits[0];
    work_result.bits[3] = work_value_1.bits[1] * work_value_2.bits[2] +
                          work_value_1.bits[2] * work_value_2.bits[1];
    work_result.bits[4] = work_value_1.bits[2] * work_value_2.bits[2];

    // result->bits[3] |= (work_result.scale << 16) & SC;

    // getoverflow(&work_result);

    if (getoverflow3(&work_result) || normalization(&work_result) ||
        s21_checkScale(&work_result)) {
      for (int i = 0; i < 4; i++) result->bits[i] = 0x0;
      if (sign_value_1 != sign_value_2) {
        error = 2;
      } else {
        error = 1;
      }
    } else {
      *result = reverseConversion(work_result);
      if (sign_value_1 == sign_value_2) {
        result->bits[3] &= ~MINUS;
      } else {
        result->bits[3] |= MINUS;
      }
    }
  }

  return error;
}

// умножаем на 10 если можно
bool mulBy10(work_decimal* work_temp, work_decimal work_value,
             work_decimal* work_iter) {
  bool error = false, gg = false;
  work_decimal work_temp_2 = *work_temp;
  // work_decimal work_num_10;

  pointleft(&work_temp_2);
  work_temp_2.scale = 0;

  while (s21_is_work_greater_or_equal(work_value, work_temp_2)) {
    pointleft(work_iter);
    work_iter->scale = 0x0;
    *work_temp = work_temp_2;
    pointleft(&work_temp_2);
    work_temp_2.scale = 0;
    gg = true;
  }

  if (!gg) {
    error = true;
  }

  return error;
}

// сумма work_decimal
int addWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal* work_res) {
  s21_decimal num_1 = reverseConversion(work_num_1);
  s21_decimal num_2 = reverseConversion(work_num_2);
  s21_decimal res;
  int error = s21_add(num_1, num_2, &res);

  *work_res = conversion(res);

  return error;
}

// вычитание work_decimal
int subWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal* work_res) {
  s21_decimal num_1 = reverseConversion(work_num_1);
  s21_decimal num_2 = reverseConversion(work_num_2);
  s21_decimal res;
  int error = s21_sub(num_1, num_2, &res);
  *work_res = conversion(res);

  return error;
}

// Приравнивает к 0 work_decimal
void setToZero(work_decimal* value) {
  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0x0;
  }
  value->scale = 0x0;
}

// Добавляет 1
int add1Work(work_decimal* work_res) {
  s21_decimal num_1 = reverseConversion(*work_res);
  s21_decimal num_2;
  for (int i = 0; i < 4; i++) {
    num_2.bits[i] = 0x0;
  }
  num_2.bits[0] = 0x1;
  s21_decimal res;
  int error = s21_add(num_1, num_2, &res);
  *work_res = conversion(res);
  return error;
}

// Деление с остатком. Возвращает остаток
work_decimal divisionWithRemainder(work_decimal work_value_1,
                                   work_decimal work_value_2,
                                   work_decimal* work_result) {
  work_value_1.scale = 0x0;
  work_value_2.scale = 0x0;
  work_decimal work_iter;
  // work_remainder = work_value_1;
  // work_decimal work_check;
  setToZero(&work_iter);
  setToZero(work_result);

  work_iter.bits[0] = 0x1;

  // цикл деления
  bool stop = true;
  while (s21_is_work_greater_or_equal(work_value_1, work_value_2)) {
    work_decimal work_temp = work_value_2;
    bool gg = true;

    if (stop && !mulBy10(&work_temp, work_value_1, &work_iter)) {
      addWork(work_iter, *work_result, work_result);
      subWork(work_value_1, work_temp, &work_value_1);
      gg = false;
    }
    setToZero(&work_iter);
    work_iter.bits[0] = 0x1;

    if (gg) {
      subWork(work_value_1, work_value_2, &work_value_1);
      add1Work(work_result);
      stop = false;
    }
  }

  return work_value_1;
}

// равно ли число work_decimal нулю
bool equalToZeroWork(work_decimal work_num) {
  s21_decimal num = reverseConversion(work_num);
  return equalToZero(num);
}

bool getoverflow3(work_decimal* num) {
  uint64_t overflow = 0;
  for (int i = 0; i < 3; i++) {
    num->bits[i] += overflow;
    overflow = num->bits[i] >> 32;
    num->bits[i] &= MAX4BITE;
  }
  return overflow;
}

bool checkDiv(work_decimal work_result, bool* stop) {
  for (int i = 0; i < 7; i++) work_result.bits[i] *= 10;
  if (getoverflow3(&work_result)) *stop = true;
  return !stop;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  if (equalToZero(value_2)) {
    error = 3;
  } else if (equalToZero(value_1)) {
    for (int i = 0; i < 4; i++) result->bits[i] = 0x0;
  } else {
    int sign_value_1 = value_1.bits[3] & MINUS;
    int sign_value_2 = value_2.bits[3] & MINUS;

    work_decimal work_value_1 = conversion(value_1);
    work_decimal work_value_2 = conversion(value_2);
    int iter = work_value_1.scale - work_value_2.scale;
    work_decimal work_result;
    work_decimal work_remainder =
        divisionWithRemainder(work_value_1, work_value_2, &work_result);

    bool stop = false;
    while (!stop && !equalToZeroWork(work_remainder) && iter < 28) {
      checkDiv(work_result, &stop);
      if (!stop) {
        for (int i = 0; i < 7; i++) work_result.bits[i] *= 10;
        getoverflow3(&work_result);
        work_result.scale = 0;
        pointleft(&work_remainder);
        work_remainder.scale = 0;
        work_decimal work_temp;
        work_remainder =
            divisionWithRemainder(work_remainder, work_value_2, &work_temp);
        work_temp.scale = 0;
        addWork(work_temp, work_result, &work_result);
        iter++;
      }
    }
    if (iter == -1) iter = 0;

    if (iter < 0) {
      error = 2;
      for (int i = 0; i < 4; i++) result->bits[i] = 0x0;
    } else {
      work_result.scale = iter + 0x0;
    }
    if (!error &&
        (normalization(&work_result) || s21_checkScale(&work_result))) {
      if (sign_value_1 != sign_value_2) {
        error = 2;
      } else {
        error = 1;
      }
      for (int i = 0; i < 4; i++) result->bits[i] = 0x0;
    }
    if (!error) {
      *result = reverseConversion(work_result);

      if (sign_value_1 == sign_value_2) {
        result->bits[3] &= ~MINUS;
      } else {
        result->bits[3] |= MINUS;
      }
    }
  }

  return error;
}
