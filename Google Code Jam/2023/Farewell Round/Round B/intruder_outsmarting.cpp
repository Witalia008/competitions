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

        
tp::ll gcd(tp::ll a, tp::ll b, tp::ll& x, tp::ll& y) {
    if (!a) {
        x = 0;
        y = 1;
        return b;
    }
    
    tp::ll x1, y1;
    
    auto g = gcd(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;

    return g;
}

bool solve_diophantine(tp::ll a, tp::ll b, tp::ll c, tp::ll& x, tp::ll& y, tp::ll& g) {
    // ax + by = c
    // use extended GCD to solve |a|x + |b|y = g
    g = gcd(abs(a), abs(b), x, y);
    if (abs(c) % g != 0) {
        return false;
    }
    // adjust the signs
    x = a < 0 ? -x : x;
    y = b < 0 ? -y : y;
    // answer for =c instead of =g
    x *= c / g;
    y *= c / g;
    // solutions have form (x + kv, y − ku)
    // where u = a/g, and v = b/g
    tp::ll v = (b / g);
    v = abs(v);
    x = (x % v + v) % v;
    //cout << "solved " << a << "*(" << x << ") + " << b << "*(" << y << ")=" << c << endl;
    return true;
}

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
        
        int w, n, d;
        cin >> w >> n >> d;
        
        auto get_steps_forward = [n, d](tp::ll a, tp::ll b) -> tp::ll {
            if (a == b) return 0;
            // a + Dx = b (mod n)
            // a + Dx + Ny = b
            // Dx + Ny = b - a = c
            tp::ll x, y, g;
            if (!solve_diophantine(d, n, b - a, x, y, g)) {
                return -1;
            }
            return x;
        };
        
        auto get_steps_backward = [n, d](tp::ll a, tp::ll b) -> tp::ll {
            if (a == b) return 0;
            // a - Dx = b (mod n)
            // a - Dx + Ny = b
            // Dx - Ny = a - b
            tp::ll x, y, g;
            if (!solve_diophantine(d, -n, a - b, x, y, g)) {
                return -1;
            }
            return x;
        };
        
        vector<int> x(w);
        for (auto& i : x) cin >> i;
        
        tp::ll ans = 0;
        bool possible = true;
        
        for (int i = 0; i < w / 2; ++i) {
            int j = w - i - 1;
            
            auto cur = min(get_steps_forward(x[i], x[j]), get_steps_backward(x[i], x[j]));
            if (cur == -1) {
                possible = false;
                break;
            }
            ans += cur;
        }
        
        if (!possible) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
