#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>

using namespace std;

typedef unsigned long long ull;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 1000005

int k, n, cnt;
ull ans = 10000000000000000000;
bool prime[N];
ull pr[200][105];

void search(int pos, int maxs, ull cur, ull cou)
{
    if ((cou + 1) / 2 == k)
        ans = cur;
    if ((cou + 1) / 2 >= k)
        return;
    for (int i = 1; i <= maxs; i++)
        if ((cou * (i + 1) + 1) / 2 <= k && cur * ull(pr[pos][i]) < ans)
            search(pos + 1, i, cur * ull(pr[pos][i]), cou * (i + 1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &k);
    memset(prime, 1, sizeof(prime));
    for (int i = 2; i <= 1000; i++)
        if (prime[i])
        {
            pr[cnt++][1] = i;
            int j = i * i;
            while (j < N)
                prime[j] = false, j += i;
        }
    for (int i = 0; i < cnt; i++)
        for (int j = 2; j < 105; j++)
            pr[i][j] = pr[i][j - 1] * pr[i][1];
    search(0, 47, 1, 1);
    cout << ans << endl;
    return 0;
}
