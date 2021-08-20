#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A totally bullshit question :- No proper information
const long long nax = 9876543210LL;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		long long n;
		scanf("%lld", &n);
		auto Valid = [&] (long long x) {
			string s = to_string(x);
			const int size = (int)s.length();
			set<char> st (s.begin(), s.end());
			return (int)st.size() == size;
		};
		
		for(long long i = 1; n * i <= nax; ++i) {
			auto j = i * n;
			if(Valid(i) && Valid(j)) {
				printf("%lld / %lld = %lld\n", j, i, n);
			}
		}
		if(qq) puts("");
	}
	return 0;
}
