#include <stdio.h>
#include <iostream>

using namespace std;

const int nmax = 32770;

int N;
int A[nmax];
int wh[nmax];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
        wh[A[i]] = i;
    }
    int res = 0;
    for (int i = 1; i <= N; i++)
        if (i != A[i])
        {
            res++;
            swap(A[i], A[wh[i]]);
            swap(wh[A[wh[i]]], wh[i]);
        }
    printf("%d\n", res);
    return 0;
}
