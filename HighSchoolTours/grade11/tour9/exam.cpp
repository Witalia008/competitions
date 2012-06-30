#include <stdio.h>
#include <cstdlib>
#include <memory.h>

using namespace std;

const char *infile = "exam.dat";
const char *outfile = "exam.sol";
const int nmax = 51;
const int mmax = nmax * nmax;

struct TList
{
    int dest, next;
};

TList List[mmax];
bool wh[nmax], used[nmax], in_ans[nmax];
int Head[nmax], Mt[nmax];
int N, M, en;

bool try_kuhn(int v)
{
    if (used[v])
        return false;
    used[v] = true;
    int j = Head[v];
    while (j)
    {
        if (Mt[List[j].dest] == -1 || try_kuhn(Mt[List[j].dest]))
        {
            Mt[List[j].dest] = v;
            return true;
        }
        j = List[j].next;
    }
    return false;
}

bool update(int v, int s)
{
    if (used[v])
        return false;
    used[v] = true;
    int j = Head[v];
    while (j)
    {
        int to = 0;
        if (wh[v])
            to = Mt[List[j].dest];
        else
        {
            for (to = 1; to <= N; to++)
                if (Mt[to] == List[j].dest)
                    break;
        }
        if (update(to, s))
        {
            if (wh[v])
                Mt[List[j].dest] = v;
            else
            {
                Mt[v] = List[j].dest;
            }
            return true;
        }
        j = List[j].next;
    }
    if (v >= s)
    {
        Mt[v] = -1 - (v == s);
        return true;
    }
    else
        return false;
}

void Add(int u, int v)
{
    en++;
    List[en].dest = v;
    List[en].next = Head[u];
    Head[u] = en;
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        Add(a, b);
        Add(b, a);
        wh[a] = 1;
    }

    memset(Mt, -1, sizeof(Mt));
    memset(in_ans, 0, sizeof(in_ans));
    for (int i = 1; i <= N; i++)
        if (wh[i])
        {
            memset(used, 0, sizeof(used));
            try_kuhn(i);
        }

    while (true)
    {
        memset(in_ans, 0, sizeof(in_ans));
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= N; i++)
            if (Mt[i] != -1)
                in_ans[i] = in_ans[Mt[i]] = true;
        int ss = 1;
        while (ss <= N && (in_ans[ss] || Mt[ss] == -2))
            ss++;
        if (ss > N)
            break;
        if (!update(ss, ss))
            break;
    }
    int last = N;
    while (!in_ans[last] || Mt[last] == -2)
        last--;
    for (int i = 1; i <= N; i++)
        if (in_ans[i] && Mt[i] != -2)
        {
            printf("%d", i);
            if (i == last)
                printf("\n");
            else
                printf(" ");
        }
    return 0;
}
