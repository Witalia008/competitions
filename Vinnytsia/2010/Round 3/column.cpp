#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int a[32770];

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int n;
    scanf("%d", &n);
    For(i, 1, n)
        scanf("%d", &a[i]);
    int g = 0, b = 0, j;
    j = 1;
    while (j <= n && a[j] == 0)
        j++;
    For(i, j, n) if (a[i] == 0) g++;
    j = n;
    while (j > 0 && a[j] == 1)
        j--;
    For(i, 1, j) if (a[i] == 1) b++;
    if (g < b)
        printf("%d\n", g);
    else
        printf("%d\n", b);
    return 0;
}
