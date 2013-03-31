#include <iostream>
#include <string>

using namespace std;

string st[300];
int top;
int n;
string wh, s;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    top = 1;
    st[0] = "/";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> wh;
        if (wh == "pwd")
        {
            for (int j = 0; j < top; j++)
            {
                cout << st[j];
                if (j)
                    cout << "/";
            }
            cout << endl;
        }
        else
        {
            cin >> s;
            if (s[0] == '/')
                top = 1;
            while (s != "")
            {
                if (s[0] == '/')
                    s.erase(0, 1);
                if (s == "")
                    break;
                st[top] = "";
                while (s.length() && s[0] != '/')
                {
                    st[top] += s[0];
                    s.erase(0, 1);
                }
                if (st[top] == "..")
                    top--;
                else
                    top++;
            }
        }
    }
    return 0;
}
