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
const int N = 2005;
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

int find_coord(vector<pair<int, int>> &c_arr, int q)
{
    sort(c_arr.begin(), c_arr.end());
    int cnt_right = 0;
    for (auto const &i : c_arr)
    {
        cnt_right += i.second == -1;
    }
    int cnt_left = 0;
    int coord_res = 0, cnt_res = 0;
    for (int i = 0, lower = 0, upper = 0; i <= q; ++i)
    {
        while (upper < c_arr.size() && c_arr[upper].first <= i)
        {
            cnt_right -= c_arr[upper++].second == -1;
        }
        while (lower < c_arr.size() && c_arr[lower].first < i)
        {
            cnt_left += c_arr[lower++].second == 1;
        }
        if (cnt_left + cnt_right > cnt_res)
        {
            cnt_res = cnt_left + cnt_right;
            coord_res = i;
        }
    }
    return coord_res;
}

struct Person
{
    int x, y;
    string dir;
};

vector<Person> a;
vector<pair<int, int>> x_arr, y_arr;

#define ONLINE_JUDGE
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
        int n, q;
        cin >> n >> q;
        a.resize(n);
        x_arr.clear();
        y_arr.clear();
        for (auto &i : a)
        {
            cin >> i.x >> i.y >> i.dir;
            if (i.dir == "W" || i.dir == "E")
            {
                x_arr.push_back(make_pair(i.x, i.dir == "E" ? 1 : -1));
            }
            else
            {
                y_arr.push_back(make_pair(i.y, i.dir == "N" ? 1 : -1));
            }
        }
        cout << find_coord(x_arr, q) << " " << find_coord(y_arr, q) << endl;
    }
    return 0;
}
