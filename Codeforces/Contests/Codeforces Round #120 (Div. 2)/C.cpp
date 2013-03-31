#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n;
string s, x;
char st[100001];
int top = 0;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> n;
    for (;;)
    {
        cin >> x;
        if (x == "")
            break;
        if (x == "int")
            n--;
        if (st[top] == 'p')
            s += "<";
        if (st[top] == 'i')
            s += ",";
        st[++top] = x[0];
        s += x;
        while (top > 2 && st[top] == 'i' && st[top - 1] == 'i' && st[top - 2] == 'p')
        {
            s += ">";
            top -= 2;
            st[top] = 'i';
        }
        x = "";
    }
    if (top == 1 && st[1] == 'i' && !n)
        cout << s << endl;
    else
        cout << "Error occurred\n";
    return 0;
}
