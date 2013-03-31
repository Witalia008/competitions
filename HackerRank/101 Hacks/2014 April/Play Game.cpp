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

int T, n;
vector<int> a;
vector<ll> F, s;

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> n;
        a.resize(n);
        s.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> a[n - 1 - i];
        for (int i = 0; i < n; ++i)
        {
            s[i] = a[i];
            if (i)
                s[i] += s[i - 1];
        }
        F.assign(n, 0);
        for (int i = 0; i < 3 && i < a.size(); ++i)
            F[i] = s[i];
        for (int i = 3; i < a.size(); ++i)
        {
            for (int j = 1; j <= 3; ++j)
            {
                F[i] = max(F[i], -F[i - j] + s[i]);
            }
        }
        cout << F.back() << endl;
    }
    return 0;
}
