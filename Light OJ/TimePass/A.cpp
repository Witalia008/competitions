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
#define N 505
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

int F[55][55][55];

int main()
{
    int T;
    cin >> T;
    REP(t, T)
    {
        string a, b, c;
        cin >> a >> b >> c;
        CLR(F, 0);
        REP(i, a.length())
        REP(j, b.length())
        REP(k, c.length())
        if (a[i] == b[j] && b[j] == c[k])
        {
            F[i][j][k] = 1;
            if (i && j && k)
                F[i][j][k] += F[i - 1][j - 1][k - 1];
        }
        else
        {
            F[i][j][k] = 0;
            REP(l, 8)
            if (i - l % 2 >= 0 && j - (l >> 1) % 2 >= 0 && k - (l >> 2) % 2 >= 0)
                F[i][j][k] = max(F[i][j][k], F[i - l % 2][j - (l >> 1) % 2][k - (l >> 2) % 2]);
        }
        printf("Case %d: ", t + 1);
        cout << F[a.length() - 1][b.length() - 1][c.length() - 1] << endl;
    }
    return 0;
}
