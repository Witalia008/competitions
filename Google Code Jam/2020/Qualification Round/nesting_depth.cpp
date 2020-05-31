#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

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

        string S;
        cin >> S;

        string res = "";

        int balance = 0;
        for (char q : S)
        {
            int n = q - '0';
            while (balance < n)
            {
                balance += 1;
                res += '(';
            }
            while (balance > n)
            {
                balance -= 1;
                res += ')';
            }
            res += q;
        }
        while (balance-- > 0)
        {
            res += ')';
        }
        cout << res << endl;
    }
    return 0;
}
