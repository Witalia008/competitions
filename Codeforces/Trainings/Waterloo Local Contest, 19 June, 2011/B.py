from random import randint
from fractions import gcd


def MonteCarlo(m):
    maxsteps = 1000000
    step = 0

    b0 = randint(0, m)
    b1 = (b0 * b0 + 1) % m
    d = gcd(b1 - b0, m)

    while (step < maxsteps) and (d == 1):
        b0 = (b0 * b0 + 1) % m
        b1 = (b1 * b1 + 1) % m
        b1 = (b1 * b1 + 1) % m
        d = gcd(b1 - b0, m)
        step += 1

    if d == 1:
        return -1
    else:
        return d


while True:
    n = input()
    n = int(n)

    if n == -1:
        break
    i = 2
    while (i <= 1000000) and (n > 1):
        if n % i == 0:
            print(i)
            n /= i
        else:
            i += 1

    while n > 1:
        d = MonteCarlo(n)
        if d == -1:
            print(n)
            break
        else:
            print(int(d))
            n /= d
    print()
