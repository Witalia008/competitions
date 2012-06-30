#include <stdio.h>
#include <cstdlib>

//#pragma comment (linker, "/STACK:200000000")

using namespace std;

const char *infile = "swapper.in";
const char *outfile = "swapper.out";

typedef long long LL;

struct Tree
{
    Tree *l, *r;
    int x, y, cnt;
    LL sum;
    Tree(int xx, int yy)
    {
        x = xx;
        y = yy;
        l = r = 0;
        cnt = 1;
        sum = x;
    }
    void update_cnt()
    {
        cnt = 1;
        if (l)
            cnt += l->cnt;
        if (r)
            cnt += r->cnt;
    }
    void update_sum()
    {
        sum = x;
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};

Tree *Merge(Tree *l, Tree *r)
{
    if (!l)
        return r;
    if (!r)
        return l;

    if (l->y > r->y)
    {
        l->r = Merge(l->r, r);
        l->update_cnt();
        l->update_sum();
        return l;
    }
    else
    {
        r->l = Merge(l, r->l);
        r->update_cnt();
        r->update_sum();
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
        Cnt += t->l->cnt;

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
    t->update_sum();
}

Tree *Insert(Tree *t, int x, int y)
{
    if (!t)
        return new Tree(x, y);

    if (y < t->y)
    {
        t->r = Insert(t->r, x, y);

        t->update_cnt();
        t->update_sum();
        return t;
    }
    else
    {
        Tree *p = new Tree(x, y);
        p->l = t;

        p->update_cnt();
        p->update_sum();
        return p;
    }
}

LL Sum(Tree *t, int l, int r)
{
    if (!t)
        return 0;
    if (l <= 1 && r >= t->cnt)
        return t->sum;

    int Cnt = 0;
    if (t->l)
        Cnt = t->l->cnt;

    if (r <= Cnt)
        return Sum(t->l, l, r);

    if (l > Cnt + 1)
        return Sum(t->r, l - Cnt - 1, r - Cnt - 1);

    return Sum(t->l, l, Cnt) + t->x + Sum(t->r, 1, r - Cnt - 1);
}

LL rnd()
{
    return ((rand() << 30) ^ rand());
}

int N, M;
Tree *odd, *notodd, *oa, *ob, *oc, *noa, *nob, *noc;
int I, a, b, nom;
LL ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &M);
    nom = 1;
    while (N)
    {
        odd = 0;
        notodd = 0;
        if (nom != 1)
            printf("\n");
        printf("Swapper %d:\n", nom);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &I);
            if (!(i & 1))
                odd = Insert(odd, I, rnd());
            else
                notodd = Insert(notodd, I, rnd());
        }

        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &I, &a, &b);

            if (I == 1)
            {
                Split(odd, (b + 1) / 2, ob, oc);
                Split(ob, a / 2, oa, ob);

                Split(notodd, b / 2, nob, noc);
                Split(nob, (a - 1) / 2, noa, nob);

                odd = Merge(Merge(oa, nob), oc);
                notodd = Merge(Merge(noa, ob), noc);
            }
            else
            {
                printf("%lld\n", Sum(odd, a / 2 + 1, (b + 1) / 2) + Sum(notodd, (a + 1) / 2, b / 2));
            }
        }

        scanf("%d%d", &N, &M);
        nom++;
    }
    return 0;
}
