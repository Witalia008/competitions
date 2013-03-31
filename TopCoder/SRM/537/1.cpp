#include <stdio.h>
#include <string>

using namespace std;

class KingXNewBaby
{
public:
    string isValid(string a)
    {
        if (a.size() != 8)
            return "NO";
        int vowel, cons;
        vowel = cons = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < 'a' || a[i] > 'z')
                return "NO";
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                vowel++;
            else
                cons++;
        }
        if (vowel != 2 || cons != 6)
            return "NO";
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (a[i] == a[j] && (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'))
                    cnt++;
        if (cnt != 1)
            return "NO";
        return "YES";
    }
};
