import random


def generate_random_hex():
    return hex(random.randint(0, 0xFFFFFFFFFFFF))[2:]


print("0000", end="")
print(generate_random_hex())
print(random.randint(0, 28))
print(random.randint(0, 1))
print("0000", end="")
print(generate_random_hex())
print(random.randint(0, 28))
print(random.randint(0, 1))
num = random.randint(1, 4)

if num == 1:
    print("+")
elif num == 2:
    print("-")
elif num == 3:
    print("*")
else:
    print("/")
