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
#define min(a, b) (a < b) ? (a) : (b)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef double ld;
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

int n, m;
int anc[N][20];
int deph[N];
ll len[N];

int lca(int a, int b)
{
    if (deph[a] > deph[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--)
        if (deph[anc[b][i]] >= deph[a])
            b = anc[b][i];
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
        if (anc[a][i] != anc[b][i])
            a = anc[a][i], b = anc[b][i];
    return anc[a][0];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    m = 1;
    REP(i, n)
    {
        char q;
        int a, b;
        scanf("%c%d%d\n", &q, &a, &b);
        if (q == '+')
        {
            m++;
            anc[m][0] = a;
            len[m] = len[a] + b;
            deph[m] = deph[a] + 1;
            FOR(j, 1, 19)
            anc[m][j] = anc[anc[m][j - 1]][j - 1];
        }
        else
        {
            ll ans = len[b];
            REP(j, a - 1)
            {
                int c;
                scanf("%d", &c);
                int x = lca(b, c);
                ans += len[b] + len[c] - len[x] * 2;
                b = c;
            }
            ans += len[b];
            cout << ans << endl;
        }
    }
    return 0;
}
