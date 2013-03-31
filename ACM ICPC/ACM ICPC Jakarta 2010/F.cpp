#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 2505

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int n, m, ans;
vi adj[N];
bool used[N];

void dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!used[adj[v][i]])
        {
            ans++;
            dfs(adj[v][i]);
        }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        FOR(i, 1, n)
        adj[i].clear();
        REP(i, m)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
        }
        FOR(i, 1, n)
        {
            CLR(used, 0);
            dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
