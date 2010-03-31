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
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 200006
#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

struct TEdge
{
    int s, t, w;
};
bool cmp(TEdge a, TEdge b) { return a.w < b.w; }

int n, m, q;
TEdge A[N];
int dsu[N], anc[N][20];
int len[N], deph[N];

void set_anc(int v)
{
    FOR(i, 1, 19)
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
}

int dsu_get(int v)
{
    if (v == dsu[v])
        return v;
    int x = dsu[v];
    dsu[v] = dsu_get(dsu[v]);
    deph[v] += deph[x];
    return dsu[v];
}

void dsu_union(int a, int b, int w)
{
    a = dsu_get(a);
    b = dsu_get(b);
    if (a == b)
        return;
    anc[a][0] = anc[b][0] = dsu[a] = dsu[b] = n;
    deph[a] = deph[b] = 1;
    len[n] = w;
    anc[n][0] = dsu[n] = n;
    ++n;
}

int lca(int a, int b)
{
    if (deph[a] > deph[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--)
        if (deph[anc[b][i]] >= deph[a])
            b = anc[b][i];
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
        if (anc[a][i] != anc[b][i])
            a = anc[a][i], b = anc[b][i];
    return anc[a][0];
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    REP(i, m)
    scanf("%d%d%d", &A[i].s, &A[i].t, &A[i].w);
    sort(A, A + m, &cmp);
    REP(i, n)
    dsu[i] = i;
    REP(i, m)
    dsu_union(A[i].s, A[i].t, A[i].w);
    REP(i, n)
    set_anc(n - i - 1), dsu_get(i);
    REP(i, q)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", len[lca(a, b)]);
    }
    return 0;
}
