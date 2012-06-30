#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "longpath.in";
const char *outfile = "longpath.out";

#define nmax 22

int n, m, Ans;
bool A[nmax][nmax];
int ans[nmax], st[nmax];

void search(int last, int mask, int cou)
{
    st[cou - 1] = last;
    if (cou > Ans)
    {
        Ans = cou;
        for (int i = 0; i < cou; i++)
            ans[i] = st[i];
    }
    for (int i = 0; i < n; i++)
        if (A[last][i] && !(mask & (1 << i)))
            search(i, (mask | (1 << i)), cou + 1);
}

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
