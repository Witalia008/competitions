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

struct Trie
{
    struct Node
    {
        int nxt[26];
    };
    int v;
    int nds[1000][26];
};

void add(Trie &a, string s)
{
    int cv = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int x = s[i] - 'A';
        if (a.nds[cv][x] == -1)
        {
            a.nds[cv][x] = a.v++;
        }
        cv = a.nds[cv][x];
    }
}

vector<string> a;
vector<Trie> b;
vector<int> pp;
int ans, cnt;

void search(int pos, int m)
{
    if (pos == a.size())
    {
        vector<int> cp(m, 0);
        for (int i = 0; i < a.size(); ++i)
            ++cp[pp[i]];
        for (int i = 0; i < m; ++i)
        {
            if (cp[i] == 0)
                return;
        }

        for (int i = 0; i < m; ++i)
        {
            b[i].v = 1;
            memset(b[i].nds, -1, sizeof(b[i].nds));
        }
        for (int i = 0; i < a.size(); ++i)
            add(b[pp[i]], a[i]);

        int cur = 0;
        for (int i = 0; i < m; ++i)
            cur += b[i].v;

        if (cur >= ans)
        {
            if (cur > ans)
                cnt = 1;
            if (cur == ans)
                ++cnt;
            ans = cur;
        }

        return;
    }
    for (pp[pos] = 0; pp[pos] < m; ++pp[pos])
        search(pos + 1, m);
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

        int n, m;
        cin >> n >> m;
        a.resize(n);
        for (auto &i : a)
            cin >> i;
        b.resize(m);

        ans = 0;
        pp.resize(n);
        search(0, m);

        cout << ans << " " << cnt << endl;
    }
    return 0;
}
