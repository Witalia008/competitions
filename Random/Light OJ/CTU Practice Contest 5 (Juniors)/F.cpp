#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#include <math.h>

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

double sq(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int cnt[26];

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    int T;
    scanf("%d\n", &T);
    REP(t, T)
    {
        printf("Case %d: ", t + 1);
        string a, b;
        REP(i, 26)
        cnt[i] = 0;
        getline(cin, a);
        getline(cin, b);
        REP(i, a.length())
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
                a[i] += 'a' - 'A';
            if (a[i] != ' ')
                cnt[a[i] - 'a']++;
        }
        REP(i, b.length())
        {
            if (b[i] >= 'A' && b[i] <= 'Z')
                b[i] += 'a' - 'A';
            if (b[i] != ' ')
                cnt[b[i] - 'a']--;
        }
        bool fl = true;
        REP(i, 26)
        if (cnt[i] != 0)
            fl = false;
        if (fl)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
