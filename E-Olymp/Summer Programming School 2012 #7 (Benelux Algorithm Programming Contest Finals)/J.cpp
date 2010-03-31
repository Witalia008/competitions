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
#define eps 10e-10
#define e_num 2.718281828259
#define Inf 1000000000
#define Mi 1000000007
#define N 555
#define K 16
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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

int x, y, n;

void try_aa(int d)
{
    int cx, cy;
    cy = (n / d + d) / 2;
    cx = (n / d - d) / 2;
    if ((cx < x || cx == x && cy < y) && cx >= 0 && cy >= 0 && cy * cy - cx * cx == n)
        x = cx, y = cy;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        scanf("%d", &n);
        if (n % 4 == 2)
            printf("IMPOSSIBLE\n");
        else
        {
            x = y = Inf;
            int q = int(sqrt(1.0 * n));
            for (int i = 1; i <= q; i++)
                if (n % i == 0)
                    try_aa(i), try_aa(n / i);
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
