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
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair

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

const int Inf = 10e9;
const int Mi = Inf + 7;
const int N = 100005;
const int K = 32;
const ld eps = 10e-7;
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

//#define DEBUG

typedef unsigned int uni;

int n, k;
uni ips[N];
int en;
int bor[N * (K + 5)][2];

bool add_bor(uni a)
{
    int v = 1;
    bool res = false;
    FORD(i, K, 0)
    {
        bool d = ((a >> i) & 1);
        if (bor[v][d] == 0)
        {
            res = true;
            bor[v][d] = ++en;
        }
        v = bor[v][d];
    }
    return res;
}

uni get_ip(uni a, uni b, uni c, uni d)
{
    return ((a << 24) | (b << 16) | (c << 8) | d);
}

void print(uni mask)
{
    printf("%d.%d.%d.%d\n", mask >> 24, (mask >> 16) % 256, (mask >> 8) % 256, mask % 256);
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d\n", &n, &k);
    REP(i, n)
    {
        uni a, b, c, d;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        ips[i] = get_ip(a, b, c, d);
    }
    uni mask = 0;
    FORD(i, 31, 1)
    {
        mask |= (uni(1) << i);
        CLR(bor, 0);
        en = 1;
        int cnt = 0;
        REP(j, n)
        {
            uni cur = mask & ips[j];
            cnt += add_bor(cur);
        }
        if (cnt == k)
        {
            print(mask);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
