#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int comp_abs(string a, string b)
{
    int i = 0;
    if (a.length() < b.length())
        return -1;
    if (a.length() > b.length())
        return 1;
    while (a[i] == b[i] && i < a.length() - 1)
        i++;
    if (a[i] == b[i])
        return 0;
    if (a[i] < b[i])
        return -1;
    return 1;
}

int comp(string a, string b)
{
    if (a[0] == '-' && b[0] != '-')
        return -1;
    if (a[0] != '-' && b[0] == '-')
        return 1;
    if (a[0] == '-')
    {
        a.erase(1, 1);
        b.erase(1, 1);
        return -comp_abs(a, b);
    }
    else
        return comp_abs(a, b);
}

struct Num
{
    string min, max;
};

Num Byte, Short, Int, Long;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    Byte.min = "-128";
    Byte.max = "127";
    Short.min = "-32768";
    Short.max = "32767";
    Int.min = "-2147483648";
    Int.max = "2147483647";
    Long.min = "-9223372036854775808";
    Long.max = "9223372036854775807";
    string n;
    cin >> n;
    if (comp(n, Byte.min) >= 0 && comp(n, Byte.max) <= 0)
    {
        cout << "byte" << endl;
        return 0;
    }
    if (comp(n, Short.min) >= 0 && comp(n, Short.max) <= 0)
    {
        cout << "short" << endl;
        return 0;
    }
    if (comp(n, Int.min) >= 0 && comp(n, Int.max) <= 0)
    {
        cout << "int" << endl;
        return 0;
    }
    if (comp(n, Long.min) >= 0 && comp(n, Long.max) <= 0)
    {
        cout << "long" << endl;
        return 0;
    }
    cout << "BigInteger" << endl;
    return 0;
}
