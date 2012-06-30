#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#define nmax 1000
#define INF 1000000000
#define sqr(a) ((a) * (a))

using namespace std;

struct TLabel
{
    long long x, y;
    int index;
    string Name;
};

struct TList
{
    int Dest, Next;
};

int N, S, F, en;
TLabel L1[nmax + 1], L2[nmax + 1], L3[nmax + 1], L4[nmax + 1];
TList List[nmax * nmax];
int Head[nmax + 1], D[nmax + 1];

int abss(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

bool compL2(TLabel a, TLabel b)
{
    return a.x < b.x;
}

bool compL3(TLabel a, TLabel b)
{
    return a.y < b.y;
}

bool compL4(TLabel a, TLabel b)
{
    return a.Name < b.Name;
}

inline void Add(int u, int v)
{
    en++;
    List[en].Dest = v;
    List[en].Next = Head[u];
    Head[u] = en;
}

inline long long dist(TLabel s, TLabel f)
{
    return sqr(s.x - f.x) + sqr(s.y - f.y);
}

inline void New_Up(int i)
{
    int ans = -1;
    for (int j = N - 1; j >= 0 && L3[j].y >= L2[i].y; j--)
        if (abss(L3[j].x - L2[i].x) <= abss(L3[j].y - L2[i].y))
        {
            if (ans != -1 && dist(L3[ans], L2[i]) == dist(L3[j], L2[i]))
            {
                if (L3[j].x < L3[ans].x)
                    ans = j;
                if (L3[j].x == L3[ans].x)
                    if (L3[j].y < L3[ans].y)
                        ans = j;
            }
            if (ans == -1 || dist(L3[ans], L2[i]) > dist(L3[j], L2[i]))
                if (L3[j].index != L2[i].index)
                    ans = j;
        }
    if (ans != -1)
        Add(L2[i].index, L3[ans].index);
}

inline void New_Down(int i)
{
    int ans = -1;
    for (int j = 0; j < N && L3[j].y <= L2[i].y; j++)
        if (abss(L3[j].x - L2[i].x) <= abss(L3[j].y - L2[i].y))
        {
            if (ans != -1 && dist(L3[ans], L2[i]) == dist(L3[j], L2[i]))
            {
                if (L3[j].x < L3[ans].x)
                    ans = j;
                if (L3[j].x == L3[ans].x)
                    if (L3[j].y < L3[ans].y)
                        ans = j;
            }
            if (ans == -1 || dist(L3[ans], L2[i]) > dist(L3[j], L2[i]))
                if (L3[j].index != L2[i].index)
                    ans = j;
        }
    if (ans != -1)
        Add(L2[i].index, L3[ans].index);
}

inline void New_Left(int i)
{
    int ans = -1;
    for (int j = 0; j < N && L2[j].x <= L2[i].x; j++)
        if (abss(L2[j].x - L2[i].x) > abss(L2[j].y - L2[i].y))
        {
            if (ans != -1 && dist(L2[ans], L2[i]) == dist(L2[j], L2[i]))
            {
                if (L2[j].x < L2[ans].x)
                    ans = j;
                if (L2[j].x == L2[ans].x)
                    if (L2[j].y < L2[ans].y)
                        ans = j;
            }
            if (ans == -1 || dist(L2[ans], L2[i]) > dist(L2[j], L2[i]))
                if (L2[j].index != L2[i].index)
                    ans = j;
        }
    if (ans != -1)
        Add(L2[i].index, L2[ans].index);
}

inline void New_Right(int i)
{
    int ans = -1;
    for (int j = N - 1; j >= 0 && L2[j].x >= L2[i].x; j--)
        if (abss(L2[j].x - L2[i].x) > abss(L2[j].y - L2[i].y))
        {
            if (ans != -1 && dist(L2[ans], L2[i]) == dist(L2[j], L2[i]))
            {
                if (L2[j].x < L2[ans].x)
                    ans = j;
                if (L2[j].x == L2[ans].x)
                    if (L2[j].y < L2[ans].y)
                        ans = j;
            }
            if (ans == -1 || dist(L2[ans], L2[i]) > dist(L2[j], L2[i]))
                if (L2[j].index != L2[i].index)
                    ans = j;
        }
    if (ans != -1)
        Add(L2[i].index, L2[ans].index);
}

inline void New_Letter(int i, char l)
{
    int ans = -1;
    for (int j = 0; j < N; j++)
        if (L4[j].Name[0] == l)
        {
            if (ans == -1 && L4[j].index != L2[i].index)
                ans = j;
            if (L4[j].index == L2[i].index && j + 1 < N && L4[j + 1].Name[0] == l)
                ans = -1;
        }
    if (ans != -1)
        Add(L2[i].index, L4[ans].index);
}

priority_queue<pair<int, int>> Q;
bool is[nmax + 1];

inline void BFS(int s)
{
    Q.push(make_pair(N, s));
    is[s] = true;
    while (!Q.empty())
    {
        pair<int, int> v = Q.top();
        is[v.second] = false;
        Q.pop();
        int j = Head[v.second];
        while (j)
        {
            if (D[v.second] + 1 < D[List[j].Dest])
            {
                D[List[j].Dest] = D[v.second] + 1;
                if (!is[List[j].Dest])
                    Q.push(make_pair(N - D[List[j].Dest], List[j].Dest));
            }
            j = List[j].Next;
        }
    }
}

int main()
{
    ifstream cin("desktop.dat");
    ofstream cout("desktop.sol");
    cin >> N >> S >> F;
    if (S == F)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> L1[i].x >> L1[i].y >> L1[i].Name;
        L1[i].index = i;
        L2[i] = L3[i] = L4[i] = L1[i];
    }
    sort(L2, L2 + N, &compL2);
    sort(L3, L3 + N, &compL3);
    sort(L4, L4 + N, &compL4);
    for (int i = 0; i < N; i++)
    {
        New_Up(i);
        New_Down(i);
        New_Left(i);
        New_Right(i);
        for (char j = 'a'; j <= 'z'; j++)
            New_Letter(i, j);
    }
    for (int i = 0; i < N; (i != S - 1) ? D[i] = INF : D[i] = 0, i++)
        ;
    BFS(S - 1);
    cout << D[F - 1] << endl;
    cin.close();
    cout.close();
    return 0;
}
