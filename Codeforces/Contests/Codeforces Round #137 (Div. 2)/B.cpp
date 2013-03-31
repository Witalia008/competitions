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
#define N 1015
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

int n, m, k;
int col[N], row[N], a[N][N];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d\n", &n, &m, &k);
    REP(i, n)
    row[i] = i;
    REP(j, m)
    col[j] = j;
    REP(i, n)
    {
        REP(j, m)
        scanf("%d", &a[i][j]);
        scanf("\n");
    }
    REP(i, k)
    {
        char s;
        int x, y;
        scanf("%c%d%d\n", &s, &x, &y);
        x--;
        y--;
        switch (s)
        {
        case 'c':
            swap(col[x], col[y]);
            break;
        case 'r':
            swap(row[x], row[y]);
            break;
        case 'g':
            printf("%d\n", a[row[x]][col[y]]);
            break;
        }
    }
    return 0;
}
