
#include "s21_decimal.h"
void printBinary(int num) {
    int i;
    for (i = sizeof(int) * 8 - 1; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main () {

  unsigned char var = 11;
  unsigned char not_var = 10;

  unsigned char res = var & not_var;

  if ((var & not_var) == not_var) {
    printf("bit is on\n");
  } else {
    printf("no\n");
  }

  printf("%d %d %d\n", var, not_var, res);
  printBinary(var);
  printBinary(not_var);
  printBinary(res);
}