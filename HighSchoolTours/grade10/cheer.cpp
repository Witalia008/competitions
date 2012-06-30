#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tmas
{
    int s, f, l;
};

int c[10000], father[10000], rang[10000];
tmas list[100000];

void swap(tmas &a, tmas &b)
{
    tmas t = a;
    a = b;
    b = t;
}

int sort(int l, int r)
{
    if ((l == r - 1) && (list[l].l < list[r].l))
        return 0;
    int et = list[(l + r) / 2].l;
    int i = l;
    int j = r;
    while (i < j)
    {
        while (list[i].l < et)
            i++;
        while (list[j].l > et)
            j--;
        if (i < j)
        {
            swap(list[i], list[j]);
            i++;
            j--;
        }
    }
    if (i < r)
        sort(i, r);
    if (j > l)
        sort(l, j);
}

int main()
{
    freopen("cheer.in", "r", stdin);
    freopen("cheer.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    For(i, 1, n)
        scanf("%d", &c[i]);
    For(i, 1, m)
    {
        scanf("%d%d%d", &list[i].s, &list[i].f, &list[i].l);
        list[i].l *= 2;
        list[i].l += c[list[i].s] + c[list[i].f];
    }
    sort(1, m);
    int ans = 0;
    For(i, 1, n)
    {
        rang[i] = 1;
        father[i] = -1;
    }
    For(i, 1, m)
    {
        int roots, rootf;
        roots = list[i].s;
        rootf = list[i].f;
        while (father[roots] != -1)
            roots = father[roots];
        while (father[rootf] != -1)
            rootf = father[rootf];
        if (roots != rootf)
        {
            ans += list[i].l;
            if (rang[roots] == rang[rootf])
            {
                if (roots < rootf)
                {
                    rang[roots]++;
                    father[rootf] = roots;
                }
                else
                {
                    rang[rootf]++;
                    father[roots] = rootf;
                }
            }
            else if (rang[roots] > rang[rootf])
            {
                father[rootf] = roots;
            }
            else
                father[roots] = rootf;
        }
    }
    int min = c[1];
    For(i, 2, n) if (c[i] < min) min = c[i];
    printf("%d\n", ans + min);
    return 0;
}
