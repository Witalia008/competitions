#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "spoon.in";
const char *outfile = "spoon.out";

#define NMAX 105

int t, c, r;
char a[NMAX][NMAX];

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++)
    {
        scanf("%d%d\n", &r, &c);
        for (int i = 0; i < r; i++)
            scanf("%s\n", &a[i]);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (a[i][j] >= 'A' && a[i][j] <= 'Z')
                    a[i][j] += 'a' - 'A';
        bool flag = false;
        if (c > 4)
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c - 4; j++)
                    if (a[i][j] == 's' && a[i][j + 1] == 'p' && a[i][j + 2] == 'o' && a[i][j + 3] == 'o' && a[i][j + 4] == 'n')
                        flag = true;
        if (r > 4)
            for (int j = 0; j < c; j++)
                for (int i = 0; i < r - 4; i++)
                    if (a[i][j] == 's' && a[i + 1][j] == 'p' && a[i + 2][j] == 'o' && a[i + 3][j] == 'o' && a[i + 4][j] == 'n')
                        flag = true;
        if (flag)
            printf("There is a spoon!\n");
        else
            printf("There is indeed no spoon!\n");
    }
    return 0;
}
