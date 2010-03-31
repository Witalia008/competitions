#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100000

struct tree
{
    tree *l, *r;
    int x, y;
    tree(int _x) : l(0), r(0), x(_x), y(rand() << 16) {}
};

void merge(tree *l, tree *r, tree *&t)
{
    if (!l || !r)
        t = l ? l : r;
    else
    {
        if (l->y > r->y)
            merge(l->r, r, l->r), t = l;
        else
            merge(l, r->l, r->l), t = r;
    }
}

void split(tree *t, int key, tree *&l, tree *&r)
{
    if (!t)
        l = r = 0;
    else
    {
        if (key <= t->x)
            split(t->l, key, l, t->l), r = t;
        else
            split(t->r, key, t->r, r), l = t;
    }
}

void insert(tree *&t, tree *it)
{
    if (!t)
        t = it;
    else
    {
        if (it->y > t->y)
            split(t, it->x, it->l, it->r), t = it;
        else
            insert(it->x < t->x ? t->l : t->r, it);
    }
}

void remove(tree *&t, int key)
{
    if (!t)
        return;
    if (t->x == key)
        merge(t->l, t->r, t);
    else
        remove(key < t->x ? t->l : t->r, key);
}

int getL(tree *t)
{
    if (t->l)
        return getL(t->l);
    return t->x;
}

tree *root;
int n, m;
bool A[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    FOR(i, 1, n)
    insert(root, new tree(i));
    REP(i, m)
    {
        char q;
        int a;
        scanf("%c%d\n", &q, &a);
        if (q == '-')
        {
            if (A[a])
            {
                printf("0\n");
                insert(root, new tree(a));
                A[a] = false;
            }
            else
                printf("-2\n");
        }
        else
        {
            if (!root)
                printf("-1\n");
            else
            {
                tree *l, *r;
                split(root, a, l, r);
                int x;
                if (r)
                    x = getL(r);
                else
                    x = getL(l);
                printf("%d\n", x);
                A[x] = true;
                merge(l, r, root);
                remove(root, x);
            }
        }
    }
    return 0;
}
