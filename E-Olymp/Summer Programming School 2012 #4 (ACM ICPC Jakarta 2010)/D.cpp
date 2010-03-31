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
#define N 100005

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

int T, n, k;
struct xx
{
    int nom, p, p0;
};

xx A[N], B[N], X[N];
int Ans[N];
int cnt;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d%d", &n, &k);
        CLR(A, 0);
        CLR(B, 0);
        CLR(X, 0);
        CLR(Ans, 0);
        int nn = 1 << n;
        for (int i = 0; i < nn; i++)
        {
            scanf("%d", &A[i].p);
            A[i].p0 = A[i].p;
            A[i].nom = i + 1;
            X[i] = A[i];
        }
        for (; nn != 1;)
        {
            for (int j = 0; j + 1 < nn; j += 2)
            {
                if (A[j].p >= A[j + 1].p)
                {
                    B[j / 2] = A[j];
                    B[j / 2].p -= A[j + 1].p;
                    B[j / 2].p += k;
                    if (B[j / 2].p > A[j].p0)
                        B[j / 2].p = A[j].p0;
                }
                else
                {
                    B[j / 2] = A[j + 1];
                    B[j / 2].p -= A[j].p;
                    B[j / 2].p += k;
                    if (B[j / 2].p > A[j + 1].p0)
                        B[j / 2].p = A[j + 1].p0;
                }
            }
            nn >>= 1;
            for (int j = 0; j < nn; j++)
                A[j] = B[j];
        }
        int winner = A[0].nom;
        nn = 1 << n;
        cnt = 0;
        for (; nn != 1;)
        {
            for (int j = 0; j + 1 < nn; j += 2)
            {
                if (X[j].p >= X[j + 1].p)
                {
                    B[j / 2] = X[j];
                    B[j / 2].p -= X[j + 1].p;
                    B[j / 2].p += k;
                    if (B[j / 2].p > X[j].p0)
                        B[j / 2].p = X[j].p0;
                    if (X[j].nom == winner)
                        Ans[cnt++] = X[j + 1].nom;
                }
                else
                {
                    B[j / 2] = X[j + 1];
                    B[j / 2].p -= X[j].p;
                    B[j / 2].p += k;
                    if (B[j / 2].p > X[j + 1].p0)
                        B[j / 2].p = X[j + 1].p0;
                    if (X[j + 1].nom == winner)
                        Ans[cnt++] = X[j].nom;
                }
            }
            nn >>= 1;
            for (int j = 0; j < nn; j++)
                X[j] = B[j];
        }
        printf("%d\n", winner);
        for (int i = 0; i < cnt; i++)
        {
            if (i)
                printf(" ");
            printf("%d", Ans[i]);
        }
        printf("\n");
    }
    return 0;
}
