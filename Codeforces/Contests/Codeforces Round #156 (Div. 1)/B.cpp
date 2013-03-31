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
#define N 4015
#define K 1000

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

inline int Abs(int x) { return x < 0 ? -x : x; }
inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll sqr(ll a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }
ll maxx(ll a, ll b) { return a < b ? b : a; }

//#define DEBUG_MODE

struct Point
{
    ll x, y;
    Point() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}
};

struct Segment
{
    Point s, f;
    Segment() {}
    Segment(Point _s, Point _f) : s(_s), f(_f) {}
};

ll n, c, x, y;

bool in(Point a)
{
    return a.x > 0 && a.y > 0 && a.x <= n && a.y <= n;
}

ll vd(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(Point a, Point b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

vector<Point> convex_hull(vector<Point> a)
{
    if (a.size() < 3)
        return a;
    sort(a.begin(), a.end(), &cmp);
    vector<Point> up, down;
    up.clear();
    down.clear();
    Point ps = a[0], pf = a.back();
    up.pb(ps);
    down.pb(ps);
    REP(i, a.size())
    {
        if (i == a.size() - 1 || vd(ps, pf, a[i]) > 0)
        {
            while (up.size() > 1 && vd(up[up.size() - 2], up.back(), a[i]) >= 0)
                up.pop_back();
            up.pb(a[i]);
        }
        if (i == a.size() - 1 || vd(ps, pf, a[i]) < 0)
        {
            while (down.size() > 1 && vd(down[down.size() - 2], down.back(), a[i]) <= 0)
                down.pop_back();
            down.pb(a[i]);
        }
    }
    vector<Point> res = up;
    FORD(i, down.size() - 2, 1)
    res.pb(down[i]);
    return res;
}

ll m_dist(Point a, Point b)
{
    return Abs(a.x - b.x) + Abs(a.y - b.y);
}

bool good(ll side)
{
    vector<Point> aa;
    aa.clear();
    aa.pb(Point(x - side, y));
    aa.pb(Point(x + side, y));
    aa.pb(Point(x, y - side));
    aa.pb(Point(x, y + side));

    vector<Point> cur;
    cur.clear();
    REP(i, 4)
    {
        Point cc = aa[i];
        if (cc.x < 1)
        {
            cur.pb(Point(1, cc.y + (cc.x - 1)));
            cur.pb(Point(1, cc.y - (cc.x - 1)));
        }
        if (cc.x > n)
        {
            cur.pb(Point(n, cc.y + (cc.x - n)));
            cur.pb(Point(n, cc.y - (cc.x - n)));
        }
        if (cc.y < 1)
        {
            cur.pb(Point(cc.x + (cc.y - 1), 1));
            cur.pb(Point(cc.x - (cc.y - 1), 1));
        }
        if (cc.y > n)
        {
            cur.pb(Point(cc.x + (cc.y - n), n));
            cur.pb(Point(cc.x - (cc.y - n), n));
        }
        cur.pb(cc);
    }
    aa.clear();
    REP(i, cur.size())
    if (in(cur[i]))
        aa.pb(cur[i]);

    if (m_dist(Point(1, 1), Point(x, y)) <= side)
        aa.pb(Point(1, 1));
    if (m_dist(Point(1, n), Point(x, y)) <= side)
        aa.pb(Point(1, n));
    if (m_dist(Point(n, 1), Point(x, y)) <= side)
        aa.pb(Point(n, 1));
    if (m_dist(Point(n, n), Point(x, y)) <= side)
        aa.pb(Point(n, n));

    cur = convex_hull(aa);
    ld r1 = 0;
    ll r2 = 0;
    REP(i, cur.size())
    {
        Point _s = cur[i];
        Point _f = cur[(i + 1) % cur.size()];
        r2 += gcd(Abs(_s.x - _f.x), Abs(_s.y - _f.y));
        r1 += (_f.x - _s.x) * (_f.y + _s.y) / 2.0;
    }
    if (r1 < 0)
        r1 *= -1;
    ll res = ll(r1 - r2 / 2.0 + 1.5);
    res += r2;
    return res >= c;
}

ll bin_search(ll l, ll r)
{
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }
    if (good(l))
        return l;
    return r;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> x >> y >> c;
    cout << bin_search(0, Inf) << endl;
    return 0;
}
