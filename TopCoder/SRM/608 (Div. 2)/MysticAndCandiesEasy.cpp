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

class MysticAndCandiesEasy
{
public:
    int minBoxes(int C, int X, vector<int> high)
    {
        sort(high.begin(), high.end());
        reverse(high.begin(), high.end());
        vector<int> get(high.size());
        for (int i = get.size() - 1; i >= 0; --i)
        {
            get[i] = min(C, high[i]);
            C -= get[i];
        }
        for (int i = 0, sum = 0; i < get.size(); ++i)
        {
            sum += get[i];
            if (sum >= X)
                return i + 1;
        }
        return high.size();
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
            int C = 10;
            int X = 10;
            int high[] = {20};
            int expected__ = 1;

            clock_t start__ = clock();
            int received__ = MysticAndCandiesEasy().minBoxes(C, X, vector<int>(high, high + (sizeof high / sizeof high[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            int C = 10;
            int X = 7;
            int high[] = {3, 3, 3, 3, 3};
            int expected__ = 4;

            clock_t start__ = clock();
            int received__ = MysticAndCandiesEasy().minBoxes(C, X, vector<int>(high, high + (sizeof high / sizeof high[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            int C = 100;
            int X = 63;
            int high[] = {12, 34, 23, 45, 34};
            int expected__ = 3;

            clock_t start__ = clock();
            int received__ = MysticAndCandiesEasy().minBoxes(C, X, vector<int>(high, high + (sizeof high / sizeof high[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            int C = 19;
            int X = 12;
            int high[] = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
            int expected__ = 22;

            clock_t start__ = clock();
            int received__ = MysticAndCandiesEasy().minBoxes(C, X, vector<int>(high, high + (sizeof high / sizeof high[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 4:
        {
            int C = 326;
            int X = 109;
            int high[] = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
            int expected__ = 15;

            clock_t start__ = clock();
            int received__ = MysticAndCandiesEasy().minBoxes(C, X, vector<int>(high, high + (sizeof high / sizeof high[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 5: {
			int C                     = ;
			int X                     = ;
			int high[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 6: {
			int C                     = ;
			int X                     = ;
			int high[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 7: {
			int C                     = ;
			int X                     = ;
			int high[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
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
