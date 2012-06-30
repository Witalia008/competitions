#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define nmax 1000005

using namespace std;

int N, M, top, Max, ans;
int a[nmax * 2 + 1], w[nmax + 1], e[nmax + 1], v[nmax * 2 + 1];
bool used[nmax * 2 + 1];

int main()
{
    freopen("overview.dat", "r", stdin);
    freopen("overview.sol", "w", stdout);
    scanf("%d%d", &N, &M);
    Max = 0;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d", &w[i], &e[i]);
        a[w[i]]++;
        a[e[i]]++;
        if (w[i] > Max)
            Max = w[i];
        if (e[i] > Max)
            Max = e[i];
    }
    top = 1;
    for (int i = 1; i <= Max; ++i)
        if (a[i] != 0)
            a[i] = top++;
    for (int i = 1; i <= N; ++i)
        v[a[w[i]]] = a[e[i]] + 1, v[a[e[i]]] = a[w[i]] + 1;

    memset(a, 0, sizeof(a));
    ans = 0;
    Max = 0;
    for (int i = 1; i <= top; ++i)
        if (!used[i])
        {
            int j = i, cou = 0;
            while (v[j] != 0 && !used[j])
                used[j] = true, j = v[j], cou++;
            a[cou]++;
            if (j == top)
                ans = cou, a[cou]--, used[j] = true;
            if (cou > Max)
                Max = cou;
        }

    for (int i = Max; i != 0 && M != 0;)
        if (a[i] > 0)
            M--, ans = ans + i + 2, a[i]--;
        else
            i--;
    ans += (M / 2) * 3 + M / 2 + M % 2;
    printf("%d\n", ans);
    return 0;
}
