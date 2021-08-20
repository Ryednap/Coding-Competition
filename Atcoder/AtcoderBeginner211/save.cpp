#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;

#define f first
#define s second

int main() {
	int n, m;
	scanf("%d %d",&n, &m);
	vector<string> v(n);
	for(string & s : v) {
		cin >> s;
	}
	vpi cor;
	for(int i = 0 ;i <n; ++i) {
		for(int j = 0;j < n; ++j) {
			if(v[i][j] == '.')
				cor.emplace_back(i, j);
		}
	}
;
	const int N = (int)cor.size();
	int ans = 0;
	for(int i = 0; i < (1LL << N); ++i) { // row
			debug() << owo(N) owo(i) owo(1 << N);
			if(__builtin_popcount(i) != m) {
				continue;
			}
			vector<string> ki = v;
			int any_x = -1, any_y = -1;
			for(int j = 0; j < N; ++j) {
				if(i & (1 << j)) {
					any_x = cor[j].f;
					any_y = cor[j].s;
					ki[any_x][any_y] = '*';
				}
			}



			int dx[] = {0, 0, -1, 1};
			int dy[] = {1, -1, 0, 0};
			auto Valid = [&] (int x, int y) {
				if(x < 0 || y < 0 ||  x >= n || y >= n)
					return false;
				if(ki[x][y] != '*')
					return false;
				return true;
			};
			function < void (int, int) > dfs = [&] (int x, int y) {
				ki[x][y] = '#';
				for(int i = 0; i < 4; ++i) {
					int RR = dx[i] + x;
					int CC = dy[i] + y;
					if(Valid(RR, CC)) dfs(RR, CC);
				}
			};

			dfs(any_x, any_y);
			bool ok = true;
			for(int i = 0 ; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					if(ki[i][j] == '*') {
						ok = false;
						break;
					}
				}
			}
			if(ok) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}