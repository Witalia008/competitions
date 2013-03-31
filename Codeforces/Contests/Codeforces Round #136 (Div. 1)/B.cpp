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
#define eps 10e-3
#define Inf 1000000000
#define Mi 1000000007
#define N 200005
#define K 26
//#define debug

typedef double ld;
typedef unsigned long long ll;
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

int n, m, en, L, R, ans;
int A[N], cnt[N], An[N];
int H[500][100005];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    REP(i, n)
    {
        scanf("%d", &A[i]);
        if (A[i] < N)
            cnt[A[i]]++;
    }
    REP(i, N)
    if (i && cnt[i] >= i)
        An[en++] = i;
    REP(i, en)
    {
        REP(j, n)
        {
            if (A[j] == An[i])
                H[i][j] = 1;
            if (j)
                H[i][j] += H[i][j - 1];
        }
    }
    REP(i, m)
    {
        scanf("%d%d", &L, &R);
        L--;
        R--;
        ans = 0;
        REP(j, en)
        {
            int s = H[j][R];
            if (L)
                s -= H[j][L - 1];
            if (s == An[j])
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
