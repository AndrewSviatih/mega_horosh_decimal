import random


def generate_random_hex():
    return hex(random.randint(0, 0xFFFFFFFFFFFFFFFF))[2:]


print(generate_random_hex())
print()
