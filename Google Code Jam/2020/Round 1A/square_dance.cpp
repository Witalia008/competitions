#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void move_grid(vector<vector<int>> &S, int x, int y, int dx, int dy, int &sum, int &cnt)
{
    while (x >= 0 && y >= 0 && x < S.size() && y < S[0].size())
    {
        if (abs(S[x][y]) != 0)
        {
            sum += abs(S[x][y]);
            cnt += 1;
            return;
        }
        x += dx;
        y += dy;
    }
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
        vector<vector<int>> S(n);
        for (int i = 0; i < n; ++i)
        {
            S[i].resize(m);
            for (int j = 0; j < m; ++j)
            {
                cin >> S[i][j];
            }
        }
        long long ans = 0;
        for (int round = 0; round <= n * m; ++round)
        {
            long long cur = 0;
            bool eliminated = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (S[i][j] == 0)
                    {
                        continue;
                    }

                    cur += S[i][j];

                    int sum_around = 0, cnt_around = 0;
                    move_grid(S, i - 1, j, -1, 0, sum_around, cnt_around);
                    move_grid(S, i + 1, j, 1, 0, sum_around, cnt_around);
                    move_grid(S, i, j - 1, 0, -1, sum_around, cnt_around);
                    move_grid(S, i, j + 1, 0, 1, sum_around, cnt_around);

                    if (1LL * S[i][j] * cnt_around < sum_around)
                    {
                        eliminated = true;
                        S[i][j] = -S[i][j];
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (S[i][j] < 0)
                    {
                        S[i][j] = 0;
                    }
                }
            }
            ans += cur;
            if (!eliminated)
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
