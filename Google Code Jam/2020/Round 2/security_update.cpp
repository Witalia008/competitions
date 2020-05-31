#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int Inf = 1000000000;

int bin_search(vector<int> const &latency, int how_many, int min_val)
{
    auto count = [&](int lat) {
        return count_if(latency.begin(), latency.end(), [=](int lat_ex) { return lat_ex < lat; });
    };

    int left = min_val, right = Inf;
    while (left < right - 1)
    {
        int mid = (left + right) >> 1;
        if (count(mid) >= how_many)
            right = mid;
        else
            left = mid;
    }

    return count(left) == how_many ? left : right;
}

#define ONLINE_JUDGE
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
        cout << "Case #" << (t + 1) << ": ";

        int n, m;
        cin >> n >> m;

        vector<int> latency(n, Inf);
        latency[0] = 0;

        // how many before, and node id
        vector<pair<int, int>> need_processing;

        for (int i = 1; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                latency[i] = x;
            }
            else
            {
                need_processing.push_back(make_pair(-x, i));
            }
        }

        vector<pair<int, int>> edges;
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            edges.push_back(make_pair(u, v));
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Process from lowest "this many before".
        sort(need_processing.begin(), need_processing.end());

        for (auto toproc : need_processing)
        {
            int x = toproc.first;
            int v = toproc.second;

            int min_val = Inf;
            for (auto to : adj[v])
            {
                min_val = min(min_val, latency[to]);
            }

            latency[v] = bin_search(latency, x, min_val + 1);
        }

        for (int i = 0; i < m; ++i)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            cout << max(1, abs(latency[u] - latency[v])) << (i == m - 1 ? "\n" : " ");
        }
    }
    return 0;
}
