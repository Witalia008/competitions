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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 1000005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

double sq(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int n, m, k, p;
int a[40][40];
int sol[40];

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        printf("Case %d: ", t + 1);
        scanf("%d%d%d", &n, &m, &k);
        FOR(i, 1, m)
        sol[i] = 0;
        REP(i, n)
        REP(j, k)
        scanf("%d", &a[i][j]);
        scanf("%d", &p);
        REP(i, p)
        {
            int x;
            scanf("%d", &x);
            sol[x] = 1;
        }
        bool fl = true;
        REP(i, n)
        {
            bool flag = false;
            REP(j, k)
            if ((a[i][j] < 0 && !sol[-a[i][j]]) || (a[i][j] > 0 && sol[a[i][j]]))
                flag = true;
            if (!flag)
                fl = false;
        }
        if (fl)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
