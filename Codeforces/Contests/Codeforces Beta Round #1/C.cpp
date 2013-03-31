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
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
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

const int Inf = 1e9;
const int Mi = Inf + 7;
const int N = 100005;
const int K = 32;
const ld eps = 10e-6;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

template <typename __T>
__T Abs(__T a)
{
    return a < 0 ? -a : a;
}

template <typename __T>
__T sqr(__T a)
{
    return a * a;
}
/*
template<typename __T>
__T min(__T a, __T b) {
    return a < b ? a : b;
}

template<typename __T>
__T max(__T a, __T b) {
    return a > b ? a : b;
}*/

//#define DEBUG

struct pt
{
    ld x, y;
    pt() {}
    pt(ld _x, ld _y) : x(_x), y(_y) {}
    pt(pt a, pt b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

ld len(pt a)
{
    return sqrt(sqr(a.x) + sqr(a.y));
}

ld angle(pt a, pt b)
{
    return acos((a.x * b.x + a.y * b.y) / (len(a) * len(b)));
}

ld ang[3];
pt a[3];
ld l[3];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    REP(i, 3)
    cin >> a[i].x >> a[i].y;
    REP(i, 3)
    {
        ang[i] = M_PI - angle(pt(a[i], a[(i + 1) % 3]), pt(a[(i + 1) % 3], a[(i + 2) % 3]));
        l[i] = len(pt(a[i], a[(i + 1) % 3]));
    }
    ld S = 0.5 * sin(ang[0]) * l[0] * l[1];
    ld R = l[0] * l[1] * l[2] / (4 * S);
    ld res = Inf;
    FOR(n, 1, 100)
    {
        ld alpha = (n - 2) * M_PI / n;
        ld gamma = (2 * M_PI) / n;
        ld cur_s = (sin(gamma) * R) * (R * 0.5) * n;
        FOR(i, 1, n - 2)
        {
            FOR(j, i + 1, n - 1)
            {
                ld alpha1 = (i - 1) * (M_PI - alpha) / 2;
                ld alpha2 = (j - i - 1) * (M_PI - alpha) / 2;
                ld alpha3 = (n - j - 1) * (M_PI - alpha) / 2;
                if (Abs(alpha - alpha1 - alpha3 - ang[2]) < eps &&
                    Abs(alpha - alpha1 - alpha2 - ang[0]) < eps &&
                    Abs(alpha - alpha2 - alpha3 - ang[1]) < eps)
                {
                    res = min(res, cur_s);
                }
            }
        }
    }
    cout << fixed << setprecision(8) << res << endl;
    return 0;
}
