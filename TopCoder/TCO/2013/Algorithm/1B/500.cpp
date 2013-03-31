#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int ans = 15;

struct varr
{
    int sum, i1, j1, i2, j2;
};

bool cmp(varr a, varr b)
{
    return a.sum > b.sum || a.sum == b.sum && a.i1 < b.i1;
}

int count(vector<string> &a, int i1, int i2, int j1, int j2)
{
    int res = 0;
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            res += a[i][j] == 'X';
    return res;
}

void find(vector<string> &a, int r, int c, int Cur)
{
    if (Cur > ans)
        return;
    vector<varr> pos;
    pos.clear();
    for (int i = 0; i + r <= a.size() || !i; i++)
    {
        varr cc;
        cc.i1 = i;
        cc.i2 = min(a.size() - 1, i + r - 1);
        cc.j1 = 0;
        cc.j2 = a[0].size() - 1;
        cc.sum = count(a, cc.i1, cc.i2, cc.j1, cc.j2);
        if (cc.sum)
            pos.push_back(cc);
    }
    for (int j = 0; j + c <= a[0].size() || !j; j++)
    {
        varr cc;
        cc.i1 = 0;
        cc.i2 = a.size() - 1;
        cc.j1 = j;
        cc.j2 = min(j + c - 1, a[0].size() - 1);
        cc.sum = count(a, cc.i1, cc.i2, cc.j1, cc.j2);
        if (cc.sum)
            pos.push_back(cc);
    }
    if (pos.size() == 0)
    {
        if (Cur < ans)
            ans = Cur;
        return;
    }
    if (Cur == ans)
        return;
    sort(pos.begin(), pos.end(), &cmp);
    vector<string> b;
    int xx = (rand() % 3 == 1);
    for (int k = 0; k < pos.size() && k < 2 + xx; k++)
    {
        varr cur = pos[k];
        b = a;
        for (int i = cur.i1; i <= cur.i2; i++)
            for (int j = cur.j1; j <= cur.j2; j++)
                b[i][j] = '.';
        find(b, r, c, Cur + 1);
    }
}

class EllysFigurines
{
public:
    int getMoves(vector<string> board, int R, int C)
    {
        ans = min(ans, (board.size() + R - 1) / R);
        ans = min(ans, (board[0].size() + C - 1) / C);
        find(board, R, C, 0);
        return ans;
    }
};
