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
#define eps 10e-10
#define Inf 1000000000
#define Mi 10000007
#define N 100006
#define p 31
//#define debug

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
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

int A[N];
int T[N];
int n, m, x, y, s, S, xx;

void add(int i, ll val)
{
    for (; i < n; i = (i | (i + 1)))
        T[i] += val;
}

int get(int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += T[r];
    return res;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    REP(tt, t)
    {
        scanf("%d%d", &n, &m);
        CLR(A, 0);
        CLR(T, 0);
        S = 0;
        REP(i, m)
        {
            scanf("%d%d", &s, &x);
            x--;
            if (s == 1)
                scanf("%d", &y), y--;
            if (s == 0)
            {
                xx = (A[x] == 1 ? -1 : 1);
                A[x] += xx;
                add(x, xx);
                S += xx;
            }
            else
            {
                if (x > y)
                    swap(x, y);
                xx = get(y - 1) - get(x - 1);
                printf("%d\n", xx == 0 || xx == S);
            }
        }
    }
    return 0;
}
