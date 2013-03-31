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
#define N 1000001
#define K 26
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

struct segm
{
    int len, l, r;
    segm() {}
    segm(int al, int ar) : len(ar - al - 1), l(al), r(ar) {}
};

int n, m;

int getPr(segm a)
{
    if (a.len == -1)
        return -Inf;
    if (a.l == -1 || a.r == n)
        return a.len;
    return (a.len + 1) / 2;
}

int getWh(segm a)
{
    if (a.l == -1)
        return a.l + 1;
    if (a.r == n)
        return a.r - 1;
    return (a.l + (a.len + 1) / 2);
}

bool comp(segm a, segm b)
{
    int la = getPr(a);
    int lb = getPr(b);
    return la > lb || la == lb && getWh(a) < getWh(b);
}

segm Q[N];
int wh[N], pl[N], R[N];
int en;

void ShiftUp(int i)
{
    for (; i > 1; i /= 2)
        if (comp(Q[i], Q[i / 2]))
        {
            swap(Q[i], Q[i / 2]);
            swap(wh[Q[i].r], wh[Q[i / 2].r]);
        }
}

void ShiftDown(int i)
{
    while (i * 2 <= en)
    {
        int k = i;
        if (comp(Q[i * 2], Q[k]))
            k = i * 2;
        if (i * 2 + 1 <= en && comp(Q[i * 2 + 1], Q[k]))
            k = i * 2 + 1;
        if (k == i)
            i = en;
        else
        {
            swap(Q[i], Q[k]);
            swap(wh[Q[i].r], wh[Q[k].r]);
            i = k;
        }
    }
}

void push(segm a)
{
    en++;
    Q[en] = a;
    wh[a.r] = en;
    R[a.l + 1] = a.r;
    ShiftUp(en);
}

segm pop()
{
    swap(Q[1], Q[en]);
    wh[Q[1].r] = 1;
    wh[Q[en].r] = -1;
    en--;
    ShiftDown(1);
    R[Q[en + 1].l + 1] = -1;
    return Q[en + 1];
}

int kill(int pos)
{
    int xx = wh[pos];
    if (xx == -1)
        return -1;
    int res = Q[xx].l;
    R[res + 1] = -1;
    swap(Q[xx], Q[en]);
    wh[Q[xx].r] = xx;
    en--;
    ShiftUp(xx);
    ShiftDown(xx);
    return res;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    CLR(wh, -1);
    CLR(R, -1);
    push(segm(-1, n));
    REP(i, m)
    {
        int t, id;
        scanf("%d%d", &t, &id);
        if (t == 1)
        {
            segm v = pop();
            int pos = getWh(v);
            pl[id] = pos;
            push(segm(v.l, pos));
            push(segm(pos, v.r));
            printf("%d\n", pos + 1);
        }
        else
        {
            int pos = pl[id];
            int lp = kill(pos), rp = n - 1;
            if (R[pos + 1] != -1)
                rp = R[pos + 1], kill(R[pos + 1]);
            push(segm(lp, rp));
        }
    }
    return 0;
}
