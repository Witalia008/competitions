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

int gauss(vector<vector<double>> a, vector<double> &ans)
{
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col)
    {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < eps)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row)
            {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i)
    {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > eps)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return Inf;
    return 1;
}

vector<int> c, d;

#define ONLINE_JUDGE
int main()
{
    std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T, W;
    cin >> T >> W;
    for (int t = 0; t < T; ++t)
    {
        long long R[7] = {};
        long long a[8] = {};
        vector<int> qq = {1, 2, 3, 4, 5, 6};
        for (int i : qq)
        {
            cout << i << endl
                 << flush;
            cin >> a[i];
            if (a[i] == -1)
                return 0;
        }
        /*R[1] = (a[7] - a[6]) / 64;
        R[2] = a[2] - a[1] - 2 * R[1];
        R[3] = a[3] - a[2] - 4 * R[1];
        R[4] = a[4] - a[3] - 8 * R[1] - 2 * R[2];
        R[6] = a[6] - a[4] - 48 * R[1] - 4 * R[2] - 2 * R[3] - R[5];*/
        vector<vector<double>> M = {
            {2, 1, 1, 1, 1, 1, (double)a[1]},
            {4, 2, 1, 1, 1, 1, (double)a[2]},
            {8, 2, 2, 1, 1, 1, (double)a[3]},
            {16, 4, 2, 2, 1, 1, (double)a[4]},
            {32, 4, 2, 2, 2, 1, (double)a[5]},
            {64, 8, 4, 2, 2, 2, (double)a[6]}};
        vector<double> ans;
        gauss(M, ans);
        for (int i = 0; i < 6; ++i)
        {
            cout << ((int)(ans[i] + 0.1));
            if (i < 5)
                cout << " ";
        }
        cout << endl
             << flush;
        int verdict = 0;
        cin >> verdict;
        if (verdict == -1)
            break;
    }
    return 0;
}
