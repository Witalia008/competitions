#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
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
#define N 105
#define M 10000

int n, m, a, b;
char A[N][N];
int mt[M];
bool used[M];
char part[M];
vector<int> adj[M];

#define getn(i, j) ((i)*m + (j))

void dfs(int v, bool c)
{
    part[v] = c + 1;
    used[v] = true;
    for (int i = 0; i < adj[v].size(); ++i)
        if (!used[adj[v][i]])
            dfs(adj[v][i], !c);
}

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
    cin >> n >> m >> a >> b;
    REP(i, n)
    {
        string s;
        cin >> s;
        REP(j, m)
        A[i][j] = s[j];
    }
    int cnt = 0;
    REP(i, n)
    REP(j, m)
    if (A[i][j] == '*')
    {
        cnt++;
        int cur = getn(i, j);
        if (i && A[i - 1][j] == '*')
            adj[cur].pb(getn(i - 1, j));
        if (j && A[i][j - 1] == '*')
            adj[cur].pb(getn(i, j - 1));
        if (i < n - 1 && A[i + 1][j] == '*')
            adj[cur].pb(getn(i + 1, j));
        if (j < m - 1 && A[i][j + 1] == '*')
            adj[cur].pb(getn(i, j + 1));
    }
    if (2 * b <= a)
    {
        printf("%d\n", cnt * b);
        return 0;
    }
    CLR(mt, -1);
    REP(i, n)
    REP(j, m)
    {
        int v = getn(i, j);
        if (A[i][j] == '*')
        {
            if (part[v] == 0)
            {
                CLR(used, false);
                dfs(v, false);
            }
            if (part[v] == 1)
            {
                CLR(used, false);
                try_kuhn(v);
            }
        }
    }
    int F = 0;
    REP(i, n * m)
    if (mt[i] != -1)
        F++;
    printf("%d\n", F * a + (cnt - F * 2) * b);
    return 0;
}
