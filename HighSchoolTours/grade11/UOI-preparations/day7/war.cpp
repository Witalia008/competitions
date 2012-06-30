#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define N 5005
#define M 200

int n;
bool is[M];
int G[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    FOR(i, 2, n)
    {
        REP(j, M)
        is[j] = false;
        FOR(j, 1, (i + 1) / 2)
        is[G[j - 1] ^ G[i - j]] = true;
        while (is[G[i]])
            G[i]++;
    }
    if (!G[n])
        printf("Mueller\n");
    else
    {
        printf("Schtirlitz\n");
        FOR(i, 1, n)
        if (!(G[i - 1] ^ G[n - i]))
            printf("%d\n", i);
    }
    return 0;
}
