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
const int N = 50005;
//const int K = 20;
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

ll poww(ll a, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}

vector<double> a;
double F[20][20];

double count_p(vector<double> b)
{
    int k = b.size();
    F[0][0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            F[i][j] = F[i - 1][j] * (1 - b[i - 1]);
            if (j)
            {
                F[i][j] += F[i - 1][j - 1] * b[i - 1];
            }
        }
    }
    return F[k][k / 2];
}

//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int _t = 0; _t < t; ++_t)
    {
        cout << "Case #" << (_t + 1) << ": ";

        int n, k;
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        double ans = 0;
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            if (__popcnt(mask) == k)
            {
                vector<double> b;
                for (int i = 0; i < n; ++i)
                {
                    if ((mask >> i) & 1)
                    {
                        b.push_back(a[i]);
                    }
                }
                ans = max(ans, count_p(b));
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
