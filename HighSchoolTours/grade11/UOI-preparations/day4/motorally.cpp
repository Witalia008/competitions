#include <stdio.h>
#include <cstdlib>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define NMAX 55

typedef unsigned long long ll;

struct Matr
{
    int n;
    ll a[NMAX][NMAX];
};

Matr multi(Matr a, Matr b)
{
    Matr res;
    res.n = a.n;
    REP(i, a.n)
    REP(j, a.n)
    {
        res.a[i][j] = 0;
        REP(k, a.n)
        {
            res.a[i][j] += a.a[i][k] * b.a[k][j];
            res.a[i][j] %= MOD;
        }
    }
    return res;
}

Matr Power(Matr a, int k)
{
    Matr res;
    res.n = a.n;
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

int N, M, K;
ll ans;
Matr A, B;

int main()
{
    freopen("motorally.in", "r", stdin);
    freopen("motorally.out", "w", stdout);
    scanf("%d%d%d", &N, &M, &K);
    if (!K)
    {
        printf("1\n");
        return 0;
    }
    REP(i, M)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        b--;
        a--;
        A.a[a][b]++;
    }
    A.n = N;
    B = Power(A, K);
    REP(i, N)
    {
        ans += B.a[0][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}
