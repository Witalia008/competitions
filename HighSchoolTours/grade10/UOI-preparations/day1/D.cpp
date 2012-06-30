#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define nmax 50

using namespace std;

struct TLong
{
    int num[nmax + 1];
};

TLong Sum(TLong a, TLong b)
{
    int p = 0;
    TLong res;
    memset(res.num, 0, sizeof(res.num));
    for (int i = nmax; i >= 1; i--)
    {
        res.num[i] = a.num[i] + b.num[i] + p;
        p = res.num[i] / 10;
        res.num[i] %= 10;
    }
    return res;
}

TLong Multi(TLong a, int b)
{
    int p = 0;
    TLong res;
    memset(res.num, 0, sizeof(res.num));
    for (int i = nmax; i >= 1; i--)
    {
        res.num[i] = a.num[i] * b + p;
        p = res.num[i] / 10;
        res.num[i] %= 10;
    }
    return res;
}

void Out(TLong &a)
{
    int s = 1;
    while (a.num[s] == 0 && s < nmax)
        s++;
    for (int i = s; i <= nmax; i++)
        printf("%d", a.num[i]);
    cout << endl;
}

int N, K;
int D[10];
TLong F[10][10][10][10];

int main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        D[i] = r - l + 1;
    }
    F[0][0][0][0].num[nmax] = 1;
    for (int i = 1; i <= N; i++)
        for (int a = 0; a <= K; a++)
            for (int b = 0; b <= K; b++)
                for (int c = 0; c <= K; c++)
                {
                    F[i][a][b][c] = F[i - 1][a][b][c];
                    if (a > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a - 1][b][c], D[i]), F[i][a][b][c]);
                    if (b > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a][b - 1][c], D[i]), F[i][a][b][c]);
                    if (c > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a][b][c - 1], D[i]), F[i][a][b][c]);
                    if (a > 0 && b > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a - 1][b - 1][c], D[i] * (D[i] - 1)), F[i][a][b][c]);
                    if (a > 0 && c > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a - 1][b][c - 1], D[i] * (D[i] - 1)), F[i][a][b][c]);
                    if (b > 0 && c > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a][b - 1][c - 1], D[i] * (D[i] - 1)), F[i][a][b][c]);
                    if (a > 0 && b > 0 && c > 0)
                        F[i][a][b][c] = Sum(Multi(F[i - 1][a - 1][b - 1][c - 1], D[i] * (D[i] - 1) * (D[i] - 2)), F[i][a][b][c]);
                }
    Out(F[N][K][K][K]);
    return 0;
}
