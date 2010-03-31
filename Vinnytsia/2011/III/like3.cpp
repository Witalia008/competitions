#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

typedef unsigned long long LL;

LL s3[40];
string A;
LL Ans;

void Cnt(int pos)
{
    if (pos == A.length())
    {
        Ans += 1;
        return;
    }
    for (int p = 0; p < 3; p++)
        if (s3[p] < A[pos] - '0')
            Ans += s3[A.length() - pos - 1];
        else if (s3[p] == A[pos] - '0')
            Cnt(pos + 1);
}

LL Plus()
{
    LL ans = 0;
    for (int i = 1; i < A.length(); i++)
        ans += s3[i];
    return ans;
}

string a, b;

inline void Sub1()
{
    int x = a.length() - 1;
    while (a[x] == '0')
        x--;
    a[x]--;
    for (int i = x + 1; i < a.length(); i++)
        a[i] = '9';
}

int main()
{
    cin >> a >> b;
    Sub1();

    s3[0] = 1;
    for (int i = 1; i < 40; i++)
        s3[i] = s3[i - 1] * 3;

    LL aA, aB;
    A = a;
    Ans = 0;
    Cnt(0);
    aA = Ans + Plus();
    A = b;
    Ans = 0;
    Cnt(0);
    aB = Ans + Plus();
    cout << aB - aA << endl;
    return 0;
}
