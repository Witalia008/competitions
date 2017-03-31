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
//#include <assert.h>
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
#define N 10005
#define K 105

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

ll power(ll a, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % Mi;
        a = (a * a) % Mi;
        k >>= 1;
    }
    return res;
}

ll fact[N];

ll C(int n, int k)
{
    ll ans = fact[n];
    ans = (ans * power(fact[k], Mi - 2)) % Mi;
    ans = (ans * power(fact[n - k], Mi - 2)) % Mi;
    return ans;
}

int n, k;
ll A[N];

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    fact[0] = 1;
    REP(i, N)
    if (i)
        fact[i] = (fact[i - 1] * i) % Mi;
    int T;
    scanf("%d", &T);
    REP(_t, T)
    {
        scanf("%d%d", &n, &k);
        REP(i, n)
        cin >> A[i];
        sort(A, A + n);
        ll ans = 0;
        FOR(i, k - 1, n - 1)
        {
            ans += (A[i] * C(i, k - 1)) % Mi;
            ans %= Mi;
        }
        printf("Case #%d: %d\n", _t + 1, ans);
    }
    return 0;
}
