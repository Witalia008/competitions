#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <memory.h>

using namespace std;

int Grand(int a)
{
    if (a % 4 == 0)
        return a - 1;
    if (a % 4 == 3)
        return a + 1;
    return a;
}

int main()
{
    freopen("crazynim.in", "r", stdin);
    freopen("crazynim.out", "w", stdout);
    int N;
    scanf("%d", &N);
    int ans = 0;
    bool one = true;
    for (int j = 1; j <= N; j++)
    {
        int S;
        scanf("%d", &S);
        ans = ans ^ Grand(S);
        if (S != 1)
            one = false;
    }
    if (one)
        ans = (ans + 1) % 2;
    if (ans > 0)
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}
