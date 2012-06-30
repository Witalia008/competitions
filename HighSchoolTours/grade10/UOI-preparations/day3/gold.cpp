#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct gold
{
    int x, y, c;
};

const int N = 50000;

gold a[N];
int n;

void Read()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int y;
        scanf("%d%d%d", &a[i].x, &y, &a[i].c);
        a[i].y = a[i].x + y;
        a[i].x -= y;
    }
}

int cmp(gold a, gold b)
{
    if (a.y != b.y)
        return a.y > b.y;
    else
        return a.x < b.x;
}
int t[N];

long long Tree[N + 1];

long long getMax(int i)
{
    long long ret = 0;
    while (i != 0)
    {
        if (Tree[i] > ret)
            ret = Tree[i];
        i = i & (i - 1);
    }
    return ret;
}
void Add(int i, long long val)
{
    while (i <= n)
    {
        if (Tree[i] < val)
            Tree[i] = val;
        i = (i | (i - 1)) + 1;
    }
}

void Solve()
{
    int i, k;

    sort(a, a + n, cmp);
    for (i = 0; i < n; i++)
        t[i] = a[i].x;

    sort(t, t + n);
    map<int, int> M;
    k = 1;
    for (i = 0; i < n; i++)
        if (M[t[i]] == 0)
            M[t[i]] = k++;
    for (i = 0; i < n; i++)
        a[i].x = M[a[i].x];

    for (i = 0; i < n; i++)
        Add(a[i].x, getMax(a[i].x) + a[i].c);
    cout << getMax(n) << endl;
}

int main()
{
    freopen("gold.in", "r", stdin);
    freopen("gold.out", "w", stdout);
    Read();
    Solve();
    return 0;
}
