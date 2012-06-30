#include <stdio.h>
#include <cstdlib>
#define nmax 100000
#include <set>
#include <memory.h>

using namespace std;

struct tmas
{
    int next, dest;
    bool used;
};

tmas list[nmax + 100];
int head[nmax + 100], stack[nmax * 10];
int en;
set<int> s;

void add(int u, int v)
{
    en++;
    list[en].dest = v;
    list[en].next = head[u];
    head[u] = en;
}

int main()
{
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n, m;
    memset(list, 0, sizeof(list));
    en = 0;
    s.clear();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    int top = 1;
    bool flag = false;
    stack[1] = 1;
    while (top != 0)
    {
        int v = stack[top];
        s.insert(v);
        int j = head[v];
        while ((j != 0) && (list[j].used))
            j = list[j].next;
        if (j == 0)
        {
            top--;
            s.erase(v);
        }
        else
        {
            if (s.find(list[j].dest) != s.end())
            {
                int i = top;
                while (stack[i] != list[j].dest)
                    i--;
                flag = true;
                printf("YES\n");
                for (int k = i; k < top; k++)
                    printf("%d ", stack[k]);
                printf("%d\n", stack[top]);
                top = 0;
            }
            else
            {
                top++;
                stack[top] = list[j].dest;
                list[j].used = true;
            }
        }
    }
    if (!flag)
        printf("NO\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
