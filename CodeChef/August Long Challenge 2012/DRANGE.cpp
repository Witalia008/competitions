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

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-10
#define Inf 1000000000
#define Mi 10000007
#define N 1000005
#define K 16
//#define debug

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;
typedef enum {heavy, light} lbl;

ll max (ll a, ll b) {if (a>b) return a; return b;}
int min (int a, int b) {if (a < b) return a; return b;}
int Abs(int a) {if (a < 0) return -a; else return a;}
ld Abs (ld a) {if (a < 0) return -a; else return a;}
ll sqr (ll a) {return a*a;}
ld sqr (ld a) {return a*a;}

struct Tree
{
    int minx, maxx, ad;
    bool all, ft;
};

Tree xtree[N*4];
int n, m, T;
int w, x, y, z;

void add (int v, int l, int r, int kl, int kr, int val)
{
    if (xtree[v].ft && l != r)
    {
        xtree[v*2].ft = xtree[v*2+1].ft = true;
        xtree[v].ft = false;
        xtree[v].maxx = r; xtree[v].minx = l;
        xtree[v*2].minx = l;
        xtree[v*2].maxx = (l + r) >> 1;
        xtree[v*2+1].minx = ((l + r) >> 1) + 1;
        xtree[v*2+1].maxx = r;
        xtree[v*2].ad = xtree[v*2+1].ad = 0;
        xtree[v*2].all = xtree[v*2+1].all = 0;
    }
    if (kl == l && kr == r)
    {
        xtree[v].ad += val;
        xtree[v].all = true;
        return ;
    }
    int mid = (l + r) >> 1;
    if (xtree[v].all)
    {
        xtree[v*2].all = xtree[v*2+1].all = true;
        xtree[v].all = false;
        xtree[v*2].ad += xtree[v].ad;
        xtree[v*2+1].ad += xtree[v].ad;
        xtree[v].ad = 0;
    }
    if (kr <= mid)
        add (v * 2, l, mid, kl, kr, val);
    else if (kl > mid)
        add (v * 2 + 1, mid + 1, r, kl, kr, val);
    else {
        add (v * 2, l, mid, kl, mid, val);
        add (v * 2 + 1, mid + 1, r, mid + 1, kr, val);
    }
    xtree[v].maxx = max (xtree[v*2].maxx + xtree[v*2].ad, xtree[v*2+1].maxx + xtree[v*2+1].ad);
    xtree[v].minx = min (xtree[v*2].minx + xtree[v*2].ad, xtree[v*2+1].minx + xtree[v*2+1].ad);
}

pii merg (pii a, pii b)
{
    a.first = max (a.first, b.first);
    a.second = min (a.second, b.second);
    return a;
}

pii get (int v, int l, int r, int kl, int kr)
{
    if (xtree[v].ft && l != r)
    {
        xtree[v*2].ft = xtree[v*2+1].ft = true;
        xtree[v].ft = false;
        xtree[v].maxx = r; xtree[v].minx = l;
        xtree[v].ad = xtree[v].all = 0;
        xtree[v*2].ad = xtree[v*2+1].ad = 0;
        xtree[v*2].all = xtree[v*2+1].all = 0;
    }
    if (kl == l && kr == r)
        return mp (xtree[v].maxx + xtree[v].ad, xtree[v].minx + xtree[v].ad);
    int mid = (l + r) >> 1;
    if (xtree[v].all)
    {
        xtree[v*2].all = xtree[v*2+1].all = true;
        xtree[v].all = false;
        xtree[v*2].ad += xtree[v].ad;
        xtree[v*2+1].ad += xtree[v].ad;
        xtree[v].ad = 0;
    }
    pii res;
    if (kr <= mid)
        res = get (v * 2, l, mid, kl, kr);
    else if (kl > mid)
        res = get (v * 2 + 1, mid + 1, r, kl, kr);
    res = merg (get (v * 2, l, mid, kl, mid), get (v * 2 + 1, mid + 1, r, mid + 1, kr));
    res.first += xtree[v].ad; res.second += xtree[v].ad;
    return res;
}

//#define ONLINE_JUDGE
int main ()
{
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    scanf ("%d", &T);
    REP(t, T)
    {
        scanf ("%d%d", &n, &m);
        xtree[1].ft = true;
        xtree[1].ad = xtree[1].all = 0;
        REP(i, m)
        {
            scanf ("%d%d%d%d", &w, &x, &y, &z);
            if (w == 2) z = -z;
            add (1, 1, n, x, y, z);
        }
        pii ans = get (1, 1, n, 1, n);
        printf ("%d\n", ans.first - ans.second);
    }
    return 0;
}
