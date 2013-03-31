#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100000

struct aa
{
    int t, p, pl;
};

bool comp(aa a, aa b)
{
    if (a.p < b.p)
        return false;
    if (a.p > b.p)
        return true;
    if (a.t < b.t)
        return true;
    return false;
}

int n, k;
aa A[60];

int main()
{
    //freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, n)
    scanf("%d%d", &A[i].p, &A[i].t);
    sort(A, A + n, &comp);
    A[0].pl = 1;
    for (int i = 1; i < n; i++)
        if (A[i].p == A[i - 1].p && A[i].t == A[i - 1].t)
            A[i].pl = A[i - 1].pl;
        else
            A[i].pl = i + 1;
    int ans = 0;
    REP(i, n)
    if (A[i].pl == A[k - 1].pl)
        ans++;
    printf("%d\n", ans);
    return 0;
}
