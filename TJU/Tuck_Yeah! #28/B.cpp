#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 1000005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

struct tree
{
    int x, y, cnt;
    string str;
    tree *l, *r;
    tree() {}
    tree(int _x, string _s) : x(_x), y(rand() << 16 | rand()), str(_s), l(0), r(0), cnt(1) {}
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

void merge(ptree &t, ptree l, ptree r)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->y > r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    if (t)
        t->upd_cnt();
}

void split(ptree t, int key, ptree &l, ptree &r)
{
    if (!t)
        l = r = 0;
    else if (key < t->x)
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
    else if (it->y > t->y)
        split(t, it->x, it->l, it->r), t = it;
    else
        insert(it->x < t->x ? t->l : t->r, it);
    t->upd_cnt();
}

void remove(ptree &t, ptree it)
{
    if (!t)
        return;
    if (t->x == it->x)
        merge(t, t->l, t->r);
    else
        remove(it->x < t->x ? t->l : t->r, it);
    if (t)
        t->upd_cnt();
}

ptree get(ptree t, int k)
{
    if (!t)
        return 0;
    if (t->l && k <= t->l->cnt)
        return get(t->l, k);
    if (k == 1 + (t->l ? t->l->cnt : 0))
        return t;
    return get(t->r, k - 1 - (t->l ? t->l->cnt : 0));
}

int cnt;
string s, ss;
ptree root, item;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    getline(cin, s);
    while (s != "0")
    {
        while (s != "")
        {
            while (s != "" && !(s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z' || s[0] >= '0' && s[0] <= '9'))
            {
                printf("%c", s[0]);
                s.erase(0, 1);
            }
            if (s != "" && s[0] >= '0' && s[0] <= '9')
            {
                int n = 0;
                while (s != "" && s[0] >= '0' && s[0] <= '9')
                {
                    n = n * 10 + s[0] - '0';
                    s.erase(0, 1);
                }
                item = get(root, n);
                cout << item->str;
                remove(root, item);
                cnt--;
                item = new tree(cnt, item->str);
                insert(root, item);
            }
            else if (s != "" && (s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z'))
            {
                ss = "";
                while (s != "" && (s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z'))
                    ss += s[0], s.erase(0, 1);
                cnt--;
                insert(root, new tree(cnt, ss));
                cout << ss;
            }
        }
        printf("\n");
        getline(cin, s);
    }
    return 0;
}
