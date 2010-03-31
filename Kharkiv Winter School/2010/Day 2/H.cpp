#include <stdio.h>
#include <cstdlib>
#include <iostream>

#pragma comment(linker, "/STACK:5000000")

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

typedef long long LL;
typedef pair<int, int> Pii;

#define MP(a, b) make_pair(a, b)

struct Tree
{
    int x, y, cnt, l, r;
    LL sum;
};

int Cou = 0;
Tree tree[100010];

inline int NewTree(int xx, int yy)
{
    Cou++;
    tree[Cou].cnt = 1;
    tree[Cou].l = tree[Cou].r = 0;
    tree[Cou].sum = xx;
    tree[Cou].x = xx;
    tree[Cou].y = yy;
    return Cou;
}

inline void Update(int nom)
{
    tree[nom].cnt = 1 + tree[tree[nom].l].cnt + tree[tree[nom].r].cnt;
    tree[nom].sum = tree[nom].x + tree[tree[nom].l].sum + tree[tree[nom].r].sum;
}

inline int Merge(int l, int r)
{
    if (!l)
        return r;
    if (!r)
        return l;

    if (tree[l].y > tree[r].y)
    {
        tree[l].r = Merge(tree[l].r, r);
        Update(l);
        return l;
    }
    else
    {
        tree[r].l = Merge(l, tree[r].l);
        Update(r);
        return r;
    }
}

inline Pii Split(int t, int x)
{
    if (!t)
        return MP(0, 0);

    Pii a;

    if (x <= tree[tree[t].l].cnt)
    {
        a = Split(tree[t].l, x);
        tree[t].l = a.second;
        Update(t);
        a.second = t;
    }
    else
    {
        a = Split(tree[t].r, x - tree[tree[t].l].cnt - 1);
        tree[t].r = a.first;
        Update(t);
        a.first = t;
    }

    return a;
}

inline int Insert(int t, int x, int y)
{
    if (!t)
        return NewTree(x, y);

    if (y < tree[t].y)
    {
        tree[t].r = Insert(tree[t].r, x, y);

        Update(t);
        return t;
    }
    else
    {
        int p = NewTree(x, y);
        tree[p].l = t;

        Update(p);
        return p;
    }
}

inline LL Sum(int t, int l, int r)
{
    if (!t)
        return 0;
    if (l <= 1 && r >= tree[t].cnt)
        return tree[t].sum;

    int Cnt = tree[tree[t].l].cnt;

    if (r <= Cnt)
        return Sum(tree[t].l, l, r);

    if (l > Cnt + 1)
        return Sum(tree[t].r, l - Cnt - 1, r - Cnt - 1);

    return Sum(tree[t].l, l, Cnt) + tree[t].x + Sum(tree[t].r, 1, r - Cnt - 1);
}

inline LL rnd()
{
    return ((rand() << 30) ^ rand());
}

int N, M;
int odd, notodd;
Pii p1, p2, np1, np2;
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
        Cou = 0;
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
                p2 = Split(odd, (b + 1) / 2);
                p1 = Split(p2.first, a / 2);

                np2 = Split(notodd, b / 2);
                np1 = Split(np2.first, (a - 1) / 2);

                odd = Merge(Merge(p1.first, np1.second), p2.second);
                notodd = Merge(Merge(np1.first, p1.second), np2.second);
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
