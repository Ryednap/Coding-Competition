#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(nlogn) 

int main() {
	int qq, tt = 0;
	scanf ("%d", &qq);
	while (qq--) {
		int n, k;
		scanf("%d %d", &n, &k);
		char s[n]; scanf("%s", s);
		
		
		// WA for this sliding window method idk
/*		map<char, int> window;
		int count = 0;
		for(int i = 1; i <= n; ++i) {
			debug() << owo(window);
			char c = s[i - 1];
			if(window[c]) ++count;
			window[c]++;
			if(i > k) {
				char ch = s[i - k - 1];
				window[ch]--;
				if(window[ch] == 0) window.erase(ch);
			}
		}
*/

	// Adjacency list method
	
		int count = 0;
		map<char, vector<int>> mapper;
		for(int i = 0; i < n; ++i) {
			mapper[s[i]].push_back(i);
		}
		
		for(auto p : mapper) {
			vector<int> v = p.second;
			for(int i = 1; i < (int)v.size() ; ++i) {
				if(v[i] - v[i - 1] <= k) ++count;
			}
		}
			
		printf("Case %d: %d\n", ++tt, count);
	}
	return 0;
}
