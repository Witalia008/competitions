#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <cmath>
#include <list>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>

using namespace std;
using namespace std::chrono;

class WolvesAndSheep
{
public:
    int getmin(vector<string> field)
    {
        int n = field.size();
        int m = field[0].size();
        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << (n - 1)); ++mask)
        {
            vector<vector<string>> mp;
            mp.push_back({field[0]});
            for (int i = 0; i + 1 < n; ++i)
            {
                if ((mask >> i) & 1)
                {
                    mp.push_back(vector<string>());
                }
                mp[mp.size() - 1].push_back(field[i + 1]);
            }
            bool good = true;
            for (int i = 0; i < mp.size(); ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    bool hs = false, hw = false;
                    for (int k = 0; k < mp[i].size(); ++k)
                    {
                        hs |= mp[i][k][j] == 'S';
                        hw |= mp[i][k][j] == 'W';
                    }
                    good &= !(hs && hw);
                }
            }
            if (!good)
                continue;
            auto cnt = [](int a) {
                int res = 0;
                while (a)
                {
                    res += a % 2;
                    a /= 2;
                }
                return res;
            };
            int cur = cnt(mask);
            vector<bool> nplace(m, false);
            for (int o = 0; o < 2; ++o)
            {
                vector<bool> has_volves(mp.size(), false);
                for (int i = 0; i < mp.size(); ++i)
                {
                    for (int j = 0; j < mp[i].size(); ++j)
                    {
                        if (mp[i][j][0] == 'W')
                            has_volves[i] = true;
                    }
                }
                for (int j = 1; j < m; ++j)
                {
                    if (nplace[j])
                    {
                        has_volves = vector<bool>(mp.size(), false);
                    }
                    else
                    {
                        for (int i = 0; i < mp.size(); ++i)
                            if (has_volves[i])
                            {
                                bool need_cur = false;
                                for (int k = 0; k < mp[i].size(); ++k)
                                {
                                    need_cur |= mp[i][k][j] == 'S';
                                }
                                need_cur &= has_volves[i];
                                if (need_cur)
                                {
                                    nplace[j] = true;
                                }
                            }
                    }
                    if (nplace[j])
                    {
                        has_volves = vector<bool>(mp.size(), false);
                    }
                    for (int i = 0; i < mp.size(); ++i)
                    {
                        for (int k = 0; k < mp[i].size(); ++k)
                        {
                            if (mp[i][k][j] == 'W')
                                has_volves[i] = true;
                        }
                    }
                }
                if (!o)
                {
                    for (int i = 0; i < mp.size(); ++i)
                    {
                        for (int j = 0; j < mp[i].size(); ++j)
                            reverse(mp[i][j].begin(), mp[i][j].end());
                    }
                    for (int i = 0; i + 1 < nplace.size(); ++i)
                        nplace[i] = nplace[i + 1];
                    nplace[nplace.size() - 1] = false;
                    reverse(nplace.begin(), nplace.end());
                }
            }
            for (auto i : nplace)
                cur += i;
            ans = min(ans, cur);
        }
        return ans;
    }
};

// BEGIN CUT HERE
namespace moj_harness
{
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false)
    {
        if (casenum != -1)
        {
            if (run_test_case(casenum) == -1 && !quiet)
            {
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            }
            return;
        }

        int correct = 0, total = 0;
        for (int i = 0;; ++i)
        {
            int x = run_test_case(i);
            if (x == -1)
            {
                if (i >= 100)
                    break;
                continue;
            }
            correct += x;
            ++total;
        }

        if (total == 0)
        {
            cerr << "No test cases run." << endl;
        }
        else if (correct < total)
        {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        }
        else
        {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }

    int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed)
    {
        cerr << "Example " << casenum << "... ";

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200)
        {
            sprintf(buf, "time %.2fs", elapsed * (1.0 / CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (expected == received)
        {
            verdict = "PASSED";
        }
        else
        {
            verdict = "FAILED";
        }

        cerr << verdict;
        if (!info.empty())
        {
            cerr << " (";
            for (int i = 0; i < (int)info.size(); ++i)
            {
                if (i > 0)
                    cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;

        if (verdict == "FAILED")
        {
            cerr << "    Expected: " << expected << endl;
            cerr << "    Received: " << received << endl;
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum)
    {
        switch (casenum)
        {
        case 0:
        {
            string field[] = {"W.WSS",
                              "WW.S.",
                              ".SSS.",
                              "SSS.S",
                              ".SS.S"};
            int expected__ = 2;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            string field[] = {".....",
                              ".....",
                              "....."};
            int expected__ = 0;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            string field[] = {".SS",
                              "...",
                              "S..",
                              "W.W"};
            int expected__ = 1;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            string field[] = {"WWWSWWSSWWW",
                              "WWSWW.SSWWW",
                              "WS.WSWWWWS."};
            int expected__ = 10;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 4:
        {
            string field[] = {".W.S.W.W",
                              "W.W.S.W.",
                              ".S.S.W.W",
                              "S.S.S.W.",
                              ".S.W.W.S",
                              "S.S.W.W.",
                              ".W.W.W.S",
                              "W.W.S.S."};
            int expected__ = 7;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 5:
        {
            string field[] = {"W.SSWWSSSW.SS",
                              ".SSSSW.SSWWWW",
                              ".WWWWS.WSSWWS",
                              "SS.WSS..W.WWS",
                              "WSSS.SSWS.W.S",
                              "WSS.WS...WWWS",
                              "S.WW.S.SWWWSW",
                              "WSSSS.SSW...S",
                              "S.WWSW.WWSWSW",
                              ".WSSS.WWSWWWS",
                              "..SSSS.WWWSSS",
                              "SSWSWWS.W.SSW",
                              "S.WSWS..WSSS.",
                              "WS....W..WSS."};
            int expected__ = 24;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 6:
        {
            string field[] = {"WW..SS",
                              "WW..SS",
                              "......",
                              "......",
                              "SS..WW",
                              "SS..WW"};
            int expected__ = 2;

            clock_t start__ = clock();
            int received__ = WolvesAndSheep().getmin(vector<string>(field, field + (sizeof field / sizeof field[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 7: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolvesAndSheep().getmin(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 8: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolvesAndSheep().getmin(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 9: {
			string field[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WolvesAndSheep().getmin(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
        default:
            return -1;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        moj_harness::run_test();
    }
    else
    {
        for (int i = 1; i < argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
    system("pause");
}
// END CUT HERE
