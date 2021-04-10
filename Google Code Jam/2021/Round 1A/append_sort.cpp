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

bool larger(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() > b.length();
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    // equal -> not larger
    return false;
}

pair<int, string> append_digits(string prev, string cur)
{
    // if cur is already larger, do nothing.
    if (larger(cur, prev))
    {
        return make_pair(0, cur);
    }

    if (cur.length() == prev.length())
    {
        // if lengths are the same, cur <= prev -> add a zero at the end.
        return make_pair(1, cur + "0");
    }

    string prev_sub = prev.substr(0, cur.size());
    int ans = 0;

    bool all_9_after_common = true;
    for (int i = cur.size(); i < prev.size(); ++i)
    {
        all_9_after_common &= prev[i] == '9';
    }

    // cur.length < prev.length && cur < prev

    ans = prev.size() - cur.size();

    if (larger(prev_sub, cur) || cur == prev_sub && all_9_after_common)
    {
        // first part already smaller
        // or first part equal but all other are 9s
        // add zeros to have prev.length + 1
        ++ans;
        while (cur.size() <= prev.size())
        {
            cur += "0";
        }
    }
    else if (larger(cur, prev_sub))
    {
        // first part already larger, just add zeros up to prev.length
        while (cur.size() < prev.size())
        {
            cur += "0";
        }
    }
    else // equal, but not all 9
    {
        vector<int> prev_dig;
        for (char i : prev)
        {
            prev_dig.push_back(i - '0');
        }
        // add 1 to prev
        for (int i = prev_dig.size() - 1, p = 1; i >= 0; --i)
        {
            prev_dig[i] += p;
            p = prev_dig[i] > 9;
            prev_dig[i] %= 10;
        }
        cur = "";
        for (int i : prev_dig)
        {
            cur += i + '0';
        }
    }

    return make_pair(ans, cur);
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

        int n;
        cin >> n;
        vector<string> a(n);
        for (auto &i : a)
        {
            int x;
            cin >> x;
            // make sure no leading digits
            i = std::to_string(x);
        }

        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            auto app = append_digits(a[i - 1], a[i]);
            ans += app.first;
            a[i] = app.second;
        }

        cout << ans << endl;
    }

    // for (int a = 1; a <= 100; ++a)
    // {
    //     for (int b = 1; b <= 100; ++b)
    //     {
    //         for (int c = 1; c <= 100; ++c)
    //         {
    //             int n = 3;
    //             vector<string> x = {std::to_string(a), std::to_string(b), std::to_string(c)};

    //             for (auto i : x)
    //                 cout << i << " ";
    //             int ans = 0;
    //             for (int i = 1; i < n; ++i)
    //             {
    //                 auto app = append_digits(x[i - 1], x[i]);
    //                 ans += app.first;
    //                 x[i] = app.second;
    //             }
    //             cout << "-> ";

    //             for (auto i : x)
    //                 cout << i << " ";

    //             cout << " : " << ans << endl;
    //         }
    //     }
    // }
    return 0;
}
