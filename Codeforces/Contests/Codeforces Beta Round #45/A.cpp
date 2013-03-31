#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <memory.h>
#define For(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

char s[10], f[10], m[10];

bool win(char a, char b)
{
    if (a == 'r' && b == 's')
        return true;
    else if (a == 's' && b == 'p')
        return true;
    else if (a == 'p' && b == 'r')
        return true;
    else
        return false;
}

int main()
{
    scanf("%s\m", &f);
    scanf("%s\m", &m);
    scanf("%s\m", &s);
    if (win(s[0], m[0]) && win(s[0], f[0]))
        printf("S\n");
    else if (win(f[0], m[0]) && win(f[0], s[0]))
        printf("F\n");
    else if (win(m[0], s[0]) && win(m[0], f[0]))
        printf("M\n");
    else
        printf("?\n");
    return 0;
}
