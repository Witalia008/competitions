#include <stdio.h>
#include <cstdlib>

using namespace std;

#define nmax 2005

int N, M, time, count;
bool A[nmax][nmax];
int Need[nmax], outTime[nmax], comp[nmax];
bool Used[nmax];

char buf[64];
char *bptr;

void nextLine()
{
    gets(buf);
    bptr = buf;
}

void nextInt(int &val)
{
    while (*bptr < '0' || *bptr > '9')
        ++bptr;
    val = 0;
    while (*bptr >= '0' && *bptr <= '9')
    {
        val = val * 10 + (*bptr) - '0';
        ++bptr;
    }
}

void fault()
{
    printf("NO\n");
    exit(0);
}

void dfs(int v)
{
    Used[v] = true;
    for (int to = 0; to < 2 * N; to++)
        if (!Used[to] && A[v][to])
            dfs(to);
    outTime[time++] = v;
}

void dfs(int v, int cou)
{
    comp[v] = cou;
    for (int to = 0; to < N * 2; to++)
        if (comp[to] == -1 && A[to][v])
            dfs(to, cou);
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d\n", &N, &M);
    for (int i = 0; i < N; i++)
        Need[i] = -1;

    for (int i = 0; i < M; i++)
    {
        int u, v, c;
        nextLine();
        nextInt(u);
        nextInt(v);
        nextInt(c);
        u--;
        v--;
        while (*bptr < 'A' || *bptr > 'Z')
            ++bptr;
        if ((*bptr) == 'O')
        {
            if (c == 1)
            {
                A[u + N][v] = true;
                A[v + N][u] = true;
            }
            else
            {
                if (Need[u] == 1 || Need[v] == 1)
                    fault();
                Need[u] = Need[v] = 0;
            }
        }
        else if ((*bptr) == 'A')
        {
            if (c == 0)
            {
                A[u][v + N] = true;
                A[v][u + N] = true;
            }
            else
            {
                if (Need[u] == 0 || Need[v] == 0)
                    fault();
                Need[u] = Need[v] = 1;
            }
        }
        else
        {
            if (c == 0)
            {
                A[u][v] = true;
                A[v][u] = true;
                A[u + N][v + N] = true;
                A[v + N][u + N] = true;
            }
            else
            {
                A[u][v + N] = true;
                A[v][u + N] = true;
                A[u + N][v] = true;
                A[v + N][u] = true;
            }
        }
    }

    time = 0;
    for (int i = 0; i < N * 2; i++)
        if (!Used[i])
            dfs(i);

    for (int i = 0; i < N * 2; i++)
        comp[i] = -1;

    for (int i = N * 2 - 1; i >= 0; i--)
    {
        int v = outTime[i];
        if (comp[v] == -1)
        {
            dfs(v, count);
            count++;
        }
    }

    for (int i = 0; i < N; i++)
        if (comp[i] == comp[i + N])
            fault();

    for (int i = 0; i < N * 2; i++)
        Used[i] = false;

    time = 0;
    for (int i = 0; i < N; i++)
        if (Need[i] == 0)
            dfs(i + N);
        else if (Need[i] == 1)
            dfs(i);

    for (int i = 0; i < N; i++)
        if (Used[i] && Used[i + N])
            fault();

    printf("YES\n");
    return 0;
}
