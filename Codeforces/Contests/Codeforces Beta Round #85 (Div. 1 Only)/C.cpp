#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 40
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int StrToInt(string a)
{
    int res = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] >= '0' && a[i] <= '9')
            res = res * 10 + a[i] - '0';
    return res;
}

struct TStr
{
    string s;
};

int n, m, ans;
bool used[nmax][nmax];
TStr a[nmax + 1][nmax + 1];

bool good(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void PutCell(int i, int j)
{
    a[i][j].s = "";
    if (good(i, j) && !used[i][j])
        used[i][j] = true, a[i][j].s.push_back('s');
    if (good(i - 1, j) && !used[i - 1][j])
        used[i - 1][j] = true, a[i][j].s.push_back('u');
    if (good(i, j - 1) && !used[i][j - 1])
        used[i][j - 1] = true, a[i][j].s.push_back('l');
    if (good(i + 1, j) && !used[i + 1][j])
        used[i + 1][j] = true, a[i][j].s.push_back('d');
    if (good(i, j + 1) && !used[i][j + 1])
        used[i][j + 1] = true, a[i][j].s.push_back('r');
}

void TakeCell(int i, int j)
{
    for (int c = 0; c < a[i][j].s.length(); c++)
    {
        switch (a[i][j].s[c])
        {
        case 's':
            used[i][j] = false;
            break;
        case 'u':
            used[i - 1][j] = false;
            break;
        case 'l':
            used[i][j - 1] = false;
            break;
        case 'd':
            used[i + 1][j] = false;
            break;
        case 'r':
            used[i][j + 1] = false;
            break;
        }
    }
    a[i][j].s = "";
}

void SearchAns(int i, int j, int curAns)
{
    if (curAns >= ans)
        return;
    while (used[i][j])
    {
        j++;
        if (j == m)
            j = 0, i++;
        if (i == n)
        {
            if (curAns < ans)
                ans = curAns;
            return;
        }
    }
    PutCell(i, j);
    SearchAns(i, j, curAns + 1);
    TakeCell(i, j);
    PutCell(i, j + 1);
    SearchAns(i, j, curAns + 1);
    TakeCell(i, j + 1);
    PutCell(i + 1, j);
    SearchAns(i, j, curAns + 1);
    TakeCell(i + 1, j);
}

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    ans = 40;
    SearchAns(0, 0, 0);
    printf("%d\n", n * m - ans);
    return 0;
}
