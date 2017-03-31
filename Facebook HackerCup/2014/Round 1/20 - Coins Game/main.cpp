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
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

using ll = long long;

int n, k, c;

int first()
{
    int x = k / n;
    int _1 = n - k % n;
    int res = c;
    if (c > x * n)
        res += _1;
    return res;
}

int second()
{
    int ans = INT_MAX;
    vector<pair<int, int>> a;
    for (int max_h = 1; max_h <= k; ++max_h)
    {
        a.clear();
        int c_mh = k / max_h;
        int n_mh = k - c_mh * max_h;
        a.push_back(make_pair(max_h, c_mh));
        if (c_mh == n || n_mh || c_mh > n)
            continue;
        int dv = n_mh / (n - c_mh), md = n_mh % (n - c_mh);

        if (dv + (md != 0) >= max_h)
            continue;
        if (n_mh % (n - c_mh) != 0)
            a.push_back(make_pair(dv + 1, md));
        a.push_back(make_pair(dv, n - c_mh - md));

        int res = c;
        int pc = c;
        int pn = n;
        while (pc > 0)
        {
            if (pc >= pn * a.back().first)
            {
                pc -= pn * a.back().first;
                pn -= a.back().second;
                if (pc > 0)
                    res += a.back().second;
                a.pop_back();
            }
            else
                pc = 0;
        }
        ans = min(ans, res);
    }

    return ans;
}

int third()
{
    int res = INT_MAX;
    //return res;
    for (int i = 1; i <= n; ++i)
    {
        res = min(res, n - k % i);
    }
    return res + c;
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int _t = 0; _t < T; ++_t)
    {
        cin >> n >> k >> c;
        cout << "Case #" << _t + 1 << ": " << min({first(), second(), third()}) << endl;
    }
    return 0;
}
