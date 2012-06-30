#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#define mod 1000000007

using namespace std;

long long f[1000][1000];
char s[1000];

int main()
{
    FILE *fi = fopen("recover.in", "r");
    FILE *fo = fopen("recover.out", "w");
    int n;
    n = 1;
    fscanf(fi, "%c", &s[1]);
    while (!feof(fi))
    {
        n++;
        fscanf(fi, "%c", &s[n]);
    }
    n--;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
        {
            switch (s[i + 1])
            {
            case '?':
                f[j + 1][i + 1] += f[j][i];
                if (j - 1 >= 0)
                    f[j - 1][i + 1] += f[j][i];
                break;
            case '(':
                f[j + 1][i + 1] += f[j][i];
                break;
            case ')':
                if (j - 1 >= 0)
                    f[j - 1][i + 1] += f[j][i];
                break;
            }
            f[j][i] = f[j][i] % mod;
        }
    fprintf(fo, "%lld\n", f[0][n]);
    fclose(fi);
    fclose(fo);
    return 0;
}
