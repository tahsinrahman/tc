#include <bits/stdc++.h>
using namespace std;

class AgeEncoding {
public:
	double check(double base, string a) {
		double res = 0.0;
		for(int i = 0, l = a.length(); i < l; ++i) if(a[i] == '1') res += pow(base, (double)i) + 1e-11;
		return res;
	}

	double bs(double n, double l, double h, string a) {
		/*
		for(int i = 0; i < 10000; ++i) {
			double m = (l+h)/2.0;

			if(check(m, a) <= n) l = m;
			else h = m;
		}
		if(fabs(n-check(l, a)) > 1e-10) return -1;
		return l;
		*/

		while(h-l >= 1e-15) {
			double m = (l+h)/2.0;

			double tmp = check(m, a);

//			cout << m << ' ' << tmp << endl;

			if(fabs(tmp-n) <= 1e-11) return m+1e-11;
			else if(tmp > n) h = m;
			else l = m;
		}
		return -1;
	}

	double getRadix( int age, string candlesLine ) {
		reverse(candlesLine.begin(), candlesLine.end());

		if(age == 1 && fabs(1-check(2.0, candlesLine)) < 1e-5) return -2;
		return bs((double) age, 0.0, (double) age, candlesLine);
	}
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int age                   = 10;
			string candlesLine        = "00010";
			double expected__         = 10.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int age                   = 21;
			string candlesLine        = "10101";
			double expected__         = 2.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int age                   = 6;
			string candlesLine        = "10100";
			double expected__         = 1.414213562373095;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int age                   = 21;
			string candlesLine        = "10111111110111101111111100111111110111111111111100";
			double expected__         = 0.9685012944510603;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int age                   = 16;
			string candlesLine        = "1";
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int age                   = 1;
			string candlesLine        = "1";
			double expected__         = -2.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int age                   = 1;
			string candlesLine        = "001000";
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int age                   = 1;
			string candlesLine        = "11";
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 8: {
			int age                   = 2;
			string candlesLine        = "11111111111111111111111111111111111111111111111111";
			double expected__         = 0.5000000000000004;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 9: {
			int age                   = 50;
			string candlesLine        = "11111111111111111111111111111111111111111111111111";
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = AgeEncoding().getRadix(age, candlesLine);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
