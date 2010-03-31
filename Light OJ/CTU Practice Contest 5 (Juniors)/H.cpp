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

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        printf("Case %d: ", t + 1);
        double ab, ac, bc, n;
        cin >> ab >> ac >> bc >> n;
        double S = sq(ab, ac, bc);
        int cnt = 0;
        double l = 0, r = ab;
        while (cnt < 100)
        {
            double mid = (l + r) / 2;
            cnt++;
            double de = mid * bc / ab;
            double ae = mid * ac / ab;
            double cur = sq(mid, de, ae);
            if (cur / (S - cur) <= n)
                l = mid;
            else
                r = mid;
        }
        printf("%0.7lf\n", l);
    }
    return 0;
}
