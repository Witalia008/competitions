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
#define N 10005
#define K 205

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

string k1, k2;
string A[K], B[K], rem[K];
string F[K][K];
string ans[K];
int m, n, l, t;

bool equal(string a, string b)
{
    REP(i, l)
    if (a[i] != b[i] && a[i] != '?' && b[i] != '?')
        return false;
    return true;
}

string replace(string a, string b)
{
    string res = a;
    REP(i, l)
    {
        if (a[i] == '?' && b[i] == '?')
            res[i] = 'a';
        else
            res[i] = a[i] == '?' ? b[i] : a[i];
    }
    return res;
}

vi adj[K];
bool used[K];
bool f[K][K];

bool dfs(int v)
{
    if (v == t)
        return true;
    used[v] = true;
    REP(i, adj[v].size())
    {
        int to = adj[v][i];
        if (f[v][to] && !used[to])
        {
            bool possible = dfs(to);
            if (possible)
            {
                f[v][to] = false;
                f[to][v] = true;
                return true;
            }
        }
    }
    return false;
}

bool next_value(int i)
{
    ans[i] = "";
    FOR(j, 1, m)
    if (F[i][j] != "" && (ans[i] == "" || F[i][j] < ans[i]))
        ans[i] = F[i][j];
    if (ans[i] == "")
        return false;
    FOR(j, 1, m)
    if (F[i][j] == ans[i])
    {
        adj[i].push_back(j + m);
        adj[j + m].push_back(i);
        f[i][j + m] = true;
        F[i][j] = "";
    }
    CLR(used, false);
    return true;
}

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    int T;
    scanf("%d", &T);
    REP(_t, T)
    {
        printf("Case #%d: ", _t + 1);
        cin >> m;
        cin >> k1;
        cin >> k2;
        n = k1.length();
        l = n / m;
        REP(i, K)
        A[i] = B[i] = "";
        REP(i, n)
        {
            A[i / l] += k1[i];
            B[i / l] += k2[i];
        }
        REP(i, m)
        REP(j, m)
        if (equal(A[i], B[j]))
            F[i + 1][j + 1] = replace(A[i], B[j]);
        else
            F[i + 1][j + 1] = "";
        CLR(f, false);
        REP(i, K)
        adj[i].clear();
        t = m * 2 + 1;
        FOR(i, 1, m)
        {
            adj[0].push_back(i);
            adj[i].push_back(0);
            adj[i + m].push_back(t);
            adj[t].push_back(i + m);
            f[0][i] = f[i + m][t] = true;
        }

        bool fl = true;
        FOR(i, 1, m)
        {
            CLR(used, false);
            FOR(j, 1, m)
            rem[j] = F[i][j];
            while (!dfs(0))
                if (!next_value(i))
                {
                    fl = false;
                    break;
                }
            int wh = -1;
            if (!fl)
            {
                FOR(j, 1, i - 1)
                {
                    int flag = 0;
                    FOR(k, 1, m)
                    {
                        if (rem[k] != "" && (f[j][k + m] || f[k + m][j]))
                            flag |= 1;
                        if (rem[k] == "" && F[j][k] != "")
                            flag |= 2;
                    }
                    if (flag == 3)
                        wh = j;
                }
            }
            if (wh != -1)
            {
                next_value(wh);
                fl = true;
                FORD(j, m, 1)
                if (rem[j] != "")
                {
                    F[i][j] = rem[j];
                    f[i][j + m] = false;
                    adj[j + m].pop_back();
                    adj[i].pop_back();
                }
                --i;
            }
            if (!fl)
                break;
        }

        if (!fl)
            printf("IMPOSSIBLE\n");
        else
        {
            FOR(i, 1, m)
            cout << ans[i];
            cout << endl;
        }
    }
    return 0;
}
