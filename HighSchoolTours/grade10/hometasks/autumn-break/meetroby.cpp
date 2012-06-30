#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define inf 200000000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int dest[103000], head[256], next[103000], wei[103000], a[256];
bool used[256];
int en, ans;

void add(int u, int v, int t)
{
    en++;
    dest[en] = v;
    next[en] = head[u];
    head[u] = en;
    wei[en] = t;
}

void bfs(int i, int to, int sum)
{
    int j = head[i];
    a[i] = sum;
    used[i] = true;
    if ((i == to) && (sum < ans))
        ans = sum;
    while (j != 0)
    {
        if ((!used[dest[j]]) || (a[dest[j]] > sum + wei[j]))
            bfs(dest[j], to, sum + wei[j]);
        j = next[j];
    }
}

int main()
{
    freopen("meetroby.dat", "r", stdin);
    freopen("meetroby.res", "w", stdout);
    int n;
    scanf("%d", &n);
    en = 0;
    while (!feof(stdin))
    {
        int i, j, t;
        scanf("%d%d%d\n", &i, &j, &t);
        add(i, j, t);
        add(j, i, t);
    }
    int max = 0;
    For(i, 1, n)
        For(j, 1, n)
    {
        ans = inf;
        memset(used, 0, sizeof(used));
        bfs(i, j, 0);
        if ((ans > max) && (ans != inf))
            max = ans;
    }
    printf("%d\n", max % 2 + max / 2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
