#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>
#define sqr(a) ((a) * (a))
#define nmax 1000
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

struct TLong
{
    int len, point, bracket;
    char sign;
    int n[nmax + 1];
};

void Input(TLong &a)
{
    char s[nmax + 1];
    memset(a.n, 0, sizeof(a.n));
    scanf("%s\n", &s);
    int min = 0;
    if (s[0] == '-' || s[0] == '+')
    {
        a.sign = s[0];
        min = 1;
    }
    else
        a.sign = '+';
    int c = 0;
    a.len = strlen(s);
    a.point = 0;
    for (int i = a.len - 1; i >= min; i--)
    {
        if (s[i] == '.')
        {
            c++;
            a.point = a.len - i - c;
        }
        else if (s[i] == ')')
            c++;
        else if (s[i] == '(')
        {
            c++;
            a.bracket = a.len - i - c;
        }
        else
            a.n[nmax - a.len + i + c + 1] = s[i] - '0';
    }
    a.len -= c + min;
}

void Output(TLong a)
{
    if (a.sign == '-')
        printf("-");
    if (a.point == a.len)
        printf("0.");
    for (int i = nmax - a.len + 1; i <= nmax; i++)
    {
        printf("%d", a.n[i]);
        if (i == nmax - a.point && a.point != 0)
            printf(".");
        if (i == nmax - a.bracket && i < nmax)
            printf("(");
    }
    //if (a.point==0 && a.bracket==0) printf("0");
    if (a.bracket != 0)
        printf(")");
    printf("\n");
}

int LongLen(TLong a)
{
    int i = 1;
    while (a.n[i] == 0 && i < nmax - a.point && i < nmax)
        i++;
    return nmax - i + 1;
}

void Shift(TLong &a, int k)
{
    if (k == 0)
        return;
    if (k > 0)
    {
        for (int i = nmax - a.len + 1; i <= nmax; i++)
            if (i - k <= nmax)
            {
                a.n[i - k] = a.n[i];
                a.n[i] = 0;
            }
    }
    else
    {
        for (int i = nmax + k; i >= nmax - a.len + 1; i--)
        {
            a.n[i - k] = a.n[i];
            a.n[i] = 0;
        }
    }
    a.len += k;
    a.point += k;
}

void DelZeros(TLong &a)
{
    int k = 0;
    while (a.n[nmax - k] == 0 && k < a.point)
        k++;
    Shift(a, -k);
}

int Comp_Abs(TLong a, TLong b)
{
    int i = 1;
    while (a.n[i] == b.n[i] && i < nmax)
        i++;
    if (a.n[i] == b.n[i])
        return 0;
    if (a.n[i] > b.n[i])
        return 1;
    if (a.n[i] < b.n[i])
        return -1;
}

TLong Minus_Abs(TLong a, TLong b)
{
    TLong res;
    int z = 0;
    for (int i = nmax; i >= 1; i--)
    {
        res.n[i] = a.n[i] - b.n[i] - z;
        if (res.n[i] < 0)
        {
            z = 1;
            res.n[i] += 10;
        }
        else
            z = 0;
    }
    res.len = LongLen(res);
    return res;
}

TLong HalfLongMulti(TLong a, int b)
{
    TLong res;
    int p = 0;
    int ost = 0;
    if (b < 0)
    {
        b = -b;
        if (a.sign == '-')
            res.sign = '+';
        else
            res.sign = '-';
    }
    else
        res.sign = a.sign;
    for (int i = nmax; i >= 1; i--)
    {
        int s = a.n[i] * b + p;
        p = s / 10;
        res.n[i] = s % 10;
    }
    res.len = LongLen(res);
    res.point = a.point;
    res.bracket = 0;
    return res;
}

