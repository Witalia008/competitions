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

bool pr[N];

int main()
{
    /// freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    CLR(pr, 1);
    for (int i = 2; i <= 245; i++)
        if (pr[i])
            for (int j = i * i; j < N; j += i)
                pr[j] = false;
    pr[0] = pr[1] = false;
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        int ans = 0;
        FOR(i, a, b)
        ans += pr[i];
        printf("Case %d: %d\n", t + 1, ans);
    }
    return 0;
}
