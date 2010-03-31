#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
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

int n, m, x, y, d;
char q;
vi a;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        printf("Case %d:\n", t + 1);
        a.clear();
        scanf("%d%d", &n, &m);
        a.resize(n);
        REP(i, n)
        scanf("%d", &a[i]);
        scanf("\n");
        REP(i, m)
        {
            scanf("%c", &q);
            if (q == 'S')
            {
                scanf("%d\n", &d);
                REP(i, n)
                a[i] += d;
            }
            if (q == 'M')
            {
                scanf("%d\n", &d);
                REP(i, n)
                a[i] *= d;
            }
            if (q == 'D')
            {
                scanf("%d\n", &d);
                REP(i, n)
                a[i] /= d;
            }
            if (q == 'R')
            {
                scanf("\n");
                reverse(a.begin(), a.end());
            }
            if (q == 'P')
            {
                scanf("%d%d\n", &x, &y);
                swap(a[x], a[y]);
            }
        }
        REP(i, n)
        {
            printf("%d", a[i]);
            if (i == n - 1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
