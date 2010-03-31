#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

#define Inf 1000000000000000000LL

LL K;
LL pow10[20];

inline void cntPows()
{
    pow10[0] = 1;
    for (int i = 1; i < 20; i++)
        pow10[i] = pow10[i - 1] * 10;
}

inline LL CntEndStart(LL N, string A, int len)
{
    LL c = 89;
    LL ans = 0;
    while (c <= N)
        ans++, c = c * 10 + 9;

    ans += pow10[len - 2] * LL(A[0] - '0' - 1);

    for (int i = 1; i < len - 1; i++)
        ans += LL(A[i] - '0') * pow10[len - 2 - i];
    if (A[0] <= A[len - 1] && len > 1)
        ans++;

    return ans;
}

inline string ToStr(LL N)
{
    string res = "";
    for (LL n = N; n; res.push_back(n % 10 + '0'), n /= 10)
        ;
    reverse(res.begin(), res.end());
    return res;
}

LL F[10][30];
LL part[30][30];

inline LL CntInside(LL N, string A, int len)
{
    for (int l = 0; l < len; l++)
    {
        LL num = A[l] - '0';
        for (int r = l; r < len; r++)
        {
            part[l][r] = num;
            if (r + 1 < len)
                num = num * 10 + A[r + 1] - '0';
        }
    }

    for (int d = 0; d < 10; d++)
    {
        LL num = d * 11;
        for (int c = 2; c <= len; c++)
        {
            F[d][c] = 0;
            for (int s = 0; s <= len - c; s++)
            {
                for (int i = 0; i < len;)
                {
                    if (i == s)
                    {
                        if (num < part[s][s + c - 1])
                            F[d][c] += pow10[len - c - s], i = len;
                        if (num == part[s][s + c - 1])
                            F[d][c]++, i += c;
                        if (num > part[s][s + c - 1])
                            i = len;
                    }
                    else
                        F[d][c] += LL(A[i] - '0') * pow10[len - i - 1], i++;
                }
                if (d == 0)
                    F[d][c]--;
            }
            num = num * 10 + d;
        }
    }

    LL ans = 0;
    for (int d = 0; d < 10; d++)
        for (int c = 2; c <= len; c++)
            if (F[d][c] > 0)
                ans += F[d][c] * (c - 1);
    return ans;
}

inline LL get_cnt(LL N)
{
    string strN = ToStr(N);
    int l = strN.length();

    //If the right way without spaces
    LL len = pow10[l - 1] - 1 + (N - pow10[l - 1] + 1) * LL(l);

    //minus groups of equal numbers
    len -= CntInside(N, strN, l);

    //end-start groups
    string N_1 = ToStr(N - 1);
    len -= CntEndStart(N - 1, N_1, N_1.length());

    return len;
}

inline LL bin_srch(LL l, LL r)
{
    while (l < r - 1)
    {
        LL mid = (l + r) / 2;
        LL cnt = get_cnt(mid);
        if (cnt == K)
            return mid;
        if (cnt > K)
            r = mid;
        else
            l = mid;
    }
    if (get_cnt(l) == K)
        return l;
    else
        return r;
}

int main()
{
    cin >> K;
    cntPows();
    cout << bin_srch(1, Inf) << endl;
    return 0;
}
