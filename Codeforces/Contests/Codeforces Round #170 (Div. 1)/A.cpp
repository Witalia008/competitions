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
#define eps 10e-9
#define Inf 1000000000
#define Mi 1000000007
#define N 300005
#define K 105

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

int n, m;
vi lan[K];
bool M[K][K];
int col[K], cnt_col[K];
int cur_col;

void dfs(int v)
{
    col[v] = cur_col;
    REP(j, n)
    if (M[v][j] && !col[j])
        dfs(j);
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
    cin >> n >> m;
    REP(i, n)
    {
        int cnt = 0;
        cin >> cnt;
        lan[i].resize(cnt);
        REP(j, cnt)
        cin >> lan[i][j];
        sort(lan[i].begin(), lan[i].end());
    }
    REP(i, n)
    REP(j, n)
    {
        int p1 = 0, p2 = 0;
        bool fl = false;
        while (p1 < lan[i].size() && p2 < lan[j].size())
        {
            if (lan[i][p1] == lan[j][p2])
            {
                fl = true;
                break;
            }
            if (lan[i][p1] < lan[j][p2])
                p1++;
            else
                p2++;
        }
        M[i][j] = M[j][i] = fl;
    }
    REP(i, n)
    if (!col[i])
    {
        ++cur_col;
        dfs(i);
    }
    bool flag = true;
    REP(i, n)
    if (lan[i].size())
        flag = false;
    cout << cur_col - 1 + flag << endl;
    return 0;
}
