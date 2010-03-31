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
#include <queue>
#include <stack>

using namespace std;

#define For(i,a,b,d) for (int i = (a); i != (b); i += d)
#define FORD(i,a,b) for (int i = (a); i >= b; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,n) for (int i = (n - 1); i >= 0; i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define CLR(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 105
//#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<double, char> pdc;

int min (int a, int b) {if (a < b) return a; return b;}
int Abs(int a) {if (a < 0) return -a; else return a;}
ld Abs (ld a) {if (a < 0) return -a; else return a;}
ll sqr (ll a) {return a*a;}
ld sqr (ld a) {return a*a;}

struct code
{
   string inp, out, key;
   void findKey (int l)
   {
       key = "";
       REP(i, l)
       {
           if (out[i] >= inp[i])
               key += 'A' + out[i] - inp[i];
           else
               key += ('Z' - inp[i] + out[i] - 'A' + 1) % 26 + 'A';
       }
   }
   bool isValidKey (string kkey)
   {
       string res = "";
       REP(i, inp.length())
           if (i < kkey.length())
               res += 'A' + (kkey[i] + inp[i]) % 26;
           else
               res += 'A' + (inp[i] + res[i - kkey.length()]) % 26;
       return res == out;
   }
};

bool comp (code a, code b)
{
   return a.inp.length() > b.inp.length();
}

int n;
code S[N];

//#define ONLINE_JUDGE
int main ()
{
   #ifndef ONLINE_JUDGE
       freopen ("input.txt", "r", stdin);
       freopen ("output.txt", "w", stdout);
   #endif
   cin >> n;
   while (n)
   {
       REP(i, n)
           cin >> S[i].inp >> S[i].out;
       sort (S, S + n, &comp);
       int ans = N;
       FOR(l, 1, 101)
       {
           S[0].findKey(l);
           bool fl = S[0].isValidKey(S[0].key);
           FOR(i, 1, n - 1)
           {
               if (!S[i].isValidKey(S[0].key)) fl = false;
               if (!fl) break;
           }
           if (fl)
           {
               ans = l;
               break;
           }
       }
       if (ans == N)
           cout << "Impossible" << endl;
       else
           cout << S[0].key << endl;
       cin >> n;
   }
   return 0;
}
