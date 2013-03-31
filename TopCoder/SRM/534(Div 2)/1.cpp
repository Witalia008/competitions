#include <string>
#include <vector>
#include <iostream>

using namespace std;

class EllysDirectoryListing
{
public:
    vector<string> getFiles(vector<string> a)
    {
        int i = 0, j = a.size() - 1;
        while (a[j] == "." || a[j] == "..")
            j--;
        if (j == a.size() - 3)
            return a;
        while (a[i] != "." && a[i] != "..")
            i++;
        swap(a[i], a[a.size() - 1]);
        j = a.size() - 1;
        while (a[j] == "." || a[j] == "..")
            j--;
        if (j == a.size() - 3)
            return a;
        i = 0;
        while (a[i] != "." && a[i] != "..")
            i++;
        swap(a[i], a[a.size() - 2]);
        return a;
    }
};
