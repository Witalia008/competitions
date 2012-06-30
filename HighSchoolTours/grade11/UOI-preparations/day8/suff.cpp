#include <memory.h>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("suff.in");
ofstream fout("suff.out");

#define LOOP(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) FORD(i, n - 1, 0)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define COPY(a, b) memcpy(b, a, sizeof(a))
#define pb push_back
#define N 100005
#define M 150

int n, cl;
string s;
int p[N], pn[N], c[N], cn[N], cnt[M];

int main()
{
    getline(fin, s);
    s.pb(30);
    n = s.length();

    REP(i, n)
    ++ cnt[s[i]];
    FOR(i, 1, M - 1)
    cnt[i] += cnt[i - 1];
    REP(i, n)
    p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    cl = 1;
    FOR(i, 1, n - 1)
    {
        if (s[p[i]] != s[p[i - 1]])
            ++cl;
        c[p[i]] = cl - 1;
    }

    for (int h = 0; (1 << h) < n; ++h)
    {
        REP(i, n)
        {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        CLR(cnt, 0);
        REP(i, n)
        ++ cnt[c[pn[i]]];
        FOR(i, 1, M - 1)
        cnt[i] += cnt[i - 1];
        REPD(i, n)
        p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        cl = 1;
        FOR(i, 1, n - 1)
        {
            int m1 = (p[i] + (1 << h)) % n, m2 = (p[i - 1] + (1 << h)) % n;
            if (c[p[i]] != c[p[i - 1]] || c[m1] != c[m2])
                ++cl;
            cn[p[i]] = cl - 1;
        }
        COPY(cn, c);
    }
    FOR(i, 1, n - 1)
    {
        fout << p[i] + 1;
        if (i == n - 1)
            fout << endl;
        else
            fout << " ";
    }
    return 0;
}
