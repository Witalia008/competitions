#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>

//#include "list.h"

using namespace std;

#define Abs(a) (a < 0 ? (-(a)) : (a))

string s1, s2;
bool fl1, fl2;

int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < s1.length(); i++) {
        fl1 |= s1[i] == '1';
        fl2 |= s2[i] == '1';
    }
    if (fl1 ^ fl2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
