#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

long long C[41][41][41][41][2];

int main()
{
    freopen("train-ab.in", "r", stdin);
    freopen("train-ab.out", "w", stdout);
    int n, k;
    scanf("%d%d\n", &n, &k);
    int AA = 0, AB = 0, BA = 0, BB = 0;
    memset(C, 0, sizeof(C));
    char Ll, Lr;
    scanf("%c%c\n", &Ll, &Lr);
    if (Lr == 'A')
        C[0][0][0][0][0] = 1;
    else
        C[0][0][0][0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        char x, y;
        scanf("%c%c\n", &x, &y);
        if (x == 'A' && y == 'A')
            AA++;
        if (x == 'A' && y == 'B')
            AB++;
        if (x == 'B' && y == 'A')
            BA++;
        if (x == 'B' && y == 'B')
            BB++;
    }
    long long ans = 0;
    for (int aa = 0; aa <= AA; aa++)
        for (int ab = 0; ab <= AB; ab++)
            for (int ba = 0; ba <= BA; ba++)
                for (int bb = 0; bb <= BB; bb++)
                {
                    if (aa > 0)
                        C[aa][ab][ba][bb][0] += C[aa - 1][ab][ba][bb][0];
                    if (ba > 0)
                        C[aa][ab][ba][bb][0] += C[aa][ab][ba - 1][bb][1];
                    if (ab > 0)
                        C[aa][ab][ba][bb][1] += C[aa][ab - 1][ba][bb][0];
                    if (bb > 0)
                        C[aa][ab][ba][bb][1] += C[aa][ab][ba][bb - 1][1];
                    if (aa + ab + ba + bb == k)
                    {
                        if (Ll == 'A')
                            ans += C[aa][ab][ba][bb][0];
                        else
                            ans += C[aa][ab][ba][bb][1];
                    }
                }
    if (ans == 0)
        printf("NO\n");
    else
        printf("YES\n");
    if (ans != 0)
        printf("%lld\n", ans);
    return 0;
}
