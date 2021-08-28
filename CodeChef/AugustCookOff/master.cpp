#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

struct FastScanner {
	FastScanner () {}
	std :: string next () {
		std :: string s;
		std :: cin >> s;
		return s;
	}
	int nextInt () {
		int x;
		scanf ("%d", &x);
		return x;
	}
	long long  nextLong () {
		long long x;
		scanf ("%lld", &x);
		return x;
	}
	float nextFloat() {
		float x;
		scanf ("%f", &x);
		return x;
	}
};


FastScanner fs;
int main () {
	int qq;
	scanf ("%d", &qq);
	vector<int> precompute;
	for (int i = 1; (int)precompute.size() < 1001; ++i) {
		vector<int> temp = precompute;
		reverse(temp.begin(), temp.end());
		precompute.push_back(i);
		for (int x : temp)
			precompute.push_back(x);
	}
	// bool ok = true;
	// for (int i = 0; i < (int)precompute.size(); ++ i) {
	// 	unordered_map<int, int> count;
	// 	for (int j = i; j < (int)precompute.size(); ++j) {
	// 		count[precompute[j]]++;
	// 		bool here = false;
	// 		for (auto x : count) {
	// 			here |= (x.second & 1);
	// 		}
	// 		if (here == false){
	// 			debug() << owo(count);
	// 			assert(false);
	// 		}
	// 		ok &= here;
	// 	}
	// }
	// assert (ok);
	for (int tt = 0; tt < qq; ++tt) {
		int n = fs.nextInt();
		for (int i = 0; i < n; ++i) {
			printf ("%d ", precompute[i]);
		}
		puts("");
	}
	return 0;
}