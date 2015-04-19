#include <bits/stdc++.h>
using namespace std;

class ManySquares {
public:
	int howManySquares( vector <int> sticks ) {
		vector <int> cnt(2000);

		int result = 0;
		for(int i = 0; i < sticks.size(); ++i) {
			++cnt[sticks[i]];
			if(cnt[sticks[i]] == 4) { ++result; cnt[sticks[i]] = 0; }
		}

		return result;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
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
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int sticks[]              = {1,1,2,2,1,1,2};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sticks[]              = {3, 1, 4, 4, 4, 10, 10, 10, 10} ;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sticks[]              = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sticks[]              = {1,1,1,2,2,2,3,3,3,4,4,4};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sticks[]              = {1,1,1,2,1,1,1,3,1,1,1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int sticks[]              = {2,2,4,4,8,8};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int sticks[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sticks[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int sticks[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ManySquares().howManySquares(vector <int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
