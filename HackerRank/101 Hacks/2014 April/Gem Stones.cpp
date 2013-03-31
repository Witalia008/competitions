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

#define Cpp11
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

string s;

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    int cnt[26] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        bool cur[26] = {};
        cin >> s;
        for (auto j : s)
            cur[j - 'a'] = true;
        for (int j = 0; j < 26; ++j)
            cnt[j] += cur[j];
    }
    int res = 0;
    for (int i = 0; i < 26; ++i)
        res += cnt[i] == n;
    cout << res << endl;
    return 0;
}
