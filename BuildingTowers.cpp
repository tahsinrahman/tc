#include <bits/stdc++.h>
using namespace std;

class BuildingTowers {
public:
    long long maxHeight( int N, int K, vector <int> x, vector <int> t ) {

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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int N                     = 10;
			int K                     = 1;
			int x[]                   = {3,8};
			int t[]                   = {1,1};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 1000000000;
			int K                     = 1000000000;
			int x[]                   = {};
			int t[]                   = {};
			long long expected__      = 999999999000000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 20;
			int K                     = 3;
			int x[]                   = {4,7,13,15,18};
			int t[]                   = {8,22,1,55,42};
			long long expected__      = 22;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 780;
			int K                     = 547990606;
			int x[]                   = {34,35,48,86,110,170,275,288,313,321,344,373,390,410,412,441,499,525,538,568,585,627,630,671,692,699,719,752,755,764,772};
			int t[]                   = {89,81,88,42,55,92,19,91,71,42,72,18,86,89,88,75,29,98,63,74,45,11,68,34,94,20,69,33,50,69,54};
			long long expected__      = 28495511604LL;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 7824078;
			int K                     = 2374;
			int x[]                   = {134668,488112,558756,590300,787884,868112,1550116,1681439,1790994, 1796091,1906637,2005485,2152813,2171716,2255697,2332732,2516853, 2749024,2922558,2930163,3568190,3882735,4264888,5080550,5167938, 5249191,5574341,5866912,5936121,6142348,6164177,6176113,6434368, 6552905,6588059,6628843,6744163,6760794,6982172,7080464,7175493, 7249044};
			int t[]                   = {8,9,171315129,52304509,1090062,476157338,245,6,253638067,37,500, 29060,106246500,129,22402,939993108,7375,2365707,40098,10200444, 3193547,55597,24920935,905027,1374,12396141,525886,41,33,3692, 11502,180,3186,5560,778988,42449532,269666,10982579,48,3994,1,9};
			long long expected__      = 1365130725;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int x[]                   = ;
			int t[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int x[]                   = ;
			int t[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int x[]                   = ;
			int t[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = BuildingTowers().maxHeight(N, K, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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
