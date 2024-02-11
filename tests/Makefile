s21_decimal:
	clang -c ../s21_decimal_lib/arithmetic.c -o arithmetic.o
	clang -c ../s21_decimal_lib/equal.c -o equal.o
	clang decimal.c arithmetic.o equal.o -o decimal
clean:
	rm -rf arithmetic.o decimal
