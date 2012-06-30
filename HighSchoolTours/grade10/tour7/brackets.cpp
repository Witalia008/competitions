#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

char a[100000];

int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    memset(a, '0', sizeof(a));
    scanf("%s", &a);
    int n = 0;
    while (a[n + 1] != '0')
        n++;
    n--;
    int bal = 0;
    For(i, 0, n)
    {
        if (a[i] == '(')
            bal++;
        else
            bal--;
    }
    if (bal != 0)
        printf("0\n");
    else
    {
        int I, J;
        J = n;
        I = 0;
        while (I < J)
        {
            if (a[I] == '(')
                bal++;
            else
                bal--;
            if (bal == -1)
            {
                int b = 0;
                while ((b != 1) && (J > I))
                {
                    if (a[J] == ')')
                        b--;
                    else
                        b++;
                    J--;
                }
                bal = 0;
            }
            I++;
        }
        bal = 0;
        int ans = 0;
        For(i, J + 1, n)
        {
            if (a[i] == '(')
                bal++;
            else
                bal--;
            if (bal == 0)
                ans++;
        }
        For(i, 0, J)
        {
            if (a[i] == '(')
                bal++;
            else
                bal--;
            if (bal == 0)
                ans++;
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
