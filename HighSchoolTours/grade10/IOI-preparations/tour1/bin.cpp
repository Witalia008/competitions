#include <stdio.h>
#include <cstdlib>

using namespace std;

#define N 200

int n;
int prev[N];
bool used[N];

int main()
{
    freopen("bin.dat", "r", stdin);
    freopen("bin.sol", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &prev[i]);
    int j = n, ans = 0;
    while (!used[j])
    {
        used[j] = true;
        j = prev[j];
        ans++;
    }
    ans = ans * 2 - 3;
    if (used[1] && j == n)
        printf("%d\n", ans);
    else
        printf("-1\n");
    return 0;
}
