#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define nmax 100000
#define maxstep 65536 * 2
#define step 17
#define INF 1000000000
#pragma comment(linker, "/STACK:20000000")

using namespace std;

struct TList
{
    int Dest, Next;
};

TList List[2 * nmax + 1];
int Head[nmax + 1], Step[nmax + 1], MaxAnc[nmax + 1];
int Ancestor[nmax + 1][step + 1];
bool Used[nmax + 1];
int en, N, M, Ans;

void Add(int u, int v)
{
    en++;
    List[en].Dest = v;
    List[en].Next = Head[u];
    Head[u] = en;
}

void DFS(int i, int f)
{
    Step[i] = Step[f] + 1;
    Ancestor[i][0] = f;
    for (int k = 1; k <= step; ++k)
        Ancestor[i][k] = Ancestor[Ancestor[i][k - 1]][k - 1];
    Used[i] = true;
    int j = Head[i];
    while (j)
    {
        if (!Used[List[j].Dest])
            DFS(List[j].Dest, i);
        j = List[j].Next;
    }
}

void LCA(int a, int b)
{
    if (Step[a] < Step[b])
        swap(a, b);
    int as = a, bs = b;
    for (int i = step; i >= 0; --i)
        if (Step[Ancestor[a][i]] >= Step[b])
            a = Ancestor[a][i];
    if (a != b)
    {
        for (int i = step; i >= 0; --i)
            if (Ancestor[a][i] != Ancestor[b][i])
                a = Ancestor[a][i], b = Ancestor[b][i];
        a = Ancestor[a][0], b = Ancestor[b][0];
    }
    if (MaxAnc[as] > Step[a])
        MaxAnc[as] = Step[a];
    if (MaxAnc[bs] > Step[b])
        MaxAnc[bs] = Step[b];
}

int Count(int i)
{
    Used[i] = true;
    int Max = MaxAnc[i];
    int j = Head[i];
    while (j)
    {
        if (!Used[List[j].Dest])
        {
            int C = Count(List[j].Dest);
            if (C < Max)
                Max = C;
        }
        j = List[j].Next;
    }
    if (Max < Step[i])
        Ans++;
    return Max;
}

void Read()
{
    scanf("%d", &N);
    for (int i = 1; i < N; ++i)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        Add(s, f);
        Add(f, s);
    }
}

void GetAnc()
{
    scanf("%d", &M);
    for (int i = 0; i <= N; ++i)
        MaxAnc[i] = INF;
    for (int i = 1; i <= M; ++i)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        LCA(s, f);
    }
}

int main()
{
    freopen("trails.in", "r", stdin);
    freopen("trails.out", "w", stdout);
    /*memset (Used, 0, sizeof (Used));
	memset (Ancestor, 0, sizeof (Ancestor));
	memset (List, 0, sizeof (List));
	memset (Head, 0, sizeof (Head));
	memset (Step, 0, sizeof (Step));*/
    Read();
    DFS(1, 1);
    GetAnc();
    memset(Used, 0, sizeof(Used));
    Count(1);
    cout << N - Ans - 1 << endl;
    return 0;
}
