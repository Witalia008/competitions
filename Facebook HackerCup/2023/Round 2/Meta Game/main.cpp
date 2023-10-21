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

        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> B[i];
        }

        for (int i = 0; i < n * 2; ++i)
        {
            A.push_back(B[i]);
            B.push_back(A[i]);
        }

        vector<int> prefix_sum_cmp(n * 3, 0);

        for (int i = 0; i < n * 3; ++i)
        {
            if (A[i] != B[i])
            {
                prefix_sum_cmp[i] = A[i] < B[i] ? -1 : 1;
            }
            if (i)
            {
                prefix_sum_cmp[i] += prefix_sum_cmp[i - 1];
            }
        }

        auto cmp = [&prefix_sum_cmp](int l, int r)
        {
            return prefix_sum_cmp[r] - (l ? prefix_sum_cmp[l - 1] : 0);
        };

        auto all_cmp_eq = [&](int l, int r, int shift_by, bool eq_less)
        {
            return cmp(l + shift_by, r + shift_by) == (r - l + 1) * (eq_less ? -1 : 1);
        };

        bool can_do = false;
        int shift_steps = 0;

        // Try to shift and check.
        for (shift_steps = 0; shift_steps < n * 2; ++shift_steps)
        {
            // if all from 0 .. n / 2 - 1 are <
            // and all from (n + 1) / 2 are >
            if (all_cmp_eq(0, n / 2 - 1, shift_steps, /* eq_less= */ true) && all_cmp_eq((n + 1) / 2, n - 1, shift_steps, /* eq_less= */ false))
            {
                // When shifting by shift_steps all in the left half are less and all in the right half are greater.
                // Check if also equal.
                bool all_equal = true;
                for (int i = 0; i < n; ++i)
                {
                    if (A[i + shift_steps] != B[n - 1 - i + shift_steps])
                    {
                        all_equal = false;
                        break;
                    }
                }
                if (all_equal)
                {
                    can_do = true;
                    break;
                }
            }
        }

        if (can_do)
        {
            cout << shift_steps << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
