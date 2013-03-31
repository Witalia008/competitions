#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define max(a, b) (a > b) ? (a) : (b)
#define M 26

char s[10];
int F[M][M];
int n;

int main()
{
    //freopen ("a.in", "r", stdin);
    //freopen ("a.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s\n", &s);
        int len = strlen(s);
        int f = s[0] - 'a', l = s[len - 1] - 'a';
        for (int j = 0; j < M; j++)
            if (F[j][f])
                F[j][l] = max(F[j][l], F[j][f] + len);
        F[f][l] = max(F[f][l], len);
    }
    int ans = 0;
    for (int i = 0; i < M; i++)
        ans = max(ans, F[i][i]);
    printf("%d\n", ans);
    return 0;
}
