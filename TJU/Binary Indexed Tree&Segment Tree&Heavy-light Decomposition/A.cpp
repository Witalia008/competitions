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

ll A[N];
ll T[N];
int n, m, x, y;
char s[10];

void add(int i, ll val)
{
    for (; i < n; i = (i | (i + 1)))
        T[i] += val;
}

ll get(int r)
{
    ll res = 0;
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
    while (t--)
    {
        scanf("%d", &n);
        CLR(A, 0);
        CLR(T, 0);
        REP(i, n)
        {
            scanf("%d", &A[i]);
            add(i, A[i]);
        }
        scanf("%d\n", &m);
        REP(i, m)
        {
            scanf("%s", &s);
            scanf("%d%d\n", &x, &y);
            x--;
            if (s[0] == 'A')
            {
                A[x] += y;
                add(x, y);
            }
            if (s[0] == 'D')
            {
                y = min(y, A[x]);
                A[x] -= y;
                add(x, -y);
            }
            if (s[0] == 'I')
                y--, printf("%I64d\n", get(y) - get(x - 1));
        }
    }
    return 0;
}
