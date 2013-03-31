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

ll power(ll a, ll k)
{
    ll res = 1;
    while (k > 0)
    {
        if (k & 1)
        {
            res = res * a;
        }
        a = a * a;
        k >>= 1;
    }
    return res;
}

char s[N];
vector<int> bad[2];
bool used[N];

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
        int type;
        scanf("%d\n", &type);
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; ++i)
        {
            s[i] = s[i] == 'B' ? 0 : 1;
        }
        // Check
        int bal = 0;
        for (int i = 0; i < n; ++i)
        {
            bal += s[i] == 0 ? 1 : -1;
        }

        ll ans = InfLL;
        for (int st = 0; st < 2; ++st)
        {
            for (int i = 0; i < 2; ++i)
            {
                bad[i].clear();
            }
            for (int i = 0; i < n; ++i)
            {
                if (s[i] != (i + st) % 2)
                {
                    bad[s[i]].push_back(i);
                }
            }
            if (bad[0].size() != bad[1].size())
            {
                continue;
            }
            ll cur = 0;
            for (int i = 0; i < bad[0].size(); ++i)
            {
                cur += power(Abs(bad[0][i] - bad[1][i]), type - (type == 2));
            }
            ans = min(ans, cur);
        }
        printf("%lld\n", ans == InfLL ? -1 : ans);
    }
    return 0;
}
