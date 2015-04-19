#include <bits/stdc++.h>
using namespace std;

class ColoringRectangle {
public:
	int chooseDisks( int width, int height, vector <int> red, vector <int> blue ) {
		sort(red.rbegin(), red.rend());
		sort(blue.rbegin(), blue.rend());

		int p = solve(width, height, red, blue); 
		int q = solve(width, height, blue, red);

		if(min(p, q) != 100000) return min(p, q);
		return -1;
	}
	int solve( int width, int h, vector <int> red, vector <int> blue ) {
		int i = 0, j = 0, n = red.size(), m = blue.size(), f = 1, cnt = 0;

		double p = 0, cover = 0;
		while(1) {
			if(f) {
				if(i == n) break;
				p = sqrt((red[i]/2.0)*(red[i]/2.0)-(h/2.0)*(h/2.0));
				++cnt;
				cover += 2.0*p;
				++i;
			}
			else {
				if(j == m) break;
				p = sqrt((blue[j]/2.0)*(blue[j]/2.0)-(h/2.0)*(h/2.0));
				++cnt;
				cover += 2.0*p;
				++j;
			}
			f = 1-f;
			if(cover >= width) return cnt;
		}
		return 100000;
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
			int width                 = 11;
			int height                = 3;
			int red[]                 = {5,5};
			int blue[]                = {2,5};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int width                 = 30;
			int height                = 5;
			int red[]                 = {4,10,7,8,10};
			int blue[]                = {5,6,11,7,5};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int width                 = 16;
			int height                = 4;
			int red[]                 = {6,5,7};
			int blue[]                = {5};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int width                 = 4;
			int height                = 4;
			int red[]                 = {5};
			int blue[]                = {6};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int width                 = 6;
			int height                = 2;
			int red[]                 = {6,6};
			int blue[]                = {2};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int width                 = ;
			int height                = ;
			int red[]                 = ;
			int blue[]                = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColoringRectangle().chooseDisks(width, height, vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
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
