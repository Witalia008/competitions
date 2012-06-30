#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define CLR(a, x) memset(a, x, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define MP make_pair
#define Inf 1000000000
#define NMAX 1005

const char *infile = "sum.in";
const char *outfile = "sum.out";

typedef long long LL;

int get_rand()
{
    return (rand() << 16) | rand();
}

struct tree
{
    int x, y;
    LL sum;
    tree *l, *r;
    tree() {}
    tree(int n) : sum(n), x(n), y(get_rand()), l(0), r(0) {}
    void update()
    {
        sum = x;
        if (l)
            sum += l->sum;
        if (r)
            sum += r->sum;
    }
};
typedef tree *ptree;

void split(ptree t, int key, ptree &l, ptree &r)
{
    if (!t)
        l = r = 0;
    else if (key < t->x)
        split(t->l, key, l, t->l), r = t;
    else
        split(t->r, key, t->r, r), l = t;
    if (l)
        l->update();
    if (r)
        r->update();
}

void merge(ptree &t, ptree l, ptree r)
{
    if (!l || !r)
        t = (l ? l : r);
    else if (l->y > r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    if (t)
        t->update();
}

bool find(ptree t, int x)
{
    if (!t)
        return false;
    if (t->x == x)
        return true;
    return find(x < t->x ? t->l : t->r, x);
}

void insert(ptree &t, ptree it)
{
    if (!t)
        t = it;
    else if (t->y < it->y)
        split(t, it->x, it->l, it->r), t = it;
    else
        insert(it->x < t->x ? t->l : t->r, it);
    if (t)
        t->update();
}

LL GetSum(ptree &t, int kl, int kr)
{
    ptree l, r;
    split(t, kl - 1, l, t);
    split(t, kr, t, r);
    LL ans = 0;
    if (t)
        ans = t->sum;
    merge(t, l, t);
    merge(t, t, r);
    return ans;
}

ptree root;
LL la;
int N, a, l, r;
char wh, prev;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d\n", &N);
    prev = '+';
    REP(i, N)
    {
        scanf("%c", &wh);
        if (wh == '+')
        {
            scanf("%d\n", &a);
            if (prev == '?')
                a = (a + la) % Inf;
            if (!find(root, a))
                insert(root, new tree(a));
        }
        else
        {
            scanf("%d%d\n", &l, &r);
            la = GetSum(root, l, r);
            printf("%I64d\n", la);
        }
        prev = wh;
    }
    return 0;
}
