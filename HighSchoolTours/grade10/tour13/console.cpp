#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <cstring>
#define nmax 80000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct tmas
{
    int next[260];
    int father, count, link;
};

char s[260];
tmas ver[nmax + 1];
int queue[nmax + 1];

int main()
{
    freopen("console.in", "r", stdin);
    freopen("console.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    memset(ver, 0, sizeof(ver));
    int top = 0;
    For(i, 1, n)
    {
        gets(s);
        int nom = 0;
        For(j, 0, strlen(s) - 1) if (ver[nom].next[s[j]] != 0) nom = ver[nom].next[s[j]];
        else
        {
            top++;
            ver[nom].next[s[j]] = top;
            ver[top].father = nom;
            nom = top;
        }
        ver[nom].count = 1;
    }
    int head = 2, tail = 2;
    memset(queue, 0, sizeof(queue));
    For(i, 1, 255) if (ver[0].next[i] != 0)
    {
        queue[tail] = ver[0].next[i];
        tail++;
        ver[ver[0].next[i]].link = ver[0].next[i];
    }
    while (head < tail)
    {
        int v = queue[head];
        head++;
        For(i, 1, 255) if (i != 10 && i != 13)
        {
            if (ver[v].next[i] != 0)
            {
                queue[tail] = ver[v].next[i];
                tail++;
                ver[ver[v].next[i]].link = ver[ver[v].link].next[i];
            }
            else
                ver[v].next[i] = ver[ver[v].link].next[i];
        }
    }
    while (!feof(stdin))
    {
        memset(s, 0, sizeof(s));
        gets(s);
        int nom = 0;
        bool fl = false;
        int len = strlen(s);
        if (len != 0)
            For(i, 0, strlen(s) - 1)
            {
                nom = ver[nom].next[s[i]];
                if (ver[nom].count > 0)
                    fl = true;
            }
        if (fl)
            printf("%s\n", s);
    }
    return 0;
}
