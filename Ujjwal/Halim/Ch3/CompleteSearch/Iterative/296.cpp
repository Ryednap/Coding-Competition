#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define FOR(x) for(char x = '0'; x <= '9'; ++x)

// O(4^5 * n) per test case.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		string s[n], buff;
		int a[n], b[n];
		for(int i = 0; i < n; ++i) {
			cin >> s[i] >> buff;
			a[i] = buff[0] - '0';
			b[i] = buff[2] - '0';
		}
		vector<string> ans;
		
		auto Valid = [&] (string p) {
			for(int i = 0; i < n; ++i) {
				string q = s[i];
				int aa = 0, bb = 0;
				bool x[4] = {0}, y[4] = {0};
				for(int j = 0; j < 4; ++j) {
					if(q[j] == p[j]) {
						++aa; // digit same place same
						x[j] = y[j] = 1;
					}
				}
				for(int j = 0; j < 4; ++j) for(int k = 0; k < 4; ++k) {
					if(!x[j] && !y[k] && q[j] == p[k]) {
						x[j] = y[k] = 1; // digit same place not same.
						++bb;
					}
				}
				if(aa != a[i] || bb != b[i]) return false; 
			}
			return true;
		};
				
		FOR(i) FOR(j) FOR(k) FOR(l) {
			string maybe = "";
			for(char ch : {i, j, k, l}) maybe += ch;
			if(Valid(maybe)) {
				ans.push_back(maybe);
			}
		}
		if((int)ans.size() == 0) puts("impossible");
		else if((int)ans.size() > 1) puts("indeterminate");
		else puts(ans[0].c_str());
	}
	return 0;
}
