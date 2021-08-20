#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// There's Some unconventional error in the checker of the judge from 2018 onwards this shows WA to all programs
// Note that I have coded a (2 ^ n * m * tt) which is by far more than required just do the math
// Note for future :- Think about some technique to reduce the bound. Remove the m bound .

int main() {
	int qq;
	scanf("%d", &qq);
	string ans = "";
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> sets[m];
		cin >> ws; // buff clear;
		
		for(int i = 0; i < m; ++i) {
			string inp; getline(cin, inp);
			stringstream ss(inp);
			int x;
			vector<int> v;
			while (ss >> x) {
				--x;
				v.push_back(x);
			}
			sets[i] = v;
		}
		
		bool valid = false;
		for(int i = 0; i < (1 << n); ++i) {
			bool ok = true;
			for(int j = 0; j < m; ++j) {
				set<int> s;
				for(int & x : sets[j]) {
					bool bit = i & (1 << x);
					s.insert(bit);
				}
				if((int)s.size() != 2 && (int)sets[j].size() != 1) {
					ok = false;
					break;
				}
			}
			if(ok) {
				valid = true;
				break;
			}
		}
		ans += valid ? "Y" : "N";
	}
	printf("%s", ans.c_str());
	return 0;
}
