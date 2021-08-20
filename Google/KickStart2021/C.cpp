#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
using piii = pair<int, pii>;

#define f first
#define s  second


void Solve() {
	int r, c;
	scanf("%d %d", &r, &c);
	
	priority_queue<piii> q;
	int grid[r][c];
	for(int i = 0 ; i < r;  ++i) {
		for(int j = 0; j < c; ++j) {
			int x ;
			scanf("%d", &x);
			q.push(make_pair(x, make_pair(i,j)));
			grid[i][j] = x;
		}
	}

	long long ans = 0;
	
	vector<vector<bool>> visited(r + 1, vector<bool>(c + 1, false));

	int dx [] = {0, 0, -1, 1};
	int dy [] = {-1, 1, 0, 0};

	auto Valid = [&] (int x, int y) {
		if(x < 0 || y < 0) return false;
		if(x >= r || y >= c) return false;
		if(visited[x][y]) return false;
		return true;
	};

	while(!q.empty()) {
		auto cell = q.top(); q.pop();
		auto p = cell.s;
		auto value = cell.f;

		/* debug() << owo(cell) owo(ans); */
		if(!visited[p.f][p.s]) {
			visited[p.f][p.s] = true;
			for(int i = 0; i < 4; ++i) {
				int x = dx[i] + p.f;
				int y = dy[i] + p.s;
				if(Valid(x, y) && value != grid[x][y]) {
					ans += (value - 1 - grid[x][y]);
					grid[x][y] = value - 1;
					q.push(make_pair(value - 1, make_pair(x, y)));
				}
			}
		}
	}
	printf("%lld\n",ans);

}



int main() {
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i) {
		printf("Case #%d: ", i + 1);
		Solve();
	}
	return 0;
}
