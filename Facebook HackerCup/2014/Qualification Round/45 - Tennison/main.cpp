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

const int MAX_P = 1005;
const int MAX_K = 105;

// F = f(prob of sun * 1000, first score, second score)
double F[MAX_P][MAX_K][MAX_K];

int norm(double a)
{
    return min(max(int(a * 1000), 0), 1000);
}

void clear()
{
    for (int i = 0; i < MAX_P; ++i)
        for (int j = 0; j < MAX_K; ++j)
            for (int k = 0; k < MAX_K; ++k)
                F[i][j][k] = 0;
}

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
        int K;
        cin >> K;
        // Ps - win in sunny day
        // Pr - win in cloudy day
        // Pi - sun in first day
        // when wins, Pi increases by Pu with prob Pw
        // when loses, Pi decreases by Pd with prob Pl
        double Ps, Pr, Pi, Pu, Pw, Pd, Pl;
        cin >> Ps >> Pr >> Pi >> Pu >> Pw >> Pd >> Pl;
        clear();
        F[norm(Pi)][0][0] = 1;
        double ans = 0;
        for (int n = 0; n < K * 2; ++n)
        {
            for (int k = 0; k <= K && k <= n; ++k)
            {
                int l = n - k;
                for (int ps = 0; ps <= 1000; ++ps)
                    if (F[ps][k][l] > 0)
                    {
                        if (k == K)
                        {
                            ans += F[ps][k][l];
                        }
                        else
                        {
                            double pss = ((double)ps) / (double)1000;
                            //try: first wins
                            double pw1 = F[ps][k][l] * (pss * (Ps - Pr) + Pr);
                            F[ps][k + 1][l] += pw1 * (1 - Pw);
                            F[norm(pss + Pu)][k + 1][l] += pw1 * Pw;
                            //try: first loses
                            double pl1 = F[ps][k][l] * (pss * (1 - Ps) + (1 - pss) * (1 - Pr));
                            F[ps][k][l + 1] += pl1 * (1 - Pl);
                            F[norm(pss - Pd)][k][l + 1] += pl1 * Pl;
                        }
                    }
            }
        }
        cout << "Case #" << _t + 1 << ": " << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
