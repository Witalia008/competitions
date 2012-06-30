#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#define nmax 1005
#define INF 1000000000

using namespace std;

int N, L, R;
int A[nmax][nmax], cou[nmax];
bool used[nmax];

void dfs1(int i, int c)
{
    used[i] = true;
    cou[i]++;
    for (int j = 1; j <= N; ++j)
        if (!used[j] && A[i][j] <= c)
            dfs1(j, c);
}

void dfs2(int i, int c)
{
    used[i] = true;
    cou[i]++;
    for (int j = 1; j <= N; ++j)
        if (!used[j] && A[j][i] <= c)
            dfs2(j, c);
}

bool Check(int mid)
{
    memset(used, 0, sizeof(used));
    memset(cou, 0, sizeof(cou));
    dfs1(1, mid);
    memset(used, 0, sizeof(used));
    dfs2(1, mid);
    for (int i = 1; i <= N; ++i)
        if (cou[i] != 2)
            return false;
    return true;
}

int main()
{
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);
    R = 0, L = INF;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &A[i][j]);
            if (A[i][j] > R)
                R = A[i][j];
            if (A[i][j] < L)
                L = A[i][j];
        }
    while (L < R - 1)
    {
        int mid = (L + R) / 2;
        if (Check(mid))
            R = mid;
        else
            L = mid;
    }
    if (Check(L))
        cout << L << endl;
    else
        cout << R << endl;
    return 0;
}
