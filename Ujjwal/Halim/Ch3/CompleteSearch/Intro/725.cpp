#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<string, string>;
#define f first
#define s second

int main() {
	int N;
	scanf("%d", &N);
	while (N) {
		vector<pii> ans;
		
		auto Valid = [&] (string & p, string & q) {
			
			const int n = (int)p.length();
			const int m = (int)q.length();
			if(n == 4 && m == 4) return false;
			if(n > 5 || m > 5) return false;
			if(n == 4) p = "0" + p;
			if(m == 4) q = "0" + q;
			string s = p + q;
			map<char, bool> used;
			for(char ch : s) {
				if(used[ch]) return false;
				used[ch] = true;
			}
			return true;
		};
		
		for(int i = (int)1e3; i < (int)1e5; ++i) {
			auto a = to_string(i);
			auto b = to_string(i * N);
			if(Valid(a, b)) ans.push_back( {a, b} );
			
		}
		if((int)ans.size() == 0) printf("There are no solutions for %d.\n", N);
		else {
			for(auto p : ans) {
				if(p.s > p.f) swap(p.f, p.s);
				printf("%s / %s = %d\n", p.f.c_str(), p.s.c_str(), N);
			}
		}
		scanf("%d", &N);
		if(N) puts("");
	}
	return 0;
}
