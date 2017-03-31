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

struct
{
    int left, right;
} nodes[N];

vector<int> preorder, postorder, pos_preorder;
vector<int> labels;

void traverse(int v, bool pre)
{
    if (v == -1)
        return;
    if (pre)
        preorder.push_back(v);
    traverse(nodes[v].left, pre);
    traverse(nodes[v].right, pre);
    if (!pre)
        postorder.push_back(v);
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
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            cin >> nodes[i].left >> nodes[i].right;
            --nodes[i].left;
            --nodes[i].right;
        }
        preorder.clear();
        postorder.clear();
        traverse(0, true);
        pos_preorder.assign(n, -1);
        for (int i = 0; i < n; ++i)
        {
            pos_preorder[preorder[i]] = i;
        }
        traverse(0, false);
        labels.assign(n, -1);
        int curlabel = 0;
        for (int i = 0; i < n; ++i)
        {
            if (labels[i] == -1)
            {
                ++curlabel;
                int j = i;
                do
                {
                    labels[j] = curlabel;
                    j = postorder[pos_preorder[j]];
                } while (j != i);
            }
        }
        if (curlabel < k)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                cout << min(labels[i], k) << (i == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
