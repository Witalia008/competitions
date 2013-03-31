#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <memory.h>

#define Mi 1000000009

using namespace std;

int F[2][101][200];
vector<int> pr;

bool prime(int a)
{
    for (int i = 2; i < a; ++i)
        if (a % i == 0)
            return false;
    return true;
}

void sett(int _i, int _j, int n)
{
    for (int i = 0; i < pr.size() && pr[i] <= n; ++i)
    {
        while (n % pr[i] == 0)
        {
            F[_i & 1][_j][i]++;
            n /= pr[i];
        }
    }
}
class MegaFactorialDiv2
{
public:
    int countDivisors(int n, int k)
    {
        pr.clear();
        for (int i = 2; i <= n; i++)
            if (prime(i))
                pr.push_back(i);
        memset(F, 0, sizeof(F));
        for (int _n = 1; _n <= n; _n++)
        {
            memset(F[(_n & 1)], 0, sizeof(F[(_n & 1)]));
            sett(_n, 0, _n);
            for (int _k = 1; _k <= k; _k++)
                for (int pos = 0; pos < pr.size(); pos++)
                    F[_n & 1][_k][pos] = F[1 - (_n & 1)][_k][pos] + F[_n & 1][_k - 1][pos];
        }
        long long res = 1;
        for (int pos = 0; pos < pr.size(); pos++)
        {
            res = res * (F[n & 1][k][pos] + 1);
            res %= Mi;
        }
        return int(res);
    }
};
