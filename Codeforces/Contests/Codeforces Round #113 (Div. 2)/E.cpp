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
#define N 10000005
#define p 1000000007

int n;
ull F[N];

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d", &n);
    F[0] = 1;
    for (int i = 2; i <= n; i++)
        F[i] = (F[i - 1] * ull(2) + F[i - 2] * ull(3)) % p;
    printf("%d\n", F[n]);
    return 0;
}
