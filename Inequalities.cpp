#include <bits/stdc++.h>
using namespace std;

vector <int> signs[5];

int check(double n)
{
	int cnt = 0;
	for(int i = 0; i < signs[0].size(); ++i) if(n <= signs[0][i]) ++cnt;
	for(int i = 0; i < signs[1].size(); ++i) if(n < signs[1][i]) ++cnt;
	for(int i = 0; i < signs[2].size(); ++i) if(n >= signs[2][i]) ++cnt;
	for(int i = 0; i < signs[3].size(); ++i) if(n > signs[3][i]) ++cnt;
	for(int i = 0; i < signs[4].size(); ++i) if(n == signs[4][i]) ++cnt;
	return cnt;
}

int toInt(string a, int idx)
{
	int n = 0;
	for(int i = idx, l = a.length(); i < l; ++i) n = n*10 + a[i]-'0';
	return n;
}

class Inequalities {
public:
	int maximumSubset( vector <string> inequalities ) {
		for(int i = 0; i < 5; ++i) signs[i].clear();


		for(int i = 0, s = inequalities.size(); i < s; ++i) {
			if(inequalities[i][2] == '<' && inequalities[i][3] == '=') signs[0].push_back(toInt(inequalities[i], 5));
			else if(inequalities[i][2] == '<') signs[1].push_back(toInt(inequalities[i], 4));
			else if(inequalities[i][2] == '>' && inequalities[i][3] == '=') signs[2].push_back(toInt(inequalities[i], 5));
			else if(inequalities[i][2] == '>') signs[3].push_back(toInt(inequalities[i], 4));
			else if(inequalities[i][2] == '=') signs[4].push_back(toInt(inequalities[i], 4));
		}
			

		int mx = 0;
		for(double n = -1001.0; n < 1002; n += 0.5) mx = max(mx, check(n));
		return mx;

/*
		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < signs[i].size(); ++j) cout << signs[i][j] << ' ';
			cout << endl;
		}

		double l = -10000.0, h = +10000.0, ml, mh, ans;
		while(h-l > 1e-5) {
			ml = l + (h-l)/3.0;
			mh = h - (h-l)/3.0;

			cout << l << ' ' << check(l) << ' ' << h << ' ' << check(h) << endl;

			if(check(h) >= check(l)) {
				ans = h;
				l = ml;
			}
			else h = mh;
		}
		cout << ans << endl;
		return check(ans);
		*/
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
			string inequalities[]     = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string inequalities[]     = {"X < 0","X <= 0"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string inequalities[]     = {"X = 1","X = 2","X = 3","X > 0"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string inequalities[]     = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string inequalities[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string inequalities[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string inequalities[]     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Inequalities().maximumSubset(vector <string>(inequalities, inequalities + (sizeof inequalities / sizeof inequalities[0])));
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
