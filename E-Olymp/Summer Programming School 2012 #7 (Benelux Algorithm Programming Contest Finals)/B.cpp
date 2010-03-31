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
#define e_num 2.718281828259
#define Inf 1000000000
#define Mi 1000000007
#define N 555
#define K 16
//#define debug

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

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
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

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

int n, m, d;
int D[N][N];
char A[N][N];
priority_queue<pair<int, pii>> Q;

bool good(pii a)
{
    return a.first >= 0 && a.second < m && a.first < n && a.second >= 0;
}

bool is_edge(pii a)
{
    return a.first == 0 || a.second == 0 || a.first == n - 1 || a.second == m - 1;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        scanf("%d%d%d\n", &n, &m, &d);
        REP(i, n)
        REP(j, m)
        D[i][j] = Inf;
        while (!Q.empty())
            Q.pop();
        REP(i, n)
        {
            scanf("%s", &A[i]);
            REP(j, m)
            if (A[i][j] == 'S')
                Q.push(mp(0, mp(i, j))), D[i][j] = 0;
        }
        int ans = 0;
        while (!Q.empty())
        {
            pii cur = Q.top().second;
            int len = -Q.top().first;
            if (is_edge(cur))
            {
                ans = len;
                break;
            }
            Q.pop();
            REP(k, 4)
            {
                pii nx = mp(cur.first + mx[k], cur.second + my[k]);
                if (good(nx) && A[nx.first][nx.second] != '#')
                    if (D[nx.first][nx.second] > len + 1 + (A[nx.first][nx.second] == '@') * d)
                    {
                        D[nx.first][nx.second] = len + 1 + (A[nx.first][nx.second] == '@') * d;
                        Q.push(mp(-D[nx.first][nx.second], nx));
                    }
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}
