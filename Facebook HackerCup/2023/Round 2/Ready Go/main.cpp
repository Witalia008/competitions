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

int dfs(
    int i, int j,
    vector<string> const &field,
    vector<vector<bool>> &visited,
    vector<pair<int, int>> &adj_empty)
{
    if (i < 0 || j < 0 || i >= field.size() || j >= field[0].size())
    {
        return 0;
    }
    if (visited[i][j])
    {
        return 0;
    }
    visited[i][j] = true;
    if (field[i][j] != 'W')
    {
        if (field[i][j] == '.')
        {
            adj_empty.push_back({i, j});
        }
        return 0;
    }
    int res = 1;
    for (int k = 0; k < 4; ++k)
    {
        int ni = i + c::mx[k];
        int nj = j + c::my[k];
        res += dfs(ni, nj, field, visited, adj_empty);
    }
    return res;
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

        int n, m;
        cin >> n >> m;
        vector<string> field(n);
        for (auto &s : field)
        {
            cin >> s;
        }

        vector<vector<bool>> visited(n, vector<bool>(m));
        vector<vector<int>> cnt_capture(n, vector<int>(m, 0));

        int max_capture = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (field[i][j] == 'W' && !visited[i][j])
                {
                    vector<pair<int, int>> adj_empty;
                    int group_size = dfs(i, j, field, visited, adj_empty);
                    if (adj_empty.size() == 1)
                    {
                        auto [x, y] = adj_empty[0];
                        cnt_capture[x][y] += group_size;
                        max_capture = max(max_capture, cnt_capture[x][y]);
                    }
                    for (auto empty_cell : adj_empty)
                    {
                        visited[empty_cell.first][empty_cell.second] = false;
                    }
                }
            }
        }

        // Part 1
        // cout << (max_capture ? "YES" : "NO") << endl;
        // Part 2
        cout << max_capture << endl;
    }
    return 0;
}
