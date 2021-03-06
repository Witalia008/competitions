MOD = 10 ** 9 + 7


def power(n, k):
    res, a, b = 1, n, k
    while b:
        if b & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b = b >> 1
    return res


s = raw_input()
k = int(raw_input())
n = len(s)
ans = 0
P = power(2, n * (k - 1) + n) - 1
Q = power(2, n) - 1
P = (P * power(Q, MOD - 2)) % MOD
poww = 1
for i in range(0, n):
    if s[i] in ["0", "5"]:
        x = (P * poww) % MOD
        ans = (ans + x) % MOD
    poww = (poww * 2) % MOD
print ans
