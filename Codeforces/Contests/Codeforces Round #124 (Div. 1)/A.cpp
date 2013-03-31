#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define MP make_pair
#define min(a, b) (a < b) ? (a) : (b)
#define Inf 1000000000
#define N 100005

typedef long double ld;
typedef long long ll;

string s;
string ans;

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    cin >> s;
    ans += s[0];
    for (int i = 1; i < s.length(); i++)
    {
        while (ans != "" && s[i] > ans[ans.length() - 1])
            ans.erase(ans.length() - 1, 1);
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}
