#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define NMAX 1000005

const char *infile = "centipede.dat";
const char *outfile = "centipede.sol";

struct TList
{
    int dest, next;
};

int N, en, top, v, to, ans;
TList List[NMAX * 2];
bool used[NMAX];
int sons[NMAX], Head[NMAX], stack[NMAX], Last[NMAX];
int F[NMAX], G[NMAX];

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
    Last[u] = Head[u];
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    REP(i, N - 1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
    }
    stack[top = 1] = 1;
    used[1] = true;
    while (top)
    {
        v = stack[top];
        while (used[List[Last[v]].dest])
            Last[v] = List[Last[v]].next;
        to = Last[v];
        if (to)
        {
            stack[++top] = List[to].dest;
            used[List[to].dest] = true;
            Last[v] = List[to].next;
            sons[v]++;
        }
        else
        {
            if (!sons[v])
                F[v] = G[v] = 1;
            else
            {
                int max1, max2;
                max1 = max2 = 0;
                for (to = Head[v]; to; to = List[to].next)
                {
                    int cnt = F[List[to].dest];
                    F[v] = max(F[v], cnt);
                    if (cnt >= max1)
                        max2 = max1, max1 = cnt;
                    else if (cnt > max2)
                        max2 = cnt;
                }
                F[v] += sons[v];
                G[v] = F[v];
                if (sons[v] > 1)
                    G[v] = max1 + max2 + sons[v] - 1;
                if (top > 1)
                    G[v]++;
            }
            top--;
            ans = max(ans, G[v]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
