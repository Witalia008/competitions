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

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 100005
#define debug

typedef double ld;
typedef long long ll;
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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

const int mx[4] = {0, 0, -1, 1};
const int my[4] = {-1, 1, 0, 0};
const pii nothing = mp(-Inf, -Inf);
const ll InfL = ll(Inf) * ll(Inf);

struct TList
{
    int dest, next;
    ll wei;
    TList() {}
    TList(int a, int b, ll c) : dest(a), next(b), wei(c) {}
};

struct TEdge
{
    int st, fi;
    ll wei;
};

bool cmp(TEdge a, TEdge b) { return a.wei < b.wei; }

int n, m, k, en;
TList List[N * 2];
int Head[N];
TEdge Edges[N];
queue<int> Q;
ll d[N];
int p[N];

void bfs()
{
    FOR(i, 1, n)
    d[i] = InfL;
    scanf("%d", &k);
    REP(i, k)
    {
        int a;
        scanf("%d", &a);
        Q.push(a);
        d[a] = 0;
        p[a] = a;
    }
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int j = Head[v]; j; j = List[j].next)
            if (d[List[j].dest] > d[v] + List[j].wei)
            {
                Q.push(List[j].dest);
                d[List[j].dest] = d[v] + List[j].wei;
                p[List[j].dest] = p[v];
            }
    }
}

int dsu[N];

int dsu_get(int v)
{
    return v == dsu[v] ? v : dsu[v] = dsu_get(dsu[v]);
}

bool dsu_union(int a, int b)
{
    a = dsu_get(a);
    b = dsu_get(b);
    if (a == b)
        return false;
    if (rand() & 1)
        swap(a, b);
    dsu[b] = a;
    return true;
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
        cin >> Edges[i].st >> Edges[i].fi >> Edges[i].wei;
        List[++en] = TList(Edges[i].fi, Head[Edges[i].st], Edges[i].wei);
        Head[Edges[i].st] = en;
        List[++en] = TList(Edges[i].st, Head[Edges[i].fi], Edges[i].wei);
        Head[Edges[i].fi] = en;
    }
    bfs();
#ifdef debug
    //FOR(i, 1, n)
    //cout << d[i] << " " << p[i] << endl;
#endif
    ll ans = 0;
    FOR(i, 1, n)
    dsu[i] = i;
    REP(i, m)
    {
        Edges[i].wei += d[Edges[i].st] + d[Edges[i].fi];
        Edges[i].st = p[Edges[i].st];
        Edges[i].fi = p[Edges[i].fi];
    }
    sort(Edges, Edges + m, &cmp);
    REP(i, m)
    if (dsu_union(Edges[i].st, Edges[i].fi))
        ans += Edges[i].wei;
    ans += d[1];
    cout << ans << endl;
    return 0;
}
