#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <set>
#define MP make_pair

using namespace std;

string mas[26000];
int N;

void swaps(string &a, string &b)
{
    string t = a;
    a = b;
    b = t;
}

int comp1(string a, string b)
{
    if (a.length() < b.length())
    {
        while (a.length() != b.length())
            a.push_back('0');
    }
    else
    {
        while (a.length() != b.length())
            b.push_back('0');
    }
    int i = 0;
    while (a[i] == b[i] && i < a.length() - 1)
        i++;
    if (a[i] < b[i])
        return -1;
    if (a[i] > b[i])
        return 1;
    return 0;
}

int comp(string a, string b)
{
    int i1 = 0, i2 = 0;
    while (i1 < a.length() && a[i1] == mas[N][i1])
        i1++;
    while (i2 < b.length() && b[i2] == mas[N][i2])
        i2++;
    if (i1 > i2)
        return 1;
    if (i1 < i2)
        return -1;
    if (i1 == i2)
    {
        return comp1(a, b);
    }
}

void qsort(int l, int r)
{
    if (l == r - 1 && comp(mas[l], mas[r]) <= 0)
        return;
    string et = mas[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (comp(mas[i], et) < 0)
            i++;
        while (comp(mas[j], et) > 0)
            j--;
        if (i < j)
        {
            swaps(mas[i], mas[j]);
            i++;
            j--;
        }
    }
    if (i < r)
        qsort(i, r);
    if (j > l)
        qsort(l, j);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &N);
    for (int i = 1; i <= N; i++)
        cin >> mas[i];
    int max = 1;
    for (int i = 2; i <= N; i++)
    {
        if (mas[i].length() > mas[max].length())
            max = i;
        if (mas[i].length() == mas[max].length())
        {
            if (comp1(mas[i], mas[max]) > 0)
                max = i;
        }
    }
    swaps(mas[max], mas[N]);
    qsort(1, N - 1);
    string sol = "";
    int x = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = x; j < mas[i].length(); j++)
            sol.push_back(mas[i][j]);
        sol.push_back('P');
        if (i != N)
        {
            x = 0;
            while (x < mas[i].length() && mas[i][x] == mas[i + 1][x])
                x++;
            if (x < mas[i].length())
                for (int j = x; j < mas[i].length(); j++)
                    sol.push_back('-');
        }
    }
    printf("%d\n", sol.length());
    for (int i = 0; i < sol.length(); i++)
        printf("%c\n", sol[i]);
    return 0;
}
