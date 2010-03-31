#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <math.h>
#include <algorithm>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int A[105][105], F[105][105];
int sol[200];

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int n, N;
    int a = 1, b = 1, maxb = 1, mina = 1;
    scanf("%d", &N);
    n = (int)sqrt((double)N);
    For(i, 1, N)
    {
        int x;
        scanf("%d", &x);
        A[a][b] = x;
        if (b == 1 || a == n)
        {
            if (a < n)
            {
                b = maxb + 1;
                maxb++;
                a = 1;
            }
            else
            {
                mina++;
                a = mina;
                b = n;
            }
        }
        else
        {
            b--;
            a++;
        }
    }
    /*For(i,1,n)
    {
        For(j,1,n)
            printf("%d ",A[i][j]);
        printf("\n");
    }*/
    memset(F, 0, sizeof(F));
    For(i, 1, n)
        For(j, 1, n)
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + A[i][j];
    /*For(i,1,n)
    {
        For(j,1,n)
            printf("%d ",F[i][j]);
        printf("\n");
    }*/
    printf("%d\n", F[n][n]);
    int top = 0;
    a = n, b = n;
    while (a != 1 || b != 1)
    {
        top++;
        sol[top] = A[a][b];
        if (F[a][b] - A[a][b] == F[a - 1][b])
            a--;
        else
            b--;
    }
    top++;
    sol[top] = A[1][1];
    for (int i = top; i > 1; i--)
        for (int j = 1; j < i; j++)
            if (sol[j] > sol[j + 1])
                swap(sol[j], sol[j + 1]);
    For(i, 1, top - 1)
        printf("%d ", sol[i]);
    printf("%d\n", sol[top]);
    return 0;
}
