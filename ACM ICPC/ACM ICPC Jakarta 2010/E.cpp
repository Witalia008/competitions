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

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) FOR(i,0,n-1)
#define CLR(a,x) memset(a,x,sizeof(a))
#define min(a,b) (a < b) ? a : b;
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 1000000007
#define N 50005

typedef long double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;

int Abs(int a) {if (a < 0) return -a; else return a;}

struct TList
{
   int dest, next;
};

int n, m, en;
TList List[N*2];
int Head[N];
int C[N];
int anc[N][20];
int deph[N];
bool used[N];

void Add (int u, int v)
{
   en++;
   List[en].dest = v;
   List[en].next = Head[u];
   Head[u] = en;
}

void dfs (int v, int p = -1)
{
   used[v] = true;
   deph[v] = (p == -1) ? 0 : deph[p] + 1;
   anc[v][0] = (p == -1) ? v : p;
   for (int i = 1; i < 20; i++)
       anc[v][i] = anc[anc[v][i-1]][i-1];
   for (int j = Head[v]; j; j = List[j].next)
       if (!used[List[j].dest])
           dfs (List[j].dest, v);
}

int lca (int a, int b)
{
   if (deph[a] > deph[b]) swap (a, b);
   for (int i = 19; i >= 0; i--)
       if (deph[anc[b][i]] >= deph[a])
           b = anc[b][i];
   if (a == b) return a;
   for (int i = 19; i >= 0; i--)
       if (anc[a][i] != anc[b][i])
           a = anc[a][i], b = anc[b][i];
   return anc[a][0];
}

void dfs1 (int v)
{
   used[v] = true;
   for (int j = Head[v]; j; j = List[j].next)
       if (!used[List[j].dest])
       {
           dfs1 (List[j].dest);
           C[v] += C[List[j].dest];
       }
}

int main ()
{
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
   int T;
   scanf ("%d", &T);
   REP(t, T)
   {
       en = 0;
       CLR(Head, 0);
       CLR(anc, 0);
       CLR(C, 0);
       CLR(used, 0);
       CLR(deph, 0);
       CLR(List, 0);
       scanf ("%d", &n);
       FOR(i, 1, n - 1)
       {
           int a, b;
           scanf ("%d%d", &a, &b);
           a++; b++;
           Add (a, b);
           Add (b, a);
       }
       dfs (1);
       scanf ("%d", &m);
       REP(i, m)
       {
           int a, b, c;
           scanf ("%d%d%d", &a, &b, &c);
           a++; b++;
           int x = lca (a, b);
           C[a] += c; C[b] += c;
           C[x] -= c;
           if (anc[x][0] != x)
               C[anc[x][0]] -= c;
       }
       CLR(used, 0);
       dfs1 (1);
       printf ("Case #%d:\n", t + 1);
       FOR(i, 1, n)
           printf ("%d\n", C[i]);
   }
   return 0;
}
