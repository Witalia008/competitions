#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "longpath.in";
const char *outfile = "longpath.out";

#define nmax 22

int n, m, Ans;
bool A[nmax][nmax];
bool used[nmax];
int ans[nmax], st[nmax];

void search(int last, int mask, int cou)
{
    used[last] = true;
    st[cou - 1] = last;
    if (cou > Ans)
    {
        Ans = cou;
        for (int i = 0; i < cou; i++)
            ans[i] = st[i];
    }
    for (int i = 0; i < n; i++)
        if (A[last][i] && !(mask & (1 << i)) && !used[i])
            search(i, (mask | (1 << i)), cou + 1);
    used[last] = false;
}

/*
int F[nmax][1<<nmax];
for (int i = 0; i < n; i++)
    F[i][1<<i] = 1;
for (int mask = 0; mask < 1<<n; mask++)
{
    for (int i = 0; i < n; i++)
        if ((mask>>i)%2 && F[i][mask])
        {
            for (int j = 0; j < n; j++)
                if (A[i][j] && !(mask>>j)%2)
                    F[j][mask|1<<j] = 1;
        }
}
ans = 0;
for (int last = 0; last < n; ++last)
    for (int mask = 0; mask < 1<<n; ++mask)
    {
        if (F[last][mask])
            if (couones(mask) > ans)
                ans = couones (mask);
    }
cout << ans;
*/

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        A[a][b] = true;
    }
    Ans = 0;
    for (int i = 0; i < n; i++)
        search(i, (1 << i), 1);
    printf("%d\n", Ans - 1);
    for (int i = 0; i < Ans - 1; i++)
        printf("%d ", ans[i] + 1);
    printf("%d\n", ans[Ans - 1] + 1);
    return 0;
}
