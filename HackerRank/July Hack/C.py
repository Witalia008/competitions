# Enter your code here. Read input from STDIN. Print output to STDOUT
# Enter your code here. Read input from STDIN. Print output to STDOUT
BASE = 10 ** 4


class Long(object):
    def __init__(self, numb):
        self.n = []
        while numb:
            self.n.append(numb % BASE)
            numb /= BASE

    def __imul__(self, numb):
        l1 = len(self.n)
        l2 = len(numb.n)
        res = Long(0)
        res.n = [0 for i in range(l1 + l2)]
        for i in range(l1):
            p = j = 0
            while j < l2 or p:
                r = self.n[i] * (numb.n[j] if j < l2 else 0) + p + res.n[i + j]
                res.n[i + j] = r % BASE
                p = r / BASE
                j += 1
        last = len(res.n) - 1
        while res.n[last] == 0 and last > 0:
            last -= 1
        res.n = res.n[max(last - 10, 0) : last + 1]
        return res

    def __repr__(self):
        x = self.n[::-1]
        res = ""
        for i in range(len(x)):
            if i:
                res = res + "%04d" % (x[i])
            else:
                res += str(x[i])
        return res


def power(a, k):
    res = Long(1)
    while k:
        if k & 1:
            res *= a
        a *= a
        k >>= 1
    return res


def pow_mod(a, k, p):
    res = 1
    while k:
        if k & 1:
            res = (res * a) % p
        a = (a * a) % p
        k >>= 1
    return res


T = int(raw_input())
for _t in range(T):
    n, k = map(int, raw_input().split())
    p = 10 ** k
    a = int(power(Long(2), n - 1).__repr__()[0:k])
    b = pow_mod(2, n - 1, p)
    print a + b
