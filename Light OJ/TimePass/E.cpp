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
#define Mi 1000000007
#define N 505
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

int A[N][N];
int F[N][N];

int main()
{
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        int n;
        scanf("%d", &n);
        CLR(F, 0);
        CLR(A, 0);
        REP(i, n * 2 - 1)
        {
            A[i][0] = min(i + 1, 2 * n - 1 - i);
            FOR(j, 1, A[i][0])
            {
                scanf("%d", &A[i][j]);
                F[i][j] = A[i][j];
                if (i)
                {
                    if (i >= n)
                        F[i][j] += max(F[i - 1][j], j < A[i - 1][0] ? F[i - 1][j + 1] : 0);
                    else
                        F[i][j] += max(F[i - 1][j], j > 1 ? F[i - 1][j - 1] : 0);
                }
            }
        }
        printf("Case %d: %d\n", t + 1, F[2 * n - 2][1]);
    }
    return 0;
}
