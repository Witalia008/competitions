#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long LL;

LL Translate(LL A, int b)
{
    int a[20];
    int i = 20;
    while (A)
    {
        i--;
        a[i] = A % b;
        A /= b;
    }
    LL res = 0;
    while (i < 20)
    {
        res = res * 10 + a[i];
        i++;
    }
    return res;
}

LL N, M;

int main()
{
    cin >> N >> M;
    for (int i = 2; i < 10; i++)
        if (Translate(N, i) == M)
        {
            printf("%d\n", i);
            return 0;
        }
}
