#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

#define m1 971
#define m2 997
#define m3 1033
#define LL long long

void ex_gcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        LL x1, y1;
        ex_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
    }
}

int main()
{
    ifstream cin("pocus.dat");
    ofstream cout("pocus.sol");
    LL p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    LL a;

    //Use extended algorithm Euclid
    LL k1, k2;
    ex_gcd(m1, m2, k1, k2);
    while (k1 <= 0)
        k1 += m2;
    k1 *= (p2 - p1);
    LL x = k1 * m1 + p1;
    //cout << (x % m1 == p1 && x % m2 == p2) << endl;
    LL M = m1 * m2;
    LL px = x % M;
    LL K1, K2;
    ex_gcd(M, m3, K1, K2);
    while (K1 <= 0)
        K1 += m3;
    K1 *= (px - p3);
    a = K1 * M + px;
    //cout << a << endl;
    //cout << (a % m1 == p1 && a % m2 == p2 && a % m3 == p3) << endl;

    //Use Chinese theorem
    a = p1;
    while (a % m2 != p2)
        a += m1;
    while (a % m3 != p3)
        a += m2 * m1;
    cout << a << endl;

    return 0;
}
