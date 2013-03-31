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
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-3
#define Inf 1000000000
#define Mi 1000000007
#define N 200001
#define K 26
//#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum
{
    heavy,
    light
} lbl;

vector<pii> g[N];
int n;
int up[N], cnt[N];
vi Ans;

void dfs1(int v, int p = -1)
{
    up[v] = 0;
    REP(i, g[v].size())
    if (g[v][i].first != p)
    {
        dfs1(g[v][i].first, v);
        up[v] += up[g[v][i].first] + g[v][i].second;
    }
}

void dfs2(int v, int p = -1)
{
    REP(i, g[v].size())
    if (g[v][i].first != p)
    {
        cnt[g[v][i].first] = cnt[v] + (g[v][i].second == 0 ? 1 : -1);
        dfs2(g[v][i].first, v);
    }
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    REP(i, n - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].pb(mp(b, 0));
        g[b].pb(mp(a, 1));
    }
    dfs1(1);
    cnt[1] = up[1];
    dfs2(1);
    Ans.clear();
    int ans = Inf;
    FOR(i, 1, n)
    {
        if (cnt[i] < ans)
        {
            ans = cnt[i];
            Ans.clear();
        }
        if (cnt[i] == ans)
            Ans.pb(i);
    }
    printf("%d\n", ans);
    REP(i, Ans.size())
    {
        if (i)
            printf(" ");
        printf("%d", Ans[i]);
    }
    printf("\n");
    return 0;
}
