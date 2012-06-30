#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int f[1000005];
int ans[200];

int main()
{
    freopen("calcul.in", "r", stdin);
    freopen("calcul.out", "w", stdout);
    int n;
    scanf("%d", &n);
    f[1] = 0;
    For(i, 2, n)
    {
        f[i] = f[i - 1];
        if ((i % 2 == 0) && (i / 2 > 0))
            if (f[i / 2] < f[i])
                f[i] = f[i / 2];
        if ((i % 3 == 0) && (i / 3 > 0))
            if (f[i / 3] < f[i])
                f[i] = f[i / 3];
        f[i]++;
    }
    printf("%d\n", f[n]);
    int top = 0;
    while (n != 1)
    {
        top++;
        ans[top] = n;
        if (f[n - 1] == f[n] - 1)
            n--;
        else
        {
            if ((n % 2 == 0) && (n / 2 > 0) && (f[n / 2] == f[n] - 1))
                n = n / 2;
            else
                n = n / 3;
        }
    }
    printf("1");
    for (int i = top; i >= 1; i--)
        printf(" %d", ans[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
