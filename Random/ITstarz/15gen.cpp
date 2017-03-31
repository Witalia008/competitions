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
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
//#include <assert.h>

using namespace std;

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define debug(x) cout << #x << "=" << x << endl;
#define Abs(a) (a < 0) ? (-(a)) : (a)
#define sqr(a) ((a) * (a))
#define pb push_back
#define mp make_pair

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

const int Inf = 1000000000;
const int Mi = 1000000009;
const int N = 5005;
const int K = 1000;
const ld eps = 10e-6;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);
;

struct Trie
{
    int num;
    Trie *next[26];
    Trie *root;
    Trie()
    {
        num = -1;
        CLR(next, 0);
        root = 0;
    }
    void add(string s, int n)
    {
        Trie *v = this;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (v->next[c] == NULL)
                v->next[c] = new Trie();
            v = v->next[c];
        }
        v->num = n;
        v->root = this;
    }
};

bool is_palindr(string s)
{
    REP(i, s.size())
    if (s[i] != s[s.size() - 1 - i])
        return false;
    return true;
}

Trie *dict, *rdict;

bool used[N];
bool es[N], er[N];
string ss;

void search(Trie *d, Trie *rd, int posr)
{
    if (!d || !rd)
        return;
    if (d->num != -1 && rd->num != -1 && !used[d->num] && !used[rd->num] && d->num != rd->num && ss.size() + posr >= K)
    {
        if (is_palindr(ss.substr(posr, ss.size() - posr)))
        {
            REP(i, ss.size())
            {
                cout << ss[i];
                if (es[i])
                    cout << " ";
            }
            cout << " ";
            ss = ss.substr(0, posr);
            reverse(ss.begin(), ss.end());
            reverse(er, er + posr);
            REP(i, ss.size())
            {
                if (er[i])
                    cout << " ";
                cout << ss[i];
            }
            cout << "\n";
            reverse(er, er + posr);
            exit(0);
        }
    }
    if (d->num != -1 && !used[d->num])
    {
        if (posr == ss.size())
        {
            used[d->num] = true;
            es[ss.size() - 1] = true;
            search(d->root, rd, posr);
            used[d->num] = false;
            es[ss.size() - 1] = false;
        }
        else
        {
            if (rd->num != -1 && !used[rd->num])
            {
                used[rd->num] = true;
                er[posr - 1] = true;
                search(d, rd->root, posr);
                used[rd->num] = false;
                er[posr - 1] = false;
            }
            int c = ss[posr] - 'a';
            if (rd->next[c])
            {
                search(d, rd->next[c], posr + 1);
            }
        }
    }
    REPD(i, 26)
    if (d->next[i])
    {
        ss += i + 'a';
        search(d->next[i], rd, posr);
        ss.erase(ss.size() - 1, 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    dict = new Trie();
    rdict = new Trie();
    int i = 0;
    for (;;)
    {
        string s = "";
        cin >> s;
        if (s == "")
            break;
        dict->add(s, i);
        reverse(s.begin(), s.end());
        rdict->add(s, i);
        i++;
    }
    ss = "";
    CLR(es, false);
    CLR(er, false);
    search(dict, rdict, 0);
    return 0;
}
