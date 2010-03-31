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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 105

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

ll Me[N][10][10];
int C[N][N];
int A[10];
int S;

ll func(int L, int D, int I = 0)
{
    if (I == 10)
        return (L == 0);
    if (Me[L][D][I] != -1)
        return Me[L][D][I];
    ll res = 0;
    int d = A[I] - (I == D);
    for (int i = 0; i <= d && i <= L; i++)
        res = (res + C[L][i] * func(L - i, D, I + 1)) % Mi;
    return (Me[L][D][I] = res);
}

ll count(int L)
{
    ll sum = 0;
    FOR(d, 1, 9)
    {
        ll pw = d;
        REP(l, L)
        {
            sum = (sum + pw * func(l, d)) % Mi;
            pw = (pw * 10 + d) % Mi;
        }
    }
    return sum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    C[0][0] = 1;
    FOR(i, 1, N - 1)
    {
        C[i][0] = 1;
        FOR(j, 1, i)
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mi;
    }
    REP(t, T)
    {
        S = 0;
        FOR(i, 1, 9)
        scanf("%d", &A[i]), S += A[i];
        CLR(Me, -1);
        cout << count(S) << endl;
    }
    return 0;
}
