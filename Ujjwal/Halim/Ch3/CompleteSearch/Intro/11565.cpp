#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n^2) solution per test case

using pii = pair<int, int>;
using piii = pair<int, pii>;
#define f first
#define s second

const int OO = (int)1e9;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		auto isSquare = [&] (int p) {
			if(p < 0) return false;
			int q = sqrt(p);
			return q * q == p;
		};
		
		auto isValid = [&] (int x, int y, int z) {
			if(x + y + z != a) return false;
			if(x * y * z != b) return false;
			if(x * x + y * y + z * z != c) return false;
			if(x == y || x == z || y == z) return false; // missed this case
			return true;
		};
		
		
		piii ans = {OO, {OO, OO}};
		for(int i = -100; i <= 100; ++i) {
			for(int j = -100; j <= 100; ++j) {
				int k = c - i * i - j * j;
				if(!isSquare(k)) continue;
				k = sqrt(k); // missed this one here lol how funny
				vector<int> v = {i, j, k};
				sort(v.begin(), v.end());
				piii comp = {v[0], {v[1], v[2]}};
				if(isValid(i, j , k)) ans = min(ans, comp);
			}
		}
		if(ans.f == OO) puts("No solution.");
		else printf("%d %d %d\n", ans.f, ans.s.f, ans.s.s);
	}
		
	return 0;
}
