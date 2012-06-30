#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define MOD 1000000007
#define NMAX 12

typedef long long ll;

struct Matr
{
    int n, m;
    ll a[NMAX][NMAX];
};

Matr multi(Matr a, Matr b)
{
    Matr res;
    res.n = a.n;
    res.m = b.m;
    REP(i, res.n)
    REP(j, res.m)
    {
        res.a[i][j] = 0;
        REP(k, a.m)
        {
            res.a[i][j] += a.a[i][k] * b.a[k][j];
            res.a[i][j] %= MOD;
        }
    }
    return res;
}

Matr Power(Matr a, ll k)
{
    Matr res;
    res.n = a.n;
    res.m = a.m;
    REP(i, a.n)
    REP(j, a.n) res.a[i][j] = 0;
    REP(i, a.n)
    res.a[i][i] = 1;
    while (k)
    {
        if (k & 1)
            res = multi(res, a);
        a = multi(a, a);
        k >>= 1;
    }
    return res;
}

int n;
ll m;
Matr A, B, C;

int main()
{
    freopen("domino2.in", "r", stdin);
    freopen("domino2.out", "w", stdout);
    cin >> n >> m;
    if (m < n)
    {
        printf("1\n");
        return 0;
    }
    A.n = n;
    A.m = n;
    A.a[n - 1][0] = A.a[n - 1][n - 1] = 1;
    REP(i, A.n - 1)
    A.a[i][i + 1] = 1;
    B = Power(A, m - n + 1);
    A.m = 1;
    REP(i, n)
    A.a[i][0] = 1;
    C = multi(B, A);
    cout << C.a[n - 1][0] % MOD << endl;
    return 0;
}
