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
#define N 100005
//#define debug

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

struct TList
{
    int dest, next, wei;
    bool us;
};

int n, q, en, cn;
TList List[N * 2];
int Head[N];
int anc[N][20];
int deph[N];
int len[N];
int comp[N];

void Add(int u, int v, int w)
{
    en++;
    List[en].dest = v;
    List[en].wei = w;
    List[en].us = false;
    List[en].next = Head[u];
    Head[u] = en;
}

bool used[N];
int in_c[N];
int cycle_len;
int T[N];
int cx;
int wh[N];

void add(int i, int val)
{
    for (; i < n; i = (i | (i + 1)))
        T[i] += val;
}

int get(int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += T[r];
    return res;
}

void findCycle(int v)
{
    if (used[v])
    {
        in_c[v] = 1;
        return;
    }
    used[v] = true;
    for (int j = Head[v]; j; j = List[j].next)
        if (!List[j].us)
        {
            List[j].us = true;
            List[j & 1 ? j + 1 : j - 1].us = true;
            findCycle(List[j].dest);
            if (in_c[List[j].dest])
            {
                if (in_c[List[j].dest] == 1)
                {
                    in_c[v]++;
                    cx++;
                    wh[v] = n - cx;
                    add(wh[v], List[j].wei);
                    cycle_len += List[j].wei;
                }
                return;
            }
        }
}

void dfs(int v, int p = -1)
{
    comp[v] = cn;
    deph[v] = p == -1 ? 0 : deph[p] + 1;
    anc[v][0] = p == -1 ? v : p;
    if (p == -1)
        len[v] = 0;
    FOR(i, 1, 19)
    anc[v][i] = anc[anc[v][i - 1]][i - 1];
    for (int j = Head[v]; j; j = List[j].next)
        if (List[j].dest != p && !in_c[List[j].dest])
        {
            len[List[j].dest] = len[v] + List[j].wei;
            dfs(List[j].dest, v);
        }
}

int lca(int a, int b)
{
    if (deph[a] > deph[b])
        swap(a, b);
    REPD(i, 20)
    if (deph[anc[b][i]] >= deph[a])
        b = anc[b][i];
    if (a == b)
        return a;
    REPD(i, 20)
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
    scanf("%d", &n);
    while (n)
    {
        CLR(Head, 0);
        CLR(used, 0);
        CLR(in_c, 0);
        CLR(anc, 0);
        CLR(deph, 0);
        CLR(len, 0);
        CLR(wh, 0);
        CLR(T, 0);
        en = cn = cycle_len = cx = 0;
        REP(i, n)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a++;
            b++;
            Add(a, b, c);
            Add(b, a, c);
        }
        findCycle(1);
        FOR(i, 1, n)
        if (in_c[i])
        {
            cn++;
#ifdef debug
            cout << i << " " << wh[i] << endl;
#endif
            dfs(i);
        }
        scanf("%d", &q);
        REP(i, q)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a++;
            b++;
            int ans = len[a] + len[b];
            if (comp[a] == comp[b])
            {
                int x = lca(a, b);
                ans -= 2 * len[x];
            }
            else
            {
                int r1 = anc[a][19];
                int r2 = anc[b][19];
                if (wh[r1] > wh[r2])
                    swap(r1, r2);
                int llen = get(wh[r2] - 1) - get(wh[r1] - 1);
#ifdef debug
                cout << r1 << " " << r2 << " ";
                cout << wh[r1] << " " << wh[r2] << " ";
#endif
                ans += min(llen, cycle_len - llen);
            }
            printf("%d\n", ans);
        }
        scanf("%d", &n);
    }
    return 0;
}
