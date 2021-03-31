#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <inttypes.h>
#include <list>
#include <cassert>

using namespace std;

using ll = long long;

const int Inf = 1000000000;

int get_reversort_cost(vector<int> arr)
{
    int n = arr.size();
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

    return cost;
}

vector<int> get_reversort_arr(int cur_num, int length, int cost)
{
    if (length == 1)
    {
        // cost must be zero by this point.
        return {cur_num};
    }

    vector<int> cur_arr(length, -1);

    // n - 1 is max for n elements, minus 1 for current.
    int cost_need_to_leave = length - 2;            // how much need to leave for other numbers.
    int cost_available = cost - cost_need_to_leave; // how much available for the current number.
    // we cannot have more than available, and more that possible to achieve in array of this length.
    int max_possible_cost_cur = min(cost_available, length);

    // place the cur element to achieve its maximum possible cost.
    int current_loc = max_possible_cost_cur - 1; // Current placed at location to achieve max_possible_cost_cur during reversort.
    cur_arr[current_loc] = cur_num;

    auto subarr = get_reversort_arr(cur_num + 1, length - 1, cost - max_possible_cost_cur);
    // Reverse the first portion of subarray that will be reversed during reversort (i.e. between beginning and cur el.).
    // Since during the normal pass of reversort cur el will be put on first position, and everything in between - reversed.
    reverse(subarr.begin(), subarr.begin() + current_loc);
    // Please the subarray into unoccupied positions.
    for (int idx_cur = 0, idx_sub = 0; idx_cur < length; ++idx_cur)
    {
        if (cur_arr[idx_cur] == -1)
        {
            cur_arr[idx_cur] = subarr[idx_sub++];
        }
    }

    return cur_arr;
}

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

        int n, cost;
        cin >> n >> cost;

        if (cost < n - 1 || cost >= n * (n + 1) / 2)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> arr = get_reversort_arr(1 /* cur_num */, n /* length */, cost);

        assert(get_reversort_cost(arr) == cost);

        for (int i = 0; i < n; ++i)
        {
            cout << (i ? " " : "") << arr[i];
        }
        cout << endl;
    }

    // Test on all possible cases.
    // for (int n = 1; n <= 100; ++n)
    // {
    //     for (int cost = 1; cost <= 1000; ++cost)
    //     {
    //         if (cost < n - 1 || cost >= n * (n + 1) / 2)
    //         {
    //             continue;
    //         }
    //         vector<int> arr = get_reversort_arr(1 /* cur_num */, n /* length */, cost);
    //         assert(get_reversort_cost(arr) == cost);
    //     }
    // }
    return 0;
}
