#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

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

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int C, O, H;
    cin >> C >>H >> O;
    cout << min (C/2, min (H/6, O)) << endl;
    return 0;
}
