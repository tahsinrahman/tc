#include <bits/stdc++.h>
using namespace std;

class SplitIntoPairs {
public:
    int makepairs( vector <int> A, int X ) {
		int n = A.size();
		vector <int> pos, neg;

		for(int i = 0; i < n; i++) {
			if(A[i] < 0) neg.push_back(A[i]);
			else pos.push_back(A[i]);
		}
		if(!(pos.size()&1)) return n>>1;

		if((long long) *max_element(neg.begin(), neg.end()) * *min_element(pos.begin(), pos.end()) >= X) return n>>1;
		return (n>>1) - 1;
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
			int A[]                   = {2,-1};
			int X                     = -1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1,-1};
			int X                     = -1;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {-5,-4,2,3};
			int X                     = -1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {5,-7,8,-2,-5,3};
			int X                     = -7;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {3,4,5,6,6,-6,-4,-10,-1,-9};
			int X                     = -2;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1000000,1000000};
			int X                     = -5;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SplitIntoPairs().makepairs(vector <int>(A, A + (sizeof A / sizeof A[0])), X);
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
