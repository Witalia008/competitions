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

const int N = 1005;
const int K = 105;
const int Inf = 1000000000;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

//int mx[] = { 1, 1, 2,2, -1, -1, -2, -2 };
//int my[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

vector<int> a;

int bin_srch(vector<int> &b, int val)
{
    int l = 0, r = b.size() - 1;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (b[mid] >= val)
            r = mid;
        else
            l = mid;
    }
    if (b[l] == val)
        return l;
    return r;
}

void remap()
{
    vector<int> b = a;
    sort(b.begin(), b.end());

    for (int &i : a)
        i = bin_srch(b, i);
}

vector<int> T;

void init(int n)
{
    T.assign(n, 0);
}

void add(int i, int val)
{
    for (; i < T.size(); i = (i | (i + 1)))
        T[i] += val;
}

int get(int r)
{
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += T[r];
    return res;
}

int count(vector<int> &b)
{
    init(N);
    int res = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        res += i - get(b[i]);
        add(b[i], 1);
    }
    return res;
}

int ans;
vector<int> p;

void search(int pos)
{
    if (pos == a.size())
    {
        vector<int> b, c;

        int cc = 0;
        int cur = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (p[i] == 0)
            {
                b.push_back(a[i]);
                cur += cc;
            }
            else
            {
                c.push_back(a[i]);
                ++cc;
            }
        }
        reverse(c.begin(), c.end());

        cur += count(b) + count(c);

        ans = min(ans, cur);

        return;
    }
    for (p[pos] = 0; p[pos] < 2; ++p[pos])
        search(pos + 1);
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << t + 1 << ": ";

        int n;
        cin >> n;
        a.resize(n);
        for (int &i : a)
            cin >> i;

        remap();

        p.resize(n);
        ans = Inf;
        search(0);
        cout << ans << endl;
    }
    return 0;
}
