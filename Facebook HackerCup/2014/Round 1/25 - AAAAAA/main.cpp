#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using namespace std::chrono;

using ll = long long;

vector<string> a;
vector<vector<int>> F, Fr;

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int _t = 0; _t < T; ++_t)
    {
        int n, m;
        cin >> n >> m;
        a.resize(n);
        F.resize(n);
        Fr.resize(n);
        for (int i = 0; i < n; ++i)
        {
            F[i].assign(m, INT_MIN);
            Fr[i].assign(m, INT_MIN);
            cin >> a[i];
            for (int j = 0; j < m; ++j)
                if (a[i][j] == '.')
                {
                    if (i == 0 && j == 0)
                        F[i][j] = 1;
                    if (i)
                        F[i][j] = max(F[i][j], F[i - 1][j] + 1);
                    if (j)
                        F[i][j] = max(F[i][j], F[i][j - 1] + 1);
                }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
                if (a[i][j] == '.')
                {
                    Fr[i][j] = 1;
                    if (i + 1 < n)
                        Fr[i][j] = max(Fr[i][j], Fr[i + 1][j] + 1);
                    if (j + 1 < m)
                        Fr[i][j] = max(Fr[i][j], Fr[i][j + 1] + 1);
                }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                ans = max(ans, F[i][j]);
                if (i + 1 < n && i > 0)
                {
                    for (int k = j; k >= 0; --k)
                    {
                        if (a[i][k] != '.')
                            break;
                        if (Fr[i + 1][k] >= 0 && F[i - 1][j] >= 0)
                            ans = max(ans, F[i - 1][j] + Fr[i + 1][k] + j - k + 1);
                    }
                }
                if (j + 1 < m && j > 0)
                {
                    for (int k = i; k >= 0; --k)
                    {
                        if (a[k][j] != '.')
                            break;
                        if (Fr[k][j + 1] >= 0 && F[i][j - 1] >= 0)
                            ans = max(ans, F[i][j - 1] + Fr[k][j + 1] + i - k + 1);
                    }
                }
            }
        cout << "Case #" << _t + 1 << ": " << ans << endl;
    }
    return 0;
}
