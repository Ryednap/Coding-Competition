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

vvi mat;
vi used;

array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {-1, 1, 0, 0};
int n;

bool valid (int x, int y, int v) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	if (mat[x][y] != v)
		return false;
	return true;
}

void dfs (int x, int y, int val) {
	mat[x][y] = -1;
	for (int i = 0; i < 4; ++i) {
		int rr = x + dx[i];
		int cc = y + dy[i];
		if (valid(rr, cc, val))
			dfs (rr, cc, val);
	}
}

int main () {
	while (scanf ("%d", &n) && n) {
		mat = vvi(n, vi(n));
		used = vi(n);
		for (int i = 1; i < n; ++i) {
			std::string in;
			std::cin >> ws;
			std::getline(std::cin, in);
			std::stringstream ss(in);
			int x, y;
			while (ss >> x >> y) {
				--x, --y;

				mat[x][y] = i;
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] != -1) {
					int w = mat[i][j];
					if (used[w])
						ok = false;
					used[w] = true;
					dfs (i, j,  w);
				}
			}
		}
		puts (!ok ? "wrong" : "good");
	}
	return 0;
}