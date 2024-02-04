#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MINUS 0x80000000     // 10000000 00000000 00000000 00000000
#define SC 0x00ff0000        // 00000000 11111111 00000000 00000000
#define MAX4BITE 0xffffffff  // 11111111 11111111 11111111 11111111

// структура decimal
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
// Нормализация рабочего decimal
bool normalization(work_decimal* num);
// Неполное вычитание
void incompleteSubtraction(work_decimal work_num_1, work_decimal work_num_2,
                           work_decimal* work_res);

// Arithmetic Operators
//  Сложение
bool s21_add(s21_decimal num_1, s21_decimal num_2, s21_decimal* res);
// Вычитание
bool s21_sub(s21_decimal num_1, s21_decimal num_2, s21_decimal* res);
//---

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