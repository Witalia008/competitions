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
#define N 1005
#define K 1005

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

struct anss
{
    int t, i, j;
    anss() {}
    anss(int _t, int _i, int _j) : t(_t), i(_i), j(_j) {}
};

int a[N][N];
int row[N], col[N];
int n;
vector<anss> ans;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    REP(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x][y] = 1;
        row[x]++;
        col[y]++;
    }
    for (; n; --n)
    {
        int m = 0;
        REP(i, n)
        if (!col[i])
            m = i;
        if (m != n - 1)
        {
            swap(col[m], col[n - 1]);
            ans.push_back(anss(2, m, n - 1));
            REP(i, n)
            swap(a[i][m], a[i][n - 1]);
        }
        REP(i, n)
        if (row[i])
            m = i;
        if (m != n - 1)
        {
            swap(row[m], row[n - 1]);
            ans.push_back(anss(1, m, n - 1));
        }
        REP(j, n)
        {
            swap(a[m][j], a[n - 1][j]);
            col[j] -= a[n - 1][j];
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size())
    printf("%d %d %d\n", ans[i].t, ans[i].i + 1, ans[i].j + 1);
    return 0;
}
