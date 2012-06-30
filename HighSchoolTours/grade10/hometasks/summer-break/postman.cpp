#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;

const char *infile = "postman.in";
const char *outfile = "postman.out";
const int nmax = 1001;
const int mmax = 100100;

int N, top;
int ans[mmax];
int step[nmax];
int m[nmax][nmax];

stack<int> St;

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &step[i]);
        int a;
        double w;
        for (int j = 0; j < step[i]; j++)
        {
            scanf("%d%lf", &a, &w);
            m[i][a]++;
        }
    }

    int start = 1;
    for (int i = 1; i <= N; i++)
        if (step[i] % 2 == 1)
            start = i;

    St.push(start);
    while (!St.empty())
    {
        int v = St.top();
        if (step[v] == 0)
        {
            top++;
            ans[top] = v;
            St.pop();
        }
        else
        {
            int j = 1;
            while (!m[v][j])
                j++;
            step[v]--;
            step[j]--;
            m[v][j]--;
            m[j][v]--;
            St.push(j);
        }
    }
    printf("%d\n", top - 1);
    for (int i = top; i > 1; i--)
        printf("%d ", ans[i]);
    printf("%d\n", ans[1]);
    return 0;
}
