#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define Inf 1000000000
#define NMAX 10005

int N;
int A[NMAX], B[NMAX];

bool can_divide(int howMuch)
{
    int curS = 0;
    REP(i, N)
    B[i] = A[i];
    REP(i, N)
    {
        B[i] -= curS;
        if (B[i] < 0)
            return false;
        if (B[i] >= howMuch)
            B[i] -= howMuch;
        else
        {
            curS += howMuch - B[i];
            howMuch = B[i];
        }
    }
    return true;
}

int bin_search(int l, int r)
{
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (can_divide(mid))
            l = mid;
        else
            r = mid;
    }
    if (can_divide(r))
        return r;
    return l;
}

int main()
{
    freopen("factory.dat", "r", stdin);
    freopen("factory.sol", "w", stdout);
    scanf("%d", &N);
    REP(i, N)
    scanf("%d", &A[i]);
    printf("%d\n", bin_search(1, Inf));
    return 0;
}
