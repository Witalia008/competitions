#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define cmax 30
#define lmax 105
#define kmax 2005

int k, n;
int Cnt[kmax][cmax];
char A[kmax][lmax];

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d\n", &k);
    scanf("%s\n", &A[0]);
    int len = strlen(A[0]);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < len; j++)
        {
            A[i][j] = A[0][j];
            Cnt[i][A[i][j] - 'a']++;
        }
    }
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        int p;
        char c;
        scanf("%d %c\n", &p, &c);
        int j = 0;
        while (p > Cnt[j][c - 'a'])
        {
            p -= Cnt[j][c - 'a'];
            j++;
        }
        int l = 0;
        while (p)
        {
            if (A[j][l] == c)
                p--;
            if (p)
                l++;
        }
        A[j][l] = '^';
        Cnt[j][c - 'a']--;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < len; j++)
            if (A[i][j] != '^')
                printf("%c", A[i][j]);
    printf("\n");
    return 0;
}
