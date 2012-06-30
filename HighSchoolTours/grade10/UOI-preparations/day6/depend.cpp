#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <memory.h>

using namespace std;

#define nmax 63500
#define maxc 4000000000
#define LL long long

LL sqr(LL a)
{
    return a * a;
}

int I, K;
bool P[nmax + 1];
int A[nmax + 1];

LL power(LL a, int b)
{
    LL res = 1;
    for (int i = 1; i <= b; i++)
        res *= a;
    return res;
}

bool Good(LL a, int n, int k)
{
    int max = 1;
    int i = 2;
    while (i <= n && a > 0)
    {
        if (a % i == 0)
        {
            int curr = 0;
            while (a % i == 0)
            {
                curr++;
                a /= i;
            }
            if (curr > max)
                max = curr;
        }
        i++;
    }
    return (max >= k);
}

int main()
{
    freopen("depend.dat", "r", stdin);
    freopen("depend.sol", "w", stdout);
    scanf("%d%d", &K, &I);
    memset(P, 1, sizeof(P));
    int n = (int)(exp(log((long double)maxc) / K) + 0.5);
    P[1] = false;
    for (int i = 2; i <= n; i++)
        if (P[i])
        {
            int j = i + i;
            while (j <= n)
            {
                P[j] = false;
                j += i;
            }
        }

    LL l = 1;
    LL r = maxc;
    while (r - l > 1)
    {
        LL mid = (l + r) >> 1;
        for (int i = 1; i <= n; i++)
            A[i] = -1;
        A[1] = 0;
        int num = 0;
        LL curr = 0;
        for (int i = 2; i <= n; i++)
        {
            if (P[i])
            {
                A[i] = 1;
                int j = 2 * i;
                while (j <= n)
                {
                    if (j % sqr(i) == 0)
                        A[j] = 0;
                    else
                        A[j] = -A[j];
                    j += i;
                }
            }
            if (A[i] != 0)
            {
                curr = power(i, K);
                num += (mid / curr) * A[i];
            }
        }
        if (num < I)
            l = mid;
        else if (num > I)
            r = mid;
        else if (Good(mid, n, K))
            l = mid;
        else
            r = mid;
    }
    printf("%lld\n", l);
    return 0;
}
