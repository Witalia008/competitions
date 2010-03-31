#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) FOR(i,0,n-1)
#define pb push_back
#define mp make_pair
#define Inf 2000000000
#define Mi 2000000
#define N 1005

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
#define eps 10e-7

struct tx
{
    string s;
};

string S, s;
int n1, n2, N1, N2;
int CS[26], cs[26];
tx A[10005], B[10005];

void printAns (int c1, int c2)
{
    if (c1 == c2) printf ("0\n");
    if (c1 < c2) printf ("2\n");
    if (c1 > c2) printf ("1\n");
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> S;
    for (int i = 0; i < S.length(); i++) CS[S[i]-'a']++;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> s;
        for (int j = 0; j < 26; j++) cs[j] = 0;
        for (int j = 0; j < s.length(); ++j)
            cs[s[j]-'a']++;
        bool fl = true;
        for (int j = 0; j < 26; j++)
            if (cs[j] > CS[j])
                fl = false;
        if (fl)
            A[N1++].s = s;
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> s;
        for (int j = 0; j < 26; j++) cs[j] = 0;
        for (int j = 0; j < s.length(); ++j)
            cs[s[j]-'a']++;
        bool fl = true;
        for (int j = 0; j < 26; j++)
            if (cs[j] > CS[j])
                fl = false;
        if (fl)
            B[N2++].s = s;
    }
    int com = 0;
    for (int i = 0; i < N1; i++)
    {
        bool fl = false;
        for (int j = 0; j < N2; j++)
            if (B[j].s == A[i].s)
                fl = true;
        if (fl) com++;
    }
    printAns (N1 - com/2, N2 - (com+1)/2);
    if (N1 - com >= com)
        printAns (N1 - com, N2);
    else {
        int x = N1 - com;
        n1 = com - x;
        int com1 = n1;
        n2 = N2 - x;
        if (x & 1)
            printAns (n1 - (com1+1)/2, n2 - com1/2);
        else
            printAns (n1 - com1/2, n2 - (com1+1)/2);
    }
    if (N2 - com >= com)
        printAns (N1, N2 - com);
    else {
        int x = N2 - com;
        n2 = com - x;
        int com1 = n2;
        n1 = N1 - x;
        if (x & 1)
            printAns (n1 - (com1+1)/2, n2 - com1/2);
        else
            printAns (n1 - com1/2, n2 - (com1+1)/2);
    }
    return 0;
}
