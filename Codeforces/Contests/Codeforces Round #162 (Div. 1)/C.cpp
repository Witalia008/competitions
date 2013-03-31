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
#include <assert.h>
using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair
#define eps 10e-9
#define Inf 1000000000
#define Mi 1000000007
#define N 100001
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

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

ll maxx(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

//#define DEBUG

ll max1, max2;
int n1, n2;
ll M[N];
int n;

void init()
{
    max1 = max2 = -InfLL;
    n1 = n2 = -1;
    REP(i, n)
    M[i] = -InfLL;
}

int q;
int c[N], v[N];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> q;
    REP(i, n)
        cin >> v[i];
    REP(i, n)
    {
        cin >> c[i];
        c[i]--;
    }
    REP(_t, q)
    {
        ll ai, bi;
        cin >> ai >> bi;
        ll ans = 0;
        init();
        REP(i, n)
        {
            ll r = max1;
            if (n1 == c[i])
                r = max2;
            r = maxx(r, 0);
            ll F = maxx(r + v[i] * bi, ((M[c[i]] > -InfLL) ? M[c[i]] + v[i] * ai : -InfLL));
            ans = maxx(ans, F);
            if (F > M[c[i]])
            {
                M[c[i]] = F;
                if (n1 == c[i])
                    max1 = F;
                else if (n2 == c[i])
                {
                    max2 = F;
                    if (max2 > max1)
                    {
                        swap(max1, max2);
                        swap(n1, n2);
                    }
                }
                else if (F >= max1)
                {
                    max2 = max1, max1 = F;
                    n2 = n1;
                    n1 = c[i];
                }
                else if (F > max2)
                    max2 = F, n2 = c[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
