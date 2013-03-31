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

typedef long long ll;

int main()
{
    //freopen (infile, "r", stdin); freopen (outfile, "w", stdout);
    int N;
    scanf("%d\n", &N);
    int ans = 0;
    REP(i, N)
    {
        string s;
        getline(cin, s);
        while (s[s.length() - 1] < '0' || s[s.length() - 1] > '9')
            s.erase(s.length() - 1, 1);
        int pos = s.length() - 1;
        while (pos && s[pos - 1] >= '0' && s[pos - 1] <= '9')
            pos--;
        bool flag = true;
        int c8, c5, c3;
        c8 = c5 = c3 = 0;
        FOR(j, pos, s.length() - 1)
        {
            if (s[j] == '8')
                c8++;
            else if (s[j] == '5')
                c5++;
            else if (s[j] == '3')
                c3++;
            else
                flag = false;
        }
        if (!(c8 >= c5 && c5 >= c3))
            flag = false;
        if (flag)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
