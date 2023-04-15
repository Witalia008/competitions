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
        
        vector<tp::ull> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i) a[i] += a[i - 1];
        }
        
        auto get_sum = [&a](int l, int r) -> tp::ull {
            return a[r] - (l ? a[l - 1] : 0);
        };
        
        tp::ull sum_all = get_sum(0, n - 1);
        
        int La, Ra, Lb, Rb;
        cin >> La >> Ra >> Lb >> Rb;
        --La; --Ra; --Lb; --Rb;
        
        tp::ull ans = 0;
        
        // Try all starting points for Alice
        for (int i = La; i <= Ra; ++i) {
            // what's the closest positions Bob can choose on the right and left
            int b_right_closest = n;
            int b_left_closest = -1;
            
            if (Rb <= i) {
                b_left_closest = min(Rb, i - 1);
            } else if (Lb >= i) {
                b_right_closest = max(i + 1, Lb);
            } else {
                b_left_closest = i - 1;
                b_right_closest = i + 1;
            }
        
            // If Bob chooses left
            tp::ull bob_max_left_choice = 0;
            tp::ull bob_max_right_choice = 0;

            if (b_left_closest != -1) { // can choose left
                // How many available b/w b_left_closest and i non-inclusive
                int distance_left = i - b_left_closest - 1;
                // Bob will choose b_left_closest
                // Then move towards i
                // Will be able to take max of distance_left / 2 steps
                bob_max_left_choice = get_sum(0, b_left_closest + distance_left / 2);
            }
            if (b_right_closest != n) { // can choose right
                // How many available b/w b_left_closest and i non-inclusive
                int distance_right = b_right_closest - i - 1;
                // Bob will choose b_right_closest
                // Then move towards i
                // Will be able to take max of distance_left / 2 steps
                bob_max_right_choice = get_sum(b_right_closest - distance_right / 2, n - 1);
            }
            tp::ull bob_max_choice = max(bob_max_left_choice, bob_max_right_choice);
            tp::ull alice_cur_choice = sum_all - bob_max_choice;
            ans = max(ans, alice_cur_choice);
        }
        
        cout << ans << endl;
    }
    return 0;
}
