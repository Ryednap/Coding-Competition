#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif




int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		string g[2];
		int n1[2], n2[2]; // Shortens the code this way 
		for(int i = 0; i < 2; ++i) {
			cin >> g[i] >> n1[i] >> n2[i]; 
		}
		
		auto Valid = [&](string a, string b) {
			int d1[4] = {0}, d2[4] = {0}; // to check for position which are done
			int p = 0, q = 0;
			for(int i = 0; i < 4; ++i) {
				if(a[i] == b[i]) { // same position
					++p;
					d1[i] = d2[i] = 1;
				}
			}
			for(int i = 0; i < 4; ++i) { // same element
				for(int j = 0; j < 4; ++j) {
					if(a[i] == b[j] && !d1[i] && !d2[j]) {
						++q;
						d1[i] = d2[j] = 1;
					}
				}
			}
			return make_pair(p, q);
		};
		
		vector<string> comb = {"R", "Y", "G", "B", "O", "V"};
		int total = 0;
		int count = 0;
		for(auto a : comb) { // A much easier way
			for(auto b : comb) {
				for(auto c : comb) {
					for(auto d : comb) {
						set<string> s;
						for(auto heff : {a, b, c, d}) {
							s.insert(heff);
						}
						if((int)s.size() != 4) continue;
						
						string maybe = a + b + c + d;
						++total;
						bool ok = true;
						for(int i = 0; i < 2; ++i) {
							pair<int, int> p = Valid(maybe, g[i]);
							if(p.first != n1[i] || p.second != n2[i]) {
								ok = false;
								break;
							}
						}
						if(ok) count++;
					}
				}
			}
		}
		assert(total == 360); // total must be equal to 6P4. I made the mistake that i was taking equal also my bad.
		if(!count) puts("Cheat");
		else puts("Possible");
	}
		
	return 0;
}
