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
#define e_num 2.718281828259
#define Inf 2000000000
#define Mi 1000000007
#define N 1005
#define K 16
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
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

struct house
{
    int x;
    ld l;
    bool is_cap;
};

bool cmp(house a, house b) { return a.x < b.x; }

int n;
house A[N];
ld F[N][N];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        scanf("%d", &n);
        CLR(A, 0);
        REP(i, N)
        REP(j, N) F[i][j] = -Inf;
        REP(i, n)
        scanf("%d%lf", &A[i].x, &A[i].l);
        A[0].is_cap = true;
        sort(A, A + n, &cmp);
        int cap = 0;
        for (; !A[cap].is_cap; cap++)
            ;
        REP(i, cap)
        {
            F[i][1] = A[i].x;
            if (i && F[i - 1][1] < F[i][1])
                F[i][1] = F[i - 1][1];
            if (i)
                FOR(k, 2, n)
                {
                    if (F[i - 1][k - 1] <= A[i].x && F[i - 1][k - 1] != -Inf)
                        F[i][k] = max(F[i - 1][k - 1] + A[i].l, A[i].x);
                    if ((F[i - 1][k] < F[i][k] || F[i][k] == -Inf) && F[i - 1][k] != -Inf)
                        F[i][k] = F[i - 1][k];
                }
        }
        F[cap][1] = A[cap].x + A[cap].l / 2;
        FOR(i, cap + 1, n - 1)
        {
            F[i][1] = F[cap][1];
            if (A[i].x < F[cap][1])
                continue;
            FOR(k, 2, n)
            {
                if (F[i - 1][k - 1] <= A[i].x && F[i - 1][k - 1] != -Inf)
                    F[i][k] = max(F[i - 1][k - 1] + A[i].l, A[i].x);
                if (F[i - 1][k] != -Inf && F[i - 1][k] < F[i][k])
                    F[i][k] = F[i - 1][k];
            }
        }
        int ans = 0;
        if (cap)
            FOR(k, 1, n)
        if (F[cap - 1][k] != -Inf && F[cap - 1][k] <= A[cap].x - A[cap].l / 2)
            ans = k;
        int cc = 0;
        FOR(k, 1, n)
        if (F[n - 1][k] != -Inf)
            cc = k;
        printf("%d\n", ans + cc);
    }
    return 0;
}
