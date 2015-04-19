#include <bits/stdc++.h>
using namespace std;

double area(int a, int b, int c, int d, int e, int f)
{
	return abs(a*(d-f) + c*(f-b) + e*(b-d) )/2.0;
}

class TrianglesContainOriginEasy {
public:
    int count( vector <int> x, vector <int> y ) {
		int s = x.size();
		int ans = 0;

		for(int k = 0; k < s; k++) {
			for(int i = k+1; i < s; i++) {
				for(int j = i+1; j < s; j++) {
					double a = area(x[i], y[i], x[j], y[j], x[k], y[k]);
					double b = area(x[i], y[i], x[j], y[j], 0, 0);
					double c = area(x[i], y[i], x[k], y[k], 0, 0); 
					double d = area(x[k], y[k], x[j], y[j], 0, 0);

//					cout << x[i] << ' ' << y[i] << endl;
//					cout << x[j] << ' ' << y[j] << endl;
//					cout << x[k] << ' ' << y[k] << endl;
//					cout << endl;

					
					if(a == b+c+d) ans++;
//					cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
				}
			}
		}
//		cout << "end\n";
		return ans;
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
			int x[]                   = {-1,-1,1};
			int y[]                   = {1,-1,0};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-1,-1,1,2};
			int y[]                   = {1,-1,2,-1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-1,-2,3,3,2,1};
			int y[]                   = {-2,-1,1,2,3,3};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6};
			int y[]                   = {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9};
			int expected__            = 256;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TrianglesContainOriginEasy().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
