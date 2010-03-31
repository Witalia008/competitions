#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define CLR(a, x) memset(a, x, sizeof(a))
#define min(a, b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 1000005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

string s;
set<string> S1, S2;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    REP(t, T)
    {
        S1.clear();
        S2.clear();
        REP(i, 26)
        {
            cin >> s;
            if (s[0] == 'T')
                s[0] = '0' + 10;
            if (s[0] == 'J')
                s[0] = '0' + 11;
            if (s[0] == 'Q')
                s[0] = '0' + 12;
            if (s[0] == 'K')
                s[0] = '0' + 13;
            if (s[0] == 'A')
                s[0] = '0' + 14;
            if (s[1] == 'D')
                s[1] = '0';
            if (s[1] == 'C')
                s[1] = '1';
            if (s[1] == 'H')
                s[1] = '2';
            if (s[1] == 'S')
                s[1] = '3';
            S1.insert(s);
        }
        int cnt = 0;
        for (set<string>::iterator it = S1.begin(); it != S1.end(); it++)
        {
            s = *it;
            string s1 = "20", ans = "";
            while (true)
            {
                if (s1 < s && S1.find(s1) == S1.end() && S2.find(s1) == S2.end())
                    ans = s1;
                s1[1]++;
                if (s1[1] == '4')
                    s1[0]++, s1[1] = '0';
                if (s1[0] == '0' + 15)
                    break;
            }
            if (ans != "")
            {
                cnt++;
                S2.insert(ans);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
