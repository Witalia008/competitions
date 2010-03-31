#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define Inf 1000000000
#define n_max 1000
#define k_max 24

const int up[k_max] = {11, 6, 22, 19, 3, 10, 14, 23, 7, 2, 18, 15, 4, 9, 17, 20, 8, 1, 21, 12, 0, 5, 13, 16};
const int rt[k_max] = {16, 8, 7, 23, 20, 0, 11, 15, 12, 4, 3, 19, 21, 5, 10, 18, 13, 9, 2, 22, 17, 1, 6, 14};

int DP[n_max][n_max][k_max];
int a, b, c;
int N, M;

inline int cost(int k)
{
    return (k < 4 ? a : (k < 8 ? b : (k < 12 ? c : (k < 16 ? (7 - a) : (k < 20 ? (7 - b) : (7 - c))))));
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &M, &N);
    scanf("%d%d%d", &a, &b, &c);
    c = 7 - c;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < k_max; k++)
                DP[i][j][k] = Inf;

    DP[0][0][0] = cost(0);

    for (int i = 1; i < N; i++)
        for (int k = 0; k < k_max; k++)
            DP[i][0][k] = DP[i - 1][0][up[k]] + cost(k);

    for (int j = 1; j < M; j++)
        for (int k = 0; k < k_max; k++)
            DP[0][j][k] = DP[0][j - 1][rt[k]] + cost(k);

    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            for (int k = 0; k < k_max; k++)
                DP[i][j][k] = min(DP[i - 1][j][up[k]], DP[i][j - 1][rt[k]]) + cost(k);

    int ans = Inf;
    for (int k = 0; k < k_max; k++)
        ans = min(DP[N - 1][M - 1][k], ans);
    printf("%d\n", ans);
    return 0;
}
