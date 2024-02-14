#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#include "limits.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MINUS 0x80000000     // 10000000 00000000 00000000 00000000
#define SC 0x00ff0000        // 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff  // 11111111 11111111 11111111 11111111
#define BIT_MASK(index) (1u << ((index) % 32))  // bit in index[0:95]
#define GET_EXP(src) (((*(int *)&src & ~MINUS) >> 23) - SIGN_INDEX)

#define BIT_ONE 1
#define BIT_NONE 0

#define S21_DEC_BIT_LEN 4
#define SIGN_INDEX 127

#define ANY_ERROR 1
#define OK 0

// sign operations
void s21_set_sign(s21_decimal *number, int sign);

int s21_copy(s21_decimal *to, s21_decimal from);
// set all bits to 0
int s21_set_zeroes(s21_decimal *number);

// scale operations with decimal
s21_decimal *s21_decrease_scale(s21_decimal *number, int by);
// ============================================

typedef struct {
  int bits[4];
} s21_decimal;
/**
 * x0000000 zzzzzzzz 00000000 00000000 - bits[3]
 * bits[2] bits[1] bits[0] - мантисса
 * x - бит для знака
 * zzzzzzzz - биты для scale, т. е. 10**scale
 */

typedef struct {
  uint64_t bits[7];
  uint16_t scale;
} work_decimal;

/**
--------------------------------------------------------------
bit operations (supp funcs)
--------------------------------------------------------------
*/
//@params !!! index == from 0 to 95 (not bits[i] from 0 to 3)
int s21_get_bit(s21_decimal dst, int index);
int s21_get_scale(s21_decimal dst);
int s21_get_sign(s21_decimal dst);

void s21_set_bit(s21_decimal *dst, int index, int bit);
void s21_set_scale(s21_decimal *dst, int scale);
void s21_swap_sign(s21_decimal *dst);

void s21_zero_decimal(s21_decimal *dst);

double s21_normalize_28_signs(double temp, int *i);
/**
--------------------------------------------------------------
converters
--------------------------------------------------------------
*/
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_double(s21_decimal src, long double *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
/**
--------------------------------------------------------------
comparison
--------------------------------------------------------------
*/ //* Main Comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
//* Comparison Helpers
bool s21_is_work_less(work_decimal num_1, work_decimal num_2);
bool s21_is_work_less_or_equal(work_decimal num_1, work_decimal num_2);
bool s21_is_work_greater(work_decimal num_1, work_decimal num_2);
bool s21_is_work_greater_or_equal(work_decimal num_1, work_decimal num_2);
bool s21_is_work_equal(work_decimal num_1, work_decimal num_2);
/**
--------------------------------------------------------------
arithmetic
--------------------------------------------------------------
*/ // arithmetic main
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// mod
work_decimal divisionWithRemainder(work_decimal work_value_1,
                                   work_decimal work_value_2,
                                   work_decimal *work_result);

// arithmetic helper
// convert decimal to big decimal
work_decimal conversion(s21_decimal v_1);
// convert big decimal to decimal
s21_decimal reverseConversion(work_decimal num);
// check is 0 number
bool equalToZero(s21_decimal num);
// put 32 bits from small to higher
bool getoverflow(work_decimal *num);
// move ',' left
void pointleft(work_decimal *num);
// move ',' right
uint64_t pointright(work_decimal *num);
// is number can be round
bool isRoundPosebal(work_decimal num);
// normalize decimal
bool normalization(work_decimal *num);
// Неполное вычитание ??????
void incompleteSubtraction(work_decimal work_num_1, work_decimal work_num_2,
                           work_decimal *work_res);
// is scale correct
bool s21_checkScale(work_decimal *value);

// multiply 10 if we can
bool mulBy10(work_decimal *work_temp, work_decimal work_value,
             work_decimal *work_iter);
// sum helper work_decimal
int addWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal *work_res);
// sub helper work_decimal
int subWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal *work_res);
// set all decimal to zero
void setToZero(work_decimal *value);
// add 1 ???????
int add1Work(work_decimal *work_res);
// is decimal is zero
bool equalToZeroWork(work_decimal work_num);
// getoverflow when loop befor 3
bool getoverflow3(work_decimal *num);
// is correct div
bool checkDiv(work_decimal work_result, bool *stop);
/**
--------------------------------------------------------------
additional funcs
--------------------------------------------------------------
*/
int s21_floor(s21_decimal number, s21_decimal *result);
int s21_round(s21_decimal number, s21_decimal *result);
int s21_truncate(s21_decimal number, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif  // MEGA_HOROSH_DECIMAL_S21_DECIMAL_H