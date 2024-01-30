
#include "s21_decimal.h"

void printBinary(int num) {
    int i;
    for (i = sizeof(int) * 8 - 1; i >= 0; --i) {
        printf("%d", (num >> i) & 1);

        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main () {

  int var = -9;
  int not_var = 1;

  if (var & MINUS) {
    printf("minus\n");
  } else {
    printf("plus\n");
  }

  unsigned char res = var | MINUS;

  if (not_var & MINUS) {
    printf("minus\n");
  } else {
    printf("plus\n");
  }

  printf("%d %d %d\n", var, not_var, res);
  printBinary(var);
  printBinary(not_var);
  printBinary(res);

  return 0;
}