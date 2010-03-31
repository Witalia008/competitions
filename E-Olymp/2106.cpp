#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define N 101

struct TLong
{
    int len;
    char sign;
    int n[N + 1];
    void input()
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            sign = '-';
            s.erase(0, 1);
        }
        else
            sign = '+';
        len = s.length();
        REP(i, len)
        n[N - len + i + 1] = s[i] - '0';
    }
    void output()
    {
        if (len == 1 && n[N] == 0)
            sign = '+';
        if (sign == '-')
            cout << '-';
        REP(i, len)
        cout << n[N - len + 1 + i];
        cout << endl;
    }
    void longlen()
    {
        len = N + 1;
        while (len != 1 && !n[N - len + 1])
            --len;
    }
};

bool comp(TLong a, TLong b)
{
    int i = 0;
    while (i < N && a.n[i] == b.n[i])
        ++i;
    if (a.n[i] < b.n[i])
        return false;
    return true;
}

TLong minus_abs(TLong a, TLong b)
{
    TLong res;
    CLR(res.n, 0);
    int z = 0;
    FORD(i, N, 0)
    {
        res.n[i] = a.n[i] - b.n[i] - z;
        if (res.n[i] < 0)
        {
            res.n[i] += 10;
            z = 1;
        }
        else
            z = 0;
    }
    res.longlen();
    return res;
}

TLong add_abs(TLong a, TLong b)
{
    TLong res;
    CLR(res.n, 0);
    int p = 0;
    FORD(i, N, 0)
    {
        res.n[i] = a.n[i] + b.n[i] + p;
        p = res.n[i] / 10;
        res.n[i] %= 10;
    }
    res.longlen();
    return res;
}

TLong Add(TLong a, TLong b)
{
    TLong res;
    if (a.sign == b.sign)
    {
        res = add_abs(a, b);
        res.sign = a.sign;
    }
    else
    {
        if (comp(a, b))
        {
            res = minus_abs(a, b);
            res.sign = a.sign;
        }
        else
        {
            res = minus_abs(b, a);
            res.sign = b.sign;
        }
    }
    return res;
}

TLong a, b, c;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    a.input();
    b.input();
    c = Add(a, b);
    c.output();
    return 0;
}
