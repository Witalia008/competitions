#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

struct Tree
{
    Tree *l, *r;
    int x, y, cnt;

    Tree(int xx, int yy)
    {
        x = xx;
        y = yy;
        cnt = 1;
        l = r = 0;
    }

    void update_cnt()
    {
        cnt = 1;
        if (l)
            cnt += l->cnt;
        if (r)
            cnt += r->cnt;
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
        l->update_cnt();
        return l;
    }
    else
    {
        r->l = Merge(l, r->l);
        r->update_cnt();
        return r;
    }
}

void Split(Tree *t, int x, Tree *&l, Tree *&r)
{
    if (!t)
    {
        l = r = 0;
        return;
    }

    int Cnt = 0;
    if (t->l)
        Cnt = t->l->cnt;
    if (x <= Cnt)
    {
        Split(t->l, x, l, t->l);
        r = t;
    }
    else
    {
        Split(t->r, x - Cnt - 1, t->r, r);
        l = t;
    }

    t->update_cnt();
}

Tree *Insert(Tree *t, int x, int y)
{
    if (!t)
        return new Tree(x, y);

    if (y < t->y)
    {
        if (x < t->x)
            t->l = Insert(t->l, x, y);
        else
            t->r = Insert(t->r, x, y);

        t->update_cnt();
        return t;
    }
    else
    {
        Tree *p = new Tree(x, y);
        Split(t, x, p->l, p->r);

        p->update_cnt();
        return p;
    }
}

void printTree(Tree *t, bool turnleft)
{
    if (!t)
        return;
    printTree(t->l, true);
    printf("%d", t->x);
    if (turnleft == false && t->r == 0)
        printf("\n");
    else
        printf(" ");
    printTree(t->r, turnleft);
}

int rnd()
{
    return ((rand() << 16) ^ rand());
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    int N, K;
    scanf("%d%d", &N, &K);

    Tree *root = 0;
    int l, r;
    for (int i = 1; i <= N; i++)
        root = Insert(root, i, rnd());

    for (int i = 0; i < K; i++)
    {
        Tree *a, *b, *c;
        scanf("%d%d", &l, &r);
        Split(root, r, b, c);
        Split(b, l - 1, a, b);

        root = Merge(Merge(b, a), c);
    }

    printTree(root, false);
    return 0;
}
