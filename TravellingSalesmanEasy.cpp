#include <bits/stdc++.h>
using namespace std;

/*
struct data {
	int dist;
	bool operator < (const data &p) const {
		return dist > p.dist;
	}
};
*/

class TravellingSalesmanEasy {
public:
    int getMaxProfit( int M, vector <int> profit, vector <int> city, vector <int> visit ) {
		vector <priority_queue<int> > q(M+1);

		for(int i = 0; i < profit.size(); i++) q[city[i]].push(profit[i]);

		int ans = 0;
		for(int i = 0; i < visit.size(); i++) {
			if(q[visit[i]].size()) {
				ans += q[visit[i]].top();
				q[visit[i]].pop();
			}
		}
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
			int M                     = 2;
			int profit[]              = {3,10};
			int city[]                = {1,1};
			int visit[]               = {2,1};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int M                     = 1;
			int profit[]              = {3,5,2,6,4};
			int city[]                = {1,1,1,1,1};
			int visit[]               = {1,1,1};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int M                     = 6;
			int profit[]              = {77,33,10,68,71,50,89};
			int city[]                = {4,1,5,6,2,2,1};
			int visit[]               = {6,5,5,6,4};
			int expected__            = 155;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int M                     = 7;
			int profit[]              = {22,91,53,7,80,100,36,65,92,93,19,92,95,3,60,50,39,36,2,30,63,84,2};
			int city[]                = {5,3,4,3,6,5,6,6,5,2,7,6,3,2,6,1,7,4,6,3,7,2,5};
			int visit[]               = {5,7,1,3,6,2,5,7,3,6,3,2,7,3,1,3,1,7,2,3,1,1,3,1,6,1};
			int expected__            = 1003;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int M                     = 85;
			int profit[]              = {94,21,99,27,91,1,64,96,32,39,84,71,97,53,73,20,7,13,33,45,5,85,7,87, 94,37,48,30,5,85,47,62,91,18,71,37,7,25,75,17,40,19,89,85,86,87,45, 12,61,71,32,73,63,89,25,51,60,76,32,2,69,78,28,32,74,44,47,11,82,5, 2,28,54,35,67,44,35,6,70,66,77,7,60,67,33,66,21,91,76,75,16,79,20,24, 91,31,2,50,11,19,93,49,4,7,55,9,95,39,54,12,48,38,73,100,57,97,44,2, 2,51,40,4,51,3,95,93,56,88,60,98,67,7,99,46,71,75,24,82,87,29,92,92, 81,87,34,83,58,46,79,53,38,32,97,41,65,10,54,81,42,37,76,28,11,50, 13,29,15,99,73,72,2,81,39,75,1,54};
			int city[]                = {72,69,19,25,3,65,10,42,37,76,29,34,41,14,46,46,37,55,30,32,84,57,74, 16,10,48,67,31,44,84,11,59,67,63,5,31,28,71,3,21,42,21,61,50,5,79,79, 27,69,33,47,70,76,70,17,73,28,64,77,84,9,6,63,71,17,71,40,9,8,16,76, 76,6,53,47,10,45,31,78,55,13,35,50,43,32,78,78,44,20,56,24,43,80,62, 72,16,5,72,67,29,11,51,64,27,7,44,59,1,40,71,64,63,67,81,72,22,73,59, 21,44,3,18,9,75,72,43,13,44,79,42,58,49,81,44,42,41,35,81,63,74,42,79, 42,39,45,49,18,73,53,36,80,34,75,57,10,79,79,33,48,18,81,3,69,36,37, 49,54,29,17,81,83,13,8,69,5,84};
			int visit[]               = {39,29,15,5,3,65,29,64,60,21,13,10,73,75,44,84,15,61,26,49,31,27,83,24, 16,55,60,74,71,53,68,15,75,15,36,4,47,9,77,45,63,32,77,84,8,68,11,5,18, 80,36,52,42,59,79,83,81,29,43,70,29,19,68,5,83,60,71,66,62,81,85,39,42, 40,69,60,34,12,2,4,31,36,81,33,71,32,68,5,30,59,61,10,71,49,63,30,62, 83,35,56,82,2,14,59,68,74,32,31,3,28,38,54,38};
			int expected__            = 4369;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int M                     = ;
			int profit[]              = ;
			int city[]                = ;
			int visit[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int M                     = ;
			int profit[]              = ;
			int city[]                = ;
			int visit[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int M                     = ;
			int profit[]              = ;
			int city[]                = ;
			int visit[]               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TravellingSalesmanEasy().getMaxProfit(M, vector <int>(profit, profit + (sizeof profit / sizeof profit[0])), vector <int>(city, city + (sizeof city / sizeof city[0])), vector <int>(visit, visit + (sizeof visit / sizeof visit[0])));
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
