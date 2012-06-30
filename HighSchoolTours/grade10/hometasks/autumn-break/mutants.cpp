#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int a[1001][1001], f[1001][1001];
int ai[1000000], aj[1000000];

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    freopen("mutants.in", "r", stdin);
    freopen("mutants.out", "w", stdout);
    int n, m;
    scanf("%d%d\n", &n, &m);
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    For(i, 1, n)
        For(j, 1, m)
            scanf("%d", &a[i][j]);
    f[1][1] = a[1][1];
    For(i, 2, n)
        f[i][1] = f[i - 1][1] + a[i][1];
    For(j, 2, m)
        f[1][j] = f[1][j - 1] + a[1][j];
    For(i, 2, n)
        For(j, 2, m)
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
    printf("%d\n", f[n][m]);
    printf("%d\n", n + m - 1);
    int top = 1;
    ai[1] = n;
    aj[1] = m;
    while ((ai[top] != 1) || (aj[top] != 1))
    {
        int i, j;
        i = ai[top];
        j = aj[top];
        if (f[i - 1][j] == f[i][j] - a[i][j])
            i--;
        else
            j--;
        top++;
        ai[top] = i;
        aj[top] = j;
    }
    for (int k = top; k >= 1; k--)
        printf("%d %d\n", ai[k], aj[k]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
