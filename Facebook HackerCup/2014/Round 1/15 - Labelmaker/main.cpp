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

ll multi(ll cur, int x)
{
    ll res = 0;
    for (int i = 0; i < x; ++i)
    {
        res += cur;
        if (res < 0)
            return -1;
    }
    return res;
}

bool bigger(ll &n, int x, int k)
{
    ll res = 1;
    for (int i = 0; i < k; ++i)
    {
        res = multi(res, x);
        if (res < 0)
            return false;
    }
    if (n > res)
    {
        n -= res;
        return true;
    }
    return false;
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
        string s;
        cin >> s;
        ll n;
        cin >> n;
        cout << "Case #" << _t + 1 << ": ";

        ll cur = s.size();
        int rl = 1;
        while (cur > 0 && n > cur)
        {
            ++rl;
            n -= cur;
            cur = multi(cur, s.size());
        }
        for (int i = 0; i < rl; ++i)
        {
            for (int j = 0; j < s.size(); ++j)
                if (!bigger(n, s.size(), rl - 1 - i))
                {
                    cout << s[j];
                    break;
                }
        }
        cout << endl;
    }
    return 0;
}
