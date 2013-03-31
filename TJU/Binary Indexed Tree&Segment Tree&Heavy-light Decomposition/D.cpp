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
#define Mi 10000007
#define N 30006
#define K 16
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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

struct Tree
{
    int sum, mx;
    Tree *l, *r;
    Tree() : sum(0), mx(0), l(0), r(0) {}
    Tree(Tree *ll, Tree *rr)
    {
        l = ll;
        r = rr;
        sum = l->sum + r->sum;
        mx = max(l->mx, r->mx);
    }
    void update()
    {
        sum = l->sum + r->sum;
        mx = max(l->mx, r->mx);
    }
};

Tree *xtree[N];
int n, m, root;
vi adj[N];
int anc[N][K];
bool isHeavyOut[N];
lbl EdgeToF[N];
int W[N];
int NumOfPath[N];
int PosInPath[N];
int PathN[N];
int cnt[N], deph[N];
int cnt_path;
int Next[N];

void dfs(int v, int p = -1)
{
    deph[v] = p == -1 ? 0 : deph[p] + 1;
    anc[v][0] = p == -1 ? v : p;
    FOR(i, 1, K - 1)
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
    cnt[v] = 1;
    REP(j, adj[v].size())
    if (adj[v][j] != p)
    {
        dfs(adj[v][j], v);
        cnt[v] += cnt[adj[v][j]];
    }
    REP(j, adj[v].size())
    if (adj[v][j] != p)
    {
        EdgeToF[adj[v][j]] = (cnt[adj[v][j]] >= (cnt[v] + 1) / 2) ? heavy : light;
        if (EdgeToF[adj[v][j]] == heavy)
            isHeavyOut[v] = true;
    }
}

int lca(int a, int b)
{
    if (deph[a] > deph[b])
        swap(a, b);
    REPD(i, K)
    if (deph[anc[b][i]] >= deph[a])
        b = anc[b][i];
    if (a == b)
        return a;
    REPD(i, K)
    if (anc[a][i] != anc[b][i])
        a = anc[a][i], b = anc[b][i];
    return anc[a][0];
}

void findPath(int v)
{
    while (true)
    {
        PosInPath[v] = ++PathN[cnt_path];
        NumOfPath[v] = cnt_path;
        if (EdgeToF[v] == light || v == root)
            break;
        v = anc[v][0];
    }
    Next[cnt_path] = (v == root ? -1 : anc[v][0]);
    cnt_path++;
}

pii merg(pii a, pii b)
{
    a.first += b.first;
    a.second = max(a.second, b.second);
    return a;
}

Tree *build(int l, int r)
{
    if (l == r)
        return new Tree();
    int mid = (l + r) >> 1;
    return new Tree(build(l, mid), build(mid + 1, r));
}

void add(Tree *t, int l, int r, int x, int val)
{
    if (l == r)
    {
        t->sum = t->mx = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        add(t->l, l, mid, x, val);
    else
        add(t->r, mid + 1, r, x, val);
    t->update();
}

pii get(Tree *t, int l, int r, int kl, int kr)
{
    if (l == kl && r == kr)
        return mp(t->sum, t->mx);
    int mid = (l + r) >> 1;
    if (kr <= mid)
        return get(t->l, l, mid, kl, kr);
    if (kl > mid)
        return get(t->r, mid + 1, r, kl, kr);
    return merg(get(t->l, l, mid, kl, mid), get(t->r, mid + 1, r, mid + 1, kr));
}

pii getFull(int v, int la)
{
    pii res = mp(0, -Inf);
    while (NumOfPath[v] != NumOfPath[la])
    {
        res = merg(res, get(xtree[NumOfPath[v]], 1, PathN[NumOfPath[v]], PosInPath[v], PathN[NumOfPath[v]]));
        v = Next[NumOfPath[v]];
    }
    res = merg(res, get(xtree[NumOfPath[v]], 1, PathN[NumOfPath[v]], PosInPath[v], PosInPath[la]));
    return res;
}

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = -1;
    scanf("%d", &n);
    while (n != -1)
    {
        //CLEAR IT ALL
        {
            CLR(xtree, 0);
            cnt_path = 0;
            FOR(i, 1, n)
            adj[i].clear();
            CLR(PathN, 0);
            CLR(anc, 0);
        }
        root = n;
        REP(i, n - 1)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        FOR(i, 1, n)
        scanf("%d", &W[i]);
        dfs(root);
        FORD(i, n, 1)
        if (!isHeavyOut[i])
            findPath(i);
        REP(i, cnt_path)
        xtree[i] = build(1, PathN[i]);
        FOR(i, 1, n)
        add(xtree[NumOfPath[i]], 1, PathN[NumOfPath[i]], PosInPath[i], W[i]);
        scanf("%d\n", &m);
        char s[10];
        int x, y, la;
        pii ans;
        REP(i, m)
        {
            scanf("%s", &s);
            scanf("%d%d\n", &x, &y);
            if (s[0] == 'C')
            {
                add(xtree[NumOfPath[x]], 1, PathN[NumOfPath[x]], PosInPath[x], y);
                W[x] = y;
            }
            else
            {
                la = lca(x, y);
                ans = merg(getFull(x, la), getFull(y, la));
                ans.first -= W[la];
                printf("%d\n", s[1] == 'S' ? ans.first : ans.second);
            }
        }
        n = -1;
        scanf("%d", &n);
    }
    return 0;
}
