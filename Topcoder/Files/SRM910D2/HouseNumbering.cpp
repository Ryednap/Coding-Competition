#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

class HouseNumbering {
  public:
  vector <int> prepareDigits(int firstHouse, int numberOfHouses) {
      vector<int> ans(10);
      for(int i = 0; i < numberOfHouses; ++i) {
		  string s = to_string(firstHouse);
		  for(char ch : s) {
			  ans[ch - '0']++;
		  }
		  firstHouse += 2;
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int firstHouse            = 7;
			int numberOfHouses        = 4;
			int expected__[]          = {0, 3, 0, 1, 0, 0, 0, 1, 0, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int firstHouse            = 2;
			int numberOfHouses        = 6;
			int expected__[]          = {1, 2, 2, 0, 1, 0, 1, 0, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int firstHouse            = 997;
			int numberOfHouses        = 1;
			int expected__[]          = {0, 0, 0, 0, 0, 0, 0, 1, 0, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int firstHouse            = 160;
			int numberOfHouses        = 47;
			int expected__[]          = {15, 25, 42, 5, 14, 2, 14, 5, 14, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int firstHouse            = ;
			int numberOfHouses        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int firstHouse            = ;
			int numberOfHouses        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int firstHouse            = ;
			int numberOfHouses        = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = HouseNumbering().prepareDigits(firstHouse, numberOfHouses);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
