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

        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &a : arr)
            cin >> a;

        int cost = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            int idx = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] < arr[idx])
                {
                    idx = j;
                }
            }

            cost += idx - i + 1;

            for (int k = i, j = idx; k < j; ++k, --j)
            {
                swap(arr[k], arr[j]);
            }
        }

        cout << cost << endl;
    }
    return 0;
}
