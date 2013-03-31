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

class PackingBallsDiv1
{
public:
    int minPacks(int K, int A, int B, int C, int D)
    {
        //generate
        vector<int> X(K);
        X[0] = A;
        for (int i = 1; i < K; ++i)
            X[i] = (X[i - 1] * 1ll * B + C) % D + 1;

        //first try
        int res = 0;
        for (int i = 0; i < K; ++i)
        {
            res += X[i] / K;
            X[i] %= K;
        }

        sort(X.begin(), X.end(), [](int a, int b) { return a > b; });
        int mx = X[0];
        for (int i = 0; i + 1 < X.size(); ++i)
            mx = min(mx, i + 1 + X[i + 1]);

        return res + mx;
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
            int K = 3;
            int A = 4;
            int B = 2;
            int C = 5;
            int D = 6;
            int expected__ = 4;

            clock_t start__ = clock();
            int received__ = PackingBallsDiv1().minPacks(K, A, B, C, D);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            int K = 1;
            int A = 58;
            int B = 23;
            int C = 39;
            int D = 93;
            int expected__ = 58;

            clock_t start__ = clock();
            int received__ = PackingBallsDiv1().minPacks(K, A, B, C, D);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            int K = 23;
            int A = 10988;
            int B = 5573;
            int C = 4384;
            int D = 100007;
            int expected__ = 47743;

            clock_t start__ = clock();
            int received__ = PackingBallsDiv1().minPacks(K, A, B, C, D);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            int K = 100000;
            int A = 123456789;
            int B = 234567890;
            int C = 345678901;
            int D = 1000000000;
            int expected__ = 331988732;

            clock_t start__ = clock();
            int received__ = PackingBallsDiv1().minPacks(K, A, B, C, D);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 4: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 5: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 6: {
			int K                     = ;
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int D                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PackingBallsDiv1().minPacks(K, A, B, C, D);
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
