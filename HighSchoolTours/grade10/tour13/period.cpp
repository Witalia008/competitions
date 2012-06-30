#include <stdio.h>
#include <cstdlib>
#include <cstring>
#define nmax 1000001
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

char s[nmax];
int p[nmax];

int main()
{
    freopen("period.in", "r", stdin);
    freopen("period.out", "w", stdout);
    gets(s);
    p[0] = 0;
    int k = 0;
    For(i, 1, strlen(s) - 1)
    {
        while (k > 0 && s[k] != s[i])
            k = p[k - 1];
        if (s[k] == s[i])
            k++;
        p[i] = k;
    }
    int n = strlen(s) - 1;
    int ans = n + 1;
    while (k > 0)
    {
        if (k * 2 >= n + 1)
            ans = k;
        n = k - 1;
        k = p[n];
    }
    printf("%d\n", ans);
    return 0;
}
