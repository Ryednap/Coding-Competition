#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vi> arr(n, vi(m));
		vector<vi> used(n, vi(m));

		int dx[] = {0, 0, -1, -1, 1, 1, -1, 1};
		int dy[] = {-1, 1, -1, 1, -1, 1, 0, 0};

		auto Valid = [&] (int a, int b) {
			return (a >= 0 && b >= 0 && a < n && b < m);
		};

		auto Set = [&] (int x, int y) {
			used[x][y] = true;
			for(int i = 0; i < 8; ++i) {
				int RR = x + dx[i];
				int CC = y + dy[i];
				if(Valid(RR, CC))
					used[RR][CC] = true;
			}
		};

		for(int i = 0; i < m; ++i) {
			if(!used[0][i]) {
				arr[0][i] = 1;
				Set(0, i);
			}
		}

		for(int i = 0; i < n; ++i) {
			if(!used[i][0]) {
				arr[i][0] = 1;
				Set(i, 0);
			}
			if(!used[i][m - 1]) {
				arr[i][m - 1] = 1;
				Set(i, m - 1);
			}
		}

		for(int i = 0; i < m; ++i) {
			if(!used[n - 1][i]) {
				arr[n - 1][i] = 1;
				Set(n - 1, i);
			}
		}

		for(auto x : arr) {
			for(auto y : x) {
				printf("%d", y);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}