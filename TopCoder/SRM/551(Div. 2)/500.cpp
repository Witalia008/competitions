#include <stdio.h>
#include <string>

using namespace std;

class ColorfulChocolates
{
public:
    int maximumSpread(string a, int maxS)
    {
        int l = 0, r = 0;
        int ans = 0;
        while (l < a.length())
        {
            while (r + 1 < a.length() && a[r + 1] == a[r])
                r++;
            for (int i = 0; i <= maxS; i++)
            {
                string s = a;
                int ll = l, rr = r;
                int j = maxS - i;
                int xi = i, xj = j;
                while (ll > 0)
                {
                    int ii = ll - 1;
                    while (ii >= 0 && s[ii] != s[l])
                        ii--;
                    if (ii < 0)
                        break;
                    if (ll - ii - 1 <= xi)
                    {
                        xi -= (ll - ii - 1);
                        while (ii != ll - 1)
                        {
                            swap(s[ii], s[ii + 1]);
                            ii++;
                        }
                        ll--;
                    }
                    else
                        break;
                }
                while (rr + 1 < s.length())
                {
                    int jj = rr + 1;
                    while (jj < s.length() && s[jj] != s[r])
                        jj++;
                    if (jj == s.length())
                        break;
                    if (jj - rr - 1 <= xj)
                    {
                        xj -= (jj - rr - 1);
                        while (jj != rr + 1)
                        {
                            swap(s[jj], s[jj - 1]);
                            jj--;
                        }
                        rr++;
                    }
                    else
                        break;
                }
                if (rr - ll + 1 > ans)
                    ans = rr - ll + 1;
            }
            l = r + 1;
            r = l;
        }
        return ans;
    }
};
