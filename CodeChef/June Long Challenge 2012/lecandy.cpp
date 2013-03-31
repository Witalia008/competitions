#include <stdio.h>
#include <cstdlib>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++)
    {
        int n, c;
        int sum = 0;
        scanf("%d%d", &n, &c);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            sum += a;
        }
        if (sum <= c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
