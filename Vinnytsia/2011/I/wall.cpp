#include <stdio.h>
#include <cstdlib>

using namespace std;

int N, M, K;
int lost, cou, have, cur;

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    lost = cou = cur = have = 0;
    while (cur < M)
    {
        cur++;
        if (have < N)
        {
            cou++;
            lost += have;
            have = K;
        }
        have -= N;
    }
    lost += have;
    printf("%d %d\n", cou, lost);
    return 0;
}
