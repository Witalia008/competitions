#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const ULL MOD = (1 << 30) + 1;
const int nmax = 17;
const ULL Mmax = (1 << 18);

inline void AddMod(ULL &a, ULL b)
{
    a = (a + b) % MOD;
}

int N, M;
ULL ans;
ULL F[2][nmax][Mmax];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen ("sympathy.in", "r", stdin);freopen ("symapthy.out", "w", stdout);
    scanf("%d%d", &N, &M);
    if (N > M)
        swap(N, M);

    int K = 1 << (N + 1);
    F[0][0][0] = 1;
    for (int j = 0; j < M; j++)
    {
        memset(F[!(j & 1)], 0, sizeof(F[!(j & 1)]));
        for (int x = 0; x < N; x++)
            for (int mask = 0; mask < K; mask++)
                if (F[j & 1][x][mask])
                {
                    if (j == 0 || x == 0)
                    {
                        AddMod(F[(j + (x + 1) / N) & 1][(x + 1) % N][(x || x == N - 1) ? (mask) : (mask << 1)], F[j & 1][x][mask]);
                        AddMod(F[(j + (x + 1) / N) & 1][(x + 1) % N][(x || x == N - 1) ? (mask ^ (1 << x)) : ((mask << 1) | 1)], F[j & 1][x][mask]);
                    }
                    else
                    {
                        bool nx_0, nx__1, nx_1;
                        nx_0 = (mask >> x) & 1;
                        nx__1 = (mask >> (x - 1)) & 1;
                        nx_1 = (mask >> (x + 1)) & 1;
                        int mi = 0;
                        if (x == N - 1 && (mask >> N) & 1)
                            mi = (1 << N);
                        AddMod(F[(j + (x + 1) / N) & 1][(x + 1) % N][(mask ^ (1 << x)) - mi], F[j & 1][x][mask]);
                        if (!(nx_0 == nx_1 && nx_0 == nx__1))
                            AddMod(F[(j + (x + 1) / N) & 1][(x + 1) % N][mask - mi], F[j & 1][x][mask]);
                    }
                }
    }

    for (int mask = 0; mask < K; mask++)
        AddMod(ans, F[M & 1][0][mask]);
    cout << ans << endl;
    return 0;
}
