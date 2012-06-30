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
#define N 60005

typedef double ld;
typedef long long ll;
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

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int n;
    cin >> n;
    int ans = 0, cnt = 0;
    REP(i, n)
    {
        string s;
        cin >> s;
        int h, m;
        string r = "";
        while (s[s.length() - 1] != '.')
        {
            r += s[s.length() - 1];
            s.erase(s.length() - 1, 1);
        }
        if (r == "iva" || r == "vkm")
        {
            scanf("%d:%d", &h, &m);
            cnt++;
            ans += h * 60 + m;
        }
    }
    printf("%d %d:%02d:%02d\n", cnt, ans / (60 * 24), (ans % (60 * 24)) / 60, ans % 60);
    return 0;
}
