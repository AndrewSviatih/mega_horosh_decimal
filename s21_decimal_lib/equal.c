#include <stdbool.h>

#include "s21_decimal.h"

bool equally(work_decimal num_1, work_decimal num_2) {
  bool res = true;
  while (num_1.scale > num_2.scale) pointleft(&num_2);
  while (num_2.scale > num_1.scale) pointleft(&num_1);
  for (int i = 6; i >= 0 && res; i--) {
    if (num_1.bits[i] != num_2.bits[2]) {
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
