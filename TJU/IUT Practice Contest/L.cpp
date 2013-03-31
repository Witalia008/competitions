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
#define Mi 29
#define N 1001
#define K 11
//#define debug

typedef double ld;
typedef long long ll;
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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
int sqr(int a) { return a * a; }

int n, m, s, t;
int D[N];
vector<pii> adj[N];
priority_queue<pii> Q;

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        scanf("%d%d", &s, &t);
        REP(i, n)
        adj[i + 1].clear();
        REP(i, m)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a].pb(mp(b, c));
            adj[b].pb(mp(a, c));
        }
        while (!Q.empty())
            Q.pop();
        Q.push(mp(0, s));
        FOR(i, 1, n)
        D[i] = Inf;
        D[s] = 0;
        while (!Q.empty())
        {
            int v = Q.top().second;
            int cur = -Q.top().first;
            Q.pop();
            if (v == t)
                break;
            REP(i, adj[v].size())
            if (cur + adj[v][i].second < D[adj[v][i].first])
            {
                D[adj[v][i].first] = cur + adj[v][i].second;
                Q.push(mp(-D[adj[v][i].first], adj[v][i].first));
            }
        }
        if (D[t] == Inf)
            D[t] = -1;
        printf("%d\n", D[t]);
    }
    return 0;
}
