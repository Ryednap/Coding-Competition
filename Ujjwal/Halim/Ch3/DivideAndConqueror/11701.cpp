#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const double EPS = 1e-6;
int main() {
	set<double> collection;
	function < void(int, double) > Precompute = [&] (int i, double x) {
		if(i == 21) {
			return;
		}
		assert(x <= 1);
		collection.insert(x);
		for(int j : {0, 2}) {
			Precompute(i + 1, x + (double) j / (double) pow(3LL, i));
		}
	};
	Precompute(1, 0);
	string s;
	//debug() << owo(collection);
	while (getline(cin, s) && s != "END") {
		double x;
		stringstream ss(s);
		ss >> x;
		double y = *collection.lower_bound(x);
		debug() << owo(y) owo(x) owo(fabs(x - y));
		if(fabs(x - y) <= EPS) puts("MEMBER");
		else puts("NON-MEMBER");
	}
	return 0;
}
