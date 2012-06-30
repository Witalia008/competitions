#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define nmax 1100
#define INF 10000000000000000

using namespace std;

int N, M;
int A[nmax][(nmax * 3) / 4];
long long Ans[nmax][(nmax * 3) / 4][2][2];

long long max(long long a, long long b)
{
    if (a < b)
        return b;
    else
        return a;
}

int main()
{
    freopen("maxsum.in", "r", stdin);
    freopen("maxsum.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &A[i][j]);
    for (int j = 1; j <= M; ++j)
        for (int wl = 0; wl <= 1; wl++)
            for (int wr = 0; wr <= 1; wr++)
                Ans[1][j][wl][wr] = -INF;
    for (int j = 2; j < M; ++j)
        Ans[1][j][false][false] = A[1][j];
    Ans[1][1][true][false] = A[1][1];
    Ans[1][M][false][true] = A[1][M];
    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            for (int wl = 0; wl <= 1; wl++)
                for (int wr = 0; wr <= 1; wr++)
                {
                    if (j > 1 && j < M)
                        Ans[i][j][wl][wr] = max(Ans[i - 1][j - 1][wl][wr],
                                                max(Ans[i - 1][j][wl][wr], Ans[i - 1][j + 1][wl][wr])) +
                                            A[i][j];
                    if (j == 1)
                    {
                        if (wl == false)
                            Ans[i][1][wl][wr] = -INF;
                        if (wl == true)
                            Ans[i][1][wl][wr] = max(Ans[i - 1][1][true][wr],
                                                    max(Ans[i - 1][2][true][wr], Ans[i - 1][2][false][wr])) +
                                                A[i][j];
                    }
                    if (j == M)
                    {
                        if (wr == false)
                            Ans[i][M][wl][false] = -INF;
                        if (wr == true)
                            Ans[i][M][wl][wr] = max(Ans[i - 1][M][wl][true],
                                                    max(Ans[i - 1][M - 1][wl][true], Ans[i - 1][M - 1][wl][false])) +
                                                A[i][j];
                    }
                }
    long long max = Ans[N][1][true][true];
    for (int j = 2; j <= M; ++j)
        if (Ans[N][j][true][true] > max)
            max = Ans[N][j][true][true];
    cout << max << endl;
    return 0;
}
