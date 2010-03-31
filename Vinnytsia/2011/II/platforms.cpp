#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define Abs(a) ((a < 0) ? (-(a)) : (a))
#define Sqr(a) ((a) * (a))

const int nmax = 500002;

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    else
        return b;
}

long long F1[nmax], F2[nmax];
int y[nmax];
int N;

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &y[i]);

    F1[1] = F2[1] = 0;
    F1[2] = Abs(y[2] - y[1]);
    F2[2] = Sqr(y[2] - y[1]);
    F1[3] = min(F1[2] + Abs(y[3] - y[2]), F1[1] + 3 * Abs(y[3] - y[1]));
    F2[3] = min(F2[2] + Sqr(y[3] - y[2]), F2[1] + 3 * Sqr(y[3] - y[1]));

    for (int i = 4; i <= N; i++)
    {
        F1[i] = min(
            min(
                F1[i - 1] + Abs(y[i] - y[i - 1]),
                F1[i - 2] + 3 * Abs(y[i] - y[i - 2])),
            F1[i - 3] + 3 * Abs(y[i - 1] - y[i - 3]) + Abs(y[i - 1] - y[i - 2]) + 3 * Abs(y[i] - y[i - 2]));
        F2[i] = min(
            min(
                F2[i - 1] + Sqr(y[i] - y[i - 1]),
                F2[i - 2] + 3 * Sqr(y[i] - y[i - 2])),
            F2[i - 3] + 3 * Sqr(y[i - 1] - y[i - 3]) + Sqr(y[i - 1] - y[i - 2]) + 3 * Sqr(y[i] - y[i - 2]));
    }
    cout << F1[N] << " " << F2[N] << endl;
    return 0;
}
