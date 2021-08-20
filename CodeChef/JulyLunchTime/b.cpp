#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using vi = std::vector<ll> ;
using pii = pair<ll, ll>;

#define f first
#define s second

vi readArray(int n) {
	vi v(n);
	for (auto & x : v) {
		cin >> x;
	}
	return v;
}

const int OO = (int)2e9;
int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vi a = readArray(n);
		vi b = readArray(n);
		map<int, vi> mapper;
		for (int i = 0; i < n; ++i) {
			int x = (a[0] + b[i]) % n;
			mapper[x].push_back(i);
		}

		vi pos = mapper.begin()->second;
		vi ans(n, OO);
		for (int x : pos) {
			vi maybe;
			for (int j = 0,i = x; j < n; i = (i + 1)%n, ++j) {
				maybe.push_back((a[j] + b[i]) % n);
			}
			ans = min(ans, maybe);
		}
		for (auto x : ans) {
			printf("%lld ", x);
		}
		puts("");
	}
	return 0;
}