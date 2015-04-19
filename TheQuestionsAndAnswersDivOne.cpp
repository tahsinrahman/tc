#include <bits/stdc++.h>
using namespace std;

int n, result, lst, repeat, ques;
vector <string> ans(10), answers(10);
int taken[10];

void bt()
{
//	cout << lst << ' ' << n << ' ' << ques << endl;
//	cout << "list " << lst << endl;
	if(lst == n) { ++result; return; }

	for(int i = 0; i < ques; ++i) {
		if(!taken[i]) {
			taken[i] = 1;
			ans[i] = answers[lst];
//			printf("taken[%d] = 1, ans[%d] = answers[%d] = ", i, i, lst);
//			cout << ans[i] << endl;
			++lst;

			bt();

			--lst;
			taken[i] = 0;
		}

		else if(repeat < n-ques && ans[i] == answers[lst]) {
			++lst;
			++repeat;

			bt();

			--lst;
			--repeat;
		}
	}
}

class TheQuestionsAndAnswersDivOne {
public:
	int find( int questions, vector <string> answerss ) {
		n = answerss.size();
		ques = questions;
		answers = answerss;

		result = 0, lst = 0, repeat = 0;
		for(int i = 0; i < questions; ++i) {
			taken[i] = 1;
			++lst;

			ans[i] = answers[0];
			bt();

			--lst;
			taken[i] = 0;
		}

		return result;
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
			int questions             = 2;
			string answers[]          = {"No", "Yes"};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int questions             = 2;
			string answers[]          = {"No", "No", "No"};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int questions             = 3;
			string answers[]          = {"Yes", "No", "No", "Yes"};
			int expected__            = 12;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int questions             = 3;
			string answers[]          = {"Yes", "Yes", "Yes", "No"};
			int expected__            = 18;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
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
