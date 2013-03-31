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
#define eps 10e-3
#define Inf 1000000000
#define Mi 10000007
#define N 150
#define K 18
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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
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
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
int sqr(int a) { return a * a; }

const int Ans[N] = {0, 0, 1, 2, 5, 2, 4, 3, 11, 2, 3, 8, 16, 4, 21, 6, 5, 2, 11, 20, 34, 8, 15, 10, 7, 13, 11, 13, 45, 18, 23, 8, 3, 2, 25, 75, 42, 13, 5, 23, 13, 50, 16, 18, 89, 38, 8, 39, 30, 29, 38, 7, 45, 23, 137, 46, 63, 17, 48, 5, 46, 34, 140, 33, 39, 2, 28, 29, 79, 33, 48, 3, 10, 46, 120, 6, 37, 17, 8, 44, 15, 160, 20, 35, 144, 104, 179, 153, 24, 8, 265, 19, 9, 62, 7, 139, 19, 44, 93, 182, 27, 158, 185, 193, 17, 82, 3, 11, 43, 55, 21, 41, 146, 29, 80, 59, 8, 29, 66, 19, 160, 59, 28, 129, 127, 120, 72, 45, 157, 2, 63, 127, 81, 318, 513, 98, 28, 32, 231, 236, 411, 26, 45, 5, 303, 228, 66, 9, 205, 65};

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (!n)
            break;
        printf("%d\n", Ans[n]);
    }
    return 0;
}
