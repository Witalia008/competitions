#include <cstdlib>
#include <memory.h>
#include <string>
#include <iostream>
#include <math.h>
#include <complex>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a == 0)
    {
        double n = b;
        if (c != 0)
            n = (n / c) * d;
        else
            n = d;
        if (n > 0)
        {
            cout << "Ron\n";
            return 0;
        }
        else
        {
            cout << "Hermione\n";
            return 0;
        }
    }
    if (b == 0)
    {
        if (c != 0)
        {
            cout << "Hermione\n";
            return 0;
        }
        else if (d > 0)
        {
            cout << "Ron\n";
            return 0;
        }
        else
        {
            cout << "Hermione\n";
            return 0;
        }
    }
    if (c == 0)
    {
        if (d > 0)
        {
            cout << "Ron\n";
            return 0;
        }
        else
        {
            cout << "Hermione\n";
            return 0;
        }
    }
    if (d == 0)
    {
        cout << "Hermione\n";
        return 0;
    }
    if (e == 0)
    {
        if (d == 0)
        {
            cout << "Hermione\n";
            return 0;
        }
        else if (a == 0)
        {
            double n = b;
            if (c != 0)
                n = (n / c) * d;
            else
                n = d;
            if (n > 0)
            {
                cout << "Ron\n";
                return 0;
            }
            else
            {
                cout << "Hermione\n";
                return 0;
            }
        }
        if (b == 0)
        {
            if (c != 0)
            {
                cout << "Hermione\n";
                return 0;
            }
            else if (d > 0)
            {
                cout << "Ron\n";
                return 0;
            }
            else
            {
                cout << "Hermione\n";
                return 0;
            }
        }
        if (c == 0)
        {
            if (d > 0)
            {
                cout << "Ron\n";
                return 0;
            }
            else
            {
                cout << "Hermione\n";
                return 0;
            }
        }
    }
    if (f == 0)
    {
        if (a == 0 && ((double)b / c) * d > 0)
        {
            cout << "Ron\n";
            return 0;
        }
        else
        {
            cout << "Hermione\n";
            return 0;
        }
    }
    double n;
    n = ((double)b / c) * d;
    if (n > 0)
    {
        if ((n / e) * f > a)
        {
            cout << "Ron\n";
            return 0;
        }
        else
        {
            cout << "Hermione\n";
            return 0;
        }
    }
    else
    {
        cout << "Hermione\n";
        return 0;
    }

    return 0;
}
