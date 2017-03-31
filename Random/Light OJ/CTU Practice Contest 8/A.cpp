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

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1000001
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

const ld y = 0.57721566490153286060;

ld A[N];
int n, T;

int main()
{
    scanf("%d", &T);
    REP(i, N)
    if (i)
        A[i] = A[i - 1] + 1 / ld(i);
    REP(t, T)
    {
        scanf("%d", &n);
        ld ans = log(ld(n)) + y + 1 / ld(2 * n);
        if (n < N)
            ans = A[n];
        printf("Case %d: %.9lf\n", t + 1, ans);
    }
    return 0;
}
