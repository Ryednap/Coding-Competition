#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define FOR(a, x) for(char a = x; a <= '9'; ++a)

static inline void ltrim(std :: string & s) {
	s.erase(s.begin(), std :: find_if(s.begin(), s.end(), [] (unsigned char ch)  {
		return !(ch == '0');
	}));
}

const int OO = (int)1e9 + 10;
const int nax = (
int main() {
	int x;
	while (scanf("%d", &x) && x) {
		int ans = OO;
		auto Valid = [&] (int y) {
			string s = to_string(y);
			const int n = (int)s.length();
			set<char> st(s.begin(), s.end());
			if((int)st.size() != n) return false;
			bool used[n] = {0};
			int curr = 0;
			while (!used[curr]) {
				used[curr] = true;
				curr = (curr + s[curr] - '0') % n;
			}
			if(curr != 0) return false;
			for(int i = 0; i < n; ++i) {
				if(!used[i]) return false;
			}
			return true;
		};
			
		for(int i = x; i < nax; ++i) {
			if(Valid(i)) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
