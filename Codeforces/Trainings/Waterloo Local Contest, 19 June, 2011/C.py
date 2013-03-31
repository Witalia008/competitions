from random import randint
from fractions import gcd


def fibo(n):
    a = 1
    b = 1
    nom = 2
    while nom < n:
        a, b = b, a + b
        nom += 1
    return b


n = input()
n = int(n)
print(fibo(n))
