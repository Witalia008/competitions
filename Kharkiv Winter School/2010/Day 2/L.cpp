#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

const int nmax = 1000000;

long long ans = 0;
long long a, b, c, x, N, top;
long long stack[nmax + 1], minimum[nmax + 1];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen ("sympathy.in", "r", stdin);freopen ("symapthy.out", "w", stdout);
    scanf("%d%d%d%d%d", &N, &a, &b, &c, &x);
    top = 0;
    minimum[0] = 10000000;
    for (int i = 0; i < N; i++)
    {
        x = (a * x * x + b * x + c) / 100 % 1000000;
        if (x % 5 < 2)
        {
            if (top > 0)
                top--;
        }
        else
        {
            top++;
            stack[top] = x;
            minimum[top] = min(minimum[top - 1], x);
        }
        if (top)
            ans += minimum[top];
    }
    printf("%lld\n", ans);
    return 0;
}
