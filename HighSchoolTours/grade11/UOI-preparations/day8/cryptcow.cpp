#include <fstream>
#include <string>

using namespace std;

ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define pb push_back

string st = "Begin the Escape execution at the Break of Dawn";

string s;

void fault(int a, int b)
{
    fout << a << " " << b << endl;
    exit(0);
}

void search(string s, int cnt = 0)
{
    if (s == st)
        fault(1, cnt);
    FOR(i, 0, s.length() - 3)
    if (s[i] == 'C')
        FOR(j, i + 1, s.length() - 2)
    if (s[j] == 'O')
        FOR(k, j + 1, s.length() - 1)
    if (s[k] == 'W')
    {
        string s1 = "";
        FOR(c, 0, i - 1)
        s1.pb(s[c]);
        FOR(c, j + 1, k - 1)
        s1.pb(s[c]);
        FOR(c, i + 1, j - 1)
        s1.pb(s[c]);
        FOR(c, k + 1, s.length() - 1)
        s1.pb(s[c]);
        search(s1, cnt + 1);
    }
}

int main()
{
    getline(fin, s);
    search(s);
    fault(0, 0);
    return 0;
}
