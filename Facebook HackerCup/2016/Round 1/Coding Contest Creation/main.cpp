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

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = {1, 0, -1, 0};
const int my[4] = {0, 1, 0, -1};

const int Inf = 1000000000;
const int Mi = 1000000007;
const int N = 100005;
const int K = 305;
const ld eps = 10e-8;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

unsigned rand16() { return rand() % (1 << 16); }
unsigned rand32() { return (rand16() << 16) + rand16(); }
ull rand64() { return (((ull)rand32()) << 32) + rand32(); }
int rand(int L, int R)
{
    if (L > R)
        return R;
    return rand32() % (R - L + 1) + L;
}
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

ll Abs(ll a) { return a < 0 ? -a : a; }
ll sqr(ll a) { return a * a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

string toStr(int n)
{
    char s[100];
    sprintf(s, "%d", n);
    return string(s);
}

vector<int> d, f;

//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
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
        d.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> d[i];
        }

        f.resize(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            // current value of function
            f[i] = Inf;
            // use 1
            f[i] = min(f[i], f[i - 1] + 3);
            // use 2
            // if can use 2 and difference of second and first is at least 1 (ascending order) and
            // at most 30 (we can still put 2 in between and it'll be correct sequence)
            if (i >= 2 && d[i] > d[i - 1] && d[i] - d[i - 1] <= 30)
            {
                f[i] = min(f[i], f[i - 2] + 2);
            }
            // use 3
            // should be ascending and difference of second and first or third and second (but not both)
            // is less than or equal to 20
            if (i >= 3 &&
                d[i] > d[i - 1] && d[i - 1] > d[i - 2] &&               // check if ascending
                (d[i] - d[i - 1] <= 10 || d[i - 1] - d[i - 2] <= 10) && // at least one of them should be less than 10 (can fix only one)
                d[i] - d[i - 1] <= 20 && d[i - 1] - d[i - 2] <= 20      // if any is wrong, will be able to fix that
            )
            {
                f[i] = min(f[i], f[i - 3] + 1);
            }
            // use 4
            // just check conditions
            if (i >= 4 &&
                d[i] > d[i - 1] && d[i - 1] > d[i - 2] && d[i - 2] > d[i - 3] &&                // check if ascending
                d[i] - d[i - 1] <= 10 && d[i - 1] - d[i - 2] <= 10 && d[i - 2] - d[i - 3] <= 10 // check the difference
            )
            {
                f[i] = min(f[i], f[i - 4]);
            }
        }
        cout << f[n] << endl;
    }

    return 0;
}
