#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

using ll = unsigned long long;

const ll Inf2 = 1500000000;

ll steps_sum(ll x)
{
    return (x * (x + 1)) >> 1;
}

ll bin_search_1(ll l, ll r)
{
    auto func = [&](ll mid, bool allow_below) {
        ll mid_sum = steps_sum(mid);
        // Check if not underflow before subtraction.
        // If underflow, return true - meaning definitely below r.
        return mid_sum > l ? allow_below : l - mid_sum <= r;
    };

    ll left = 0, right = Inf2;
    while (left < right - 1)
    {
        ll mid = (left + right) >> 1;
        if (func(mid, true))
            right = mid;
        else
            left = mid;
    }

    return (func(right, false) && !func(left, false)) ? right : left;
}

ll subtr(ll start_n, ll n, bool isfirst)
{
    // Adds nn * start_n - since numbers are actually start_n + 1 ... start_n + nn*2-1
    if (isfirst) // sum odd
    {
        ll nn = (n + 1) / 2;
        // nn^2 - sum of odd numbers in [1, n]
        // nn - how many odd numbers there are.
        return nn * start_n + nn * nn;
    }
    else // sum even
    {
        ll nn = n / 2;
        // nn - how many even numbers there are
        // nn^(nn+1) - sum of even numbers in [1, n]
        return nn * start_n + nn * (nn + 1);
    }
}

ll bin_search_2(ll l, ll r, ll start_n)
{
    auto func = [&](ll mid) {
        ll sub_l = subtr(start_n, mid, true);
        ll sub_r = subtr(start_n, mid, false);
        return l >= sub_l && r >= sub_r;
    };

    ll left = 0, right = Inf2;
    while (left < right - 1)
    {
        ll mid = (left + right) >> 1;
        if (func(mid))
            left = mid;
        else
            right = mid;
    }
    return func(right) ? right : left;
}

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t + 1) << ": ";

        ll L, R;
        cin >> L >> R;

        // Make that l points to higher of the two.
        ll *l = &L, *r = &R;
        if (*l < *r)
            swap(l, r);

        // Calc how much needed to make higher number <= to lower number.
        ll n = bin_search_1(*l, *r);

        // L is higher and we need to subtract some amount from it.
        *l -= steps_sum(n);

        // Make that l points again to higher of the two or L of they are equal.
        l = &L, r = &R;
        if (*r > *l)
            swap(l, r);

        ll n2 = bin_search_2(*l, *r, n);

        // Subtract n2 steps count of pancakes after the initial n steps.
        *l -= subtr(n, n2, true);
        *r -= subtr(n, n2, false);
        n += n2;

        cout << n << " " << L << " " << R << endl;
    }
    return 0;
}
