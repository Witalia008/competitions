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

#define For(i, a, b, d) for (int i = (a); i != (b); i += d)
#define FORD(i, a, b) for (int i = (a); i >= b; i--)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REPD(i, n) for (int i = (n - 1); i >= 0; i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define mp make_pair
#define eps 10e-10
#define Inf 1000000000
#define Mi 1000000007
#define N 555
//#define debug

typedef double ld;
typedef unsigned long long ll;
typedef int i;
typedef vector<i> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<double, char> pdc;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int Abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ld Abs(ld a)
{
    if (a < 0)
        return -a;
    else
        return a;
}
ll sqr(ll a) { return a * a; }
ld sqr(ld a) { return a * a; }

string s;
int n, top;
const ld X = 15;
ld st[N];

void outSt()
{
#ifdef debug
    REP(i, top)
    cout << st[i + 1] << " ";
    cout << endl;
#endif
}

//#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    while (n)
    {
        top = 0;
        REP(i, n)
        {
            cin >> s;
            if (s == "x")
                st[++top] = X, outSt();
            else if (s == "sin")
                st[top] = sin(st[top]), outSt();
            else if (s == "cos")
                st[top] = cos(st[top]), outSt();
            else if (s == "tan")
                st[top] = tan(st[top]), outSt();
            else if (s == "+")
            {
                --top;
                st[top] += st[top + 1], outSt();
            }
            else if (s == "-")
            {
                --top;
                st[top] -= st[top + 1], outSt();
            }
            else if (s == "*")
            {
                --top;
                st[top] *= st[top + 1], outSt();
            }
        }
        if (Abs(st[1]) < eps && top == 1)
            cout << "Identity" << endl;
        else
            cout << "Not an identity" << endl;
        cin >> n;
    }
    return 0;
}
