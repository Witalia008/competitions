import os
import sys
import time
from functools import partial


TEST_RUN = True

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

        ...

    end = time.time()
    debug_print(f"Execution time: {end - start}")


if __name__ == "__main__":
    main()
