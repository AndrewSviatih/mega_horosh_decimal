from decimal import Decimal


def preobrazovanie(num, scale, sign):
    if sign:
        num = -num
    num = Decimal(num)
    while scale > 0:
        num /= 10
        scale -= 1
    return num


num_1 = int(input(), 16)
print(num_1)
scale_1 = int(input())
print(scale_1)
sign_1 = int(input())
print(sign_1)
num_1 = preobrazovanie(num_1, scale_1, sign_1)
print(num_1)

num_2 = int(input(), 16)
scale_2 = int(input())
sign_2 = int(input())
num_2 = preobrazovanie(num_2, scale_2, sign_2)

operacion = input()

if operacion == "+":
    print(num_1 + num_2)
elif operacion == "-":
    print(num_1 - num_2)
elif operacion == "/":
    print(num_1 / num_2)
elif operacion == "*":
    print(num_1 * num_2)
