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
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1001
#define p 31
#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

int T, n;
int Time[2][N], Jump[2][N], F[2][N];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &T);
    REP(t, T)
    {
        scanf("%d", &n);
        REP(i, n)
        scanf("%d", &Time[0][i]);
        REP(i, n)
        scanf("%d", &Time[1][i]);
        REP(i, n - 1)
        scanf("%d", &Jump[0][i]);
        REP(i, n - 1)
        scanf("%d", &Jump[1][i]);
        F[0][0] = Time[0][0];
        F[1][0] = Time[1][0];
        REP(i, n)
        if (i)
        {
            F[0][i] = min(F[0][i - 1], F[1][i - 1] + Jump[1][i - 1]) + Time[0][i];
            F[1][i] = min(F[1][i - 1], F[0][i - 1] + Jump[0][i - 1]) + Time[1][i];
        }
        printf("Case %d: %d\n", t + 1, min(F[0][n - 1], F[1][n - 1]));
    }
    return 0;
}
