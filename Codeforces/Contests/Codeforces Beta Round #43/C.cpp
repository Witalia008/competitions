#include <stdio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    char a[10001];
    int n;
    scanf("%d\n", &n);
    int ans = 10000;
    scanf("%s", &a);
    int l = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 'T')
            l++;
    for (int i = 0; i < n; i++)
    {
        int cou = 0;
        int j = i, k = 0;
        while (k < l)
        {
            int nom = j + k;
            if (nom >= n)
                nom -= n;
            if (a[nom] == 'H')
                cou++;
            k++;
        }
        if (cou < ans)
            ans = cou;
    }
    printf("%d\n", ans);
    return 0;
}
