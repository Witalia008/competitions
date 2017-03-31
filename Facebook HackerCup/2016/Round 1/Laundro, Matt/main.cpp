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
const int Mi = 1000000007;
const int N = 100005;
const int K = 305;
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
ll sqr(ll a) { return a * a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

string toStr(int n)
{
    char s[100];
    sprintf(s, "%d", n);
    return string(s);
}

int n, m, l, d;
vector<int> w;

bool good(ll c)
{
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += c / w[i];
    return cnt >= l;
}

ll bin_srch(ll l, ll r)
{
    while (r - l > 1)
    {
        ll mid = (l + r) >> 1;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }
    if (good(l))
        return l;
    return r;
}

vector<ll> times;
multiset<ll> dryers;

//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t + 1) << ": ";

        cin >> l >> n >> m >> d;
        w.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> w[i];
        }
        // not necessary
        sort(w.begin(), w.end());

        // find minimal time to finish laundry
        ll lopt = bin_srch(0, InfLL);
        // find times of finishing for each item
        times.clear();
        for (int i = 0; i < n; ++i)
        {
            int cnt = lopt / w[i];
            for (int j = 0; j < cnt; ++j)
            {
                times.push_back((j + 1) * w[i]);
            }
        }
        // sort those times
        sort(times.begin(), times.end());
        // send to dryers
        for (int i = 0; i < min(l, m); ++i)
            dryers.insert(0);

        ll ans = 0;
        for (int i = 0; i < l; ++i)
        {
            ll cur = max(times[i], *dryers.begin()) + d;
            dryers.erase(dryers.begin());
            dryers.insert(cur);
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }

    return 0;
}
