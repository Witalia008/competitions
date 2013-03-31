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
#define Inf 1000000000
#define Mi 1000000007
#define N 200015
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

inline ld Abs(ld x) { return x < 0 ? -x : x; }
inline ld sqr(ld a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

struct pt
{
    ld x, y;
};

struct pl
{
    ld A, B, C;
};

struct pa
{
    pt a;
    char wh;
};

int n, m;
pt s, f;
vector<pa> A;

ld dist(pt a, pt b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

pl sett(pt a, pt b)
{
    pl res;
    res.A = a.y - b.y;
    res.B = b.x - a.x;
    res.C = a.x * b.y - a.y * b.x;
    return res;
}

bool comp(pa a, pa b)
{
    if (dist(a.a, b.a) > eps)
    {
        if (Abs(s.x - f.x) <= eps)
            return a.a.y < b.a.y;
        else
            return a.a.x < b.a.x;
    }
    return a.wh < b.wh;
}

void inter(pt o, ld r)
{
    s.x -= o.x;
    s.y -= o.y;
    f.x -= o.x;
    f.y -= o.y;
    pl L = sett(s, f);
    s.x += o.x;
    s.y += o.y;
    f.x += o.x;
    f.y += o.y;

    ld a = L.A, b = L.B, c = L.C;
    ld x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    if (c * c < r * r * (a * a + b * b) - eps)
    {
        ld d = r * r - c * c / (a * a + b * b);
        ld mult = sqrt(d / (a * a + b * b));
        pt cA, cB;
        cA.x = x0 + b * mult;
        cB.x = x0 - b * mult;
        cA.y = y0 - a * mult;
        cB.y = y0 + a * mult;
        cA.x += o.x;
        cA.y += o.y;
        cB.x += o.x;
        cB.y += o.y;
        if (Abs(s.x - f.x) <= eps)
        {
            if (cA.y > cB.y)
                swap(cA, cB);
            if (cA.y < s.y)
                cA = s;
            if (cB.y > f.y)
                cB = f;
            if (cA.y <= cB.y)
            {
                pa cur;
                cur.a = cA;
                cur.wh = 'l';
                A.pb(cur);
                cur.a = cB;
                cur.wh = 'r';
                A.pb(cur);
            }
        }
        else
        {
            if (cA.x > cB.x)
                swap(cA, cB);
            if (cA.x < s.x)
                cA = s;
            if (cB.x > f.x)
                cB = f;
            if (cA.x <= cB.x)
            {
                pa cur;
                cur.a = cA;
                cur.wh = 'l';
                A.pb(cur);
                cur.a = cB;
                cur.wh = 'r';
                A.pb(cur);
            }
        }
    }
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lantern2.in", "r", stdin);
    freopen("lantern2.out", "w", stdout);
#endif
    scanf("%d", &n);
    cin >> s.x >> s.y >> f.x >> f.y;
    if (Abs(s.x - f.x) <= eps)
    {
        if (s.y > f.y)
            swap(s, f);
    }
    else if (s.x > f.x)
        swap(s, f);
    REP(i, n)
    {
        pt o;
        int r;
        scanf("%lf%lf%d", &o.x, &o.y, &r);
        inter(o, r);
    }

    sort(A.begin(), A.end(), &comp);
    int bal = 0;
    pt st, fi;
    ld ans = 0;
    REP(i, A.size())
    {
        if (A[i].wh == 'l')
        {
            if (!bal)
                st = A[i].a;
            bal++;
        }
        else
        {
            bal--;
            if (!bal)
            {
                fi = A[i].a;
                ans += dist(st, fi);
            }
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
