#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "hard_test.in";
const char *outfile = "hard_test.out";

int N, M, cur, MM;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &M);

    cur = 1;
    MM = 1000000;
    while (M)
    {
        printf("%d %d 0\n", cur, cur + 1);
        M--;
        for (int i = cur + 2; (i <= N) && (M > 0); i++)
        {
            printf("%d %d %d\n", cur, i, MM);
            M--;
        }
        cur++;
        MM--;
    }

    return 0;
}
