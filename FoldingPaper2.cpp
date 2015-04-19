#include <bits/stdc++.h>
using namespace std;

class FoldingPaper2 {
public:
	int solve( int W, int H, int A ) {
		if(H > W) swap(H, W);

		int mn = INT_MAX;
		for(int i = 1; i <= A; ++i) if(A%i == 0 && i <= H && A/i <= W) mn = min(mn, (int) ceil(log2((double) W/(A/i))) + (int) ceil(log2((double) H/i)));

		return mn == INT_MAX?-1:mn;
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
			int W                     = 1000000000;//5;
			int H                     = 1000000000;//3;
			int A                     = 100000;//12;
			int expected__            = 44;//1;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int W                     = 2;
			int H                     = 2;
			int A                     = 3;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int W                     = 4;
			int H                     = 4;
			int A                     = 1;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int W                     = 127;
			int H                     = 129;
			int A                     = 72;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int W                     = 1;
			int H                     = 100000;
			int A                     = 100000;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int W                     = 1;
			int H                     = 1;
			int A                     = 2;
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      	case 6: {
			int W                     = 103;
			int H                     = 201;
			int A                     = 10403;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			int W                     = 4;
			int H                     = 75;
			int A                     = 222;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int W                     = ;
			int H                     = ;
			int A                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoldingPaper2().solve(W, H, A);
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
