#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int C[1005][1005], F[1005][1005];
int queue[1005], f[1005], pos[1005];

int main()
{
    freopen("ways.dat", "r", stdin);
    freopen("ways.sol", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int N = n * m * 2;
    memset(C, 0, sizeof(C));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            scanf("%d", &a);
            C[(i - 1) * n * 2 + j][(i - 1) * n * 2 + n + j] = 1;
            for (int k = 1; k <= a; k++)
            {
                int c;
                scanf("%d", &c);
                C[(i - 1) * n * 2 + n + j][i * n * 2 + c] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        C[(m - 1) * n * 2 + i][(m - 1) * n * 2 + n + i] = 1;
    for (int i = 1; i <= n; i++)
        C[0][i] = 1;
    for (int i = 1; i <= n; i++)
        C[(m - 1) * n * 2 + n + i][N + 1] = 1;
    int maxflow = 0;
    memset(F, 0, sizeof(F));
    while (true)
    {
        int H = 0, T = 1;
        queue[0] = 0;
        memset(f, -1, sizeof(f));
        memset(pos, -1, sizeof(pos));
        pos[0] = 0;
        while (H < T)
        {
            int v = queue[H];
            H++;
            pos[v] = -1;
            for (int i = 1; i <= N + 1; i++)
                if (C[v][i] - F[v][i] > 0 && f[i] == -1 && pos[i] == -1)
                {
                    f[i] = v;
                    queue[T] = i;
                    pos[i] = T;
                    T++;
                }
        }
        if (f[N + 1] == -1)
            break;
        int c = f[N + 1];
        while (c > 0)
        {
            F[f[c]][c]++;
            F[c][f[c]]--;
            c = f[c];
        }
        maxflow++;
    }
    printf("%d\n", maxflow);
    return 0;
}
