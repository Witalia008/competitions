#include <stdio.h>
#include <cstdlib>
#include <map>

using namespace std;

typedef unsigned long long ULL;

const char *infile = "input.txt";
const char *outfile = "output.txt";

#define t_max 12
#define n_max 15

int N, T;
int cards[t_max][n_max];
int A[t_max];

map<ULL, int> DP;

int search(ULL curPos, int cou)
{
    if (!cou)
        return 0;
    if (DP.find(curPos) != DP.end())
        return DP[curPos];

    bool fl = true;
    ULL nextPos = 0;
    int Max = 0;

    for (int i = 0; i < T && fl; i++)
        if (A[i])
        {
            for (int j = i + 1; j < T && fl; j++)
                if (A[j] && cards[i][A[i] - 1] + cards[j][A[j] - 1] == N + 1)
                {
                    A[i]--;
                    A[j]--;

                    for (int k = 0; k < T; k++)
                        nextPos = (nextPos << 4) | A[k];

                    Max = max(Max, search(nextPos, cou - 2) + 2);
                    if (Max == cou)
                        fl = false;

                    A[i]++;
                    A[j]++;
                }
        }

    DP[curPos] = Max;
    return Max;
}

ULL curPos;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);

    scanf("%d%d", &N, &T);

    for (int i = 0; i < T; i++)
    {
        int cnt = (4 * N) / T;
        if ((4 * N) % T > i)
            cnt++;
        A[i] = cnt;

        curPos = (curPos << 4) | cnt;

        for (int j = 0; j < cnt; j++)
            scanf("%d%*c", &cards[i][j]);
    }

    printf("%d\n", search(curPos, 4 * N));
    return 0;
}
