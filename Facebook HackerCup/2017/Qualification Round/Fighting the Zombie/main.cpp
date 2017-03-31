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
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

//const int mx[4] = { 1, 0, -1, 0 };
//const int my[4] = { 0, 1, 0, -1 };

const int Inf = 1000000000;
const int Mi = 1000000007;
const int N = 500005;
const int M = 100005;
//const int K = 20;
const ld eps = 10e-7;
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

const int TPS = 6;
const int MAXS = 405;
const int MAXR = 21;
int ys[TPS] = {4, 6, 8, 10, 12, 20};
double F[TPS][MAXS][MAXR]; // F[type][sum][number of spins - X]

struct roll
{
    char sign;
    int x, y, z, mul;

    roll() : sign('+'), z(0) {}
};

roll convert(string ss)
{
    roll ans;
    sscanf(ss.c_str(), "%dd%d%c%d", &ans.x, &ans.y, &ans.sign, &ans.z);
    ans.mul = ans.sign == '+' ? 1 : -1;
    ans.y = find(ys, ys + TPS, ans.y) - ys;
    return ans;
}

//#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int t = 0; t < TPS; ++t)
    {
        F[t][0][0] = 1;
        for (int x = 1; x <= MAXR; ++x)
        {
            for (int s = 1; s < MAXS; ++s)
            {
                for (int y = 1; y <= ys[t] && y <= s; ++y)
                {
                    F[t][s][x] += F[t][s - y][x - 1];
                }
                F[t][s][x] /= ys[t];
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t + 1) << ": ";

        int h, s;
        cin >> h >> s;
        string ss;
        double ans = 0;
        for (int i = 0; i < s; ++i)
        {
            cin >> ss;
            roll cur = convert(ss);
            double prob = 0;
            for (int j = 0; j < MAXS; ++j)
            {
                if (j + (cur.sign == '+' ? 1 : -1) * cur.z >= h)
                {
                    prob += F[cur.y][j][cur.x];
                }
            }
            ans = max(ans, prob);
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
