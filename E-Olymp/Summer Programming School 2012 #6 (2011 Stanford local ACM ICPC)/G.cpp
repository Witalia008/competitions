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
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 1005
//#define debug

typedef double ld;
typedef unsigned long long ll;
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
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

int n, m, q;
pii A[N][N];

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d\n", &n, &m, &q);
    while (n)
    {
        REP(i, n)
        REP(j, m)
        A[i][j] = mp(Inf, Inf);
        REP(i, q)
        {
            int a, b, c;
            char q, q1;
            scanf("%d %d %c%c %d\n", &a, &b, &q, &q1, &c);
            a--;
            b--;
            if (q == '>')
                A[a][b].first = c;
            else
                A[a][b].second = c;
        }
        bool fl = true;
        REP(i, n)
        REP(j, m)
        if (A[i][j].first != Inf && A[i][j].second != Inf)
            if (A[i][j].first > A[i][j].second)
                fl = false;
        if (fl)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
        scanf("%d%d%d\n", &n, &m, &q);
    }
    return 0;
}
