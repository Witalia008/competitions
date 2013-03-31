#include <stdio.h>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

#define Inf 1000000000

string ToStr(int a)
{
    string res = "";
    while (a)
    {
        res += a % 10 + '0';
        a /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

class TheNumberGameDiv2
{
public:
    int minimumMoves(int A, int B)
    {
        string a = ToStr(A);
        string b = ToStr(B);
        int ans = Inf;
        for (int i = 0; i + b.size() <= a.size(); i++)
        {
            string x = a.substr(i, b.size());
            string y = x;
            reverse(y.begin(), y.end());
            if (x == b || y == b)
            {
                int cur = a.size() - b.size() - i;
                if (i)
                {
                    cur += 1 + i;
                    if (y != b)
                        cur++;
                }
                else
                {
                    if (x != b)
                        cur++;
                }
                ans = min(ans, cur);
            }
        }
        if (ans == Inf)
            ans = -1;
        return ans;
    }
};
