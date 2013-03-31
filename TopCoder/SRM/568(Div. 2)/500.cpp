#include <stdio.h>
#include <cstdlib>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int dp[100][8];

class BallsSeparating
{
public:
    int minOperations(vector<int> red, vector<int> green, vector<int> blue)
    {
        int n = red.size();
        REP(i, n + 2)
        REP(j, 8)
            dp[i][j] = -1;
        if (n < 3)
            return -1;
        dp[0][0] = 0;
        REP(i, n)
        REP(mask, 8)
        if (dp[i][mask] != -1)
        {
            dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]);
            dp[i + 1][mask | 1] = max(dp[i + 1][mask | 1], dp[i][mask] + red[i]);
            dp[i + 1][mask | 2] = max(dp[i + 1][mask | 2], dp[i][mask] + green[i]);
            dp[i + 1][mask | 4] = max(dp[i + 1][mask | 4], dp[i][mask] + blue[i]);
        }
        int res = 0;
        REP(i, n)
        res += red[i] + blue[i] + green[i];
        return res - dp[n][7];
    }
};
