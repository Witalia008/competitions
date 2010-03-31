#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    printf("%d.00\n", n);
    return 0;
}
