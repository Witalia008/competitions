import os
import sys
import time


def main():
    if "LOCAL_RUN" in os.environ:
        sys.stdin = open("input.txt", "r")
        sys.stdout = open("output.txt", "w")
        print("local run", file=sys.stderr)

    start = time.time()

    T = int(input())

    for t in range(T):
        print(f"Case #{t + 1}: ", end="")

        ...

    end = time.time()
    print(f"Execution time: {end - start}", file=sys.stderr)


if __name__ == "__main__":
    main()
