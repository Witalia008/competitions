import os
import sys
import time
import math
from functools import partial
import json


TEST_RUN = False

debug_print = partial(print, file=sys.stderr) if TEST_RUN else lambda *args, **kwargs: None


N = 10_000_000

def sieve_of_eratosthenes(n):
    primes = []
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    return primes


def precompute_subtractorization(n, primes: list[int]):
    cnt = [0] * (n + 1)
    cnt[5] = 1  # for the 2 itself

    for i in range(2, len(primes)):
        if primes[i] == primes[i - 1] + 2:
            debug_print(f"2 + {primes[i - 1]} == {primes[i]}")
            cnt[primes[i]] += 1

    for i in range(1, n + 1):
        cnt[i] += cnt[i - 1]

    return cnt


def main():
    if "LOCAL_RUN" in os.environ:
        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
        debug_print("local run")

    start = time.time()

    primes = sieve_of_eratosthenes(N)
    cnt_subtractorizations = precompute_subtractorization(N, primes)

    debug_print(cnt_subtractorizations[:30])

    T = int(input())

    for t in range(T):
        print(f"Case #{t + 1}: ", end="")
        debug_print(f"Case #{t + 1}: ")

        n = int(input())

        print(cnt_subtractorizations[n])

    end = time.time()
    debug_print(f"Execution time: {end - start}")


if __name__ == "__main__":
    main()
