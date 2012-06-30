#include <fstream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define finish 123456780
#define NMAX 200000

ifstream fin("eight.dat");
ofstream fout("eight.sol");

struct tq
{
    int from, pos, wh0, cnt, prev;
};

inline void nEl(tq &a, int f, int p, int w, int c, int pr)
{
    a.cnt = c;
    a.from = f;
    a.pos = p;
    a.prev = pr;
    a.wh0 = w;
}

int step[10];

int getC(int cur, int pos)
{
    return (cur / step[pos]) % 10;
}

int npos(int cur, int j, int i)
{
    return (cur + getC(cur, i) * (step[j] - step[i]));
}

map<int, bool> MAP;
tq queue[NMAX];
int Ans[NMAX];
int head, tail, Cnt;

int main()
{
    step[0] = 1;
    FOR(i, 1, 9)
    step[i] = step[i - 1] * 10;
    REP(i, 9)
    {
        int a;
        fin >> a;
        if (!a)
            queue[0].wh0 = 8 - i;
        queue[0].pos = queue[0].pos * 10 + a;
    }
    MAP[queue[0].pos] = true;
    tail = 1;
    while (head != tail)
    {
        tq curr = queue[head];
        if (curr.pos == finish)
        {
            fout << curr.cnt << endl;
            int xx = head;
            while (xx)
            {
                Ans[Cnt++] = queue[xx].from;
                xx = queue[xx].prev;
            }
            REP(i, Cnt)
            {
                fout << Ans[Cnt - 1 - i];
                if (i == Cnt - 1)
                    fout << endl;
                else
                    fout << " ";
            }
            return 0;
        }
        if (curr.wh0 - 3 >= 0)
        {
            int nn = npos(curr.pos, curr.wh0, curr.wh0 - 3);
            if (!MAP[nn])
            {
                MAP[nn] = true;
                nEl(queue[tail++], getC(curr.pos, curr.wh0 - 3), nn, curr.wh0 - 3, curr.cnt + 1, head);
            }
        }
        if (curr.wh0 + 3 < 9)
        {
            int nn = npos(curr.pos, curr.wh0, curr.wh0 + 3);
            if (!MAP[nn])
            {
                MAP[nn] = true;
                nEl(queue[tail++], getC(curr.pos, curr.wh0 + 3), nn, curr.wh0 + 3, curr.cnt + 1, head);
            }
        }
        if (curr.wh0 % 3 > 0)
        {
            int nn = npos(curr.pos, curr.wh0, curr.wh0 - 1);
            if (!MAP[nn])
            {
                MAP[nn] = true;
                nEl(queue[tail++], getC(curr.pos, curr.wh0 - 1), nn, curr.wh0 - 1, curr.cnt + 1, head);
            }
        }
        if (curr.wh0 % 3 < 2)
        {
            int nn = npos(curr.pos, curr.wh0, curr.wh0 + 1);
            if (!MAP[nn])
            {
                MAP[nn] = true;
                nEl(queue[tail++], getC(curr.pos, curr.wh0 + 1), nn, curr.wh0 + 1, curr.cnt + 1, head);
            }
        }
        head++;
    }
    fout << -1 << endl;
    return 0;
}
