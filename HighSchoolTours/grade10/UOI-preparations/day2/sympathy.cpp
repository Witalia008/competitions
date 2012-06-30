#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#define nmax 1024
#define mmax 5
#define D 1000000000

using namespace std;

struct TLong
{
    int num[mmax + 1];
};

int N, M;
bool A[nmax + 1][nmax + 1];
TLong F[nmax][nmax];

bool good(int a, int b, int N)
{
    for (int i = 1; i < N; i++, a /= 2, b /= 2)
        if ((a & 1) == (b & 1) && (a & 1) == ((b >> 1) & 1) && (a & 1) == ((a >> 1) & 1) && ((a >> 1) & 1) == ((b >> 1) & 1))
            return false;
    return true;
}

void Sum(TLong &a, TLong &b)
{
    int p = 0;
    for (int i = mmax; i > 0; i--)
    {
        a.num[i] += b.num[i] + p;
        p = a.num[i] / D;
        a.num[i] %= D;
    }
}

int main()
{
    freopen("sympathy.in", "r", stdin);
    freopen("sympathy.out", "w", stdout);
    cin >> N >> M;
    if (N > M)
        swap(N, M);
    int n = 1;
    for (int i = 1; i <= N; i++)
        n *= 2;
    for (int i = 0; i < n; i++)
        for (int ii = 0; ii <= i; ii++)
            A[i][ii] = good(i, ii, N), A[ii][i] = A[i][ii];
    for (int i = 0; i < n; i++)
        F[1][i].num[mmax] = 1;
    for (int i = 2; i <= M; i++)
        for (int m1 = 0; m1 < n; m1++)
            for (int m2 = 0; m2 < n; m2++)
                if (A[m2][m1])
                    Sum(F[i][m1], F[i - 1][m2]);
    for (int m = 1; m < n; m++)
        Sum(F[M][m], F[M][m - 1]);
    int c = 1;
    while (F[M][n - 1].num[c] == 0 && c < mmax)
        c++;
    cout << F[M][n - 1].num[c];
    c++;
    for (; c <= mmax; c++)
        printf("%09d", F[M][n - 1].num[c]);
    cout << endl;
    return 0;
}
