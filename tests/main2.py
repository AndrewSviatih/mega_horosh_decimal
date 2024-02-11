from decimal import Decimal

sign = int(input())
num = int(input(), 16)
num = Decimal(num)
scale = int(input())
while scale > 0:
    num /= 10
    scale -= 1


if sign == 1:
    print("-", end="")
print(round(num, 10))
