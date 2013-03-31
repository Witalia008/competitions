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
const int N = 100005;
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

string toStr(int n)
{
    char s[100];
    sprintf(s, "%d", n);
    return string(s);
}

char s[N];
vector<pii> req[N];
int vals[N];
ll res[N];
ll sum[N];

int bin_srch(int l, int r, int x)
{
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (vals[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (vals[l] >= x)
    {
        return l;
    }
    if (vals[r] >= x)
    {
        return r;
    }
    return r + 1;
}

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
        int n, k, m;
        scanf("%d%d%d\n", &n, &k, &m);
        scanf("%s", s);
        for (int i = 0; i < n; ++i)
        {
            req[i].clear();
        }
        for (int i = 0; i < m; ++i)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            --r;
            req[r].push_back(make_pair(l, i));
        }

        int cnt[2] = {0};
        for (int l = 0, i = 0; i < n; ++i)
        {
            ++cnt[s[i] - '0'];
            while (cnt[0] > k || cnt[1] > k)
            {
                --cnt[s[l++] - '0'];
            }
            vals[i] = l;
            sum[i] = (i - l + 1) + (i == 0 ? 0 : sum[i - 1]);
            for (auto p : req[i])
            {
                int mid = bin_srch(p.first, i, p.first);
                ll ans = sum[i];
                if (mid > p.first)
                {
                    ans -= sum[mid - 1];
                    int x = mid - p.first;
                    ans += (ll)x * (x + 1) / 2;
                }
                else if (p.first > 0)
                {
                    ans -= sum[p.first - 1];
                }
                res[p.second] = ans;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            printf("%lld\n", res[i]);
        }
    }
    return 0;
}
