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
#define eps 10e-7
#define Inf 1000000000
#define Mi 1000000007
#define N 115
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

inline ld Abs(ld x) { return x < 0 ? -x : x; }
inline ld sqr(ld a) { return a * a; }
inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

int n;
int ans[N];
int a[N][N];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    freopen("gluck.in", "r", stdin);
    freopen("gluck.out", "w", stdout);
#endif
    scanf("%d", &n);
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        scanf("%d", &a[i][j]);
        a[i][j] *= -1;
    }
    vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
    FOR(i, 1, n)
    {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, Inf);
        vector<char> used(n + 1, false);
        do
        {
            used[j0] = true;
            int i0 = p[j0], delta = Inf, j1;
            FOR(j, 1, n)
            if (!used[j])
            {
                int cur = a[i0][j] - u[i0] - v[j];
                if (cur < minv[j])
                    minv[j] = cur, way[j] = j0;
                if (minv[j] < delta)
                    delta = minv[j], j1 = j;
            }
            FOR(j, 0, n)
            if (used[j])
                u[p[j]] += delta, v[j] -= delta;
            else
                minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do
        {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    cout << v[0] << endl;
    FOR(i, 1, n)
    ans[p[i]] = i;
    FOR(i, 1, n)
    printf("%d %d\n", i, ans[i]);
    return 0;
}
