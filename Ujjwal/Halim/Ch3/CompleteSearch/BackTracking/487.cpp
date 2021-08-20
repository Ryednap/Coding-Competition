#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Actually the complexity is more that what could allow to pass for n = 20
// but we have to maintain the order so we can prune the result.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vector<string> grid(n);
		for(int i = 0; i < n; ++i) {
			cin >> grid[i];
		}
		
		vector<vector<bool>> done(n + 1, vector<bool> (n + 1, false));
		int dx[] = {1, 1, -1, -1, 1, -1, 0, 0};
		int dy[] = {1, -1, 1, -1, 0, 0, -1, 1};
		vector<string> answer;
		set<string> ss;
		
		auto Valid = [&] (int x, int y) {
			if(x < 0 || y < 0 || x >= n || y >= n) return false;
			if(done[x][y]) return false;
			return true;
		};
		
		function < void(int, int, string) > Dfs = [&] (int i, int j, string str) {
			done[i][j] = true;
			if((int)str.length() >= 3) {
				ss.insert(str);
			}
		
			for(int k = 0; k < 8; ++k) {
				int x = dx[k] + i;
				int y = dy[k] + j; // Initially i had put dy[i] damn took 10 min before i figured it out :<
				if(Valid(x, y)) {
					if(grid[x][y] > str.back())
						Dfs(x, y, str + grid[x][y]);
				}
			}
			done[i][j] = false;
		};

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				Dfs(i, j, string(1, grid[i][j]));
			}
		}

		answer = vector<string> (ss.begin(), ss.end());
		
		auto cmp = [&] (const string & s, const string & t) {
			if((int)s.length() == (int)t.length()) {
				return s < t;
			} else return (int)s.length() < (int)t.length();
		};
		
		sort(answer.begin(), answer.end(), cmp);
		for (auto s : answer) {
			puts(s.c_str());
		}
		if(qq) puts("");
	}
	
	return 0;
}
