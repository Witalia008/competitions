#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>

using namespace std;

typedef long long ll;

#define N 55

int mx[4] = {0, 0, 1, -1};
int my[4] = {-1, 1, 0, 0};

int n, m, cnt, cou;
char a[N][N];
bool used[N][N];

bool good(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int i, int j)
{
    used[i][j] = true;
    cou++;
    for (int k = 0; k < 4; k++)
        if (good(i + mx[k], j + my[k]) && a[i + mx[k]][j + my[k]] == '#' && !used[i + mx[k]][j + my[k]])
            dfs(i + mx[k], j + my[k]);
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s\n", &a[i]);
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#')
                cnt++;
    }
    if (cnt <= 2)
        printf("-1\n");
    else
    {
        int ans = 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '#')
                {
                    a[i][j] = '.';
                    cou = 0;
                    memset(used, 0, sizeof(used));
                    for (int si = 0; si < n; si++)
                        for (int sj = 0; sj < m; sj++)
                            if (a[si][sj] == '#')
                                dfs(si, sj), si = n, sj = m;
                    if (cou != cnt - 1)
                        ans = 1;
                    a[i][j] = '#';
                }
        printf("%d\n", ans);
    }
    return 0;
}
