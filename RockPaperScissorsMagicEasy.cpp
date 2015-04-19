#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long nCr(int n, int r)
{
	if(n == r) return 1;
	if(r == 0) return 1;

	return (nCr(n-1, r)%mod + nCr(n-1, r-1)%mod)%mod;
}

long long expo(int a, int b)
{
	long long ans = 1;
	while(b) {
		if(b&1) ans = ((long long) ans*a)%mod;
		b >>= 1;
		a = ((long long)a*a)%mod;
	}
	return ans%mod;
}


class RockPaperScissorsMagicEasy {
public:
    int count( vector <int> card, int score ) {
		int n = card.size();
		if(score > card.size()) return 0;

//		return (nCr(n, min(score, n-score)) * expo(2, n-score))%mod;
		return (nCr(n, min(score, n-score)) * (1LL<<(n-score))%mod)%mod;
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
			int card[]                = {0,1,2};
			int score                 = 2;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int card[]                = {1,2};
			int score                 = 0;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int card[]                = {2,2,1,0,0};
			int score                 = 10;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int card[]                = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
			int score                 = 7;
			int expected__            = 286226628;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int card[]                = {0,1,2,0,1,2,2,1,0};
			int score                 = 8;
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int card[]                = ;
			int score                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/**/      case 6: {
			int card[]                = {2, 1, 1, 2, 0, 2, 2, 0, 0, 0, 0, 1, 1, 2, 1, 0, 2, 0, 1, 2, 1, 0, 0, 2, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 1, 2, 1, 0, 0, 0, 2, 2, 1, 0, 1, 1, 0, 2, 0, 2, 0, 0, 1, 2, 0, 2, 1, 2, 0, 2, 1, 2, 2, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 2, 2, 2, 1, 2, 0, 1, 2, 0, 1, 2, 1, 1, 2, 2, 2, 0, 0};
			int score                 = 66;
			int expected__            = 34094492;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}/**/
/*      case 7: {
			int card[]                = ;
			int score                 = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RockPaperScissorsMagicEasy().count(vector <int>(card, card + (sizeof card / sizeof card[0])), score);
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
