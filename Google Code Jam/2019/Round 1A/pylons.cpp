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
#include <random>
#include <valarray>
using namespace std::chrono;
using namespace std;

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int mx[4] = {1, 0, -1, 0};
const int my[4] = {0, 1, 0, -1};

const int Inf = 1000000000;
const int Mi = 1000000007;
const int N = 1005;
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

vector<pair<int, int>> small_ans{};
bool visited[10][10];

bool get_small_ans_rec(int i, int j, int r, int c)
{
    visited[i][j] = true;
    small_ans.push_back(make_pair(i, j));
    if (small_ans.size() == r * c)
    {
        return true;
    }
    for (int x = 0; x < r; ++x)
    {
        for (int y = 0; y < c; ++y)
        {
            if (x == i || y == j || i - j == x - y || i + j == x + y || visited[x][y])
            {
                continue;
            }
            if (get_small_ans_rec(x, y, r, c))
            {
                return true;
            }
        }
    }
    visited[i][j] = false;
    small_ans.pop_back();
    return false;
}

bool get_small_ans(int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            memset(visited, 0, sizeof(visited));
            small_ans.clear();
            if (get_small_ans_rec(i, j, r, c))
            {
                return true;
            }
        }
    }
    small_ans.clear();
    return false;
}

void add_3_pattern(int col_offset, int r, vector<pair<int, int>> &res)
{
    for (int i = 0; i < r; ++i)
    {
        res.push_back(make_pair(i, col_offset));
        res.push_back(make_pair((i + 2) % r, col_offset + 1));
        res.push_back(make_pair(i, col_offset + 2));
    }
}

void add_2_pattern(int col_offset, int r, vector<pair<int, int>> &res)
{
    vector<pair<int, int>> start_points;
    int steps_made = 1 + (r - 1) / 2;
    if (steps_made % 2 == 1) // will stop at same side
    {
        if (r % 2 == 0) // will have extra row (like r = 6)
        {
            start_points = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        }
        else // like r = 9
        {
            start_points = {{0, 0}, {1, 1}, {0, 1}, {1, 0}};
        }
    }
    else
    {
        if (r % 2 == 1)
        {
            start_points = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        }
        else
        {
            for (int start_row = 0; start_row < 4; ++start_row)
            {
                for (int i = start_row, cnt = 0, j = 0; cnt < steps_made; ++cnt, j = 1 - j, i = (i + 2) % r)
                {
                    res.push_back(make_pair(i, j + col_offset));
                }
            }
            return;
        }
    }
    for (auto p : start_points)
    {
        for (int i = p.first, j = p.second; i < r; i += 2, j = 1 - j)
        {
            res.push_back(make_pair(i, j + col_offset));
        }
    }
}

auto get_pattern(int r, int c)
{
    vector<pair<int, int>> res{};
    for (int col = 0; c > 0;)
    {
        if (c == 3)
        {
            add_3_pattern(col, r, res);
            break;
        }
        else
        {
            add_2_pattern(col, r, res);
            c -= 2;
            col += 2;
        }
    }
    return res;
}

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
        int r, c;
        cin >> r >> c;
        if (r <= 5 && c <= 5)
        {
            bool has_ans = get_small_ans(r, c);
            cout << (has_ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
            for (auto const &p : small_ans)
            {
                cout << (p.first + 1) << " " << (p.second + 1) << endl;
            }
        }
        else
        {
            bool swapped = false;
            if (r < c)
            {
                swapped = true;
                swap(r, c);
            }
            if (c == 1)
            {
                cout << "IMPOSSIBLE" << endl;
                continue;
            }
            auto res = get_pattern(r, c);
            if (swapped)
            {
                for (auto &p : res)
                {
                    swap(p.first, p.second);
                }
            }
            cout << "POSSIBLE" << endl;
            for (auto const &p : res)
            {
                cout << (p.first + 1) << " " << (p.second + 1) << endl;
            }
        }
    }
    return 0;
}
