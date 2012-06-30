#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NMAX 12
#define MMAX 1 << NMAX

typedef long long ll;

int n, m, k;
ll F[NMAX][NMAX][MMAX];

int main()
{
    freopen("drahir.in", "r", stdin);
    freopen("drahir.out", "w", stdout);
    scanf("%d%d", &m, &n);
    F[0][0][0] = 1;
    k = 1 << n;
    REP(j, m)
    REP(x, n)
    REP(mask, k)
    {
        F[j + (x + 1) / n][(x + 1) % n][mask ^ (1 << x)] += F[j][x][mask];
        if (x + 3 <= n && !(mask & (1 << x)) && !(mask & (1 << (x + 1))) && !(mask & (1 << (x + 2))))
            F[j + (x + 3) / n][(x + 3) % n][mask] += F[j][x][mask];
    }
    cout << F[m][0][0] << endl;
    return 0;
}
