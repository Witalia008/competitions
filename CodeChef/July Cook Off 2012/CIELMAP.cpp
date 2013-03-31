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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1005

typedef double ld;
typedef long long ll;
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
int sqr(int a) { return a * a; }

struct pt
{
    int x, y;
};

int n;
pt A[N];

#define debug
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    REP(t, T)
    {
        scanf("%d", &n);
        REP(i, n)
        scanf("%d%d", &A[i].x, &A[i].y);
        ld ans = 0;
        if (n == 4)
        {
            REP(i, n)
            REP(j, n)
            if (i != j)
            {
                ld d = sqrt(ld(sqr(A[i].x - A[j].x)) + ld(sqr(A[i].y - A[j].y)));
                int k = 0;
                while (k == i || k == j)
                    k++;
                int l = 0;
                while (l == i || l == j || l == k)
                    l++;
                if (cw(A[i], A[j], A[k]) == cw(A[i], A[j], A[l]))
                    if (d > ans)
                        ans = d;
            }
        }
        else
        {
            REP(i, n)
            REP(j, n)
            {
                ld d = sqrt(ld(sqr(A[i].x - A[j].x)) + ld(sqr(A[i].y - A[j].y)));
                if (d > ans)
                    ans = d;
            }
        }
        printf("%0.7lf\n", ans);
    }
    return 0;
}
