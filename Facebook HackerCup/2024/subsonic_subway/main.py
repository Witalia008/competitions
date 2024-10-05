import os
import sys
import time
import math
from functools import partial


TEST_RUN = False

debug_print = partial(print, file=sys.stderr) if TEST_RUN else lambda *args, **kwargs: None


def main():
    if "LOCAL_RUN" in os.environ:
        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
        debug_print("local run")

    start = time.time()

    T = int(input())

    for t in range(T):
        print(f"Case #{t + 1}: ", end="")
        debug_print(f"Case #{t + 1}: ")

        n = int(input())
        lower, upper = 0, math.pi / 2
        debug_print(n)

        for i in range(1, n + 1):
            a, b = list(map(int, input().split(" ")))
            debug_print(i, a, b)

            l = math.atan2(a, i)
            r = math.atan2(b, i)

            debug_print(f"{l} - {r}")

            lower = max(lower, l)
            upper = min(upper, r)

        if lower > upper + 1e-7:
            print(-1)
        else:
            print(f"{1 / math.tan(upper):.6f}")

    end = time.time()
    debug_print(f"Execution time: {end - start}")


if __name__ == "__main__":
    main()
