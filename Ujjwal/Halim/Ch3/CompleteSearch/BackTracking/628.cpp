#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		vector<string> dict(n);
		for(auto & s : dict) {
			cin >> s;
		}
		int m; scanf("%d", &m);
		vector<vector<string>> ans;
		
		
		
		for(int _ = 0; _ < m; ++_) {
			string rule;
			cin >> rule;
			vector<string> v;
			
			function <void(int , string)> Generate = [&] (int i, string str) {
				if(i == (int)rule.length()) {
					v.push_back(str);
					return;
				}
				
				char c = rule[i];
				if(c == '#') {
					for(string s : dict) {
						Generate(i + 1, str + s);
					}
				} else {
					for(char ch = '0'; ch <= '9' ;++ch) {
						Generate(i + 1, str + ch);
					}
				}
			};
			Generate(0, "");
			//sort(v.begin(), v.end());
			ans.push_back(v);
		}
		puts("--");
		for(auto v : ans) {
			for(auto s : v) {
				puts(s.c_str());
			}
		}
	}
	return 0;
}
