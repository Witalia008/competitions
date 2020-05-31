#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<bool> convert_bin(int a)
{
    vector<bool> res;
    while (a)
    {
        res.push_back(a % 2 == 1);
        a >>= 1;
    }
    return res;
}

void advance_next_row(int &x, int &y)
{
    cout << x << " " << y << endl;
    x += 1;
    if (y != 1)
        y += 1;
}

void advance_next_col(int &x, int &y, int y_delta)
{
    cout << x << " " << y << endl;
    y += y_delta;
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
        cout << "Case #" << (t + 1) << ":\n";

        int n;
        cin >> n;
        for (int k = 0; k < 500 && k < n; ++k)
        {
            int m = n - k;
            vector<bool> bin_nums = convert_bin(m);
            int skips = 0;
            for (bool bit : bin_nums)
            {
                skips += !bit;
            }
            if (skips > k)
            {
                continue;
            }
            // Found a solution.
            int x = 1, y = 1;

            int acc_num = 0;
            for (int i = 0; i < bin_nums.size(); ++i)
            {
                if (bin_nums[i])
                {
                    // Need to grab entire row.
                    // If at beginning, move right, else move left.
                    int y_del = (y == 1 ? 1 : -1);
                    // Move i times sideways and 1 time down.
                    for (int j = 0; j < i; ++j)
                    {
                        advance_next_col(x, y, y_del);
                    }
                    advance_next_row(x, y);
                    // One row gives 2^i to the sum.
                    acc_num += (1 << i);
                }
                else
                {
                    // Skipping row means adding 1.
                    advance_next_row(x, y);
                    acc_num += 1;
                }
            }
            // Move down until reach n.
            while (acc_num != n)
            {
                advance_next_row(x, y);
                acc_num += 1;
            }
            break;
        }
    }
    return 0;
}
