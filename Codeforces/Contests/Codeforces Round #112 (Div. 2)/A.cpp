#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 205

struct pt
{
    int x, y;
};

int n;
pt A[N];

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, n)
    scanf("%d%d", &A[i].x, &A[i].y);
    int ans = 0;
    REP(i, n)
    {
        bool f1, f2, f3, f4;
        f1 = f2 = f3 = f4 = false;
        REP(j, n)
        {
            if (A[j].x > A[i].x && A[j].y == A[i].y)
                f1 = true;
            if (A[j].x < A[i].x && A[j].y == A[i].y)
                f2 = true;
            if (A[j].y > A[i].y && A[j].x == A[i].x)
                f3 = true;
            if (A[j].y < A[i].y && A[j].x == A[i].x)
                f4 = true;
        }
        if (f1 && f2 && f3 && f4)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
