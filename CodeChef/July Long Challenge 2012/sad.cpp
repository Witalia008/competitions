#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 2000000
#define N 105

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

int A[N][N];
int ans = -1, n, m;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, n)
    REP(j, m)
    scanf("%d", &A[i][j]);
    REP(i, n)
    REP(j, m)
    {
        bool f1, f2;
        f1 = f2 = true;
        REP(l, m)
        if (A[i][l] < A[i][j])
            f1 = false;
        REP(l, n)
        if (A[l][j] > A[i][j])
            f2 = false;
        if (f1 && f2)
            ans = A[i][j];
    }
    if (ans == -1)
        printf("GUESS\n");
    else
        printf("%d\n", ans);
    return 0;
}
