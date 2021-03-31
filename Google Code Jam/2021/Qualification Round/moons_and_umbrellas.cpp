#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <inttypes.h>
#include <list>

using namespace std;

using ll = long long;

const int Inf = 1000000000;

// #define ONLINE_JUDGE
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

        int X, Y;
        // CJ - X, JC - Y
        string s;
        cin >> X >> Y >> s;
        int n = s.length();

        vector<vector<ll>> dp(n + 1, {Inf, Inf});
        // dp[i] -> 0 = C, 1 = J
        dp[0][0] = dp[0][1] = 0;

        for (int i = 1; i <= n; ++i)
        {
            char cur_char = s[i - 1];
            // If we could have C in current position.
            if (cur_char == 'C' || cur_char == '?')
            {
                // Either before was C + no cost OR was J + cost of JC (Y)
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + Y);
            }
            // If we could have J in current position.
            if (cur_char == 'J' || cur_char == '?')
            {
                // Either before was J + no cost OR was C + cost of CJ (X)
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + X);
            }
        }

        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}
