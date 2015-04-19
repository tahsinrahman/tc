#include <bits/stdc++.h>
using namespace std;

int n, m, nn, mm, row, colum;
map <int , map<int, vector <string> > > dp;

void check(vector <string> a)
{
	int i, j, k, f;
	string tmp;

	row = 0;
	for(i = 0; i < n; i++) {
		tmp = string(a[i].rbegin(), a[i].rend());
		if(a[i] == tmp) row++;
	}

	colum = 0;
	for(i = 0; i < m; i++) {
		f = 1;
		for(j = 0, k = n-1; j < n/2; j++, k--) {
			if(a[j][i] != a[k][i]) {
				f = 0;
				break;
			}
		}
		if(f) colum++;
	}
}
				





int f(int i, int j, vector <string> a)
{
	if(i == n || j == m) return 10000;


	check(a);

	if(row >= nn && colum >= mm) return 0;


	int p, q, r, s;

	p = f(i+1, j, a);
	q = f(i, j+1, a);
	
	if(a[i][j] == '1') {
		a[i][j] = '0';

		check(a);
		if(row >= nn && colum >= mm) return 1;


		r = 1 + f(i+1, j, a);
		s = 1 + f(i, j+1, a);
	}

	else {
		a[i][j] = '1';

		check(a);
		if(row >= nn && colum >= mm) return 1;

		r = 1 + f(i+1, j, a);
		s = 1 + f(i, j+1, a);
	}

	return min(p, min(q, min(r, s)));
}




class PalindromeMatrixDiv2 {
public:
    int minChange( vector <string> A, int rowCount, int columnCount ) {
		n = A.size();
		m = A[0].length();
		nn = rowCount;
		mm = columnCount;

		return f(0, 0, A);
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
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 2;
			int columnCount           = 2;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 3;
			int columnCount           = 2;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A[]                = {"01"
,"10"};
			int rowCount              = 1;
			int columnCount           = 1;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
	/*	case 3: {
			string A[]                = {"1110"
,"0001"};
			int rowCount              = 0;
			int columnCount           = 0;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
	/*	case 4: {
			string A[]                = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"};
			int rowCount              = 2;
			int columnCount           = 2;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		} */

		// custom cases

      case 5: {
			string A[]                = {"100100", "111110", "000001", "100100", "100010", "011110"};
			int rowCount              = 3;
			int columnCount           = 3;
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromeMatrixDiv2().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
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
