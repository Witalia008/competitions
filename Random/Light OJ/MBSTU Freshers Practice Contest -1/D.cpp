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
#define N 105

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

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    string s;
    getline(cin, s);
    while (s != "")
    {
        int cons = 0, vov = 0;
        while (s != "")
        {
            while (s != "" && !(s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z'))
            {
                printf("%c", s[0]);
                s.erase(0, 1);
            }
            if (s != "")
            {
                char q = s[0];
                if (q >= 'A' && q <= 'Z')
                    q += 'a' - 'A';
                s.erase(0, 1);
                if (q == 'a' || q == 'o' || q == 'i' || q == 'u' || q == 'y' || q == 'e')
                {
                    vov++;
                    printf("*");
                }
                else
                {
                    cons++;
                    printf("#");
                }
                while (s != "" && (s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z'))
                {
                    printf("%c", s[0]);
                    s.erase(0, 1);
                }
            }
        }
        printf("\n");
        printf("Number of * is: %d.\n", vov);
        printf("Number of # is: %d.\n\n", cons);
        getline(cin, s);
    }
    return 0;
}
