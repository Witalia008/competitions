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

class TaroString
{
public:
    string getAnswer(string S)
    {
        int cnt[3] = {};
        for (auto i : S)
        {
            if (i == 'C')
                ++cnt[0];
            else if (i == 'A')
                ++cnt[1];
            else if (i == 'T')
                ++cnt[2];
        }
        if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1)
            return "Impossible";
        if ((S.find("A") > S.find("C") && S.find("T") > S.find("A")))
            return "Possible";
        return "Impossible";
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

    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed)
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
            cerr << "    Expected: \"" << expected << "\"" << endl;
            cerr << "    Received: \"" << received << "\"" << endl;
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum)
    {
        switch (casenum)
        {
        case 0:
        {
            string S = "XCYAZTX";
            string expected__ = "Possible";

            clock_t start__ = clock();
            string received__ = TaroString().getAnswer(S);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            string S = "CTA";
            string expected__ = "Impossible";

            clock_t start__ = clock();
            string received__ = TaroString().getAnswer(S);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            string S = "ACBBAT";
            string expected__ = "Impossible";

            clock_t start__ = clock();
            string received__ = TaroString().getAnswer(S);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            string S = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
            string expected__ = "Possible";

            clock_t start__ = clock();
            string received__ = TaroString().getAnswer(S);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 4:
        {
            string S = "CCCATT";
            string expected__ = "Impossible";

            clock_t start__ = clock();
            string received__ = TaroString().getAnswer(S);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 5: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TaroString().getAnswer(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 6: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TaroString().getAnswer(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 7: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TaroString().getAnswer(S);
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
