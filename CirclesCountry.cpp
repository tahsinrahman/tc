#include <bits/stdc++.h>
using namespace std;

bool check(int h, int k, int r, int x, int y)
{
	return (x-h)*(x-h)+(y-k)*(y-k) <= r*r;
}

class CirclesCountry {
public:
	int leastBorders( vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2 ) {
		int n = X.size();
		vector <bool> taken(n);
		
		int cnt = 0;
		for(int i = 0; i < n; ++i) cnt += check(X[i], Y[i], R[i], x1, y1)^check(X[i], Y[i], R[i], x2, y2);

		return cnt;
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
			int X[]                   = {0};
			int Y[]                   = {0};
			int R[]                   = {2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 5;
			int y2                    = 1;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {0,-6,6};
			int Y[]                   = {0,1,2};
			int R[]                   = {2,2,2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 5;
			int y2                    = 1;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {1,-3,2,5,-4,12,12};
			int Y[]                   = {1,-1,2,5,5,1,1};
			int R[]                   = {8,1,2,1,1,1,2};
			int x1                    = -5;
			int y1                    = 1;
			int x2                    = 12;
			int y2                    = 1;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {-3,2,2,0,-4,12,12,12};
			int Y[]                   = {-1,2,3,1,5,1,1,1};
			int R[]                   = {1,3,1,7,1,1,2,3};
			int x1                    = 2;
			int y1                    = 3;
			int x2                    = 13;
			int y2                    = 2;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int X[]                   = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
			int Y[]                   = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
			int R[]                   = {135,42,70,39,89,39,43,150,10,120,16,8};
			int x1                    = 102;
			int y1                    = 16;
			int x2                    = 19;
			int y2                    = -108;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int X[]                   = ;
			int Y[]                   = ;
			int R[]                   = ;
			int x1                    = ;
			int y1                    = ;
			int x2                    = ;
			int y2                    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = CirclesCountry().leastBorders(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])), x1, y1, x2, y2);
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
