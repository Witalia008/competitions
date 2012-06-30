#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;
int n, k, ans;
int p[35], h[35], v[35], a[35];
bool fl;

void srch(int i, int V, int P)
{
    if (i == n + 1)
    {
        if (P < ans && V >= k)
        {
            fl = true;
            ans = P;
        }
        return;
    }
    a[i] = 0;
    if (h[i] == 1)
        srch(i + 1, V + v[i], P);
    else
        srch(i + 1, V, P);
    a[i] = 1;
    if (h[i] == 1)
        srch(i + 1, V, P - p[i]);
    else if (P + p[i] < ans)
        srch(i + 1, V + v[i], P + p[i]);
}

int main()
{
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    fl = false;
    ans = 1000000000;
    srch(1, 0, 0);
    if (!fl)
        printf("-1\n");
    else
    {
        if (ans <= 0)
            printf("0\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
