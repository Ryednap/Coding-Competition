#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif

// 1 WA attempt :- Reason :- I was trying to do like do the sort the s based on the character first and then position and then binary search 
// for each character and then the next character must occur after the prev one
// But this approach was wrong as it was not totally correct as i was doing binary search on the character and then figuring out whether the found was
// right or wrong.

// The similar approach would have been find the lower and higher index of the character and then search for the desired position. but it is similar to
// storing it as adjacency list and doing BS. Same compleixty but reduced code.

int main() {
	string s;
	cin >> s;
	map<char, vector<int>> mapper;
	for(int i = 0; i < (int)s.length(); ++i) {
		mapper[s[i]].push_back(i);
	}
	
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		string t;
		cin >> t;
		int prev = -1, lo = (int)1e9, hi = 0;
		bool ok = true;
		for(char ch : t) {
			auto & v = mapper[ch];
			auto itr = lower_bound(v.begin(), v.end(), prev + 1);
			if(itr == v.end()) {
				ok = false;
				break;
			} else prev = *itr;
			
			lo = min(lo, prev);
			hi = max(hi, prev);
		}
		if(ok) {
			printf("Matched %d %d\n", lo, hi);
			
		} else puts("Not matched");
	}
			
	return 0;
}
