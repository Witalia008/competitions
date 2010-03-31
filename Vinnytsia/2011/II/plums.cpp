#include <stdio.h>
#include <cstdlib>

using namespace std;

int N, s;
int A[101][101];

int main()
{
    scanf("%d", &N);
    s = 1;
    int x = 1;
    for (int j = 1; j <= N; j++)
    {
        int c = s;
        for (int i = 0; i < N; i++)
        {
            A[c][j] = x++;
            c--;
            if (c == 0)
                c = N;
        }
        s++;
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d", A[i][1]);
        for (int j = 2; j <= N; j++)
            printf(" %d", A[i][j]);
        printf("\n");
    }
    return 0;
}
