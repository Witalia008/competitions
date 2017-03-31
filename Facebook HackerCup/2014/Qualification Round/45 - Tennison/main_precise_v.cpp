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
#include <gmp.h>

using namespace std;
using namespace std::chrono;

const int M_SZ = 256;
const int MAX_P = 1005;
const int MAX_K = 105;

// F = f(prob of sun * 1000, first score, second score)
mpf_t F[MAX_P][MAX_K][MAX_K];

int norm(double a)
{
    return min(max(int(a * 1000), 0), 1000);
}

void init()
{
    for (int i = 0; i < MAX_P; ++i)
        for (int j = 0; j < MAX_K; ++j)
            for (int k = 0; k < MAX_K; ++k)
            {
                mpf_init2(F[i][j][k], M_SZ);
            }
}

void clear()
{
    for (int i = 0; i < MAX_P; ++i)
        for (int j = 0; j < MAX_K; ++j)
            for (int k = 0; k < MAX_K; ++k)
            {
                mpf_set_d(F[i][j][k], 0);
            }
}

void destroy()
{
    for (int i = 0; i < MAX_P; ++i)
        for (int j = 0; j < MAX_K; ++j)
            for (int k = 0; k < MAX_K; ++k)
            {
                mpf_clear(F[i][j][k]);
            }
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
    mpf_t Ps, Pr, Pw, Pl, __Ps, __Pr, __Pw, __Pl, ans;
    mpf_init2(Ps, M_SZ);
    mpf_init2(Pr, M_SZ);
    mpf_init2(Pw, M_SZ);
    mpf_init2(Pl, M_SZ);
    mpf_init2(__Ps, M_SZ);
    mpf_init2(__Pr, M_SZ);
    mpf_init2(__Pw, M_SZ);
    mpf_init2(__Pl, M_SZ);
    mpf_init2(ans, M_SZ);
    init();
    for (int _t = 0; _t < T; ++_t)
    {
        int K;
        cin >> K;
        // Ps - win in sunny day
        // Pr - win in cloudy day
        // Pi - sun in first day
        // when wins, Pi increases by Pu with prob Pw
        // when loses, Pi decreases by Pd with prob Pl
        double _Ps, _Pr, Pi, Pu, _Pw, Pd, _Pl;
        cin >> _Ps >> _Pr >> Pi >> Pu >> _Pw >> Pd >> _Pl;
        mpf_set_d(Ps, _Ps);
        mpf_set_d(Pr, _Pr);
        mpf_set_d(Pw, _Pw);
        mpf_set_d(Pl, _Pl);
        mpf_set_d(__Ps, 1 - _Ps);
        mpf_set_d(__Pr, 1 - _Pr);
        mpf_set_d(__Pw, 1 - _Pw);
        mpf_set_d(__Pl, 1 - _Pl);
        clear();
        mpf_set_d(F[norm(Pi)][0][0], 1);
        mpf_set_d(ans, 0);
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
                            mpf_add(ans, F[ps][k][l], ans);
                        }
                        else
                        {
                            mpf_t pss;
                            mpf_init2(pss, M_SZ);
                            mpf_set_d(pss, ((double)ps) / (double)1000);
                            //try: first wins
                            //double pw1 = F[ps][k][l] * (pss * (Ps - Pr) + Pr);
                            mpf_t pw1;
                            mpf_init2(pw1, M_SZ);
                            mpf_sub(pw1, Ps, Pr);
                            mpf_mul(pw1, pss, pw1);
                            mpf_add(pw1, pw1, Pr);
                            mpf_mul(pw1, pw1, F[ps][k][l]);

                            mpf_t __pss, one;
                            mpf_init2(__pss, M_SZ);
                            mpf_init2(one, M_SZ);
                            mpf_set_d(one, 1);
                            mpf_sub(__pss, one, pss);

                            //F[ps][k + 1][l] += pw1 * (1 - Pw);
                            mpf_t tmp;
                            mpf_init2(tmp, M_SZ);
                            mpf_mul(tmp, pw1, __Pw);
                            mpf_add(F[ps][k + 1][l], F[ps][k + 1][l], tmp);

                            //F[norm(pss + Pu)][k + 1][l] += pw1 * Pw;
                            mpf_mul(tmp, pw1, Pw);
                            mpf_add(F[norm(mpf_get_d(pss) + Pu)][k + 1][l], F[norm(mpf_get_d(pss) + Pu)][k + 1][l], tmp);

                            //try: first loses
                            //double pl1 = F[ps][k][l] * (pss * (1 - Ps) + (1 - pss) * (1 - Pr));
                            mpf_t pl1;
                            mpf_init2(pl1, M_SZ);
                            mpf_mul(pl1, pss, __Ps);

                            mpf_t tmp1;
                            mpf_init2(tmp1, M_SZ);
                            mpf_mul(tmp1, __pss, __Pr);

                            mpf_add(pl1, pl1, tmp1);
                            mpf_mul(pl1, pl1, F[ps][k][l]);

                            //F[ps][k][l + 1] += pl1 * (1 - Pl);
                            mpf_mul(tmp1, pl1, __Pl);
                            mpf_add(F[ps][k][l + 1], F[ps][k][l + 1], tmp1);

                            //F[norm(pss - Pd)][k][l + 1] += pl1 * Pl;
                            mpf_mul(tmp1, pl1, Pl);
                            mpf_add(F[norm(mpf_get_d(pss) - Pd)][k][l + 1], F[norm(mpf_get_d(pss) - Pd)][k][l + 1], tmp1);

                            mpf_clear(pss);
                            mpf_clear(pw1);
                            mpf_clear(pl1);
                            mpf_clear(tmp);
                            mpf_clear(tmp1);
                            mpf_clear(one);
                        }
                    }
            }
        }
        cout << "Case #" << _t + 1 << ": " << fixed << setprecision(20) << mpf_get_d(ans) << endl;
    }
    destroy();
    mpf_clear(Ps);
    mpf_clear(Pr);
    mpf_clear(Pw);
    mpf_clear(Pl);
    mpf_clear(__Ps);
    mpf_clear(__Pr);
    mpf_clear(__Pw);
    mpf_clear(__Pl);
    mpf_clear(ans);
    return 0;
}
