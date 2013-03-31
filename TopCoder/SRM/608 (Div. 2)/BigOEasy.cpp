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

vector<bool> used;
int cnt_cycl;

void dfs(vector<string> &g, int v, int targ)
{
    used[v] = true;
    for (int to = 0; to < g.size(); ++to)
    {
        if (g[v][to] == 'Y')
        {
            if (!used[to])
                dfs(g, to, targ);
            else if (to == targ)
                ++cnt_cycl;
        }
    }
}

class BigOEasy
{
public:
    string isBounded(vector<string> graph)
    {
        bool bounded = true;
        int n = graph.size();
        for (int i = 0; i < n; ++i)
        {
            used.assign(n, false);
            cnt_cycl = 0;
            dfs(graph, i, i);
            if (cnt_cycl > 1)
                bounded = false;
        }
        return bounded ? "Bounded" : "Unbounded";
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
            string graph[] = {"NYY",
                              "YNY",
                              "YYN"};
            string expected__ = "Unbounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 1:
        {
            string graph[] = {"NYYN",
                              "NNNY",
                              "NNNY",
                              "NNNN"};
            string expected__ = "Bounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 2:
        {
            string graph[] = {"NYN",
                              "NNY",
                              "YNN"};
            string expected__ = "Bounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 3:
        {
            string graph[] = {"NYYN",
                              "YNNN",
                              "NNNY",
                              "NNYN"};
            string expected__ = "Bounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 4:
        {
            string graph[] = {"NYY",
                              "YNN",
                              "YNN"};
            string expected__ = "Unbounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 5:
        {
            string graph[] = {"NYNYN",
                              "NNYNY",
                              "YNNNN",
                              "NNNNN",
                              "YNNNN"};
            string expected__ = "Unbounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 6:
        {
            string graph[] = {"NYYN",
                              "NNYN",
                              "NNNY",
                              "YNNN"};
            string expected__ = "Unbounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }
        case 7:
        {
            string graph[] = {"NYYNNNNYNNYNYNNNNYYNNYNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
                              "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNYYYYYNYYN",
                              "YYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
                              "YYYNYNNYNNYYYNNNYYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYYYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN",
                              "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYNNYNNNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYYYYYYYYNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYNYYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYYNNNNNNYYNYNNNN",
                              "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "YYYNYNNYYNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYYNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYNNYYYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYNYNNYNYYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNYNNNNNNNNNNYNNNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYYYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYYNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNYNNNYNNNNNNNYYNYNNNN",
                              "YYYNYYNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN",
                              "YYYNYNNYNNYYYYNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYY",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNYNNNNNYNNNNNNNYYNYNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYYYYYYYNYYN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNYNN",
                              "NYYNNNNYNNYYYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNYNNNNNNNYNNNNNNNYYNYNNNN",
                              "YYYNYNNYNNYYYNYNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYNYNYNYYYNYNYNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNYNNYYNYNNNN",
                              "NYYNNNNYNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNYYNNNNNNNYYNYNNNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYNNNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYYNNYNYYYNYNYNN",
                              "YYYNYNNYNNYYYNNYNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNYYYNYNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYYYYN",
                              "NYYNYNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
                              "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNN",
                              "NYYNNNNNNNYNYNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYNYNYNN",
                              "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYNYYN",
                              "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNYNNNNYNNNNNNNYYNYNNNN",
                              "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYNN",
                              "YYYNYYYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN"};
            string expected__ = "Bounded";

            clock_t start__ = clock();
            string received__ = BigOEasy().isBounded(vector<string>(graph, graph + (sizeof graph / sizeof graph[0])));
            return verify_case(casenum, expected__, received__, clock() - start__);
        }

            // custom cases

            /*      case 8: {
			string graph[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 9: {
			string graph[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
            /*      case 10: {
			string graph[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
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
