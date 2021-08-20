#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif



using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using piii = std::pair<int, pii>;
using vpi = std::vector<pii>;

#define f first
#define s second

vector<string> graph;
vvi used;
int n, m;

array<int, 4> dx = {0, 0, 1, -1};
array<int, 4> dy = {-1, 1, 0, 0};

bool inside (int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

bool valid (int x, int y) {
	if (!inside(x, y))
		return false;
	if (used[x][y])
		return false;
	if (graph[x][y] == '#' || graph[x][y] == 'T')
		return false;
	return true;
}

int dfs (int x, int y){
	used[x][y] = true;
	int cnt = 0;
	if (graph[x][y] == 'G')
		++cnt;

	bool sense = false;
	for (int i = 0; i < 4; ++i) {
		int rr = x + dx[i];
		int cc = y + dy[i];
		if (inside(rr, cc) && graph[rr][cc] == 'T')
			sense = true;
	}
	if (sense)
		return cnt;

	for (int i = 0; i < 4; ++i) {
		int rr = x + dx[i];
		int cc = y + dy[i];
		if (valid(rr, cc)) {
			cnt += dfs(rr, cc);
		}
	}
	return cnt;
}

int main () {
	while (scanf ("%d %d", &m, &n) != EOF) {
		graph = vector<string> (n);
		used = vvi(n, vi(m));
		for (std::string & s : graph) {
			cin >> s;
		}
		int start_x, start_y;
		for (int i = 0 ; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (graph[i][j] == 'P') {
					start_y = j;
					start_x = i;
					break;
				}
			}
		}
		printf ("%d\n", dfs(start_x, start_y));
	}
	return 0;
}