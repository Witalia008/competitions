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
#define N 1005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;

struct mstr
{
    string s;
};

struct func
{
    string name;
    int cnt;
    mstr param[5];
};

struct var
{
    string name, type;
};

int n, m, k;
func A[N], cur;
var B[N];
string s;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        while (s[0] == ' ')
            s.erase(0, 1);
        s.erase(0, 4);
        while (s[0] == ' ')
            s.erase(0, 1);
        while (s[0] != '(' && s[0] != ' ')
        {
            A[i].name += s[0];
            s.erase(0, 1);
        }
        while (s[0] == ' ' || s[0] == '(')
            s.erase(0, 1);
        while (s != "")
        {
            while (s[0] != ',' && s[0] != ')' && s[0] != ' ')
            {
                A[i].param[A[i].cnt].s += s[0];
                s.erase(0, 1);
            }
            A[i].cnt++;
            while (s != "" && (s[0] == ' ' || s[0] == ')' || s[0] == ','))
                s.erase(0, 1);
        }
    }
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++)
        cin >> B[i].type >> B[i].name;
    scanf("%d\n", &k);
    for (int i = 0; i < k; i++)
    {
        cur.name = "";
        cur.cnt = 0;
        for (int j = 0; j < 5; j++)
            cur.param[j].s = "";
        getline(cin, s);
        while (s[0] == ' ')
            s.erase(0, 1);
        while (s[0] != ' ' && s[0] != '(')
            cur.name += s[0], s.erase(0, 1);
        while (s[0] == ' ' || s[0] == '(')
            s.erase(0, 1);
        while (s != "")
        {
            while (s[0] != ',' && s[0] != ')' && s[0] != ' ')
                cur.param[cur.cnt].s += s[0], s.erase(0, 1);
            while (s != "" && (s[0] == ',' || s[0] == ')' || s[0] == ' '))
                s.erase(0, 1);
            cur.cnt++;
        }
        for (int j = 0; j < cur.cnt; j++)
            for (int l = 0; l < m; l++)
                if (cur.param[j].s == B[l].name)
                {
                    cur.param[j].s = B[l].type;
                    break;
                }
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            bool fl = cur.name == A[j].name;
            if (cur.cnt != A[j].cnt)
                fl = false;
            else
            {
                for (int l = 0; l < cur.cnt; l++)
                    if (!(cur.param[l].s == A[j].param[l].s || A[j].param[l].s == "T"))
                        fl = false;
            }
            if (fl)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
