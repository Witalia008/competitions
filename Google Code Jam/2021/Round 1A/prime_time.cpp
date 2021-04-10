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

tp::ll do_the_prime_time(vector<tp::ll> const &p, vector<tp::ll> const &n, tp::ll sum_remains, int i = 0, tp::ll prod = 1, tp::ll sum = 0)
{
    if (i == p.size())
    {
        if (prod == sum)
        {
            return prod;
        }
        return 0;
    }

    tp::ll ans = 0;

    sum += p[i] * n[i];
    sum_remains -= p[i] * n[i];

    // cannot multiply more than 64 times
    for (int prod_cnt = 0; prod_cnt <= n[i] && prod_cnt <= 64; ++prod_cnt)
    {
        // Cannot possibly get a better answer, cause can't get a larger sum.
        // Or cannot possibly collect sum for the prod.
        if (sum + sum_remains <= ans || sum + sum_remains < prod)
        {
            break;
        }

        auto ans_cur = do_the_prime_time(p, n, sum_remains, i + 1, prod, sum);
        ans = max(ans, ans_cur);

        if (prod_cnt != n[i]) // if not end of iteration
        {
            // If next step will get us totally out of possible bounds.
            if (prod >= c::InfLL / p[i])
            {
                break;
            }
            prod *= p[i];
            sum -= p[i];
        }
    }

    return ans;
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

        int m;
        cin >> m;
        vector<tp::ll> p(m), n(m);

        tp::ll total_sum = 0;

        for (int i = 0; i < m; ++i)
        {
            cin >> p[i] >> n[i];
            total_sum += p[i] * n[i];
        }

        tp::ll ans = do_the_prime_time(p, n, total_sum);
        cout << ans << endl;
    }

    // int m = 95;
    // vector<tp::ll> p = {
    //     2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    //     101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    //     211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
    //     307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
    //     401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
    // vector<tp::ll> n(m);
    // tp::ll total_sum = 0;
    // for (int i = 0; i < m; ++i)
    // {
    //     n[i] = 1000000000000000LL / m;
    //     total_sum += p[i] * n[i];
    // }
    // do_the_prime_time(p, n, total_sum);

    return 0;
}
