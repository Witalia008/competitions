#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>

using namespace std;

#define N 105

char J[N], S[N];
int a[N * 3];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int _t = 0; _t < t; _t++)
    {
        memset(a, 0, sizeof(a));
        scanf("%s\n", &J);
        scanf("%s\n", &S);
        for (int i = 0; i < strlen(J); i++)
            a[J[i]]++;
        int cnt = 0;
        for (int i = 0; i < strlen(S); i++)
            if (a[S[i]])
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
