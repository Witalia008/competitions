#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;
using std::swap;

#define eps 10e-5
#define sqr(a) ((a) * (a))
#define nmax 101
#define INF 1000000000
#define MP make_pair

typedef long long LL;
typedef pair<int, int> PII;

const int Base = 10000;
const int MaxLen = 760;

struct TLong
{
    int len;
    short a[MaxLen];
    TLong(int op2)
    {
        for (len = -1; op2; op2 /= Base)
            a[++len] = op2 % Base;
    }
    void mul(int op2, int t)
    {
        for (int i = 0; i <= len; i++)
        {
            t += a[i] * op2 + Base;
            a[i] = t % Base;
            t = t / Base - 1;
        }
        while (t)
        {
            len++;
            a[len] = t % Base;
            t /= Base;
        }
    }
    void div(int op2)
    {
        int t = 0;
        int i;
        for (i = len; i >= 0; i--)
        {
            t = t * Base + a[i];
            a[i] = t / op2;
            t %= op2;
        }
        if (t)
        {
            for (i = 0; i <= len && a[i] == Base - 1; i++)
                a[i] = 0;
            if (i > len)
                a[++len] = 1;
            else
                a[i]++;
        }
        while (len >= 0 && a[len] == 0)
            len--;
    }
    void operator--()
    {
        int i;
        for (i = 0; i <= len && a[i] == 0; i++)
            a[i] = Base - 1;
        if (i > len)
        {
            len++;
            a[i] = -1;
        }
        else
            a[i]--;
    }
    void print() const
    {
        if (len == -1)
            putchar('0');
        else
        {
            printf("%hd", a[len]);
            for (int i = len - 1; i >= 0; i--)
                printf("%04hd", a[i]);
        }
    }

    void operator+=(const TLong &op2)
    {
        int len2 = op2.len;
        int minlen = (len < len2) ? len : len2;
        int i;
        short t = 0;
        for (i = 0; i <= minlen; i++)
        {
            t += a[i] + op2.a[i];
            a[i] = t % Base;
            t = t / Base;
        }
        for (; i <= len2; i++)
        {
            t += op2.a[i];
            a[i] = t % Base;
            t = t / Base;
        }
        for (; i <= len; i++)
        {
            t += a[i];
            a[i] = t % Base;
            t = t / Base;
        }
        len = i;
        if (t)
            a[len] = t;
        else
            len--;
    }
};

const int MaxN = 10000;
const int MaxK = 100;
int K;
int N;
int a[MaxN];

int main()
{
    freopen("corridor.in", "r", stdin);
    freopen("corridor.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    TLong s = 0;
    TLong f = 1;
    for (int i = N; i--;)
    {
        f.mul(K + 1, -a[i]);
        f.div(K);
        s += f;
    }
    --f;
    f.print();
    cout << ' ';
    s.print();
    cout << endl;
}
