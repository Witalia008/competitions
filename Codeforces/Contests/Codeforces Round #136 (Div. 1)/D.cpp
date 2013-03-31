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
#define N 4005
#define K 4
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

ll Abs(ll x) { return x < 0 ? -x : x; }

int gcd(int a, int b)
{
    if (!a || !b)
        return a ? a : b;
    return gcd(b, a % b);
}

int n, m;
ll cnt[2][2];
ll C[N][K];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    REP(i, N)
    REP(j, K)
    if (i == j || !j)
        C[i][j] = 1;
    else if (i)
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mi;
    scanf("%d%d", &n, &m);
    REP(i, n + 1)
    REP(j, m + 1)
    cnt[i % 2][j % 2]++;
    ll ans = 0;
    REP(x1, 2)
    REP(y1, 2)
        REP(x2, 2) REP(y2, 2)
            REP(x3, 2) REP(y3, 2)
    {
        int vd = Abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
        if (vd % 2 == 0)
        {
            ll cur = 1;
            cur = (cur * cnt[x1][y1]) % Mi;
            cnt[x1][y1]--;
            cur = (cur * cnt[x2][y2]) % Mi;
            cnt[x2][y2]--;
            cur = (cur * cnt[x3][y3]) % Mi;
            cnt[x3][y3]--;

            ans = (ans + cur) % Mi;

            cnt[x1][y1]++;
            cnt[x2][y2]++;
            cnt[x3][y3]++;
        }
    }

    REP(i, n + 1)
    {
        ans -= (6LL * C[m + 1][3]) % Mi;
        ans = (ans + Mi) % Mi;
    }
    REP(i, m + 1)
    {
        ans -= (6LL * C[n + 1][3]) % Mi;
        ans = (ans + Mi) % Mi;
    }
    FOR(dx, 1, n)
    FOR(dy, 1, m)
    {
        ll cur = (ll(n - dx + 1) * ll(m - dy + 1)) % Mi;
        int g = gcd(dx, dy) - 1;
        cur = (cur * ll(g)) % Mi;
        cur = (cur * 12LL) % Mi;
        ans = (ans - cur + Mi) % Mi;
    }
    cout << ans << endl;
    return 0;
}
