#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)

ll Abs(ll a)
{
    if (a < 0)
        return -a;
    return a;
}

ll get_rand()
{
    return (rand() << 16) | rand();
}

struct tree
{
    tree *l, *r;
    ll x, y;
    tree() {}
    tree(ll _x) : x(_x), y(get_rand()), l(0), r(0) {}
};
typedef tree *ptree;

void split(ptree t, ll key, ptree &l, ptree &r)
{
    if (!t)
        l = r = 0;
    else
    {
        if (key < t->x)
            split(t->l, key, l, t->l), r = t;
        else
            split(t->r, key, t->r, r), l = t;
    }
}

void merge(ptree &t, ptree l, ptree r)
{
    if (!l || !r)
        t = (l ? l : r);
    else
    {
        if (l->y > r->y)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
    }
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
            insert(it->x < t->x ? t->l : t->r, it);
    }
}

ll lower_bound(ptree t, ll key)
{
    if (!t)
        return 0;
    if (t->x == key)
        return key;
    if (key > t->x)
        return lower_bound(t->r, key);
    ll res = lower_bound(t->l, key);
    if (!res)
        res = t->x;
    return res;
}

ll upper_bound(ptree t, ll key)
{
    if (!t)
        return 0;
    if (t->x == key)
        return key;
    if (key < t->x)
        return upper_bound(t->l, key);
    ll res = upper_bound(t->r, key);
    if (!res)
        res = t->x;
    return res;
}

void replace(ptree &t, ll key, ll nkey)
{
    if (!t)
        return;
    if (t->x == key)
        t->x = nkey;
    else
        replace(key < t->x ? t->l : t->r, key, nkey);
}

ptree root;
ll N, M, a, ans;

int main()
{
    freopen("courier.dat", "r", stdin);
    freopen("courier.sol", "w", stdout);
    scanf("%d%d", &N, &M);
    REP(i, N)
    {
        scanf("%d", &a);
        insert(root, new tree(a));
    }
    ans = 0;
    REP(i, M)
    {
        scanf("%d", &a);
        ll l = upper_bound(root, a), r = lower_bound(root, a);
        ll pos;
        if (!l || !r)
            pos = (l ? l : r);
        else if (a - l > r - a)
            pos = r;
        else
            pos = l;
        ans += Abs(a - pos);
        replace(root, pos, a);
    }
    cout << ans << endl;
    return 0;
}
