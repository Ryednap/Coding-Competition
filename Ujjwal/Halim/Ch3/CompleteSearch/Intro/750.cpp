#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 8;
bool Row[2 * nax + 1], Left[2 * nax + 1], Right[2 * nax + 1];
vector<vector<int>> ans;

bool Set(int r, int c) {
	if(Row[r] || Left[nax + c - r] || Right[r + c]) return false;
	Row[r] = Left[nax + c - r] = Right[r + c] = true;
	return true;
}

void Unset(int r, int c) {
	Row[r] = Left[nax + c - r] = Right[r + c] = false;
}

int r, c;
void nQueen(int col, vector<int> v) {
	if(col == 8) {
		ans.push_back(v);
		
	} else if(col == c) {
		if(Set(r, c)) {
			v.push_back(r);
			nQueen(col + 1, v);
			v.pop_back();
			Unset(r, c);
		}
		
	} else {
		for(int row = 0; row < nax; ++row) {
			if(Set(row, col)) {
				v.push_back(row);
				nQueen(col + 1, v);
				v.pop_back();
				Unset(row, col);
			}
		}
	}
}

void Clear() {
	memset(Row, false, sizeof(Row));
	memset(Right, false, sizeof(Right));
	memset(Left, false, sizeof(Left));
	ans.clear();
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		scanf("%d %d", &r, &c);
		--r, --c;
		Clear();
		nQueen(0, vector<int>());
		sort(ans.begin(), ans.end());
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		for(int i = 0; i < (int)ans.size(); ++i) {
			printf("%2d      %d", i + 1, ans[i][0] + 1);
			for(int j = 1; j < (int)ans[i].size(); ++j) {
				printf(" %d", ans[i][j] + 1);
			}
			puts("");
		}
		if(qq) puts("");
	}
	return 0;
}
