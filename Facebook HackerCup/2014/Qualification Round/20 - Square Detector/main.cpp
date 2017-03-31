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
        int n;
        cin >> n;
        vector<string> a(n);
        int sum_all = 0;
        int min_x = n, max_x = -1, min_y = n, max_y = -1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == '#')
                {
                    ++sum_all;
                    min_x = min(min_x, i);
                    min_y = min(min_y, j);
                    max_x = max(max_x, i);
                    max_y = max(max_y, j);
                }
            }
        }
        cout << "Case #" << _t + 1 << ": ";
        if (max_x - min_x != max_y - min_y || (max_x - min_x + 1) * (max_y - min_y + 1) != sum_all)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
