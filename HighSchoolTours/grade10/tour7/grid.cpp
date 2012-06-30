#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int a[55][55];

int main()
{
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(a, 5, sizeof(a));
    For(i, 1, n)
        For(j, 1, n)
            scanf("%d", &a[i][j]);
    int ans = 0;
    For(i, 2, n)
        For(j, 2, n)
            For(I, 1, i)
                For(J, 1, j - 1) if ((I - j + J > 0) && (J + i - I > 0) && (i - j + J > 0) && (j + i - I > 0)) if ((a[I][J] == a[i][j]) && (a[I - j + J][J + i - I] == a[i][j]) && (a[i - j + J][j + i - I] == a[i][j]))
                    ans++;
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
