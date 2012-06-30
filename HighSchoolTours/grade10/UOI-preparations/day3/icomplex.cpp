#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int sol[15];

void Solve(string s, int CouN, int StepN)
{
    if (s == "")
        sol[StepN] += CouN;
    int i = 0;
    string x;
    while (i < s.length())
    {
        if (s[i] == 'O')
        {
            int I = 0;
            i += 2;
            while (s[i] != ')')
                I = I * 10 + s[i] - '0', i++;
            i++;
            sol[StepN] += I * CouN;
        }
        else if (s[i] == 'L')
        {
            int balans = 1;
            i += 2;
            int cn = 0, sn = 0;
            if (s[i] == 'n')
            {
                i += 2;
                sn++;
            }
            else
            {
                while (s[i] >= '0' && s[i] <= '9')
                    cn = cn * 10 + s[i] - '0', i++;
                i++;
            }
            x = "";
            while (balans)
            {
                x.push_back(s[i]);
                if (s[i] == 'L')
                    balans++;
                if (s[i] == 'E')
                    balans--;
                i++;
            }
            x.erase(x.length() - 1, 1);
            Solve(x, CouN * ((sn == 1) ? 1 : cn), StepN + sn);
        }
    }
}

int k;
string S, x;
int ans[15][2];

int main()
{
    freopen("icomplex.in", "r", stdin);
    freopen("icomplex.out", "w", stdout);
    cin >> k;
    cin >> x;
    for (int t = 1; t <= k; ++t)
    {
        S = "";
        int balans = 1;
        while (balans != 0)
        {
            if (x[0] == 'L')
                balans++;
            if (x[0] == 'E')
                balans--;
            S.push_back(x[0]);
            if (x[0] == 'O' || x[0] == 'L')
            {
                S.push_back('(');
                cin >> x;
                S.append(x);
                S.push_back(')');
            }
            cin >> x;
        }
        memset(sol, 0, sizeof(sol));
        S.erase(0, 1);
        S.erase(S.length() - 1, 1);
        Solve(S, 1, 0);
        memset(ans, 0, sizeof(ans));
        int top = 0;
        for (int p = 11; p >= 0; --p)
            if (sol[p] != 0)
            {
                top++;
                ans[top][0] = p;
                ans[top][1] = sol[p];
            }
        cout << "Program #" << t << endl;
        cout << "Runtime = ";
        for (int p = 1; p <= top; ++p)
        {
            if (ans[p][1] != 1 || ans[p][0] == 0)
                cout << ans[p][1];
            if (ans[p][0] != 0)
            {
                if (ans[p][1] != 1)
                    cout << "*";
                cout << "n";
            }
            if (ans[p][0] > 1)
                cout << "^" << ans[p][0];
            if (p != top)
                cout << "+";
        }
        if (top == 0)
            cout << 0;
        cout << endl;
        if (t != k)
            cout << endl;
    }
    return 0;
}
