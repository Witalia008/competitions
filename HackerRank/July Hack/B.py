# Enter your code here. Read input from STDIN. Print output to STDOUT
MOD = 10 ** 9 + 7


def power(a, k):
    res = 1
    while k:
        if k & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        k >>= 1
    return res


def facts(n):
    f = 1
    for i in range(0, n + 1):
        if i:
            f = (f * i) % MOD
        yield f


s = raw_input()
cnt_odd = 0
alph = "qwertyuioplkjhgfdsazxcvbnm"
al = []
for i in alph:
    cnt = s.count(i)
    cnt_odd += cnt % 2
    al.append(cnt / 2)
if cnt_odd < 2:
    # if has any
    n = len(s) / 2
    fact = list(facts(n))
    ans = fact[n]
    for i in al:
        ans = (ans * power(fact[i], MOD - 2)) % MOD
    print ans
else:
    print 0
