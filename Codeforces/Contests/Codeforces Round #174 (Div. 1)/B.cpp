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
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define Abs(a) ((a < 0) ? -(a) : a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair
#define eps 10e-5
#define Inf 1000000000
#define Mi 1000000007
#define N 200005
#define K 32

typedef double ld;
typedef long long ll;
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

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

inline ll gcd(ll a, ll b) { return (!b ? a : gcd(b, a % b)); }

const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

int rand15() { return rand() % (1 << 15); }
int rand30() { return (rand15() << 15) + rand15(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand30() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

//#define DEBUG

int n;
int A[N];
ll F[N][2];
int to[N][2];
bool used[N][2];
int len[N][2];
int c_0;

void dfs(int x, int c)
{
    if (x <= 0 || x > n)
    {
        return;
    }
    if (x == 1)
    {
        c_0 = c;
        return;
    }
    if (!used[x][c])
    {
        used[x][c] = true;
        int nx = x + (c ? -1 : 1) * A[x];
        dfs(nx, 1 - c);

        F[x][c] = A[x];
        to[x][c] = -1;
        len[x][c] = 0;

        if (nx >= 1 && nx <= n)
        {
            F[x][c] += F[nx][1 - c];
            to[x][c] = to[nx][1 - c];
            len[x][c] = 1 + len[nx][1 - c];
        }
    }
    if (to[x][c] == 1)
    {
        c_0 = (c + len[x][c]) % 2;
    }
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    scanf("%d", &n);
    FOR(i, 2, n)
    scanf("%d", &A[i]);
    CLR(used, false);

    FOR(i, 1, n - 1)
    {
        int x = 1, y = 0;
        x += i;
        y += i;
        if (x <= n)
        {
            c_0 = -1;
            dfs(x, 1);
            if (to[x][1] == -1)
            {
                cout << y + F[x][1] << endl;
            }
            else if (to[x][1] == 1)
            {
                if (c_0 == 0)
                    cout << -1 << endl;
                else
                    cout << y + F[x][1] + A[1] << endl;
            }
            else
                cout << -1 << endl;
        }
        else
            cout << y << endl;
    }
    return 0;
}
