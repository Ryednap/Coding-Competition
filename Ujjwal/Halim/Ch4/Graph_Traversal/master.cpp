#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*

T 000:17:16.913

*/

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using piii = std::pair<int, pii>;
using vpi = std::vector<pii>;

#define f first
#define s second

vector<string> mat;
vvi used;
const int n = 9;

char ne = '#';
int cnt = 0;
bool addable = true;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {-1, 1, 0, 0};

bool valid (int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	if (used[x][y])
		return false;
	return true;
}

void dfs (int x, int y) {
	++cnt;
	used[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int rr = x + dx[i];
		int cc = y + dy[i];
		if (valid(rr, cc)) {
			if (mat[rr][cc] == '.')
				dfs (rr, cc);
			else {
				if (ne == '#')
					ne = mat[rr][cc];
				else if(ne != mat[rr][cc]) {
					addable = false;
				}
			}
		}
	}
}

int main() {
	int qq;
	scanf ("%d",&qq);
	while (qq--) {
		mat = vector<string> (n);
		used = vvi(n, vi(n));
		for (string & s : mat)
			cin >> s;

		int white = 0, black = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 'O') ++white;
				if (mat[i][j] == 'X') ++black;
				if (!used[i][j] && mat[i][j] == '.') {
					ne = '#';
					cnt = 0;
					addable = true;
					dfs (i, j);
					if (addable) {
						if (ne == 'O') white += cnt;
						else if (ne == 'X') black += cnt;
					}
				}
			}
		}
		printf ("Black %d White %d\n", black, white);
	}
	
}