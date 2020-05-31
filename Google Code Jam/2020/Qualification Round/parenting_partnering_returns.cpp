#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool dfs(int v, vector<vector<int>> adj, vector<int> &col, int cur_col = 0)
{
    if (col[v] != -1)
    {
        return col[v] == cur_col;
    }
    col[v] = cur_col;
    for (int to : adj[v])
    {
        if (!dfs(to, adj, col, 1 - cur_col))
        {
            return false;
        }
    }
    return true;
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

        int n;
        cin >> n;

        vector<vector<int>> adj(n);

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].first >> a[i].second;
            for (int j = 0; j < i; ++j)
            {
                if (!(a[i].second <= a[j].first || a[j].second <= a[i].first))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> col(n, -1);
        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            if (col[i] == -1 && !dfs(i, adj, col))
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            for (int i : col)
            {
                cout << (i == 0 ? 'C' : 'J');
            }
            cout << endl;
        }
    }
    return 0;
}
