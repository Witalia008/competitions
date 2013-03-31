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
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-6
#define Inf 1000000000
#define Mi 1000000007
#define N 1005

typedef double ld;
typedef long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<double, char> pdc;

int min (int a, int b) {if (a < b) return a; return b;}
int Abs(int a) {if (a < 0) return -a; else return a;}
int sqr (int a) {return a*a;}

#define debug
int main ()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 2 < s.length() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
        {
            s.erase(i, 2);
            s[i] = ' ';
        }
    }
    while (s[0] == ' ') s.erase(0, 1);
    while (s[s.length()-1] == ' ') s.erase (s.length()-1, 1);
    for (int i = 0; i < s.length(); i++)
        while (i + 1 < s.length() && s[i] == ' ' && s[i+1] == ' ')
            s.erase(i, 1);
    cout << s << endl;
    return 0;
}
