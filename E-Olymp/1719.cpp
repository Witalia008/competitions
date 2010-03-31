#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 45

int n, m, nn;
int R[N], C[N];
int Z[N][N], M[N][N], F[N][N];
int queue[N], d[N], ptr[N];

bool bfs()
{
    int head = 0, tail = 1;
    queue[0] = 0;
    CLR(d, -1);
    d[0] = 0;
    while (head < tail)
    {
        int v = queue[head++];
        REP(i, nn)
        if (F[v][i] < M[v][i] && d[i] == -1)
        {
            d[i] = d[v] + 1;
            queue[tail++] = i;
        }
    }
    return (d[nn - 1] != -1);
}

int dfs(int v = 0, int cur = Inf)
{
    if (!cur)
        return 0;
    if (v == nn - 1)
        return cur;
    for (int &i = ptr[v]; i < nn; i++)
        if (d[i] == d[v] + 1)
        {
            int pushed = dfs(i, min(cur, M[v][i] - F[v][i]));
            if (pushed)
            {
                F[v][i] += pushed;
                F[i][v] -= pushed;
                return pushed;
            }
        }
    return 0;
}

void dinic()
{
    while (bfs())
    {
        CLR(ptr, 0);
        while (dfs())
        {
        }
    }
}

void fault()
{
    printf("-1\n");
    exit(0);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    nn = n + m + 2;
    REP(i, n)
    scanf("%d", &R[i]);
    REP(i, m)
    scanf("%d", &C[i]);
    REP(i, n)
    REP(j, m)
    {
        scanf("%d", &Z[i][j]);
        if (Z[i][j] == -1)
            M[i + 1][n + j + 1] = Inf;
        else
        {
            R[i] -= Z[i][j];
            C[j] -= Z[i][j];
        }
    }
    REP(i, n)
    {
        M[0][i + 1] = R[i];
        if (R[i] < 0)
            fault();
    }
    REP(i, m)
    {
        M[n + i + 1][nn - 1] = C[i];
        if (C[i] < 0)
            fault();
    }
    dinic();
    REP(i, n)
    REP(j, m)
    {
        if (Z[i][j] == -1)
            Z[i][j] = F[i + 1][n + j + 1];
        printf("%d", Z[i][j]);
        if (j == m - 1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
