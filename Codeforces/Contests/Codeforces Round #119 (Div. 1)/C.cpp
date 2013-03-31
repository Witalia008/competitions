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
#define N 100006
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

struct TList
{
    int dest, next;
};

int n, m, k, en;
TList List[N * 4];
int Head[N];
int s, t;
int d[N];
bool vol[N];
priority_queue<pii> Q;

void add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

bool can_do_it(int q)
{
#ifdef debug
    printf("%d\n", q);
#endif
    CLR(d, -1);
    while (!Q.empty())
        Q.pop();
    d[s] = q;
    Q.push(mp(q, s));
    while (!Q.empty() && d[t] == -1)
    {
        int v = Q.top().second;
        int cur = Q.top().first;
#ifdef debug
        printf("%d %d\n", v, cur);
#endif
        Q.pop();
        if (cur > d[v] || d[v] <= 0)
            continue;
        for (int j = Head[v]; j; j = List[j].next)
        {
            int to = List[j].dest;
            if (d[to] < d[v] - 1)
            {
                d[to] = d[v] - 1;
#ifdef debug
                printf(" |->> %d %d\n", d[to], to);
#endif
                if (vol[to])
                    d[to] = q;
                if (d[to] > 0)
                    Q.push(mp(d[to], to));
            }
        }
    }
    return d[t] != -1;
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (can_do_it(mid))
            r = mid;
        else
            l = mid;
    }
    if (can_do_it(l))
        return l;
    if (can_do_it(r))
        return r;
    return -1;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k)
    {
        int a;
        scanf("%d", &a);
        vol[a] = true;
    }
    REP(i, m)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    scanf("%d%d", &s, &t);
    printf("%d\n", bin_search(1, n));
    return 0;
}
