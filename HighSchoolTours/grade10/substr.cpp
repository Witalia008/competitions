#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int p[100000];

int main()
{
    freopen("substr.dat", "r", stdin);
    freopen("substr.res", "w", stdout);
    string a, b, c;
    cin >> a;
    cin >> b;
    c = b;
    c.push_back('#');
    c.append(a);
    int k = 0;
    p[0] = 0;
    for (int i = 1; i <= a.length() + b.length(); i++)
    {
        while (c[k] != c[i] && k != 0)
            k = p[k - 1];
        if (k != 0 || c[k] == c[i])
            k++;
        p[i] = k;
    }
    for (int i = b.length() + 1; i <= a.length() + b.length(); i++)
        if (p[i] == b.length())
        {
            printf("%d\n", i - 2 * b.length() + 1);
            break;
        }
    return 0;
}
