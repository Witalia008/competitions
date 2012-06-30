#include <stdio.h>
#include <cstdlib>

using namespace std;

#define NMAX 100005

struct tree
{
    tree *l, *r;
    int sum;
    tree(int x)
    {
        l = r = 0;
        sum = x;
    }
    tree(tree *L, tree *R)
    {
        l = L;
        r = R;
        sum = L->sum + R->sum;
    }
};

int a[NMAX], T[NMAX];
tree *A[NMAX];
int Cnt, N, M, I, D, f, t;

tree *build(int l, int r)
{
    if (l == r)
        return new tree(a[l]);
    int mid = (l + r) / 2;
    return new tree(build(l, mid), build(mid + 1, r));
}

tree *Add(tree *t, int l, int r)
{
    if (l == r)
        return new tree(t->sum + D);
    int mid = (l + r) / 2;
    if (I <= mid)
        return new tree(Add(t->l, l, mid), t->r);
    else
        return new tree(t->l, Add(t->r, mid + 1, r));
}

int GetSum(tree *t, int l, int r, int kl, int kr)
{
    if (kl == l && kr == r)
        return t->sum;
    int mid = (l + r) / 2;
    if (kr <= mid)
        return GetSum(t->l, l, mid, kl, kr);
    if (kl > mid)
        return GetSum(t->r, mid + 1, r, kl, kr);
    return GetSum(t->l, l, mid, kl, mid) + GetSum(t->r, mid + 1, r, mid + 1, kr);
}

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    scanf("\n");
    A[0] = build(1, N);
    Cnt = 0;
    for (int i = 1; i <= M; i++)
    {
        char wh;
        scanf("%c", &wh);
        T[i] = Cnt;
        if (wh == '+')
        {
            scanf("%d%d\n", &I, &D);
            Cnt++;
            A[Cnt] = Add(A[Cnt - 1], 1, N);
        }
        if (wh == '?')
        {
            scanf("%d%d\n", &f, &t);
            printf("%d\n", GetSum(A[Cnt], 1, N, f, t));
        }
        if (wh == 't')
        {
            scanf("%d\n", &t);
            Cnt++;
            A[Cnt] = A[T[t]];
        }
    }
    return 0;
}
