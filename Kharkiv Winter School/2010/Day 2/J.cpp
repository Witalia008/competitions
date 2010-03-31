#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";
const int nmax = 100000;
const int kmax = 18;
const int amax = 1000000000;

int CntBits(int N)
{
    int res = 0;
    while (N)
    {
        res++;
        N /= 2;
    }
    return res;
}

int N, M;
int u, v, ans, l, u1, v1;
int a[nmax];
int rmq[kmax][nmax];
int p2[kmax];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d%d", &N, &M, &a[0]);
    scanf("%d%d", &u, &v);
    u--;
    v--;
    rmq[0][0] = a[0];
    for (int i = 1; i < N; i++)
    {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
        rmq[0][i] = a[i];
    }
    p2[0] = 1;
    for (int i = 1; i < kmax; i++)
        p2[i] = p2[i - 1] << 1;

    int K = CntBits(N) + 1;
    for (int k = 1; k < K; k++)
        for (int i = 0; i < N; i++)
            rmq[k][i] = min(rmq[k - 1][i], (i + p2[k - 1] < N) ? rmq[k - 1][i + p2[k - 1]] : amax);

    for (int i = 0; i < M; i++)
    {
        u1 = u, v1 = v;
        if (u1 > v1)
            swap(u1, v1);

        l = CntBits(v1 - u1 + 1) - 1;
        ans = min(rmq[l][u1], rmq[l][v1 - p2[l] + 1]);

        if (i + 1 == M)
            printf("%d %d %d\n", u + 1, v + 1, ans);

        u = ((17 * (u + 1) + 751 + ans + 2 * (i + 1)) % N);
        v = ((13 * (v + 1) + 593 + ans + 5 * (i + 1)) % N);
    }
    return 0;
}
