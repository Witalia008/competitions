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

int D[1000][1000][3][3];

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
        
        string c;
        cin >> c;
        int n = c.size();
        
        for (auto& i : c) {
            i = string("PRS").find(i);
        }
        
        auto get_D = [&D, &c](int l, int r, int lc, int rc) -> int {
            if (l > r) return 0; // Always 0 for empty string
            if (l == r) {
                if (lc != rc) {
                    return c::Inf; // Cannot have different endings of len 1
                }
                return (c[l] != lc); // If that once char at pos l is changed
            }
            // otherwise - return what's in the array D
            return D[l][r][lc][rc];
        };
        
        // Start with len 2 since 0 and 1 are covered in the funciton above
        for (int len = 2; len <= n; ++len) {
            // Iterate [l, r] bounds of the substring
            for (int l = 0, r = len - 1; r < n; ++l, ++r) {
                // Iterate possible left and right chars
                for (int lc = 0; lc < 3; ++lc) {
                    for (int rc = 0; rc < 3; ++rc) {
                        if (len == 2 && lc == rc) {
                            D[l][r][lc][rc] = c::Inf;
                            continue;
                        }
                        int cur_min = c::Inf;
                        
                        // Iterate possible left and right chars of
                        // substring [l + 1, r - 1]
                        for (int lc1 = 0; lc1 < 3; ++lc1) {
                            // Cannot have same chars in l and l + 1
                            if (len > 2 && lc1 == lc) continue;
                            
                            for (int rc1 = 0; rc1 < 3; ++rc1) {
                                // Cannot have same chars in r and r - 1
                                if (len > 2 && rc1 == rc) continue;
                                
                                // Update smallest of allowed substrings
                                // [l + 1, r - 1] starting in lc1 ending in rc1
                                cur_min = min(cur_min, get_D(l + 1, r - 1, lc1, rc1));
                            }
                        }
                        
                        // Update current.
                        // Add whether left or right chars need changing.
                        D[l][r][lc][rc] = cur_min + (lc != c[l]) + (rc != c[r]);
                    }
                }
            }
        }
        
        int ans = c::Inf;
        
        for (int lc = 0; lc < 3; ++lc) {
            for (int rc = 0; rc < 3; ++rc) {
                // Possible answer in string [0, n - 1]
                // where left and right are different
                if (rc == lc) continue;
                ans = min(ans, D[0][n - 1][lc][rc]);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}