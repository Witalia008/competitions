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

//#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef long long ll;

const int N = 10000000;
const int K = 605;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

int n;
vector<ll> a, s, S;

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    cin >> n;
    a.resize(n);
    s.resize(n);
    S.resize(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; ++i)
    {
        s[i] = a[i];
        S[i] = a[i] * (i + 1);
        if (i)
        {
            s[i] += s[i - 1];
            S[i] += S[i - 1];
        }
    }
    ll ans = S[n - 1];
    for (int i = 0; i < n; ++i)
    {
        ll cur = S[i] + s[i] * (n - i - 1);
        cur += S[n - 1] - S[i] - (s[n - 1] - s[i]) * (i + 1);
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
