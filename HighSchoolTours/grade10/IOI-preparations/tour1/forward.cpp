#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 2000

int n, m, C;
int M[N][N];

int frst(int i, int j) { return 2 * (i - 1) * m + j; }
int scnd(int i, int j) { return frst(i, j) + m; }

int queue[N], d[N], ptr[N];

bool bfs()
{
    memset(d, -1, sizeof(d));
    d[0] = 1;
    int qh = 0, qt = 1;
    queue[0] = 0;
    while (qh < qt)
    {
        int v = queue[qh++];
        for (int j = 0; j <= C; j++)
            if (d[j] == -1 && M[v][j])
            {
                d[j] = d[v] + 1;
                queue[qt++] = j;
            }
    }
    return d[C] != -1;
}

int dfs(int v = 0, int cur = Inf)
{
    if (!cur)
        return 0;
    if (v == C)
        return cur;
    for (int &to = ptr[v]; to <= C; to++)
        if (d[to] == d[v] + 1)
        {
            int pushed = dfs(to, min(cur, M[v][to]));
            if (pushed)
            {
                M[v][to] -= pushed;
                M[to][v] += pushed;
                return pushed;
            }
        }
    return 0;
}

int dinic()
{
    int flow = 0;
    while (bfs())
    {
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs())
            flow += pushed;
    }
    return flow;
}

int main()
{
    freopen("forward.dat", "r", stdin);
    freopen("forward.sol", "w", stdout);
    scanf("%d%d", &n, &m);
    C = 2 * m * n + 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
        {
            int c;
            scanf("%d", &c);
            for (int k = 0; k < c; k++)
            {
                int a;
                scanf("%d", &a);
                M[scnd(i, j)][frst(i + 1, a)] = 1;
            }
        }
    for (int j = 1; j <= m; j++)
    {
        M[0][frst(1, j)] = 1;
        M[scnd(n, j)][C] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            M[frst(i, j)][scnd(i, j)] = 1;
    printf("%d\n", dinic());
    return 0;
}
