#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int a[1005], f[1005];

int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int n;
    scanf("%d", &n);
    For(i, 1, n)
        scanf("%d", &a[i]);
    f[1] = 1;
    int max = 1;
    For(i, 2, n)
    {
        f[i] = 0;
        For(j, 1, i - 1) if (a[j] < a[i]) if (f[j] > f[i]) f[i] = f[j];
        f[i]++;
        if (f[i] > max)
            max = f[i];
    }
    printf("%d\n", max);
    /*For(i,1,n)
		printf("%d ",f[i]);*/
    return 0;
}
