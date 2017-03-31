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
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 60005

typedef float ld;
typedef long long ll;
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

const double pi = 3.14159;

int main()
{
    //freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);

    ld m, a;
    m = -1;
    cin >> m >> a;
    while (m != -1)
    {
        a = a * pi / 180;
        ld xx = sin(a);
        ld yy = tan(a);
        ld x = m / xx;
        ld h = m / yy;
        printf("%f\n", h + x);
        m = -1;
        cin >> m >> a;
    }
    return 0;
}
