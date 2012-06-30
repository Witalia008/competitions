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
#define N 10005

typedef double ld;
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

int S[N];

int phi(int n)
{
    if (n <= 1)
        return 0;
    int res = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    REP(i, N)
    {
        S[i] = phi(i);
        if (i)
            S[i] += S[i - 1];
    }
    REP(i, n)
    {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        int ans = S[b];
        if (a)
            ans -= S[a - 1];
        ans = ans % (x + y);
        if (ans >= x)
            printf("Funtik\n");
        else
            printf("Slivka\n");
    }
    return 0;
}
