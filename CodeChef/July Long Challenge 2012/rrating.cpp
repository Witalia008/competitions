#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 100005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct tree
{
    int x, y, cnt;
    tree *l, *r;
    tree() {}
    tree(int _x) : x(_x), y(rand() << 16 | rand()), l(0), r(0) {}
    void upd_cnt()
    {
        cnt = 1;
        if (l)
            cnt += l->cnt;
        if (r)
            cnt += r->cnt;
    }
};
typedef tree *ptree;

void split(ptree t, int key, ptree &l, ptree &r)
{
    if (!t)
        l = r = 0;
    else if (key > t->x)
        split(t->l, key, l, t->l), r = t;
    else
        split(t->r, key, t->r, r), l = t;
    if (l)
        l->upd_cnt();
    if (r)
        r->upd_cnt();
}

void insert(ptree &t, ptree it)
{
    if (!t)
        t = it;
    else
    {
        if (it->y > t->y)
            split(t, it->x, it->l, it->r), t = it;
        else
            insert(it->x > t->x ? t->l : t->r, it);
    }
    t->upd_cnt();
}

int kth(ptree t, int k)
{
    if (t->l && k <= t->l->cnt)
        return kth(t->l, k);
    if (k == (t->l ? t->l->cnt : 0) + 1)
        return t->x;
    return kth(t->r, k - (t->l ? t->l->cnt : 0) - 1);
}

ptree root;
int n, m;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &m);
    REP(i, m)
    {
        int q;
        scanf("%d", &q);
        if (q == 1)
        {
            int x;
            scanf("%d", &x);
            insert(root, new tree(x));
            n++;
        }
        else
        {
            int k = n / 3;
            if (!k)
                printf("No reviews yet\n");
            else
                printf("%d\n", kth(root, k));
        }
    }
    return 0;
}
