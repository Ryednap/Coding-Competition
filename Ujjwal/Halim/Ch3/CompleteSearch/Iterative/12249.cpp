#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using mds = map<deque<char>, string>;

int main() {
	int qq, tt = 0;
	scanf("%d",&qq);
	while (qq--) {
		int n; scanf("%d", &n);
		string v[n];
		for(int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v, v + n);
		
		map<string, mds> precompute;
		
		for(int i = 0; i < n; ++i) {
			string s = v[i];
			mds m;
			const int b = (int)s.length();
			for(int j = 0; j < b; ++j) {
				string x = s.substr(0, j);
				string y = s.substr(j, b);
				deque<char> d;
				for(char ch : x) d.push_back(ch);
				m[d] = y;
			}
			precompute[s] = m;
		}
		

		int answer = (int)1e9;	
		do {
			string s = v[0];

			for(int i = 1; i < n; ++i) {
				const int a = (int)s.length();
				
				deque<char> x;
				for(char ch : s) x.push_back(ch);
				
				auto m = precompute[v[i]];
				for(int j = 0; j <= a; ++j) {
					if(m.find(x) != m.end()) {
						s += m[x];
						break;
					}
					x.pop_front();
				}
			}
			answer = min(answer, (int)s.length());
			
		} while( next_permutation(v, v + n));
		printf("Case %d: %d\n", ++tt, answer);
	}
	return 0;
}
