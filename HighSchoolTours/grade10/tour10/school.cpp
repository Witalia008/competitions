#include <stdio.h>
#include <cstdlib>
#define For(i, a, b) for (int i = a; i <= b; i++)
#include <memory.h>

using namespace std;

struct tmas
{
    int s, f, wei, used;
};

tmas list[10005];
int par[105];
int sol[105];

void swap(tmas &a, tmas &b)
{
    tmas t = a;
    a = b;
    b = t;
}

int sort(int l, int r)
{
    if ((l == r - 1) && (list[l].wei < list[r].wei))
        return 0;
    int et = list[(l + r) / 2].wei;
    int i = l, j = r;
    while (i < j)
    {
        while (list[i].wei < et)
            i++;
        while (list[j].wei > et)
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
    freopen("school.dat", "r", stdin);
    freopen("school.sol", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    memset(list, 0, sizeof(list));
    For(i, 1, m)
        scanf("%d%d%d", &list[i].s, &list[i].f, &list[i].wei);
    sort(1, m);
    For(i, 1, n)
        par[i] = -1;
    int ans = 0;
    int nom = 1, cou = 0;
    while ((nom <= m) && (cou < n - 1))
    {
        int roota = list[nom].s, rootb = list[nom].f;
        while (par[roota] != -1)
            roota = par[roota];
        while (par[rootb] != -1)
            rootb = par[rootb];
        if (roota != rootb)
        {
            cou++;
            sol[cou] = nom;
            ans += list[nom].wei;
            par[rootb] = roota;
        }
        nom++;
    }
    printf("%d ", ans);
    For(i, 1, m)
        list[i]
            .used = false;
    ans = 2000000000;
    For(i, 1, cou)
    {
        list[sol[i]].used = true;
        For(i, 1, n)
            par[i] = -1;
        nom = 1;
        cou = 0;
        int mm = 0;
        while ((nom <= m) && (cou < n - 1))
        {
            if (!list[nom].used)
            {
                int roota = list[nom].s, rootb = list[nom].f;
                while (par[roota] != -1)
                    roota = par[roota];
                while (par[rootb] != -1)
                    rootb = par[rootb];
                if (roota != rootb)
                {
                    cou++;
                    mm += list[nom].wei;
                    par[rootb] = roota;
                }
            }
            nom++;
        }
        if ((mm < ans) && (cou == n - 1))
            ans = mm;
        list[sol[i]].used = false;
    }
    printf("%d\n", ans);
    return 0;
}
