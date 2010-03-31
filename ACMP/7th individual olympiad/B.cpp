#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) FOR(i,0,n-1)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 2000000
#define N 1005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
#define eps 10e-7

ld sqr (ld a) { return a*a; }

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    ld x0, y0;
    ld x1 ,y1, r;
    cin >> x0 >> y0 >> x1 >> y1 >> r;
    ld d = sqrt(sqr(x0-x1)+sqr(y0-y1));
    ld b = sqrt (sqr(d) - sqr(r));
    ld res = b * r;
    ld alpha = 2*M_PI - asin(b / d) * 2;
    if (d > r)
        printf ("%0.6lf\n", res + alpha * r * r / 2);
    else
        printf ("%0.6lf\n", M_PI * r * r);
    return 0;
}
