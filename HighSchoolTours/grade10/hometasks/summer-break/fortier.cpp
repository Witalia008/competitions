#include <stdio.h>
#include <cstdlib>

using namespace std;

const char *infile = "input.txt";
const char *outfile = "output.txt";
const int nmax = 1000101;

struct TList
{
    int dest, next;
};

int N, en, ans, top, g, j, i, a, b, v, maxson1, maxson2, sons;
bool used[nmax];
int f[nmax], Head[nmax], p[nmax], St[nmax];
TList List[nmax * 2];

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (i = 1; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
    }

    top = 1;
    St[1] = 1;
    used[1] = true;
    while (top > 0)
    {
        v = St[top];
        j = Head[v];
        while (j > 0 && used[List[j].dest])
            j = List[j].next;
        if (j != 0)
        {
            used[List[j].dest] = true;
            p[List[j].dest] = v;
            top++;
            St[top] = List[j].dest;
        }
        else
        {
            j = Head[v];
            maxson1 = 0;
            maxson2 = 0;
            sons = 0;
            while (j != 0)
            {
                if (List[j].dest != p[v])
                {
                    sons++;
                    if (f[List[j].dest] > maxson1)
                    {
                        maxson2 = maxson1;
                        maxson1 = f[List[j].dest];
                    }
                    else if (f[List[j].dest] > maxson2)
                        maxson2 = f[List[j].dest];
                }
                j = List[j].next;
            }
            f[v] = sons + maxson1;
            if (sons == 0)
                f[v] = 1;
            if (sons > 1)
                g = f[v] - 1 + maxson2;
            else
                g = f[v];
            if (p[v] != 0)
                g++;
            if (g > ans)
                ans = g;
            top--;
        }
    }

    printf("%d\n", ans);
    return 0;
}
