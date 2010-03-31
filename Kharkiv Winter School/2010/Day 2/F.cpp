#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

struct Tree
{
    Tree *l, *r;
    int cnt, x, y;
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

    if (x < t->x)
    {
        Split(t->l, x, l, t->l);
        r = t;
    }
    else
    {
        Split(t->r, x, t->r, r);
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

Tree *Remove(Tree *t, int x)
{
    //if (!t)
    //assert(false);

    if (t->x == x)
    {
        Tree *p = Merge(t->l, t->r);
        delete t;
        return p;
    }

    if (x < t->x)
        t->l = Remove(t->l, x);
    else
        t->r = Remove(t->r, x);

    t->update_cnt();

    return t;
}

int KthMax(Tree *t, int k)
{
    //assert(t != 0 && t -> cnt >= k);

    int CNT;
    if (t->r == 0)
        CNT = 0;
    else
        CNT = t->r->cnt;

    if (CNT >= k)
        return KthMax(t->r, k);

    if (CNT + 1 == k)
        return t->x;

    return KthMax(t->l, k - CNT - 1);
}

int rnd()
{
    return ((rand() << 16) ^ rand());
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    int N;
    scanf("%d", &N);

    Tree *root = 0;
    int k, t;

    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &k, &t);
        switch (k)
        {
        case 1:
            root = Insert(root, t, rnd());
            break;
        case 0:
            printf("%d\n", KthMax(root, t));
            break;
        case -1:
            root = Remove(root, t);
            break;
        }
    }
    return 0;
}
