#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define REP(x) for(int x = 0; x < 10; ++x)

class CreateMixture {
  public:
  vector <int> mix(int concentration) {
	  vector<int> ans;
	  vector<int> hundreds(10, 0); hundreds[0] = 1; // 2
	  vector<int> tens(10, 0); tens[0] = 2; // 3
	  vector<int> ones(10, 0); ones[0] = 3; // 4

	  for(auto v : {hundreds, tens, ones}) {
		  for(auto & x : v) {
			  ans.push_back(x);
		  }
	  }
	  
	  vector<int> ing;
	  int curr = 5;
	  for(auto x : {4, 3, 2}) {
		  int digit = concentration % 10;
		  concentration /= 10;
	
		  if(digit) {
			  for(int i = 0; i < digit; ++i) {
				  ans.push_back(x);
			  }
			  for(int i = digit; i < 10; ++i) {
				  ans.push_back(0);
			  }
			  ing.push_back(curr++);
		  }
	  }
  	
	  for(auto & x : ing) {
		  ans.push_back(x);
	  }
	  
	  for(int i = (int)ing.size(); i < 10; ++i) {
		  ans.push_back(0);
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
			int concentration         = 500;
			int expected__[]          = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int concentration         = 250;
			int expected__[]          = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 2, 0, -1, -1, -1, -1, -1, -1, -1, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int concentration         = 0;
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int concentration         = 400;
			int expected__[]          = {0, 1, -1, 1, -1, 0, -1, -1, -1, -1, 0, 0, 1, 2, 2, -1, -1, -1, -1, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int concentration         = 2;
			int expected__[]          = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, -1, -1, -1, -1, -1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int concentration         = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int concentration         = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int concentration         = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = CreateMixture().mix(concentration);
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
