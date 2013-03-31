#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 2001
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

int p[nmax];

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cou = 1;
        int j = i;
        while (p[j] != -1)
            j = p[j], cou++;
        if (cou > ans)
            ans = cou;
    }
    printf("%d\n", ans);
    return 0;
}
