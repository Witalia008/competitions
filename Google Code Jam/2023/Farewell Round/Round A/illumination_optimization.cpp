#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <stdio.h>
#include <time.h>
#include <vector>

#include <atomic>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <random>
#include <regex>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <valarray>

using namespace std;
using namespace std::chrono;

namespace tp
{
    using ld = double;
    using ll = long long;
    using ull = unsigned long long;
    using pii = pair<int, int>;
    using pll = pair<ll, ll>;
    using vi = vector<int>;
    using vvi = vector<vi>;
} // namespace tp

namespace c
{
    using namespace tp;

    const int mx[4] = {1, 0, -1, 0};
    const int my[4] = {0, 1, 0, -1};

    const int Inf = 1000000000;
    const ll InfLL = ll(Inf) * ll(Inf);
    const int Mi = 1000000007;
    const int N = 500000;
    const int M = 100005;
    const ld eps = 1e-7;
} // namespace c

namespace rnd
{
    using namespace tp;
    using namespace c;

    inline unsigned rand16()
    {
        return std::rand() % (1 << 16);
    }

    inline unsigned rand32()
    {
        return (rand16() << 16) + rand16();
    }

    inline ull rand64()
    {
        return (((ull)rand32()) << 32) + rand32();
    }

    inline int rand(int L, int R)
    {
        return L > R ? R : rand32() % (R - L + 1) + L;
    }

    inline ld random(ld L, ld R)
    {
        return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0;
    }
} // namespace rnd

namespace u
{
    using namespace tp;

    inline ll Abs(ll a)
    {
        return a < 0 ? -a : a;
    }

    inline ll sqr(ll a)
    {
        return a * a;
    }

    ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }
} // namespace u

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef LOCAL_RUN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t + 1) << ": ";
        
        int M, R, n;
        cin >> M >> R >> n;
        
        vector<int> x(n);
        for (auto& i : x) cin >> i;
        
        bool possible = true;
        
        possible &= x[0] <= R;
        possible &= M - x.back() <= R;
        for (int i = 1; i < n; ++i) {
            possible &= x[i] - x[i - 1] <= 2 * R;
        }
        
        if (!possible) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        
        int count_bulbs = 0;

        int max_cur_x = R;
        
        for (int i = 0; i < n; ++i) {
            // choose next bulb
            while (i + 1 < n && x[i + 1] <= max_cur_x) {
                ++i;
            }
            ++count_bulbs;
            max_cur_x = x[i] + R * 2;
            if (x[i] + R >= M) {
                break;
            }
        }

        cout << count_bulbs << endl;
    }
    return 0;
}