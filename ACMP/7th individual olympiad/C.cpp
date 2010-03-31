#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) FOR(i,0,n-1)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 2000000
#define N 1005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
#define eps 10e-7

int A[10005], B[10005];
int D, n;

int Abs (int a) { if (a < 0) return -a; return a; }

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &n, &D);
    for (int i = 0; i < n; i++)
        scanf ("%d", &A[i]);
    int ans = 1;
    B[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int m = 1;
        for (int j = 0; j < i; j++)
            if (Abs(A[i] - A[j]) <= D)
                m = max (m, B[j] + 1);
        B[i] = m;
        ans = max (ans, m);
    }
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++)
    {
        printf ("%d", B[i]);
        if (i == n - 1)
            printf ("\n");
        else
            printf (" ");
    }
    return 0;
}
