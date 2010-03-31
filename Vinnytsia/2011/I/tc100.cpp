#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int A[200][200];
int N, M, K, ans;
int x, y, s1, s2, i, j;

int main()
{
    //freopen ("i", "r", stdin); freopen ("o", "w", stdout);
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d", &x, &y);
        A[x - 1][y - 1] = 1;
    }
    ans = 0;

    s1 = 0, s2 = 0;
    for (i = 0; i < N; i++)
    {
        j = 0;
        while (j < M && A[i][j] == 0)
            j++;
        s1 += j;
        j = 0;
        while (j < M && A[i][M - j - 1] == 0)
            j++;
        s2 += j;
    }
    ans = max(ans, s1);
    ans = max(ans, s2);

    s1 = 0, s2 = 0;
    for (j = 0; j < M; j++)
    {
        i = 0;
        while (i < N && A[i][j] == 0)
            i++;
        s1 += i;
        i = 0;
        while (i < N && A[N - i - 1][j] == 0)
            i++;
        s2 += i;
    }
    ans = max(ans, s1);
    ans = max(ans, s2);

    printf("%d\n", ans);
    return 0;
}
