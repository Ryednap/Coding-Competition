#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

std :: vector<int> arr;
int n;

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

#define sz(x) ((int)x.size())

std :: vector<int> Merge(std :: vector<int> a, std :: vector<int> b) {
	std :: vector<int> final;
	int i = 0, j = 0;
	for(; i < sz(a) && j < sz(b);) {
		if(a[i] < b[j]) {
			final.push_back(a[i++]);
		} else final.push_back(b[j++]);
	}

	for(; i < sz(a); ++i) final.push_back(a[i]);
	for(; j < sz(b); ++j) final.push_back(b[j]);
	return final;
}

std :: vector<int> Divide(int l, int r) {
	debug() << owo(l) owo(r);
	assert(l <= r);
	if(l == r) return std :: vector<int> (1, arr[l]);
	int mid = (l + r) >> 1;
	auto a = Divide(l, mid);
	auto b = Divide(mid + 1, r);
	return Merge(a, b);
}

int main() {
	srand(21134);
	int n = 1000000;
	for(int i = 0; i < n; ++i) {
		arr.push_back(rand(1, 10000));
	}
	debug() << owo(n);
	vector<int> res = Divide(0, n - 1);
	assert(is_sorted(res.begin(),res.end()));
	return 0;
}