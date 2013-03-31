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
#define N 100005
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

struct xtree
{
    bool all;
    ll val, maxx;
};

xtree Tree[N * 4];

void add(int v, int l, int r, int kl, int kr, ll val)
{
    if (kl == l && kr == r)
    {
        Tree[v].all = true;
        Tree[v].val = val;
        Tree[v].maxx = val;
        return;
    }
    if (Tree[v].all)
    {
        Tree[v << 1].all = Tree[(v << 1) | 1].all = true;
        Tree[v].all = false;
        Tree[v << 1].val = Tree[(v << 1) | 1].val = Tree[v].val;
        Tree[v << 1].maxx = Tree[(v << 1) | 1].maxx = Tree[v].maxx;
    }
    int mid = (l + r) >> 1;
    if (kr <= mid)
        add(v << 1, l, mid, kl, kr, val);
    else if (kl > mid)
        add((v << 1) | 1, mid + 1, r, kl, kr, val);
    else
    {
        add(v << 1, l, mid, kl, mid, val);
        add((v << 1) | 1, mid + 1, r, mid + 1, kr, val);
    }
    Tree[v].maxx = max(Tree[v << 1].maxx, Tree[(v << 1) | 1].maxx);
}

ll get(int v, int l, int r, int kl, int kr)
{
    if (Tree[v].all)
        return Tree[v].val;
    if (kl == l && kr == r)
        return Tree[v].maxx;
    int mid = (l + r) >> 1;
    if (kr <= mid)
        return get(v << 1, l, mid, kl, kr);
    if (kl > mid)
        return get((v << 1) | 1, mid + 1, r, kl, kr);
    return max(
        get(v << 1, l, mid, kl, mid),
        get((v << 1) | 1, mid + 1, r, mid + 1, kr));
}

int n, m;

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
    REP(i, n)
    {
        int a;
        scanf("%d", &a);
        add(1, 1, n, i + 1, i + 1, a);
    }
    scanf("%d", &m);
    REP(i, m)
    {
        int w, h;
        scanf("%d%d", &w, &h);
        ll cur = get(1, 1, n, 1, w);
        cout << cur << endl;
        add(1, 1, n, 1, w, cur + h);
    }
    return 0;
}
