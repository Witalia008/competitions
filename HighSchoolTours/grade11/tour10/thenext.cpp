#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "thenext.in";
const char *outfile = "thenext.out";

typedef long long LL;

LL mmax(LL a, LL b)
{
    if (a > b)
        return a;
    else
        return b;
}

struct Tree
{
    Tree *l, *r;
    LL x, y, Max;
    Tree(LL xx, LL yy)
    {
        x = xx;
        y = yy;
        l = r = 0;
        Max = x;
    }
    void update_Max()
    {
        Max = x;
        if (l)
            Max = mmax(Max, l->Max);
        if (r)
            Max = mmax(Max, r->Max);
    }
};

Tree *Merge(Tree *l, Tree *r)
{
    if (!l)
        return r;
    if (!r)
        return l;

    if (l->y < r->y)
    {
        l->r = Merge(l->r, r);
        l->update_Max();
        return l;
    }
    else
    {
        r->l = Merge(l, r->l);
        r->update_Max();
        return r;
    }
}

void Split(Tree *t, LL x, Tree *&l, Tree *&r)
{
    if (!t)
    {
        l = r = 0;
        return;
    }

    if (x <= t->x)
    {
        Split(t->l, x, l, t->l);
        r = t;
    }
    else
    {
        Split(t->r, x, t->r, r);
        l = t;
    }

    t->update_Max();
}

Tree *Insert(Tree *t, LL x, LL y)
{
    if (!t)
        return new Tree(x, y);

    if (y < t->y)
    {
        if (x < t->x)
            t->l = Insert(t->l, x, y);
        else
            t->r = Insert(t->r, x, y);

        t->update_Max();
        return t;
    }
    else
    {
        Tree *p = new Tree(x, y);
        Split(t, x, p->l, p->r);

        p->update_Max();
        return p;
    }
}

int GetNext(Tree *t, LL x)
{
    if (!t)
        return -1;

    if (x == t->x)
        return x;

    if (x < t->x)
    {
        if (!(t->l) || t->l->Max < x)
            return t->x;
        else
            return GetNext(t->l, x);
    }

    if (x > t->x)
        return GetNext(t->r, x);
}

int rnd()
{
    return ((rand() << 16) ^ rand());
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    Tree *root = 0;
    int N;
    scanf("%d\n", &N);
    char last = ' ';
    LL lastr = 0;

    for (int i = 0; i < N; i++)
    {
        char x;
        LL a;
        scanf("%c %lld\n", &x, &a);
        if (x == '+')
        {
            if (last != '?')
                root = Insert(root, a, rnd());
            else
                root = Insert(root, (a + lastr) % 1000000000, rnd());
        }
        if (x == '?')
        {
            lastr = GetNext(root, a);
            printf("%lld\n", lastr);
        }
        last = x;
    }
    return 0;
}
