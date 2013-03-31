#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <limits.h>
#include <algorithm>
#include <iterator>

using namespace std;

void find_max_rect(const vector<vector<int>> &a)
{
    if (a.size() == 1)
        return;
    vector<int> b, num;
    int ans = INT_MIN;
    pair<int, int> l_up, r_down;
    for (int j = 1; j < a[0].size(); ++j)
    {
        b.assign(j, INT_MIN);
        num.assign(j, 0);
        for (int i = 0; i < a.size(); ++i)
        {
            for (int k = 0; k < j; ++k)
            {
                if (b[k] + a[i][k] + a[i][j] > ans)
                {
                    ans = b[k] + a[i][k] + a[i][j];
                    l_up = make_pair(num[k], k);
                    r_down = make_pair(i, j);
                }
                if (a[i][k] + a[i][j] > b[k])
                {
                    b[k] = a[i][k] + a[i][j];
                    num[k] = i;
                }
            }
        }
    }
    cout << ans << endl;
    if (ans != INT_MIN)
    {
        cout << l_up.first << " " << l_up.second << endl;
        cout << r_down.first << " " << r_down.second << endl;
    }
}

vector<vector<int>> a;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a)
    {
        for (int j = 0; j < m; ++j)
        {
            int b;
            cin >> b;
            i.push_back(b);
        }
    }
    find_max_rect(a);
    return 0;
}
