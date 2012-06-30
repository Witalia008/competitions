#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef unsigned long long ULL;

const char *infile = "pattern.in";
const char *outfile = "pattern.out";
const int nmax = 8;
const int mm = 1 << (nmax << 1);
const int INF = 10000000000;

struct TBar
{
    int type, cost;
    int color[3];
};

inline int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int A[nmax][nmax];
int F[nmax][2][mm];
int N, M, K;
TBar Bars[10];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < K; i++)
    {
        scanf("%d%d", &Bars[i].type, &Bars[i].cost);
        int c;
        switch (Bars[i].type)
        {
        case 1:
            c = 1;
            break;
        case 2:
            c = 2;
            break;
        default:
            c = 3;
        }
        for (int k = 0; k < c; k++)
            scanf("%d", &Bars[i].color[k]);
    }

    int MaxMask = 1 << (N << 1);
    for (int i = 0; i < nmax; i++)
        for (int c = 0; c < mm; c++)
            F[i][0][c] = INF;
    F[0][0][0] = 0;

    for (int j = 0; j < M; j++)
    {
        for (int x = 0; x < N; x++)
            for (int mask = 0; mask < MaxMask; mask++)
                F[x][!(j & 1)][mask] = INF;
        for (int x = 0; x < N; x++)
        {
            for (int mask = 0; mask < MaxMask; mask++)
            {
                if (A[x][j] == 2 || mask & 1)
                {
                    F[(x + 1) % N][(j + (x + 1) / N) & 1][mask >> 1] = min(F[x][j & 1][mask], F[(x + 1) % N][(j + (x + 1) / N) & 1][mask >> 1]);
                }
                else
                {
                    for (int k = 0; k < K; k++)
                    {
                        switch (Bars[k].type)
                        {
                        case 1:
                            if (A[x][j] == Bars[k].color[0])
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][mask >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][mask >> 1]);
                            break;
                        case 2:
                            //gorisontal position
                            if (j < M - 1 && A[x][j] == Bars[k].color[0] && A[x][j + 1] == Bars[k].color[1] && !((mask >> N) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) >> 1)] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) >> 1)]);
                            //reverse gorisontal position
                            if (j < M - 1 && A[x][j] == Bars[k].color[1] && A[x][j + 1] == Bars[k].color[0] && !((mask >> N) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) >> 1)] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) >> 1)]);
                            //vertical position
                            if (x < N - 1 && A[x][j] == Bars[k].color[0] && A[x + 1][j] == Bars[k].color[1] && !(mask & 2))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) | 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) | 1]);
                            //reverse vertical position
                            if (x < N - 1 && A[x][j] == Bars[k].color[1] && A[x + 1][j] == Bars[k].color[0] && !(mask & 2))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) | 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) | 1]);
                            break;
                        case 3:
                            //gorisontal position
                            if (j < M - 2 && A[x][j] == Bars[k].color[0] && A[x][j + 1] == Bars[k].color[1] && A[x][j + 2] == Bars[k].color[2] && !((mask >> N) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N << 1))) >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (2 * N))) >> 1]);
                            //reverse gorisontal position
                            if (j < M - 2 && A[x][j] == Bars[k].color[2] && A[x][j + 1] == Bars[k].color[1] && A[x][j + 2] == Bars[k].color[0] && !((mask >> N) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N << 1))) >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (2 * N))) >> 1]);
                            //vertical position
                            if (x < N - 2 && A[x][j] == Bars[k].color[0] && A[x + 1][j] == Bars[k].color[1] && A[x + 2][j] == Bars[k].color[2] && !(mask & 2) && !(mask & 4))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) + 3] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) + 3]);
                            //reverse vertical position
                            if (x < N - 2 && A[x][j] == Bars[k].color[2] && A[x + 1][j] == Bars[k].color[1] && A[x + 2][j] == Bars[k].color[0] && !(mask & 2) && !(mask & 4))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) + 3] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][(mask >> 1) + 3]);
                            break;
                        case 4:
                            //gorisontal position
                            if (x < N - 1 && j < M - 1 && A[x][j] == Bars[k].color[0] && A[x][j + 1] == Bars[k].color[1] && A[x + 1][j + 1] == Bars[k].color[2] && !((mask >> N) & 1) && !((mask >> N) & 2))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N + 1))) >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N + 1))) >> 1]);
                            //gor. pos. + 90 degrees
                            if (j < M - 1 && x > 0 && A[x][j] == Bars[k].color[2] && A[x][j + 1] == Bars[k].color[1] && A[x - 1][j + 1] == Bars[k].color[0] && !((mask >> N) & 1) && !((mask >> (N - 1)) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N - 1))) >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | (1 << (N - 1))) >> 1]);
                            //gor. pos. + 180 degrees
                            if (x < N - 1 && j < M - 1 && A[x][j] == Bars[k].color[2] && A[x + 1][j] == Bars[k].color[1] && A[x + 1][j + 1] == Bars[k].color[0] && !(mask & 2) && !((mask >> (N + 1)) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask >> 1) | 1) | (1 << N)] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask >> 1) | 1) | (1 << N)]);
                            //gor. pos. + 270 degrees
                            if (x < N - 1 && j < M - 1 && A[x][j] == Bars[k].color[1] && A[x + 1][j] == Bars[k].color[0] && A[x][j + 1] == Bars[k].color[2] && !(mask & 2) && !((mask >> N) & 1))
                                F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | 2) >> 1] = min(F[x][j & 1][mask] + Bars[k].cost, F[(x + 1) % N][(j + (x + 1) / N) & 1][((mask | (1 << N)) | 2) >> 1]);
                            break;
                        }
                    }
                }
            }
        }
    }
    if (F[0][M & 1][0] == INF)
        printf("-1\n");
    else
        printf("%d\n", F[0][M & 1][0]);
    return 0;
}
