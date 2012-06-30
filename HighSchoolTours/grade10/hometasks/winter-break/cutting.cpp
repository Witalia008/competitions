#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <cstring>
#include <set>
#define nmax 50000
#define MP(a, b) make_pair(a, b)
#define For(i, a, b) for (int i = a; i <= b; i++)
//make bigger stack than stack, which we have

using namespace std;

struct tlist
{
    int dest, next;
};

tlist list[nmax * 4 + 1];
int head[nmax + 1], part[nmax + 1];
bool used[nmax + 1];
set<pair<int, int>> s;
int en, top, n, m, k;

void add(int u, int v)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
}

void dfs(int i)
{
    used[i] = true;
    part[i] = top;
    int j = head[i];
    while (j)
    {
        if (!used[list[j].dest] && s.find(MP(i, list[j].dest)) == s.end() && s.find(MP(list[j].dest, i)) == s.end())
            dfs(list[j].dest);
        j = list[j].next;
    }
}

int main()
{
    freopen("cutting.in", "r", stdin);
    freopen("cutting.out", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    en = 0;
    memset(head, 0, sizeof(head));
    For(i, 1, m)
    {
        int si, fi;
        scanf("%d%d\n", &si, &fi);
        add(si, fi);
        add(fi, si);
    }
    s.clear();
    top = 0;
    memset(used, 0, sizeof(used));
    For(i, 1, n) if (!used[i])
    {
        top++;
        dfs(i);
    }
    For(i, 1, k)
    {
        char a[10];
        scanf("%[a-z]", &a);
        int si, fi;
        scanf("%d%d\n", &si, &fi);
        if (a[0] == 'c')
            s.insert(MP(si, fi));
        else
        {
            if (si == fi)
                printf("YES\n");
            else
            {
                memset(used, 0, sizeof(used));
                top++;
                dfs(fi);
                if (part[si] == part[fi])
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
