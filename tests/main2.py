from decimal import Decimal

num = int(input(), 16)
num = Decimal(num)
scale = int(input())
while scale > 0:
    num /= 10
    scale -= 1

print(num)
