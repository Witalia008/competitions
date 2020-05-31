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

        int N;
        cin >> N;

        long long k = 0;

        vector<unordered_set<int>> rows(N), cols(N);

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int a;
                cin >> a;
                if (j == i)
                {
                    k += a;
                }
                rows[i].insert(a);
                cols[j].insert(a);
            }
        }
        int r = 0, c = 0;
        for (int i = 0; i < N; ++i)
        {
            r += rows[i].size() != N;
            c += cols[i].size() != N;
        }
        cout << k << " " << r << " " << c << endl;
    }
    return 0;
}