TLong Multi(TLong a, TLong b)
{
    TLong res;
    memset(res.n, 0, sizeof(res.n));
    if (a.sign == b.sign)
        res.sign = '+';
    else
        res.sign = '-';
    for (int j = nmax; j >= nmax - b.len; j--)
        if (b.n[j] != 0)
        {
            int p = 0;
            for (int i = nmax; i >= nmax - a.len; i--)
            {
                int s = a.n[i] * b.n[j] + p + res.n[i + j - nmax];
                res.n[i + j - nmax] = s % 10;
                p = s / 10;
            }
        }
    res.point = a.point + b.point;
    res.bracket = 0;
    res.len = LongLen(res);
    DelZeros(res);
    return res;
}

TLong NWE(TLong a, int k)
{
    a.n[nmax] = k;
    return HalfLongMulti(a, k);
}

TLong Root(TLong a, int K)
{
    TLong res, A, sub;
    memset(res.n, 0, sizeof(res.n));
    res.len = 1;
    res.bracket = 0;
    res.point = 0;
    res.sign = '+';
    if (a.point / 2 < K)
    {
        if (a.bracket == 0)
            Shift(a, K * 2 - a.point);
        else
        {
            int c = K * 2 - a.point;
            while (c)
            {
                int x = a.bracket;
                if (c < x)
                    x = c;
                Shift(a, x);
                for (int i = nmax - x + 1; i <= nmax; i++)
                    a.n[i] = a.n[i - a.bracket];
                c -= x;
            }
        }
    }
    if (a.point % 2 == 1)
        Shift(a, 1);
    a.len += a.len % 2;
    int i = nmax - a.len + 1;
    while (sqr(res.n[nmax] + 1) <= a.n[i] * 10 + a.n[i + 1])
        res.n[nmax]++;
    sub = res;
    sub.len = 2;
    sub.n[nmax] = a.n[i + 1];
    sub.n[nmax - 1] = a.n[i];
    i += 2;
    A = Multi(res, res);
    int top = 0;
    for (i; i < nmax; i += 2)
    {
        sub = Minus_Abs(sub, A);
        A = HalfLongMulti(res, 2);
        Shift(A, 1);
        Shift(sub, 2);
        sub.n[nmax - 1] = a.n[i];
        sub.n[nmax] = a.n[i + 1];
        int k = 0;
        while (Comp_Abs(NWE(A, k + 1), sub) <= 0)
            k++;
        Shift(res, 1);
        res.n[nmax] = k;
        if (i == nmax - a.point + 1)
            res.point = 1;
        A.n[nmax] = k;
        A = HalfLongMulti(A, k);
    }
    res.len = LongLen(res);
    if (res.point > K)
    {
        Shift(res, K - res.point);
    }
    return res;
}

TLong A, B;
int X;
string s;

int main()
{
    freopen("root.dat", "r", stdin);
    freopen("root.res", "w", stdout);
    Input(A);
    scanf("%d", &X);
    B = Root(A, X * 3);
    DelZeros(B);
    s = "";
    for (int i = nmax - B.point + 1; i <= nmax; i++)
        s.push_back(B.n[i] + 48);
    for (int i = nmax - B.len + 1; i <= nmax - B.point; i++)
        printf("%d", B.n[i]);
    if (B.point != 0)
        printf(".");
    int ans = s.length(), L = -1;
    for (int i = 0; i < s.length() / 2; i++)
    {
        for (int j = i; j < s.length() / 2; j++)
        {
            bool fl = true;
            for (int l = i; l < s.length(); l++)
                if (l + j - i + 1 < s.length())
                {
                    if (s[l] != s[l + j - i + 1])
                        fl = false;
                }
            if (fl && j - i < ans)
            {
                ans = j - i;
                L = i;
            }
        }
    }
    if (L != -1)
    {
        for (int i = 0; i < L; i++)
            printf("%c", s[i]);
        printf("(");
        for (int i = L; i <= L + ans; i++)
            printf("%c", s[i]);
        printf(")\n");
    }
    else if (B.point != 0)
    {
        for (int i = 0; i < X && i < s.length(); i++)
            printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}
