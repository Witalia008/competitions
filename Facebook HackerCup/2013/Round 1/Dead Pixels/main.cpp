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
#define N 1000005
#define K 40005

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
    int cnt, min, all;
};

xtree Tree[K * 4];

void build(int v, int l, int r)
{
    Tree[v].min = 0;
    Tree[v].cnt = r - l + 1;
    Tree[v].all = 0;
    if (l == r)
        return;
    int mid = (r + l) >> 1;
    build(v << 1, l, mid);
    build((v << 1) | 1, mid + 1, r);
}

xtree merg(xtree a, xtree b)
{
    xtree res;
    res.min = min(a.min, b.min);
    res.cnt = 0;
    if (a.min == res.min)
        res.cnt += a.cnt;
    if (b.min == res.min)
        res.cnt += b.cnt;
    res.all = 0;
    return res;
}

void add(int v, int l, int r, int kl, int kr, int val)
{
    if (l == kl && r == kr)
    {
        Tree[v].min += val;
        Tree[v].all += val;
        return;
    }
    if (Tree[v].all)
    {
        Tree[v << 1].all += Tree[v].all;
        Tree[(v << 1) | 1].all += Tree[v].all;
        Tree[v << 1].min += Tree[v].all;
        Tree[(v << 1) | 1].min += Tree[v].all;
        Tree[v].all = 0;
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
    Tree[v] = merg(Tree[v << 1], Tree[(v << 1) | 1]);
}

xtree get(int v, int l, int r, int kl, int kr)
{
    if (l == kl && r == kr)
        return Tree[v];
    int mid = (l + r) >> 1;
    xtree res;
    if (kr <= mid)
        res = get(v << 1, l, mid, kl, kr);
    else if (kl > mid)
        res = get((v << 1) | 1, mid + 1, r, kl, kr);
    else
        res = merg(
            get(v << 1, l, mid, kl, mid),
            get((v << 1) | 1, mid + 1, r, mid + 1, kr));
    res.min += Tree[v].all;
    return res;
}

struct pt
{
    int x, y;
};

struct segm
{
    int l, r, wh;
    segm() {}
    segm(int _l, int _r, int _wh) : l(_l), r(_r), wh(_wh) {}
};

vector<segm> B[K];
pt A[N];
int F[1001][1001];
int n, W, H, P, Q, a, b, c, d;
int minX, maxX, minY, maxY;

//#define DEBUG_MODE
//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "wb", stdout);
#endif
    int tt;
    scanf("%d", &tt);
    REP(_t, tt)
    {
        printf("Case #%d: ", _t + 1);
        cin >> W >> H >> P >> Q >> n >> A[0].x >> A[0].y >> a >> b >> c >> d;
        FOR(i, 1, n - 1)
        {
            A[i].x = (A[i - 1].x * a + A[i - 1].y * b + 1) % W;
            A[i].y = (A[i - 1].x * c + A[i - 1].y * d + 1) % H;
        }
#ifdef DEBUG_MODE
        cout << endl;
        REP(i, n)
        cout << A[i].x << " " << A[i].y << endl;
        cout << endl;
#endif
        int ans = 0;
        REP(i, K)
        B[i].clear();
        REP(i, n)
        {
            maxX = min(A[i].x, W - P);
            maxY = min(A[i].y, H - Q);
            minX = max(0, A[i].x - P + 1);
            minY = max(0, A[i].y - Q + 1);
            B[minX].push_back(segm(minY, maxY, 1));
            B[maxX + 1].push_back(segm(minY, maxY, -1));
        }
        build(1, 0, H - 1);
        REP(i, W - P + 1)
        {
            REP(j, B[i].size())
            add(1, 0, H - 1, B[i][j].l, B[i][j].r, B[i][j].wh);
            xtree cur = get(1, 0, H - 1, 0, H - Q);
            if (cur.min == 0)
                ans += cur.cnt;
        }
        printf("%d\n", ans);
#ifdef DEBUG_MODE
        CLR(F, 0);
        if (W <= 1000 && H <= 1000)
        {
            REP(i, n)
            F[A[i].x][A[i].y] = 1;
            REP(i, W)
            REP(j, H)
            {
                if (i)
                    F[i][j] += F[i - 1][j];
                if (j)
                    F[i][j] += F[i][j - 1];
                if (i && j)
                    F[i][j] -= F[i - 1][j - 1];
            }
            ans = 0;
            FOR(i, P - 1, W - 1)
            FOR(j, Q - 1, H - 1)
            {
                int cur = F[i][j];
                if (i >= P)
                    cur -= F[i - P][j];
                if (j >= Q)
                    cur -= F[i][j - Q];
                if (i >= P && j >= Q)
                    cur += F[i - P][j - Q];
                if (!cur)
                    ans++;
            }
            cout << "BRUTE\n"
                 << ans << endl;
        }
#endif
    }
    return 0;
}
