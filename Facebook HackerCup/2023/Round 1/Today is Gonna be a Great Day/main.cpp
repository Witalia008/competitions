#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <stdio.h>
#include <time.h>
#include <vector>

#include <atomic>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <random>
#include <regex>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <valarray>

using namespace std;
using namespace std::chrono;

namespace tp
{
    using ld = double;
    using ll = long long;
    using ull = unsigned long long;
    using pii = pair<int, int>;
    using pll = pair<ll, ll>;
    using vi = vector<int>;
    using vvi = vector<vi>;
} // namespace tp

namespace c
{
    using namespace tp;

    const int mx[4] = {1, 0, -1, 0};
    const int my[4] = {0, 1, 0, -1};

    const int Inf = 1000000000;
    const ll InfLL = ll(Inf) * ll(Inf);
    const int Mi = 1000000007;
    const int N = 1000010;
    const int M = 100005;
    const ld eps = 1e-7;
} // namespace c

namespace rnd
{
    using namespace tp;
    using namespace c;

    inline unsigned rand16()
    {
        return std::rand() % (1 << 16);
    }

    inline unsigned rand32()
    {
        return (rand16() << 16) + rand16();
    }

    inline ull rand64()
    {
        return (((ull)rand32()) << 32) + rand32();
    }

    inline int rand(int L, int R)
    {
        return L > R ? R : rand32() % (R - L + 1) + L;
    }

    inline ld random(ld L, ld R)
    {
        return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0;
    }
} // namespace rnd

namespace u
{
    using namespace tp;

    inline ll Abs(ll a)
    {
        return a < 0 ? -a : a;
    }

    inline ll sqr(ll a)
    {
        return a * a;
    }

    ll gcd(ll a, ll b)
    {
        return !b ? a : gcd(b, a % b);
    }
} // namespace u

struct Node
{
    int max_val;
    int max_idx;
    int min_val;
    int min_idx;
    bool flipped;
};

void update_node(vector<Node> &tree, int v)
{
    tree[v] = tree[v * 2];
    tree[v].flipped = false;

    if (tree[v * 2 + 1].max_val > tree[v].max_val)
    {
        tree[v].max_val = tree[v * 2 + 1].max_val;
        tree[v].max_idx = tree[v * 2 + 1].max_idx;
    }
    if (tree[v * 2 + 1].min_val < tree[v].min_val)
    {
        tree[v].min_val = tree[v * 2 + 1].min_val;
        tree[v].min_idx = tree[v * 2 + 1].min_idx;
    }
}

void build_tree(vector<Node> &tree, int v, int l, int r, tp::vi const &a)
{
    if (l == r)
    {
        tree[v].max_val = tree[v].min_val = a[l - 1];
        tree[v].max_idx = tree[v].min_idx = l;
        tree[v].flipped = false;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(tree, v * 2, l, mid, a);
    build_tree(tree, v * 2 + 1, mid + 1, r, a);
    update_node(tree, v);
}

void flip_node(vector<Node> &tree, int v)
{
    swap(tree[v].max_idx, tree[v].min_idx);
    swap(tree[v].max_val, tree[v].min_val);
    tree[v].max_val = c::Mi - tree[v].max_val;
    tree[v].min_val = c::Mi - tree[v].min_val;
    tree[v].flipped = !tree[v].flipped;
}

void update(vector<Node> &tree, int v, int l, int r, int ul, int ur)
{
    if (l == ul && r == ur)
    {
        flip_node(tree, v);
        return;
    }
    if (tree[v].flipped)
    {
        flip_node(tree, v * 2);
        flip_node(tree, v * 2 + 1);
        tree[v].flipped = false;
    }
    int mid = (l + r) >> 1;
    if (ur <= mid)
    {
        update(tree, v * 2, l, mid, ul, ur);
    }
    else if (ul > mid)
    {
        update(tree, v * 2 + 1, mid + 1, r, ul, ur);
    }
    else
    {
        update(tree, v * 2, l, mid, ul, mid);
        update(tree, v * 2 + 1, mid + 1, r, mid + 1, ur);
    }
    update_node(tree, v);
}

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef LOCAL_RUN
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

        tp::vi a(n, 0);
        for (int &i : a)
        {
            cin >> i;
        }

        vector<Node> tree(n * 3);

        build_tree(tree, 1, 1, n, a);

        long long ans = 0;

        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            int l, r;
            cin >> l >> r;
            update(tree, 1, 1, n, l, r);

            ans += tree[1].max_idx;
        }

        cout << ans << endl;
    }
    return 0;
}
