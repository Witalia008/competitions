#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define pb push_back
#define mp make_pair
#define Inf 1000000000
#define N 2005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

struct tx
{
    string name;
    int bal, gi, go, cc;
};

int cnt = 0;
tx A[4];

void add(string s, int cou, int in, int ou)
{
    int pos = cnt;
    for (int i = 0; i < cnt; i++)
        if (A[i].name == s)
            pos = i;
    A[pos].name = s;
    A[pos].bal += cou;
    A[pos].gi += in;
    A[pos].go += ou;
    A[pos].cc++;
    if (pos == cnt)
        cnt++;
}

bool comp(tx a, tx b)
{
    if (a.bal > b.bal)
        return true;
    if (a.bal < b.bal)
        return false;
    if (a.gi - a.go > b.gi - b.go)
        return true;
    if (a.gi - a.go < b.gi - b.go)
        return false;
    if (a.gi > b.gi)
        return true;
    if (a.gi < b.gi)
        return false;
    return a.name < b.name;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    for (int i = 0; i < 5; i++)
    {
        string a, b;
        int ga, gb;
        cin >> a >> b;
        scanf("%d:%d\n", &ga, &gb);
        if (ga == gb)
        {
            add(a, 1, ga, gb);
            add(b, 1, gb, ga);
        }
        if (ga > gb)
        {
            add(a, 3, ga, gb);
            add(b, 0, gb, ga);
        }
        if (ga < gb)
        {
            add(b, 3, gb, ga);
            add(a, 0, ga, gb);
        }
    }
    string opposite = "";
    for (int i = 0; i < 4; i++)
        if (A[i].cc == 2 && A[i].name != "BERLAND")
            opposite = A[i].name;
    int ax, ay;
    ax = ay = -1;
    for (int X = 0; X <= 100; X++)
        for (int Y = 0; Y < X; Y++)
        {
            add("BERLAND", 3, X, Y);
            add(opposite, 0, Y, X);
            sort(A, A + 4, &comp);
            int pl = 0;
            for (int i = 0; i < 4; i++)
                if (A[i].name == "BERLAND")
                    pl = i;
            if (pl == 0 || pl == 1)
            {
                if (ax == -1)
                    ax = X, ay = Y;
                else
                {
                    if (X - Y < ax - ay)
                        ax = X, ay = Y;
                    else if (X - Y == ax - ay)
                        if (Y < ay)
                            ax = X, ay = Y;
                }
            }
            add("BERLAND", -3, -X, -Y);
            add(opposite, 0, -Y, -X);
        }
    if (ax == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << ax << ":" << ay << endl;
    return 0;
}
