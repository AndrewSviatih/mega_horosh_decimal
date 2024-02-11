#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define MINUS 0x80000000     // 10000000 00000000 00000000 00000000
#define SC 0x00ff0000        // 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff  // 11111111 11111111 11111111 11111111
#define BIT_MASK(index) (1u << ((index) % 32))  // bit in index[0:95]
#define GET_EXP(src) (((*(int *)&src & ~MINUS) >> 23) - 127)

typedef struct {
  int bits[4];
} s21_decimal;
/**
 * x0000000 zzzzzzzz 00000000 00000000 - bits[3]
 * bits[2] bits[1] bits[0] - мантисса
 * x - бит для знака
 * zzzzzzzz - биты для scale, т. е. 10**scale
 */
// Расширенный decimal. Структура
typedef struct {
  uint64_t bits[7];
  uint16_t scale;
} work_decimal;

/*
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
void s21_set_sign(s21_decimal *dst);

void s21_zero_decimal(s21_decimal *dst);

double s21_normalize_28_signs(double temp, int *i);
/*
--------------------------------------------------------------
converters
--------------------------------------------------------------
*/
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_double(s21_decimal src, long double *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
/*
--------------------------------------------------------------
comparison
--------------------------------------------------------------
*/
// Функция конвертирует decimal в расширенный decimal
work_decimal conversion(s21_decimal v_1);
// Обратная конвертация в исходный decimal
s21_decimal reverseConversion(work_decimal num);
// Проверяем равно ли число нулю
bool equalToZero(s21_decimal num);
// Переносит переполнение 32 битов из младшего в старший
bool getoverflow(work_decimal* num);
// Сдвиг запятой в лево
void pointleft(work_decimal* num);
// Сдвиг запятов в право
uint64_t pointright(work_decimal* num);
// Проверяет можно ли округлить(удалить лишние нули)
bool isRoundPosebal(work_decimal num);
// Нормализация рабочего decimal
bool normalization(work_decimal* num);
// Неполное вычитание
void incompleteSubtraction(work_decimal work_num_1, work_decimal work_num_2,
                           work_decimal* work_res);
// Сложение
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// Вычитание
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Смотрит не вышла ли scale за границы
bool s21_checkScale(work_decimal* value);
// Умножение
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// умножаем на 10 если можно
bool mulBy10(work_decimal* work_temp, work_decimal work_value,
             work_decimal* work_iter);
// сумма work_decimal
int addWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal* work_res);
// вычитание work_decimal
int subWork(work_decimal work_num_1, work_decimal work_num_2,
            work_decimal* work_res);
// Приравнивает к 0 work_decimal
void setToZero(work_decimal* value);
// Добавляет 1
int add1Work(work_decimal* work_res);
// Деление с остатком. Возвращает остаток
work_decimal divisionWithRemainder(work_decimal work_value_1,
                                   work_decimal work_value_2,
                                   work_decimal* work_result);
// равно ли число work_decimal нулю
bool equalToZeroWork(work_decimal work_num);
// getoverflow где цикл до 3
bool getoverflow3(work_decimal* num);
// Можно ли далить
bool checkDiv(work_decimal work_result, bool* stop);
// Деление
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

//* Comparison Operators
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
//* Work
bool s21_is_work_less(work_decimal num_1, work_decimal num_2);
bool s21_is_work_less_or_equal(work_decimal num_1, work_decimal num_2);
bool s21_is_work_greater(work_decimal num_1, work_decimal num_2);
bool s21_is_work_greater_or_equal(work_decimal num_1, work_decimal num_2);
bool s21_is_work_equal(work_decimal num_1, work_decimal num_2);
//*----
#endif  // MEGA_HOROSH_DECIMAL_S21_DECIMAL_H