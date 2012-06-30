#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPD(i, n) for (int i = (n)-1; i >= 0; i--)
#define pb push_back
#define Inf 1000000000
#define LMAX 100000
#define NMAX 55

const char *infile = "divan.dat";
const char *outfile = "divan.sol";

const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

struct Mblia
{
    int x, y, pos; //(pos == 1 ->> gorisontal) (pos == 0 ->> vertical)
};

int N, len;
Mblia s, f;
char pole[NMAX][NMAX];
int A[NMAX][NMAX];
int ans[NMAX][NMAX][2];
string Ans;
Mblia queue[LMAX];
int head, tail;

void GetPos(char wh, Mblia &a)
{
    a.x = a.y = 0;
    len = 1;
    a.pos = 1;
    while (pole[a.x][a.y] != wh)
        a.y += (a.x + 1) / N, a.x = (a.x + 1) % N;
    if (a.x + 1 < N && pole[a.x + 1][a.y] == wh)
    {
        a.pos = 0;
        while (a.x + len < N && pole[a.x + len][a.y] == wh)
            len++;
        a.x += len / 2;
    }
    else if (a.y + 1 < N && pole[a.x][a.y + 1] == wh)
    {
        while (a.y + len < N && pole[a.x][a.y + len] == wh)
            len++;
        a.y += len / 2;
    }
}

bool in_rect(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}

int sum_rect(Mblia l, Mblia r)
{
    int sum = A[r.x][r.y];
    if (l.x)
        sum -= A[l.x - 1][r.y];
    if (l.y)
        sum -= A[r.x][l.y - 1];
    if (l.x && l.y)
        sum += A[l.x - 1][l.y - 1];
    return sum;
}

bool can_rotate(Mblia po)
{
    Mblia l, r;
    l.x = po.x - len / 2;
    l.y = po.y - len / 2;
    r.x = po.x + len / 2;
    r.y = po.y + len / 2;
    if (!in_rect(l.x, l.y) || !in_rect(r.x, r.y))
        return false;
    return (sum_rect(l, r) == 0);
}

int main()
{
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    scanf("%d", &N);
    REP(i, N)
    scanf("%s", &pole[i]);
    REP(i, N)
    REP(j, N)
    {
        A[i][j] = pole[i][j] == '1';
        if (i)
            A[i][j] += A[i - 1][j];
        if (j)
            A[i][j] += A[i][j - 1];
        if (i && j)
            A[i][j] -= A[i - 1][j - 1];
        ans[i][j][0] = ans[i][j][1] = Inf;
    }
    GetPos('B', s);
    GetPos('E', f);
    queue[0] = s;
    ans[s.x][s.y][s.pos] = 0;
    tail = 1;
    while (head != tail)
    {
        Mblia cur = queue[head];
        head = (head + 1) % LMAX;
        if (can_rotate(cur))
            if (ans[cur.x][cur.y][cur.pos ^ 1] > ans[cur.x][cur.y][cur.pos] + 1)
            {
                ans[cur.x][cur.y][cur.pos ^ 1] = ans[cur.x][cur.y][cur.pos] + 1;
                queue[tail] = cur;
                queue[tail].pos ^= 1;
                tail = (tail + 1) % LMAX;
            }
        REP(k, 4)
        {
            Mblia l, r;
            l.x = r.x = cur.x + mx[k];
            l.y = r.y = cur.y + my[k];
            if (cur.pos == 1)
                l.y -= len / 2, r.y += len / 2;
            else
                l.x -= len / 2, r.x += len / 2;
            if (in_rect(l.x, l.y) && in_rect(r.x, r.y) && sum_rect(l, r) == 0)
                if (ans[cur.x + mx[k]][cur.y + my[k]][cur.pos] > ans[cur.x][cur.y][cur.pos] + 1)
                {
                    ans[cur.x + mx[k]][cur.y + my[k]][cur.pos] = ans[cur.x][cur.y][cur.pos] + 1;
                    queue[tail].x = cur.x + mx[k];
                    queue[tail].y = cur.y + my[k];
                    queue[tail].pos = cur.pos;
                    tail = (tail + 1) % LMAX;
                }
        }
    }
    if (ans[f.x][f.y][f.pos] == Inf)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n", ans[f.x][f.y][f.pos]);
    Ans = "";
    while (f.x != s.x || f.y != s.y || f.pos != s.pos)
    {
        int cc = ans[f.x][f.y][f.pos];
        if (ans[f.x][f.y][f.pos ^ 1] == cc - 1 && can_rotate(f))
        {
            Ans.pb('T');
            f.pos ^= 1;
        }
        else if (f.x && ans[f.x - 1][f.y][f.pos] == cc - 1)
        {
            Ans.pb('D');
            f.x--;
        }
        else if (f.y && ans[f.x][f.y - 1][f.pos] == cc - 1)
        {
            Ans.pb('R');
            f.y--;
        }
        else if (f.x + 1 < N && ans[f.x + 1][f.y][f.pos] == cc - 1)
        {
            Ans.pb('U');
            f.x++;
        }
        else
        {
            Ans.pb('L');
            f.y++;
        }
    }
    REPD(i, Ans.length())
    printf("%c\n", Ans[i]);
    return 0;
}
