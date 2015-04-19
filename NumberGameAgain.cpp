#include <bits/stdc++.h>
using namespace std;

vector <long long> a;

int bs(long long n)
{
	int l = 0, h = a.size()-1, m;

	while(l <= h) {
		m = (l+h)>>1;

		if(n == a[m]) return m;
		else if(n > a[m]) l = m+1;
		else h = m-1;
	}
	return -1;
}

bool findparent(long long n)
{
	if(!n) return 0;
	if(bs(n) == -1) return findparent(n>>1);
	else return 1;
}

class NumberGameAgain {
public:
    long long solve( int k, vector<long long> table ) {
		a = table;

		sort(a.begin(), a.end());

		int i = 0;
		while(i < a.size()) {
			if(findparent(a[i]>>1)) a.erase(a.begin()+i);
			else i++;
		}

		long long ans = (1LL<<k)-2;
		for(int i = 0; i < a.size(); i++) ans -= (1LL<<(k-(int) (log2(a[i]))))-1;
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
			int k                     = 3;
			long long table[]         = {2, 4, 6};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int k                     = 5;
			long long table[]         = {2, 3};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int k                     = 5;
			long long table[]         = {};
			long long expected__      = 30;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int k                     = 40;
			long long table[]         = {2, 4, 8, 16, 32141531, 2324577, 1099511627775LL, 2222222222LL, 33333333333LL, 4444444444LL, 2135};
			long long expected__      = 549755748288LL;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int k                     = 40;
			long long table[]         = {};
			long long expected__      = 1099511627774LL;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int k                     = ;
			long long table[]         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = NumberGameAgain().solve(k, vector<long long>(table, table + (sizeof table / sizeof table[0])));
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
