#include <bits/stdc++.h>

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int k, n, m;
		scanf("%d %d %d", &k, &n, &m);
		int a[n], b[m];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < m; ++i) {
			scanf("%d", &b[i]);
		}

		std :: vector<int> answer;
		bool ok = true;
		int i = 0, j = 0;
		while (i < n && j < m) {
			if(a[i] == 0) answer.push_back(0), ++i, ++k;
			else if(b[j] == 0) answer.push_back(0), ++j, ++k;
			else {
				if(a[i] < b[j]) {
					if(a[i] > k) ok = false;
					else answer.push_back(a[i]);
					++i;
				} else {
					if(b[j] > k) ok = false;
					else answer.push_back(b[j]);
					++j;
				}
			}
		}

		for(int l = i; l < n; ++l) {
			if(a[l] == 0) answer.push_back(0), ++k;
			else if(a[l] > k) ok = false;
			else answer.push_back(a[l]);
		}
		for(int l = j; l < m; ++l) {
					if(b[l] == 0) answer.push_back(0), ++k;
					else if(b[l] > k) ok = false;
					else answer.push_back(b[l]);
				}

		if(ok) {
			for(auto x : answer) {
				printf("%d ", x);
			}
			puts("");
		} else puts("-1");

	}
}