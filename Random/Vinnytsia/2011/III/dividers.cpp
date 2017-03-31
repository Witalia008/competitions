#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long LL;

#define pmax 16
#define smax 64

int primes[pmax] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
LL steps[pmax][smax];

LL N;
int ans = 1;

void CntSteps()
{
    for (int i = 0; i < pmax; i++)
        steps[i][0] = 1;
    for (int j = 1; j < smax; j++)
        for (int i = 0; i < pmax; i++)
            steps[i][j] = steps[i][j - 1] * primes[i];
}

void Search(int last, LL cou, LL cur, int pos)
{
    if (pos == pmax)
    {
        if (cou > ans)
            ans = cou;
        return;
    }
    for (int i = 0; i <= last && cur <= N / steps[pos][i]; i++)
        Search(i, cou * (i + 1), cur * steps[pos][i], pos + 1);
}

int main()
{
    CntSteps();

    cin >> N;
    Search(smax, 1, 1, 0);
    printf("%d\n", ans);
    return 0;
}
