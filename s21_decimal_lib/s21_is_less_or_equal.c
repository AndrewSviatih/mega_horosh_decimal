#include "s21_decimal.h"


int s21_is_less_or_equal(s21_decimal a, s21_decimal b) {
    int result = 1;
    if (a.bits[0] && b.bits[0]) {
        result = 0;      
    }
    return result;
}