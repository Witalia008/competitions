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
#define N 100015
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

int n, m;

ll power()
{
    ll res = 1;
    ll a = 3;
    while (n)
    {
        if (n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    ll ans = power();
    ans = (ans - 1 + m) % m;
    cout << ans << endl;
    return 0;
}
