#include <stdio.h>
#include <cstdlib>

#pragma comment(linker, "/STACK:64000000")

using namespace std;

const char *infile = "combination.in";
const char *outfile = "combination.out";

#define n_max 50000
#define m_max 64

int N, D;
int go[n_max][m_max];
int firstM[n_max], secondM[n_max], used[n_max];
int count, sum;

bool kuhn(int v)
{
    if (used[v] == count)
        return false;
    used[v] = count;

    for (int j = 0; j < D; j++)
    {
        int to = go[v][j];
        if (secondM[to] == -1 || kuhn(secondM[to]))
        {
            secondM[to] = v;
            firstM[v] = to;
            return true;
        }
    }

    return false;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < D; j++)
        {
            scanf("%d", &go[i][j]);
            go[i][j]--;
        }

    for (int i = 0; i < N; i++)
        firstM[i] = secondM[i] = -1;

    while (sum != N)
    {
        count++;
        for (int i = 0; i < N; i++)
            if (firstM[i] == -1 && used[i] != count)
                if (kuhn(i))
                    sum++;
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", firstM[i] + 1);
    return 0;
}
