#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define eps 10e-5
#define abs(a) (((a) < 0) ? (-a) : (a))
#define sqr(a) ((a) * (a))
#define nmax 100000
#define MP make_pair

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

int StrToInt(string s)
{
    int res = 0;
    if (s == "")
        return -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            res = res * 10 + s[i] - '0';
        else
            return -1;
    return res;
}

int main()
{
    //ifstream cin ("input.txt"); ofstream cout ("output.txt");
    //freopen ("input.txt", "r", stdin); freopen ("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string a = "", b = "";
        int j = s.length() - 1;
        while (s[j] >= '0' && s[j] <= '9')
            b += s[j--];
        reverse(b.begin(), b.end());
        for (int c = 1; c < j; c++)
            a += s[c];
        if (s[0] == 'R' && s[j] == 'C' && StrToInt(a) != -1)
        {
            int B = StrToInt(b);
            string bb = "";
            while (B > 0)
            {
                bb.push_back(B % 26 ? B % 26 + 'A' - 1 : 'Z');
                if (B % 26 == 0)
                    B = B / 26 - 1;
                else
                    B /= 26;
            }
            for (int c = bb.length() - 1; c >= 0; c--)
                cout << bb[c];
            cout << a << endl;
        }
        else
        {
            a = "";
            for (int c = 0; c <= j; c++)
                a += s[c];
            cout << "R" << b << "C";
            int aa = 0;
            for (int c = 0; c < a.length(); c++)
                aa = (aa * 26 + a[c] - 'A' + 1);
            cout << aa << endl;
        }
    }
    return 0;
}
