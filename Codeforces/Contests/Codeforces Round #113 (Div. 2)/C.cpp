#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 2000

int n, x;
int A[N];

void push(int a)
{
    A[n++] = a;
    int j = n - 1;
    while (j && A[j] < A[j - 1])
        swap(A[j], A[j - 1]), j--;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    REP(i, n)
    scanf("%d", &A[i]);
    sort(A, A + n);
    if (A[(n + 1) / 2 - 1] == x)
        printf("0\n");
    else
    {
        push(x);
        int ans = 1;
        while (A[(n + 1) / 2 - 1] != x)
            push(x), ans++;
        printf("%d\n", ans);
    }
    return 0;
}
