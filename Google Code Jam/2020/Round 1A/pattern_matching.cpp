#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> split_pattern(string s)
{
    vector<string> sp;
    string cur = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '*')
        {
            sp.push_back(cur);
            cur = "";
        }
        else
        {
            cur += s[i];
        }
    }
    sp.push_back(cur);
    return sp;
}

bool compare_assign(string &old_pattern, const string &candidate, bool beginning)
{
    int smaller_size = min(old_pattern.size(), candidate.size());
    int start_pos_old = beginning ? 0 : old_pattern.size() - smaller_size;
    int start_pos_candidate = beginning ? 0 : candidate.size() - smaller_size;
    if (old_pattern.substr(start_pos_old, smaller_size) != candidate.substr(start_pos_candidate, smaller_size))
    {
        return false;
    }
    if (candidate.size() > old_pattern.size())
    {
        old_pattern = candidate;
    }
    return true;
}

#define ONLINE_JUDGE
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << (t + 1) << ": ";

        int n;
        cin >> n;
        vector<vector<string>> patterns;
        for (int i = 0; i < n; ++i)
        {
            string p;
            cin >> p;
            patterns.push_back(split_pattern(p));
        }

        bool can_do = true;
        string begin_pattern = "", end_pattern = "";
        string between_pattern = "";
        for (int i = 0; i < n; ++i)
        {
            if (!compare_assign(begin_pattern, patterns[i][0], true) || !compare_assign(end_pattern, patterns[i].back(), false))
            {
                can_do = false;
                break;
            }
            for (int j = 1; j + 1 < patterns[i].size(); ++j)
            {
                between_pattern += patterns[i][j];
            }
        }
        if (can_do)
        {
            cout << begin_pattern << between_pattern << end_pattern << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }
    return 0;
}
