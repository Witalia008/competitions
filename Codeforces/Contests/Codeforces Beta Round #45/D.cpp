#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int a[100001], mas[100001], sol[100001];

int main()
{
    /*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    For(i, 1, n)
    {
        scanf("%d", &mas[i]);
        a[mas[i]]++;
    }
    bool fl = true;
    For(i, 2, 100000) if (a[i] > a[i - 1]) fl = false;
    if (!fl)
        printf("-1\n");
    else
    {
        printf("%d\n", a[1]);
        For(i, 1, n)
        {
            sol[i] = a[mas[i]];
            a[mas[i]]--;
        }
        For(i, 1, n - 1)
            printf("%d ", sol[i]);
        printf("%d\n", sol[n]);
    }
    return 0;
}
