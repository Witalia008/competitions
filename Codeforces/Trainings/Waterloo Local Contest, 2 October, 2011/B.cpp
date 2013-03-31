#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> from;
vector<string> to;

void AddRule(string a, string b)
{
    from.push_back(a);
    to.push_back(b);
}

void Init()
{
    AddRule("aa", "");
    AddRule("bb", "");
    AddRule("cc", "");
    AddRule("baba", "abab");
    AddRule("caca", "acac");
    AddRule("cbcb", "bcbc");
    AddRule("cbcabab", "bcbcaba");
}

int N;
string s;

int find(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        int fl = true;
        for (int j = 0; j < b.length(); j++)
        {
            if (i + j >= a.length())
                return -1;
            if (a[i + j] != b[j])
                fl = false;
        }
        if (fl)
            return i;
    }
    return -1;
}

string replace(string &a, string b, int s, int s1)
{
    string res = "";
    for (int i = 0; i < s; i++)
        res += a[i];
    res += b;
    for (int i = s + s1; i < a.length(); i++)
        res += a[i];
    return res;
}

int main()
{
    Init();
    cin >> N;
    for (; N; N--)
    {
        cin >> s;
        while (true)
        {
            int p = -1;
            for (int i = 0; i < from.size(); i++)
            {
                p = find(s, from[i]);
                if (p != -1)
                {
                    s = replace(s, to[i], p, from[i].size());
                    break;
                }
            }
            if (p == -1)
                break;
        }
        if (s == "")
            puts("closed");
        else
            puts("open");
    }
    return 0;
}
