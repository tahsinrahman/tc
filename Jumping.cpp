#include <bits/stdc++.h>
using namespace std;

class Jumping {
public:
    string ableToGet( int x, int y, vector <int> jumpLengths ) {
		long long a = 0, b = 0;

		for(int i = 0; i < jumpLengths.size(); i++) {
			int r = jumpLengths[i];
			if(r <= a) a = a-r;
			else if(r <= b) a = 0;
			else a = r-b;
			b = b+r;
		}
		long long p = x*x + y*y;
		return (a*a <= p && p <= b*b) ? "Able" : "Not able";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x                     = 5;
			int y                     = 4;
			int jumpLengths[]         = {2, 5};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {4};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 3;
			int y                     = 4;
			int jumpLengths[]         = {6};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 0;
			int y                     = 1;
			int jumpLengths[]         = {100, 100};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 300;
			int y                     = 400;
			int jumpLengths[]         = {500};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,10};
			string expected__         = "Able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 11;
			int y                     = 12;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,100};
			string expected__         = "Not able";

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int y                     = ;
			int jumpLengths[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Jumping().ableToGet(x, y, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
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
