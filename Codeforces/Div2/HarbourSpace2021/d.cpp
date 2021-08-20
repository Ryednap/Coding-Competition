#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define sz(x) ((int)x.size())
#define all(x) ((x.begin(), x.end()))
#define f first
#define s second



int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		string s, t;
		cin >> s >> t;
		const int n = s.length();
		const int m = t.length();
		if(m > n) {
			puts("NO");
			continue;
		}
		bool ok = false;
		vector<int> store[26][2];
		for(int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			store[c][i & 1].push_back(i);
		}

		auto check = [&] (int s) {

			for(int i = 1; i < m; ++i) {
				int c = t[i] - 'a';
				int sign = !(s & 1);
				if(sz(store[c][sign]) == 0)
					return 0;
				auto itr =  upper_bound(store[c][sign].begin(), store[c][sign].end(), s);

				if(itr == store[c][sign].end())
					return 0;
				s = *itr;
			}
	
			return ((n - s) & 1);
		};

		for(int i = 0; i < 2;  ++i) {
			int c = t[0] - 'a';
			if(sz(store[c][i])) {
				ok |= check(store[c][i][0]);
			}
		}

		puts(ok ? "YES" : "NO");

	}
	return 0;
}