#include <stdint.h>
#include <stdio.h>

#include "../s21_decimal_lib/s21_decimal.h"

void printConsole(s21_decimal num);
void printConsoleWork(work_decimal num);
void printdiv(s21_decimal num_1, s21_decimal num_2);
void printdivost(s21_decimal num_1, s21_decimal num_2);
void printadd(s21_decimal num_1, s21_decimal num_2);
void printsub(s21_decimal num_1, s21_decimal num_2);
void printmul(s21_decimal num_1, s21_decimal num_2);

uint32_t readHexInput() {
  char hex_str[9];  // Массив для хранения 8 символов + завершающий нуль
  uint32_t result;

  // Запрашиваем ввод шестнадцатеричного числа
  scanf("%8s", hex_str);

  // Используем функцию sscanf для преобразования строки в 32-битное беззнаковое
  // целое число
  sscanf(hex_str, "%x", &result);

  return result;
}

uint32_t readSignScale() {
  uint32_t res = 0, scale = 0, sign = 0;
  scanf("%d ", &scale);
  scanf("%d", &sign);
  if (scale > 28) scale = 0;
  if (sign > 1) sign = 0;
  res = ((sign << 15) + scale) << 16;

  return res;
}

int main(void) {
  s21_decimal num_1, num_2;
  num_1.bits[1] = readHexInput();
  num_1.bits[0] = readHexInput();
  num_1.bits[2] = 0x00000000;
  num_1.bits[3] = readSignScale();

  num_2.bits[1] = readHexInput();
  num_2.bits[0] = readHexInput();
  num_2.bits[2] = 0x00000000;
  num_2.bits[3] = readSignScale();

  // printf("num_1: ");
  // printConsole(num_1);
  // printf("num_2: ");
  // printConsole(num_2);

  char num = 0;
  scanf(" %c", &num);
  // ----------Сложение------------
  if (num == '+') printadd(num_1, num_2);
  // ----------Вычитание-----------
  else if (num == '-')
    printsub(num_1, num_2);
  // ----------Умножение-----------
  else if (num == '*')
    printmul(num_1, num_2);
  // ----------Деление-------------
  else if (num == '/')
    printdiv(num_1, num_2);
  // ----------Деление с остатком--
  // printdivost(num_1, num_2);
  // ----------больше--------------
  else if (num == '>')
    printf("%d\n", s21_is_greater(num_1, num_2));
  // ----------больше или равно----
  else if (num == '.')
    printf("%d\n", s21_is_greater_or_equal(num_1, num_2));
  // ----------меньше--------------
  else if (num == '<')
    printf("%d\n", s21_is_less(num_1, num_2));
  // ----------меньше или равно----
  else if (num == ',')
    printf("%d\n", s21_is_less_or_equal(num_1, num_2));
  // ----------равно---------------
  else if (num == '=')
    printf("%d\n", s21_is_equal(num_1, num_2));
  // ---------- не равно-----------
  else if (num == '!')
    printf("%d\n", s21_is_not_equal(num_1, num_2));

  return 0;
}

void printsub(s21_decimal num_1, s21_decimal num_2) {
  s21_decimal res;
  // printf("Вычитание: \n");
  int num = s21_sub(num_1, num_2, &res);
  if (num) {
    printf("ОШИБКА %d\n", num);
  }

  // printf("res: = ");
  printConsole(res);
}

void printmul(s21_decimal num_1, s21_decimal num_2) {
  s21_decimal res;
  // printf("Умножение: \n");
  int num = s21_mul(num_1, num_2, &res);
  if (num) {
    printf("ОШИБКА %d\n", num);
  }

  // printf("res: = ");
  printConsole(res);
}

void printadd(s21_decimal num_1, s21_decimal num_2) {
  s21_decimal res;
  // printf("Сложение: \n");
  int num = s21_add(num_1, num_2, &res);
  if (num) {
    printf("ОШИБКА %d\n", num);
  }

  // printf("res: = ");
  printConsole(res);
}

void printdiv(s21_decimal num_1, s21_decimal num_2) {
  s21_decimal res;
  // printf("Деление: \n");
  int num = s21_div(num_1, num_2, &res);
  if (num) {
    printf("ОШИБКА %d\n", num);
  }

  // printf("res: = ");
  printConsole(res);
}

void printdivost(s21_decimal num_1, s21_decimal num_2) {
  work_decimal work_num_1 = conversion(num_1);
  work_decimal work_num_2 = conversion(num_2);
  work_decimal work_res, work_remainder;
  work_remainder = divisionWithRemainder(work_num_1, work_num_2, &work_res);

  printf("Деление с остатком: \n");
  printf("work_res: ");
  printConsoleWork(work_res);

  printf("work_remainder: ");
  printConsoleWork(work_remainder);

  printf("\n");
}

void funcPoPricoluGCC(uint64_t gg) {
  if (gg < 0x10000000) {
    printf("0");
    if (gg < 0x1000000) {
      printf("0");
      if (gg < 0x100000) {
        printf("0");
        if (gg < 0x10000) {
          printf("0");
          if (gg < 0x1000) {
            printf("0");
            if (gg < 0x100) {
              printf("0");
              if (gg < 0x10) {
                printf("0");
              }
            }
          }
        }
      }
    }
  }
}

void printConsole(s21_decimal num) {
  if (num.bits[3] & MINUS) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  uint64_t gg;
  for (int i = 2; i >= 0; i--) {
    gg = num.bits[i] & MAX4BITE;
    funcPoPricoluGCC(gg);
    printf("%lx", gg);
  }
  printf("\n");
  int scale = ((num.bits[3] & SC) >> 16);
  printf("%d\n", scale);
}

void printConsoleWork(work_decimal num) {
  uint64_t gg;
  for (int i = 6; i >= 0; i--) {
    gg = num.bits[i] & MAX4BITE;
    printf("%lx", gg);
  }
  printf("\n");
}
