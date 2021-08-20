#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// As the size if small just do check all the possible combination of putting in empty cell
// don't forget to filter out the wrong configuration one
// O(16 * 2 ^ 16 + 16 ^ 3) at max complexity

int main() {
	int n;
	while (scanf("%d",&n) && n) {
		string mat[n];
		for(int i = 0; i < n; ++i) {
			cin >> mat[i];
		}
		int answer = 0;
		vector<pii> cell;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(mat[i][j] == '.') cell.push_back({i,j});
			}
		}
		
		const int m = (int)cell.size();
		for(int _ = 0; _ < (1 << m); ++_) {
			vector<vector<int>> done(n, vector<int> (n, false));
			for(int j = 0; j < m; ++j) {
				if(_ & (1 << j)) {
					done[cell[j].f][cell[j].s] = 1;
				}
			}
			int count = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					if(!done[i][j]) continue;
					++count;
					if(mat[i][j] != '.') count = -1;
					for(int k = j + 1; k < n; ++k) {
						if(mat[i][k] != '.') break;
						if(done[i][k]) count = -1;
					}
					for(int k = i + 1; k < n; ++k) {
						if(mat[k][j] != '.') break;
						if(done[k][j]) count = -1;
					}
					
					if(count == -1) break;
					
				}
				if(count == -1) break;
			}
			//debug() << owo(done) owo(answer);
			answer = max(answer, count);
		}
		printf("%d\n", answer);
	}
	return 0;
}
