#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
#define nmax 20
#define mmax 70000
#define INF 1000000000

using namespace std;

int N, M, Ans, top;
bool flag;
int A[nmax][nmax], S[nmax], K[nmax][nmax];
int D[mmax], is[mmax], Q[mmax];

void Read()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            A[i][j] = INF;
    for (int i = 1; i <= M; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (c < A[a][b])
        {
            A[a][b] = c;
            A[b][a] = c;
        }
        K[a][b]++;
        K[b][a]++;
        S[a]++, S[b]++;
        Ans += c;
    }
}

void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (A[i][j] > A[i][k] + A[k][j])
                    A[i][j] = A[i][k] + A[k][j];
    for (int i = 1; i <= N; ++i)
        A[i][i] = 0;
}

void ShiftUp(int i)
{
    for (; i > 0 && D[Q[i]] < D[Q[i / 2]]; i /= 2)
        swap(Q[i], Q[i / 2]), swap(is[Q[i]], is[Q[i / 2]]);
}

void ShiftDown(int i)
{
    while (i * 2 <= top)
    {
        int k = i;
        if (D[Q[i * 2]] < D[Q[k]])
            k = i * 2;
        if (i * 2 + 1 <= top && D[Q[i * 2 + 1]] < D[Q[k]])
            k = i * 2 + 1;
        if (k == i)
            i = top;
        else
        {
            swap(Q[i], Q[k]);
            swap(is[Q[i]], is[Q[k]]);
            i = k;
        }
    }
}

void Dijkstra(int p)
{
    memset(D, -1, sizeof(D));
    top = 1;
    Q[1] = p;
    D[p] = 0;
    memset(is, -1, sizeof(is));
    is[p] = 1;
    while (top != 0)
    {
        int v = Q[1];
        swap(Q[1], Q[top]);
        top--;
        ShiftDown(1);
        is[v] = -1;
        int x = 1;
        for (int i = 1; i <= N; ++i)
        {
            int y = 1;
            for (int j = 1; j < i; ++j)
            {
                int k = v ^ x ^ y;
                if (D[k] > D[v] + A[N - i + 1][N - j + 1] || D[k] == -1)
                {
                    D[k] = D[v] + A[N - i + 1][N - j + 1];
                    if (is[k] == -1)
                    {
                        top++;
                        Q[top] = k;
                        is[k] = top;
                        ShiftUp(top);
                    }
                    else
                        ShiftUp(is[k]);
                }
                y <<= 1;
            }
            x <<= 1;
        }
    }
}

void DFS(int i)
{
    if (M == 0)
    {
        flag = true;
        return;
    }
    for (int j = 1; j <= N; ++j)
        if (K[i][j] > 0)
        {
            M--;
            K[i][j]--;
            K[j][i]--;
            DFS(j);
        }
}

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    Read();
    Floyd();
    int c = 0;
    for (int i = 1; i <= N; ++i)
        c = c * 2 + S[i] % 2;
    flag = false;
    DFS(1);
    if (!flag)
        cout << "-1\n";
    else
    {
        Dijkstra(c);
        cout << ((D[0] > -1) ? Ans + D[0] : Ans) << endl;
    }
    return 0;
}
