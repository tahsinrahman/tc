#include <bits/stdc++.h>
using namespace std;

int n, m, k;

bool check(vector <string> board)
{
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(board[i][j] == 'B') return 0;
	return 1;
}

class BichromePainting {
public:
	string isThatPossible( vector <string> board, int K ) {
		n = board.size();
		m = board[0].length();
		k = K;

		
		while(1) {
			if(check(board)) return "Possible";
			int f = 1;
			for(int i = 0; i < n-k+1; ++i) {
				for(int j = 0; j < m-k+1; ++j) {
					int bl, w, q;
					bl = w = q = 0;
					for(int a = 0; a < k; ++a) {
						for(int b = 0; b < k; ++b) {
							if(board[a+i][b+j] == 'B') ++bl;
							else if(board[a+i][b+j] == 'W') ++w;
							else ++q;
						}
					}
					if((w && w+q == k*k) || (bl && bl+q == k*k)) {
						for(int a = 0; a < k; ++a) for(int b = 0; b < k; ++b) board[a+i][b+j] = '?';
						f = 0;
					}
				}
			}
			if(f) return "Impossible";
		}
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
			string board[]            = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"};
			int k                     = 3;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"BW",
 "WB"}
;
			int k                     = 2;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
;
			int k                     = 2;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int k                     = 2;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
;
			int k                     = 1;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"BB",
 "BB"};
			int k                     = 2;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int k                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = BichromePainting().isThatPossible(vector <string>(board, board + (sizeof board / sizeof board[0])), k);
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
