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
    const int N = 500000;
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

vector<vector<int>> children;
vector<unordered_set<int>> topics;
vector<unordered_map<int, int>> possible_learnings_paths;
vector<unordered_map<int, int>> cnt_topic_in_children;
unordered_map<int, int> cnt_available_in_anc;
unordered_map<string, int> topic_mapping;

// dfs returns number of leaves
int dfs(int v)
{
    if (children[v].size() == 0)
    {
        // This is a leaf
        for (auto s : topics[v])
        {
            possible_learnings_paths[v][s] = 1;
        }
        return 1;
    }
    for (auto s : topics[v])
    {
        ++cnt_available_in_anc[s];
    }
    int cnt_leaves = 0;
    // Calc for children and count total leaves (paths).
    for (int to : children[v])
    {
        cnt_leaves += dfs(to);
        for (auto learnings_to : possible_learnings_paths[to])
        {
            possible_learnings_paths[v][learnings_to.first] += learnings_to.second;
        }
        for (auto s : topics[to])
        {
            cnt_topic_in_children[v][s]++;
        }
        // Consumed - no longer needed.
        possible_learnings_paths[to].clear();
        topics[to].clear();
    }
    // Can salvage up to one path if not all children have the topic.
    for (auto s : topics[v])
    {
        if (cnt_topic_in_children[v][s] != children[v].size())
        {
            possible_learnings_paths[v][s] = min(possible_learnings_paths[v][s] + 1, cnt_leaves);
        }
    }
    // Remove those that cannot be learnt.
    for (auto it = possible_learnings_paths[v].begin(); it != possible_learnings_paths[v].end();)
    {
        // Max 1 path can be missing the topic if it's also available in any ancestor.
        if (it->second < cnt_leaves - (cnt_available_in_anc[it->first] > 0))
        {
            possible_learnings_paths[v].erase(it++);
        }
        else
        {
            ++it;
        }
    }
    for (auto s : topics[v])
    {
        --cnt_available_in_anc[s];
    }
    // No longer needed.
    return cnt_leaves;
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

        children.resize(n);
        for (int i = 1; i < n; ++i)
        {
            int p;
            cin >> p;
            children[p - 1].push_back(i);
        }

        topics.resize(n);
        topic_mapping.clear();
        for (int i = 0; i < n; ++i)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j)
            {
                string s;
                cin >> s;
                if (topic_mapping.find(s) == topic_mapping.end())
                {
                    topic_mapping[s] = topic_mapping.size() + 1;
                }
                topics[i].insert(topic_mapping[s]);
            }
        }

        possible_learnings_paths.resize(n);
        cnt_topic_in_children.resize(n);
        int total_leaves = dfs(0);

        int ans = 0;

        for (auto it : possible_learnings_paths[0])
        {
            if (it.second == total_leaves)
            {
                ++ans;
            }
        }
        cout << ans << endl;

        children.clear();
        topics.clear();
        possible_learnings_paths.clear();
        cnt_topic_in_children.clear();
        cnt_available_in_anc.clear();
    }
    return 0;
}
