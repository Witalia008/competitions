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
#define N 1000001
#define K 26
//#define debug

typedef double ld;
typedef unsigned long long ll;
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

int cnt_9(ll a)
{
    int res = 0;
    while (a % 10 == 9)
        res++, a /= 10;
    return res;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll p, d;
    cin >> p >> d;
    ll st = 10;
    ll ans = p;
    REP(i, 19)
    {
        if (st - 1 > p)
            break;
        ll cur = (p / st) * st - 1;
        if (p - st + 1 <= d && st != 1)
            ans = st - 1;
        if (p - cur <= d)
            ans = cur;
        st *= 10;
    }
    if (cnt_9(p) > cnt_9(ans) || cnt_9(p) == cnt_9(ans) && p > ans)
        ans = p;
    cout << ans << endl;
    return 0;
}
