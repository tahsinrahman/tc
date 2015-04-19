#include <bits/stdc++.h>
using namespace std;

class GreenWarfare {
public:
	int minimumEnergyCost( vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius ) {

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
			int canonX[]              = { 0 };
			int canonY[]              = { 0 };
			int baseX[]               = {1,2,3};
			int baseY[]               = {0,0,0};
			int plantX[]              = {3};
			int plantY[]              = {3};
			int energySupplyRadius    = 4;
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int canonX[]              = { 0 };
			int canonY[]              = { 0 };
			int baseX[]               = {1,2,3};
			int baseY[]               = {0,0,0};
			int plantX[]              = {2};
			int plantY[]              = {2};
			int energySupplyRadius    = 4;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int canonX[]              = {3,6};
			int canonY[]              = {3,6};
			int baseX[]               = {1,2,3,4,5};
			int baseY[]               = {5,4,2,3,1};
			int plantX[]              = {1,2,5};
			int plantY[]              = {1,2,5};
			int energySupplyRadius    = 5;
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int canonX[]              = {0};
			int canonY[]              = {0};
			int baseX[]               = {-10,-10,10};
			int baseY[]               = {10,-10,0};
			int plantX[]              = {10,10,-10};
			int plantY[]              = {10,-10,0};
			int energySupplyRadius    = 10;
			int expected__            = 200;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int canonX[]              = {0};
			int canonY[]              = {0};
			int baseX[]               = {3};
			int baseY[]               = {3};
			int plantX[]              = {1,2,3};
			int plantY[]              = {0,0,0};
			int energySupplyRadius    = 4;
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int canonX[]              = ;
			int canonY[]              = ;
			int baseX[]               = ;
			int baseY[]               = ;
			int plantX[]              = ;
			int plantY[]              = ;
			int energySupplyRadius    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int canonX[]              = ;
			int canonY[]              = ;
			int baseX[]               = ;
			int baseY[]               = ;
			int plantX[]              = ;
			int plantY[]              = ;
			int energySupplyRadius    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int canonX[]              = ;
			int canonY[]              = ;
			int baseX[]               = ;
			int baseY[]               = ;
			int plantX[]              = ;
			int plantY[]              = ;
			int energySupplyRadius    = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GreenWarfare().minimumEnergyCost(vector <int>(canonX, canonX + (sizeof canonX / sizeof canonX[0])), vector <int>(canonY, canonY + (sizeof canonY / sizeof canonY[0])), vector <int>(baseX, baseX + (sizeof baseX / sizeof baseX[0])), vector <int>(baseY, baseY + (sizeof baseY / sizeof baseY[0])), vector <int>(plantX, plantX + (sizeof plantX / sizeof plantX[0])), vector <int>(plantY, plantY + (sizeof plantY / sizeof plantY[0])), energySupplyRadius);
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
