#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#define nmax 7505
#define INF 1000000000
#define sqr(a) ((a) * (a))

using namespace std;

struct TPoint
{
    int x, y, col;
};

struct TList
{
    int dest, next;
};

int N, en;
TPoint A[nmax];
TList List[2 * nmax];
int Head[nmax], F[nmax], d[nmax];
bool used[nmax];

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

void DFS(int i, int col)
{
    A[i].col = ((col == 2) ? 1 : 2);
    used[i] = true;
    for (int j = Head[i]; j != 0; j = List[j].next)
        if (!used[List[j].dest])
            DFS(List[j].dest, A[i].col);
}

int main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &A[i].x, &A[i].y);
    for (int i = 2; i <= N; ++i)
        d[i] = sqr(A[i].x - A[1].x) + sqr(A[i].y - A[1].y), F[i] = 1;
    used[1] = true;
    for (int i = 1; i < N; ++i)
    {
        int k = -1;
        for (int j = 1; j <= N; ++j)
            if (!used[j] && (k == -1 || d[j] < d[k]))
                k = j;
        Add(F[k], k);
        Add(k, F[k]);
        used[k] = true;
        for (int j = 1; j <= N; ++j)
            if (!used[j] && d[j] > sqr(A[k].x - A[j].x) + sqr(A[k].y - A[j].y))
                F[j] = k, d[j] = sqr(A[k].x - A[j].x) + sqr(A[k].y - A[j].y);
    }
    memset(used, 0, sizeof(used));
    DFS(1, 2);
    int ans = INF;
    for (int i = 1; i < N; ++i)
        for (int j = i + 1; j <= N; ++j)
            if (A[i].col == A[j].col)
                if (sqr(A[i].x - A[j].x) + sqr(A[i].y - A[j].y) < ans)
                    ans = sqr(A[i].x - A[j].x) + sqr(A[i].y - A[j].y);
    printf("%0.7lf\n", sqrt((double)ans) / 2);
    for (int i = 1; i < N; ++i)
        printf("%d ", A[i].col);
    printf("%d\n", A[N].col);
    return 0;
}
