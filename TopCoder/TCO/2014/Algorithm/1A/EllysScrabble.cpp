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

class EllysScrabble {
public:
   string getMin( string letters, int maxDistance ) {
	   auto Abs = [](int a) { return a < 0 ? -a : a; };
	   string res = "";
	   for (int i = 0; i < letters.size(); ++i) {
		   if (i >= maxDistance && letters[i - maxDistance] != ' ') {
			   res += letters[i - maxDistance];
			   continue;
		   }
		   for (char j = 'A'; j <= 'Z'; ++j) {
			   for (int k = 0; k < letters.size(); ++k) {
				   if (Abs(i - k) <= maxDistance && letters[k] == j) {
					   res += letters[k];
					   letters[k] = ' ';
					   break;
				   }
			   }
			   if (res.size() == i + 1)
				   break;
		   }
	   }
	   return res;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string letters            = "TOPCODER";
			int maxDistance           = 3;
			string expected__         = "CODTEPOR";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string letters            = "ESPRIT";
			int maxDistance           = 3;
			string expected__         = "EIPRST";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string letters            = "BAZINGA";
			int maxDistance           = 8;
			string expected__         = "AABGINZ";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string letters            = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int maxDistance           = 9;
			string expected__         = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string letters            = "GOODLUCKANDHAVEFUN";
			int maxDistance           = 7;
			string expected__         = "CADDGAHEOOFLUKNNUV";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string letters            = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int maxDistance           = 6;
			string expected__         = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			string letters            = "ABRACADABRA";
			int maxDistance           = 2;
			string expected__         = "AABARACBDAR";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
	system("pause");
}
// END CUT HERE
