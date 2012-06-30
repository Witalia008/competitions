#include <stdio.h>
#include <cstdlib>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define Inf 1000000000
#define M 100000
#define N 55

const int mx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int my[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct pt
{
    int x, y;
};

int A[N][N], pole[N][N], from[N][N];
bool Ans[N][N], Cur[N][N], used[N][N], vis[N][N];
pt queue[M];
int n, m, ans, head, tail;
pt cur, a, b;

pt npt(int x, int y)
{
    pt r;
    r.x = x;
    r.y = y;
    return r;
}

bool in_rect(pt c)
{
    return (c.x > 0 && c.y > 0 && c.x <= n && c.y <= m);
}

bool dfs(pt v, pt f)
{
    used[v.x][v.y] = true;
    if (v.x == f.x && v.y == f.y)
        return true;
    REP(k, 4)
    {
        pt to = npt(v.x + mx[k], v.y + my[k]);
        if (in_rect(to))
            if (!used[to.x][to.y] && !Cur[to.x][to.y])
                if (dfs(to, f))
                    return true;
    }
    return false;
}

void search(pt s, pt f)
{
    if (A[s.x][s.y] != 1 && A[s.x][s.y] != -1)
        return;
    FOR(i, 1, n)
    FOR(j, 1, m) pole[i][j] = Inf,
                 from[i][j] = 0;
    queue[head = 0] = s;
    pole[s.x][s.y] = (A[s.x][s.y] == 1);
    tail = 1;
    while (head != tail)
    {
        pt cur = queue[head];
        REP(k, 8)
        {
            pt to = npt(cur.x + mx[k], cur.y + my[k]);
            if (in_rect(to))
                if (A[to.x][to.y] == 1 || A[to.x][to.y] == -1)
                    if (pole[to.x][to.y] > pole[cur.x][cur.y] + (A[to.x][to.y] == 1))
                    {
                        queue[tail++] = to;
                        from[to.x][to.y] = head;
                        pole[to.x][to.y] = pole[cur.x][cur.y] + (A[to.x][to.y] == 1);
                    }
        }
        head++;
    }
    if (pole[f.x][f.y] < ans)
    {
        int cur = pole[f.x][f.y];
        FOR(i, 1, n)
        FOR(j, 1, m) Cur[i][j] = 0;
        Cur[f.x][f.y] = true;
        int xx = from[f.x][f.y];
        while (xx)
        {
            Cur[queue[xx].x][queue[xx].y] = true;
            xx = from[queue[xx].x][queue[xx].y];
        }
        Cur[s.x][s.y] = true;
        FOR(i, 1, n)
        FOR(j, 1, m) used[i][j] = false;
        if (!dfs(a, b))
        {
            ans = cur;
            FOR(i, 1, n)
            FOR(j, 1, m) Ans[i][j] = Cur[i][j];
        }
    }
}

bool bfs(pt v, pt s, int cnt)
{
    Cur[v.x][v.y] = true;
    vis[v.x][v.y] = true;
    REP(k, 8)
    {
        pt to = npt(v.x + mx[k], v.y + my[k]);
        if (in_rect(to))
            if (!vis[to.x][to.y])
            {
                if (A[to.x][to.y] == 1 || A[to.x][to.y] == -1)
                    if (bfs(to, s, cnt + (A[to.x][to.y] == 1)))
                    {
                        Ans[v.x][v.y] = true;
                        Cur[v.x][v.y] = false;
                        return true;
                    }
            }
            else if (to.x == s.x && to.y == s.y)
            {
                if (cnt < ans)
                {
                    FOR(i1, 1, n)
                    FOR(j1, 1, m) used[i1][j1] = false;
                    if (!dfs(a, b))
                    {
                        ans = cnt;
                        Ans[v.x][v.y] = true;
                        Cur[v.x][v.y] = false;
                        return true;
                    }
                }
            }
    }
    Cur[v.x][v.y] = false;
    return false;
}

int main()
{
    freopen("greatwall.dat", "r", stdin);
    freopen("greatwall.sol", "w", stdout);
    scanf("%d%d", &n, &m);
    int k, l;
    scanf("%d%d", &k, &l);
    REP(i, k)
    {
        scanf("%d%d", &cur.x, &cur.y);
        A[cur.x][cur.y] = -1;
    }
    REP(i, l)
    {
        scanf("%d%d", &cur.x, &cur.y);
        A[cur.x][cur.y] = 1;
    }
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);
    ans = Inf;
    FOR(i, 1, n)
    FOR(j, 1, m)
    {
        search(npt(i, 1), npt(1, j));
        search(npt(i, m), npt(1, j));
        search(npt(i, 1), npt(n, j));
        search(npt(i, m), npt(n, j));
    }
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        search(npt(i, 1), npt(j, m));
        search(npt(i, 1), npt(j, 1));
        search(npt(i, m), npt(j, m));
    }
    FOR(i, 1, m)
    FOR(j, 1, m)
    {
        search(npt(1, i), npt(n, j));
        search(npt(1, i), npt(1, j));
        search(npt(n, i), npt(n, j));
    }
    FOR(i, 1, n)
    FOR(j, 1, m)
    if (A[i][j] == 1 && !vis[i][j])
    {
        FOR(i1, 1, n)
        FOR(j1, 1, m) Cur[i1][j1] = false;
        bfs(npt(i, j), npt(i, j), 1);
    }
    if (ans == Inf)
        printf("-1\n");
    else
    {
        ans = 0;
        FOR(i, 1, n)
        FOR(j, 1, m)
        if (Ans[i][j] && A[i][j] == 1)
            ans++;
        printf("%d\n", ans);
        FOR(i, 1, n)
        FOR(j, 1, m)
        if (Ans[i][j] && A[i][j] == 1)
            printf("%d %d\n", i, j);
    }
    return 0;
}
