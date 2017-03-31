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
const int N = 3005;
const int K = 25;
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

int english[N], french[N];
unordered_map<string, int> mp;
string s;
vector<int> stcs[K];

void add(int arr[N], vector<int> &stc)
{
    for (int &i : stc)
        ++arr[i];
}

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
        getline(cin, s);
        int count_words = 0;
        mp.clear();
        for (int i = 0; i < n; ++i)
        {
            getline(cin, s);
            stcs[i].clear();
            stringstream ss(s);
            for (;;)
            {
                string x = "";
                ss >> x;
                if (x == "")
                    break;
                if (!mp[x])
                    mp[x] = ++count_words;
                stcs[i].push_back(mp[x]);
            }
        }

        int ans = Inf;
        for (int step = 0; step < (1 << (n - 2)); ++step)
        {
            memset(english, 0, sizeof(english));
            memset(french, 0, sizeof(french));
            add(english, stcs[0]);
            add(french, stcs[1]);

            for (int i = 2; i < n; ++i)
            {
                if ((step >> (i - 2)) & 1)
                    add(english, stcs[i]);
                else
                    add(french, stcs[i]);
            }
            int cur = 0;
            for (int i = 0; i < N; ++i)
                cur += english[i] > 0 && french[i] > 0;
            ans = min(ans, cur);
        }
        cout << ans << endl;
        cerr << t << endl;
    }
    return 0;
}
