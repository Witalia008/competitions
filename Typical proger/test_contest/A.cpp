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
#define N 1005
#define K 1005

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

string s;
int pos;

bool next_int(int &a)
{
    while (pos < s.length() && (s[pos] < '0' || s[pos] > '9'))
        ++pos;
    if (pos == s.length())
        return false;
    a = 0;
    while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9')
    {
        a = a * 10 + s[pos] - '0';
        ++pos;
    }
    return true;
}

bool used[N][N], was[N][N];
vi adj[N];
int n, m, st;

bool dfs(int v, int t)
{
    if (used[v][t])
        return false;
    used[v][t] = true;
    if (was[v][t])
        return false;
    if (t == n - 1)
        return true;
    REP(i, adj[v].size())
    {
        int to = adj[v][i];
        if (dfs(to, t + 1))
            return true;
    }
    if (was[v + 1][t] && was[v][t + 1])
        ;
    else if (dfs(v + 1, t + 1))
        return true;
    return false;
}

//#define DEBUG_MODE
#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    cin >> n >> m;
    cin >> st;
    cin >> s;
    was[st][0] = true;
    REP(i, s.length())
    {
        if (s[i] == 'L')
            --st;
        else
            ++st;
        was[st][i + 1] = true;
    }
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        adj[u].push_back(v);
    }
    printf("%s\n", dfs(0, 0) ? "YES" : "NO");
    return 0;
}
