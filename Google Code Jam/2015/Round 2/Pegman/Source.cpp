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
const int Mi = 1000000009;
const int N = 200005;
const int K = 105;
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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

string toStr(int n)
{
    char s[100];
    sprintf(s, "%d", n);
    return string(s);
}

vector<string> a;
bool can[K][K][4]; // 0 - up, 1 - right, 2 - down, 3 - left;;;  true - can contain that arrow
string dirs = "^>v<";

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

        int n, m;
        cin >> n >> m;
        a.resize(n);
        for (auto &i : a)
            cin >> i;

        bool impossible = false;
        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == '.')
                    continue;
                memset(can[i][j], 0, sizeof(can[i][j]));

                for (int k = 0; k < n; ++k)
                {
                    if (k < i)
                        can[i][j][0] |= a[k][j] != '.';
                    if (k > i)
                        can[i][j][2] |= a[k][j] != '.';
                }
                for (int k = 0; k < m; ++k)
                {
                    if (k > j)
                        can[i][j][1] |= a[i][k] != '.';
                    if (k < j)
                        can[i][j][3] |= a[i][k] != '.';
                }

                // check if impossible
                bool fl = true;
                for (int k = 0; k < dirs.size(); ++k)
                    fl &= !can[i][j][k];
                if (fl)
                    impossible = true;

                // check if needs change
                count += !can[i][j][dirs.find(a[i][j])];
            }
        }
        if (impossible)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << count << endl;
    }
    return 0;
}
