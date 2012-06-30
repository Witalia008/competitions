#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int len(int a)
{
    int ans = 0;
    while (a)
    {
        ans++;
        a /= 10;
    }
    return ans;
}

bool isPeriod(string s, int l, int r, int x)
{
    if ((r - l + 1) % x != 0)
        return false;
    bool fl = true;
    for (int i = l; i <= r - (r - l + 1) / x; i++)
        if (s[i] != s[i + (r - l + 1) / x])
            fl = false;
    return fl;
}

string IntToStr(int x)
{
    string a = "", c = "";
    int ob = 0, k = x;
    while (k % 10 == 0)
    {
        c.push_back(48);
        k /= 10;
    }
    while (x)
    {
        ob = ob * 10 + x % 10;
        x /= 10;
    }
    while (ob)
    {
        a.push_back(ob % 10 + 48);
        ob /= 10;
    }
    a += c;
    return a;
}

string s;
int M[105][105];
string Ans[105][105];

int main()
{
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    cin >> s;
    memset(M, 0, sizeof(M));
    memset(Ans, 0, sizeof(Ans));
    for (int i = 0; i < s.length(); i++)
    {
        Ans[i][i] = s[i];
        M[i][i] = 1;
    }
    for (int i = 2; i <= s.length(); i++)
    {
        for (int l = 0; l <= s.length() - i; l++)
        {
            int r = l + i - 1;
            M[l][r] = 200;
            for (int e = l; e < r; e++)
                if (M[l][e] + M[e + 1][r] < M[l][r])
                {
                    Ans[l][r] = "";
                    Ans[l][r] += Ans[l][e];
                    Ans[l][r] += Ans[e + 1][r];
                    M[l][r] = M[l][e] + M[e + 1][r];
                }
            for (int x = 2; x <= r - l + 1; x++)
                if (len(x) + 2 + M[l][l + i / x - 1] < M[l][r] && isPeriod(s, l, r, x))
                {
                    M[l][r] = len(x) + 2 + M[l][l + (r - l + 1) / x - 1];
                    Ans[l][r] = "";
                    Ans[l][r] += IntToStr(x);
                    Ans[l][r] += "(";
                    Ans[l][r] += Ans[l][l + (r - l + 1) / x - 1];
                    Ans[l][r] += ")";
                }
        }
    }
    cout << M[0][s.length() - 1] << "\n";
    cout << Ans[0][s.length() - 1] << "\n";
    return 0;
}
