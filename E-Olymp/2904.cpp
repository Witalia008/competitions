#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 305

int n, m, c, en;
bool A[N][N];
vector<int> adj[N];
bool used[N];
int mt[N];

bool try_kuhn(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (int i = 0; i < adj[v].size(); ++i)
    {
        int to = adj[v][i];
        if (mt[to] == -1 || try_kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &c);
    while (n)
    {
        CLR(A, true);
        REP(i, c)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            A[x][y] = false;
        }
        CLR(mt, -1);
        REP(i, n)
        {
            adj[i].resize(0);
            REP(j, m)
            if (A[i][j])
                adj[i].pb(j);
        }
        REP(i, n)
        {
            CLR(used, false);
            try_kuhn(i);
        }
        int ans = 0;
        REP(i, m)
        if (mt[i] != -1)
            ans++;
        printf("%d\n", ans);
        n = m = 0;
        scanf("%d%d%d", &n, &m, &c);
    }
    return 0;
}
