#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(200 ^ 3 log(n))
// although log(n) factor could be reduced by precomputation and DAT

const int nax = 200;

int CubeRoot (int n) {
	int lo = 0, hi = nax;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int val = mid * mid * mid;
		if(val == n) return mid;
		else if(val < n) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}

int main() {
	vector<array<int, 4>> ans;
	for(int i = 2; i <= nax; ++i) {
		for(int j = i; j <= nax; ++j) {
			for(int k = j; k <= nax; ++k) {
				int c = i * i * i + j * j * j + k * k * k;
				c = CubeRoot(c);
				if(c != -1) {
					array<int, 4> is = {c, i, j, k};
					ans.push_back(is);
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto x : ans) {
		printf("Cube = %d, Triple = (%d,%d,%d)\n", x[0], x[1], x[2], x[3]);
	}		
	return 0;
}
