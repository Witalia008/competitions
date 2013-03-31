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
#define N 100006
#define p 31
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

struct Tree
{
    bool rev;
    int sum;
};

Tree xtree[N * 4];
int n, m, x, y, s;

void revers(int v, int l, int r)
{
    xtree[v].rev = !xtree[v].rev;
    xtree[v].sum = r - l + 1 - xtree[v].sum;
}

void add(int v, int l, int r, int kl, int kr)
{
    if (l == kl && r == kr)
    {
        revers(v, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (xtree[v].rev)
    {
        xtree[v].rev = false;
        revers(v * 2, l, mid);
        revers(v * 2 + 1, mid + 1, r);
    }
    if (kr <= mid)
        add(v * 2, l, mid, kl, kr);
    else if (kl > mid)
        add(v * 2 + 1, mid + 1, r, kl, kr);
    else
    {
        add(v * 2, l, mid, kl, mid);
        add(v * 2 + 1, mid + 1, r, mid + 1, kr);
    }
    xtree[v].sum = xtree[v * 2].sum + xtree[v * 2 + 1].sum;
}

int get(int v, int l, int r, int kl, int kr)
{
    if (l == kl && r == kr)
        return xtree[v].sum;
    int mid = (l + r) >> 1;
    if (xtree[v].rev)
    {
        xtree[v].rev = false;
        revers(v * 2, l, mid);
        revers(v * 2 + 1, mid + 1, r);
    }
    if (kr <= mid)
        return get(v * 2, l, mid, kl, kr);
    if (kl > mid)
        return get(v * 2 + 1, mid + 1, r, kl, kr);
    return get(v * 2, l, mid, kl, mid) + get(v * 2 + 1, mid + 1, r, mid + 1, kr);
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    REP(i, m)
    {
        scanf("%d%d%d", &s, &x, &y);
        if (s == 0)
            add(1, 1, n, x, y);
        else
            printf("%d\n", get(1, 1, n, x, y));
    }
    return 0;
}
