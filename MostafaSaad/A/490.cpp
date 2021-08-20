#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n;
	scanf ("%d", &n);
	vector<int> v[3];
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		v[x - 1].push_back(i + 1);
	}
	int answer = (int)1e9;
	for(int i = 0; i < 3; ++i) {
		answer = min(answer, (int)v[i].size());
	}
	printf("%d\n", answer);
	for(int i = 0; i < answer; ++i) {
		for(int j = 0; j < 3; ++j) {
			printf("%d ", v[j].back());
			v[j].pop_back();
		}
		puts("");
	}

	return 0;
}