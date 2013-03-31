#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 40
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int StrToInt(string a)
{
    int res = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] >= '0' && a[i] <= '9')
            res = res * 10 + a[i] - '0';
    return res;
}

char a[10][10];

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'P')
            {
                if (i > 0 && a[i - 1][j] == 'W')
                    ans++, a[i - 1][j] = '.';
                if (j > 0 && a[i][j - 1] == 'W')
                    ans++, a[i][j - 1] = '.';
                if (i < n - 1 && a[i + 1][j] == 'W')
                    ans++, a[i + 1][j] = '.';
                if (j < m - 1 && a[i][j + 1] == 'W')
                    ans++, a[i][j + 1] = '.';
            }
    cout << ans << endl;
    return 0;
}
