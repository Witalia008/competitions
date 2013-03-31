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

const int N = 55;
const int K = 10;

long long F[N][N][1 << K];

class TaroCards
{
public:
    long long getNumber(vector<int> first, vector<int> second, int Kc)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < (1 << K); ++k)
                    F[i][j][k] = 0;
        F[0][0][0] = 1;
        int n = first.size();
        for (int i = 0; i < n; ++i)
        {
            --first[i];
            --second[i];
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < (1 << K); ++k)
                {
                    F[i + 1][j + (first[i] >= K)][k | (first[i] < K ? (1 << first[i]) : 0) | (1 << second[i])] += F[i][j][k];
                    F[i + 1][j][k] += F[i][j][k];
                }
            }
        }
        auto cnt_b = [](int x) {
            int res = 0;
            for (int i = 0; i < K; ++i)
                res += ((x >> i) & 1);
            return res;
        };
        long long ans = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < (1 << K); ++k)
            {
                if (j + cnt_b(k) <= Kc)
                    ans += F[n][j][k];
            }
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

    int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed)
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
            int first[] = {1, 2};
            int second[] = {2, 3};
            int K = 2;
            long long expected__ = 3;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            int first[] = {3, 1, 2};
            int second[] = {1, 1, 1};
            int K = 3;
            long long expected__ = 8;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            int first[] = {4, 2, 1, 3};
            int second[] = {1, 2, 3, 4};
            int K = 5;
            long long expected__ = 16;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            int first[] = {1, 2, 3, 4, 5, 6, 7};
            int second[] = {2, 1, 10, 9, 3, 2, 2};
            int K = 3;
            long long expected__ = 17;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 4:
        {
            int first[] = {1};
            int second[] = {2};
            int K = 1;
            long long expected__ = 1;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 5:
        {
            int first[] = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5};
            int second[] = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4};
            int K = 14;
            long long expected__ = 2239000;

            clock_t start__ = clock();
            long long received__ = TaroCards().getNumber(vector<int>(first, first + (sizeof first / sizeof first[0])), vector<int>(second, second + (sizeof second / sizeof second[0])), K);
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 6: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 7: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 8: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
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
