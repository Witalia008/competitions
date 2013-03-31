#include <stdio.h>
#include <cstdlib>

using namespace std;

#define N 200000

int n;
int a[N], b[N];

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    int l = 0, r = 0;
    int ans = n;
    while (l < n)
    {
        while (r < n && a[l] != b[r])
            r++;
        if (r == n)
            break;
        ans--;
        l++;
        r++;
    }
    printf("%d\n", ans);
    return 0;
}
