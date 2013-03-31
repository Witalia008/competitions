#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int StrToInt(string a)
{
    int res = 0;
    for (int i = 0; i < a.length(); ++i)
        res = res * 10 + a[i] - '0';
    return res;
}

vector<vector<int>> A;

int get_max()
{
    int res = 0, ar = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        int s = 0;
        for (int j = 0; j < A[i].size(); ++j)
            s += A[i][j];
        if (s > ar)
        {
            ar = s;
            res = i;
        }
    }
    return res;
}

int rotate(int &from, int to, int n)
{
    int f = from, t = to;
    from = to;
    if (f > t)
        swap(f, t);
    return min(t - f, f + n - t);
}

class VendingMachine
{
public:
    int motorUse(vector<string> pr, vector<string> pu)
    {
        A.clear();
        int n = 1;
        for (int i = 0; i < pr[0].length(); ++i)
            n += (pr[0][i] == ' ');
        A.resize(n);
        for (int i = 0; i < pr.size(); ++i)
        {
            string s = "";
            int cnt = 0;
            pr[i] += ' ';
            for (int j = 0; j < pr[i].length(); ++j)
                if (pr[i][j] == ' ')
                {
                    A[cnt++].push_back(StrToInt(s));
                    s = "";
                }
                else
                    s += pr[i][j];
        }
        int wh = 0, ans = 0, time = 0;
        ans += rotate(wh, get_max(), n);
        for (int i = 0; i < pu.size(); ++i)
        {
            int I, J, T;
            sscanf(pu[i].c_str(), "%d,%d:%d", &J, &I, &T);
            if (T >= time + 5)
                ans += rotate(wh, get_max(), n);
            if (I != wh)
                ans += rotate(wh, I, n);
            if (A[I][J] == 0)
                return -1;
            A[I][J] = 0;
            wh = I;
            time = T;
        }
        ans += rotate(wh, get_max(), n);
        return ans;
    }
};
