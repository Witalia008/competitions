#include <stdio.h>
#include <cstdlib>

using namespace std;

int a[9][9];
int N, x, y, ans;

int main()
{
    //freopen ("i", "r", stdin); freopen ("o", "w", stdout);
    ans = 0;
    scanf("%d", &N);

    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            a[i][j] = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &x, &y);
        a[x][y]++;
    }

    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            if (a[i][j] > ans)
                ans = a[i][j];

    printf("%d\n", ans);
    return 0;
}
