//#include "spoj.h"
#define _CRT_SECURE_NO_WARNINGS
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
#include <limits.h>

#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = {1, 0, -1, 0};
const int my[4] = {0, 1, 0, -1};

const int Inf = 1000000000;
const int MOD = 1000000007;
const int N = 1005;
const int K = 20;
const ld eps = 10e-8;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

unsigned rand16() { return rand() % (1 << 16); }
unsigned rand32() { return (rand16() << 16) + rand16(); }
ull rand64() { return (((ull)rand32()) << 32) + rand32(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand32() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

#define x first
#define y second

string toStr(int n)
{
    char s[100];
    sprintf(s, "%d", n);
    return string(s);
}

int dsu[N * N];
int cnt[N * N];
int max_size;

int dsu_get(int v)
{
    return (dsu[v] == v) ? v : (dsu[v] = dsu_get(dsu[v]));
}
bool dsu_union(int u, int v, int x)
{
    u = dsu_get(u);
    v = dsu_get(v);
    if (u == v)
    {
        return false;
    }
    if (rand() & x)
    {
        swap(u, v);
    }
    dsu[v] = u;
    cnt[u] += cnt[v];
    max_size = max(max_size, cnt[u]);
    return true;
}

int n, m;

int get_id(pii a) { return a.x * m + a.y; }
pii get_pos(int id) { return make_pair(id / m, id % m); }

pii dsu_get(pii v)
{
    return get_pos(dsu_get(get_id(v)));
}
bool dsu_union(pii u, pii v, int x)
{
    return dsu_union(get_id(u), get_id(v), x);
}
int get_cnt(pii v) { return cnt[get_id(v)]; }

struct Query
{
    int type;
    pii u;
    pii v;
};

vector<Query> quer;
int walls[N][N][2];

//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int q;
        scanf("%d%d%d", &n, &m, &q);
        quer.resize(q);
        memset(walls, 0, sizeof(walls));
        for (int i = 0; i < q; ++i)
        {
            // read query
            scanf("%d", &quer[i].type);
            if (quer[i].type != 4)
            {
                scanf("%d%d", &quer[i].u.x, &quer[i].u.y);
                --quer[i].u.x;
                --quer[i].u.y;
            }
            if (quer[i].type == 3)
            {
                scanf("%d%d", &quer[i].v.x, &quer[i].v.y);
                --quer[i].v.x;
                --quer[i].v.y;
            }
            // add walls
            if (quer[i].type <= 2)
            {
                ++walls[quer[i].u.x][quer[i].u.y][quer[i].type - 1];
            }
        }
        for (int i = 0; i < n * m; ++i)
        {
            dsu[i] = i;
            cnt[i] = 1;
        }
        max_size = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                pii cur = make_pair(i, j);
                if (j + 1 < m && !walls[i][j][0])
                {
                    dsu_union(cur, make_pair(i, j + 1), 0);
                }
                if (i + 1 < n && !walls[i][j][1])
                {
                    dsu_union(cur, make_pair(i + 1, j), 0);
                }
            }
        }
        // process queries in reverse order
        ll ans = 0;
        for (int i = q - 1; i >= 0; --i)
        {
            switch (quer[i].type)
            {
            case 1:
                if (!--walls[quer[i].u.x][quer[i].u.y][0])
                {
                    dsu_union(quer[i].u, make_pair(quer[i].u.x, quer[i].u.y + 1), 1);
                }
                break;
            case 2:
                if (!--walls[quer[i].u.x][quer[i].u.y][1])
                {
                    dsu_union(quer[i].u, make_pair(quer[i].u.x + 1, quer[i].u.y), 1);
                }
                break;
            case 3:
                ans += (dsu_get(quer[i].u) == dsu_get(quer[i].v));
                break;
            case 4:
                ans += max_size;
                break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
