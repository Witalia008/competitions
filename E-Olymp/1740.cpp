#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";

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
#define NMAX 101

typedef pair<int, int> PII;
typedef unsigned long long LL;

struct Func
{
    int len;
    string a;
};

string s;
int N;
Func F[NMAX][NMAX];
Func ans;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    cin >> s;
    N = s.length();
    REP(i, N)
    {
        F[i][1].len = 1;
        F[i][1].a = s[i];
    }
    ans = F[0][1];
    FOR(l, 2, N)
    REP(i, N - l + 1)
    {
        if (s[i] == s[i + l - 1])
            if (F[i][l].len < F[i + 1][l - 2].len + 2)
            {
                F[i][l].len = F[i + 1][l - 2].len + 2;
                F[i][l].a = s[i] + F[i + 1][l - 2].a + s[i + l - 1];
            }
        if (F[i][l - 1].len > F[i][l].len)
            F[i][l] = F[i][l - 1];
        if (F[i + 1][l - 1].len > F[i][l].len)
            F[i][l] = F[i + 1][l - 1];
        if (F[i][l].len > ans.len)
            ans = F[i][l];
    }
    cout << ans.len << endl;
    cout << ans.a << endl;
    return 0;
}
