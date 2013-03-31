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
#define eps 10e-7
#define InfL 10000000000000000000LL
#define Inf 1000000000
#define Mi 1000000007
#define N 115
#define K 15
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

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll sqr(ll a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }
inline ll minn(ll a, ll b) { return a < b ? a : b; }
inline ll maxx(ll a, ll b) { return a > b ? a : b; }

struct pt
{
    ll x, y;
    pt() {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}
};

pt n, m;
vector<pt> a, b, A;
ll d[N];
int Q[N * N];

void try_intersect(pt a1, pt b1, pt a2, pt b2)
{
    if (a1.x == b1.x)
    {
        if (a2.y == b2.y)
        {
            if (a2.y >= min(a1.y, b1.y) && a2.y <= max(a1.y, b1.y) && a1.x >= min(a2.x, b2.x) && a1.x <= max(a2.x, b2.x))
            {
                A.pb(pt(a1.x, a2.y));
            }
        }
    }
    else
    {
        if (a2.x == b2.x)
        {
            if (a1.y >= min(a2.y, b2.y) && a1.y <= max(a2.y, b2.y) && a2.x >= min(a1.x, b1.x) && a2.x <= max(a1.x, b1.x))
            {
                A.pb(pt(a2.x, a1.y));
            }
        }
    }
}

bool inn(pt o, pt a, pt b)
{
    if (a.x == b.x)
        return o.x == a.x && o.y >= minn(a.y, b.y) && o.y <= maxx(a.y, b.y);
    else
        return o.y == a.y && o.x >= minn(a.x, b.x) && o.x <= maxx(a.x, b.x);
}

int which(pt c)
{
    int r1 = 0, r2 = 0;
    REP(i, 4)
    if (inn(c, a[i], a[(i + 1) % 4]))
        r1 = 1;
    REP(i, 4)
    if (inn(c, b[i], b[(i + 1) % 4]))
        r2 = 1;
    return ((r1 && r2) ? 3 : (r1 ? 1 : 2));
}

bool cango(pt a, pt b)
{
    int na = which(a);
    int nb = which(b);
    return na == 3 || nb == 3 || na == nb;
}

ll dst(pt a, pt b)
{
    return Abs(a.x - b.x) + Abs(a.y - b.y);
}

ll dist(pt x, pt y)
{
    int n1 = which(x);
    int n2 = which(y);
    if (n1 == 3)
        n1 = n2;
    if (n1 == 3)
        n1 = 2;
    vector<pt> cur = n1 == 1 ? a : b;
    ll res = 0;
    bool fl = false;
    for (int i = 0;; i = (i + 1) % 4)
    {
        if (inn(x, cur[i], cur[(i + 1) % 4]) && !fl)
        {
            fl = true;
            res += dst(x, cur[(i + 1) % 4]);
        }
        else if (inn(y, cur[i], cur[(i + 1) % 4]) && fl)
        {
            fl = false;
            res += dst(cur[i], y);
            break;
        }
        else if (fl)
            res += dst(cur[i], cur[(i + 1) % 4]);
    }
    ll all = dst(cur[0], cur[2]) * 2;
    while (res >= all)
        res -= all;
    return minn(res, all - res);
}

int par[N];

#define TASK "bicycle"
#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    cin >> n.x >> n.y >> m.x >> m.y;
    if (n.x > m.x)
        swap(n.x, m.x);
    if (n.y > m.y)
        swap(n.y, m.y);
    a.pb(n);
    a.pb(pt(n.x, m.y));
    a.pb(m);
    a.pb(pt(m.x, n.y));
    cin >> n.x >> n.y >> m.x >> m.y;
    if (n.x > m.x)
        swap(n.x, m.x);
    if (n.y > m.y)
        swap(n.y, m.y);
    b.pb(n);
    b.pb(pt(n.x, m.y));
    b.pb(m);
    b.pb(pt(m.x, n.y));
    cin >> n.x >> n.y;
    A.pb(n);
    REP(i, 4)
    {
        A.pb(a[i]);
        A.pb(b[i]);
    }
    REP(i, 4)
    REP(j, 4)
    try_intersect(a[i], a[(i + 1) % 4], b[j], b[(j + 1) % 4]);
    cin >> n.x >> n.y;
    A.pb(n);

    REP(i, A.size())
    d[i] = InfL;
    CLR(par, -1);
    d[0] = 0;
    int qt = 1, qh = 0;
    Q[0] = 0;
    while (qh < qt)
    {
        int v = Q[qh++];
        REP(i, A.size())
        if (cango(A[v], A[i]) && d[i] > dist(A[v], A[i]) + d[v])
        {
            d[i] = dist(A[v], A[i]) + d[v];
            Q[qt++] = i;
            par[i] = v;
        }
    }
    if (d[A.size() - 1] == InfL)
        d[A.size() - 1] = -1;
    cout << d[A.size() - 1] << endl;
    //    for (int i = A.size() - 1; i != -1; i = par[i])
    //        cout << A[i].x << " " << A[i].y << endl;
    return 0;
}
