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

inline ll Abs(ll x) { return x < 0 ? -x : x; }
inline ll sqr(ll a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

struct pa
{
    int a;
    char wh;
};

bool comp(pa a, pa b)
{
    if (a.a != b.a)
        return a.a < b.a;
    return a.wh < b.wh;
}

int n, m;
pa A[N];
vector<pii> v;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lantern.in", "r", stdin);
    freopen("lantern.out", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    REP(i, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        A[i * 2].a = x;
        A[i * 2].wh = 'l';
        A[i * 2 + 1].a = y;
        A[i * 2 + 1].wh = 'r';
    }
    v.clear();
    n *= 2;
    sort(A, A + n, &comp);
    int bal = 0;
    int st, fi;
    int ans = 0;
    REP(i, n)
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
                v.pb(mp(st, fi));
                ans += fi - st;
            }
        }
    }
    int cnt = v.size() - 1;
    if (v[0].first != 0)
        cnt++;
    if (v.back().second != m)
        cnt++;
    cout << ans << " " << cnt << endl;
    return 0;
}
