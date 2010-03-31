#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

#define nmax 9
#define mmax 101
#define MaxMask (1 << nmax)

typedef vector<int> VI;

int N, M, K, cou;
bool beauty[16];
int F[2][nmax][MaxMask][3];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    scanf("%d", &cou);
    for (int i = 0; i < cou; i++)
    {
        int a1, a2, a3, a4;
        scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
        beauty[a1 * 8 + a2 * 4 + a3 * 2 + a4] = true;
    }

    F[0][0][0][2] = 1;
    K = (1 << N);
    for (int i = 0; i < M; i++)
    {
        memset(F[1 - i % 2], 0, sizeof(F[1 - i % 2]));
        for (int x = 0; x < N; x++)
            for (int mask = 0; mask < K; mask++)
                for (int b = 0; b < 2 + (x == 0 || i == 0) ? 1 : 0; b++)
                {
                    int nx = ((x > 0) ? (mask >> (x - 1)) % 2 : 2), nx_1 = ((i == 0) ? 2 : (mask >> x) % 2);
                    for (int curr = 0; curr < 2; curr++)
                    {
                        if (beauty[b * 8 + nx * 4 + nx_1 * 2 + curr] || b == 2 || nx == 2 || nx_1 == 2)
                        {
                            if (curr == 0)
                            {
                                F[(i + (x + 1) / N) % 2][(x + 1) % N][((mask >> x) % 2) ? mask - (1 << x) : mask][(x < N - 1) ? nx_1 : 2] += F[i % 2][x][mask][b];
                            }
                            else
                            {
                                F[(i + (x + 1) / N) % 2][(x + 1) % N][((mask >> x) % 2) ? mask : mask + (1 << x)][(x < N - 1) ? nx_1 : 2] += F[i % 2][x][mask][b];
                            }
                        }
                    }
                }
    }

    int ans = 0;
    for (int mask = 0; mask < K; mask++)
        ans += F[M % 2][0][mask][2];
    printf("%d\n", ans);
    return 0;
}
