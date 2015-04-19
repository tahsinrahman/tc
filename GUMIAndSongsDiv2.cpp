#include <bits/stdc++.h>
using namespace std;

class GUMIAndSongsDiv2 {
public:
	int maxSongs( vector <int> duration, vector <int> tone, int T ) {
		int n = duration.size();

		int result = 0;
		for(int mask = 0; mask < (1<<n); ++mask) {
			int total = 0, mx = 0, mn = INT_MAX, curr = 0;
			for(int i = 0; i < n; ++i) {
				if(mask&(1<<i)) {
					mx = max(mx, tone[i]);
					mn = min(mn, tone[i]);
					total += duration[i];
					++curr;
				}
			}
			if(total + mx-mn <= T) result = max(result, curr);
		}
		return result;
	}
};

/*
//		vector <pair<int, int> > songs;
		pair<int, int> songs[n];
		for(int i = 0; i < n; ++i) songs[i].first = tone[i], songs[i].second = duration[i];

//		sort(songs.begin(), songs.end());
		sort(songs, songs+n);

		int mx = 0;
		for(int mask = 0; mask < (1<<n); ++mask) {
			bool first = 1;
			int cnt = 0, prev, currTime = 0;
			for(int i = 0; i < n; ++i) {
				if(mask&(1<<i)) {
					if(first) {
						++cnt;
						prev = i;
//						currTime = duration[i];
						currTime = songs[i].second;
						first = 0;
					}
					else {
						++cnt;
//						currTime += duration[i]+abs(tone[i]-tone[prev]);
						currTime += songs[i].second+abs(songs[i].first-songs[prev].first);
						prev = i;
					}
				}
			}
			if(currTime <= T) mx = max(mx, cnt);
		}

		return mx;
	}
	*/

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
			int duration[]            = {3, 5, 4, 11};
			int tone[]                = {2, 1, 3, 1};
			int T                     = 17;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int duration[]            = {100, 200, 300};
			int tone[]                = {1, 2, 3};
			int T                     = 10;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int duration[]            = {1, 2, 3, 4};
			int tone[]                = {1, 1, 1, 1};
			int T                     = 100;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int duration[]            = {10, 10, 10};
			int tone[]                = {58, 58, 58};
			int T                     = 30;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int duration[]            = {8, 11, 7, 15, 9, 16, 7, 9};
			int tone[]                = {3, 8, 5, 4, 2, 7, 4, 1};
			int T                     = 14;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int duration[]            = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
			int tone[]                = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
			int T                     = 302606;
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int duration[]            = ;
			int tone[]                = ;
			int T                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GUMIAndSongsDiv2().maxSongs(vector <int>(duration, duration + (sizeof duration / sizeof duration[0])), vector <int>(tone, tone + (sizeof tone / sizeof tone[0])), T);
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
