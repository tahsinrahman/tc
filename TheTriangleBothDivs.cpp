#include <bits/stdc++.h>
using namespace std;

class TheTriangleBothDivs {
public:
	string fix( string a ) {
		vector <int> hours, gmt;
		//hours
		if(a[0] != '?' && a[1] != '?') hours.push_back((a[0]-'0')*10+a[1]-'0');
		else if(a[0] == '?' && a[1] != '?') {
			if(a[1] < '4') for(int i = 0; i < 3; ++i) hours.push_back(i*10+a[1]-'0');
			else for(int i = 0; i < 2; ++i) hours.push_back(i*10+a[1]-'0');
		}
		else if(a[0] != '?' && a[1] == '?') {
			if(a[0] == '2') for(int i = 0; i < 4; ++i) hours.push_back(20+i);
			else for(int i = 0; i < 10; ++i) hours.push_back((a[0]-'0')*10+i);
		}
		else for(int i = 0; i < 24; ++i) hours.push_back(i);
//		cout << "hours" << endl;
//		for(int i = 0; i < hours.size(); ++i) cout << hours[i] << endl;

		//minuites
		if(a[3] == '?') a[3] = '0';
		if(a[4] == '?') a[4] = '0';

		//gmt
		if(a[9] == '?' && a[10] == '?') for(int i = -9; i < 10; ++i) gmt.push_back(i);
		else if(a[9] != '?' && a[10] == '?') {
			if(a[9] == '+') for(int i = 0; i < 10; ++i) gmt.push_back(i);
			else for(int i = -9; i < 0; ++i) gmt.push_back(i);
		}
		else if(a[9] == '?' && a[10] != '?') { gmt.push_back(a[10]-'0'); gmt.push_back(-(a[10]-'0')); }
		else {
			if(a[9] == '+') gmt.push_back(a[10]-'0');
			else gmt.push_back(-(a[10]-'0'));
		}
//		cout << "gmt" << endl;
//		for(int i = 0; i < gmt.size(); ++i) cout << gmt[i] << endl;

		int mnHour = INT_MAX;
		for(int i = 0; i < hours.size(); ++i) {
			for(int j = 0; j < gmt.size(); ++j) {
//				if((hours[i]-gmt[j])%24>=0?(hours[i < mnHour) {
				int tmp = (hours[i]-gmt[j])%24;
				if(tmp < 0) tmp += 24;
				mnHour = min(mnHour, tmp);
			}
		}

		string ans = "";
		ans += (char) mnHour/10+'0';
		ans += (char) mnHour%10+'0';
		ans += ":";
		ans += (char) a[3];
		ans += (char) a[4];
		return ans;
//		return (char) (mnHour/10+'0') + (char) (mnHour%10+'0') + ":" +a[3]+a[4];
		
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
			string time               = "17:45 GMT-4";
			string expected__         = "21:45";

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string time               = "16:?? GMT??";
			string expected__         = "00:00";

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string time               = "?1:34 GMT-9";
			string expected__         = "06:34";

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string time               = "??:?? GMT??";
			string expected__         = "00:00";

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string time               = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = TheTriangleBothDivs().fix(time);
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
