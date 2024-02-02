#include "s21_decimal.h"

work_decimal conversion(s21_decimal v_1) {
  work_decimal res;
  for (int i = 0; i < 7; i++) {
    if (i < 4)
      res.bits[i] = v_1.bits[i] & MAX4BITE;
    else
      res.bits[i] = 0;
  }

  return res;
}
