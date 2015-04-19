#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, f, taken[11], sz, subSz;
int digits[12];
string ans;
int substrings[1000000];

class ColorfulStrings {
public:
	void color() {
		vector <int> check(1000000);
		for(int i = 0; i < n; ++i) {
			int res = 1;
			for(int j = i; j < n; ++j) {
				res *= digits[j];
				if(check[res]) return;
				check[res] = 1;
			}
		}
		for(int i = 0; i < n; ++i) cout << digits[i];
		cout << endl;
		++cnt;
		if(cnt == k) {
			f = 1;
			ans = "";
			for(int i = 0; i < n; ++i) ans += (char) digits[i]+'0';
		}
	}

	void bt() {
		if(f) return;


		if(sz == n) {
			color();
			return;
		}

		for(int i = n==2?1:2; i < 10; ++i) {
			if(!taken[i]) {
				taken[i] = 1;
				digits[sz] = i;
				++sz;
				bt();
				--sz;
				taken[i] = 0;
			}
		}
	}

	string getKth( int N, int K ) {
		n = N;
		k = K;
		cnt = 0;
		f = 0;

		if(n > 8) return "";
		if(n == 1) {
			k -= 2;
			if(k == -1) return "0";
			if(k == 0) return "1";
		}

		sz = 0;
		bt();
		if(f) return ans;//string(ans.begin(), ans.end());
		return "";
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
			int n                     = 3;
			int k                     = 4;
			string expected__         = "238";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			int k                     = 2000;
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 5;
			int k                     = 1;
			string expected__         = "23457";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 2;
			int k                     = 22;
			string expected__         = "52";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 6;
			int k                     = 464;
			string expected__         = "257936";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int n                     = 1;
			int k                     = 1;
			string expected__         = "0";

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int n                     = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = ColorfulStrings().getKth(n, k);
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
