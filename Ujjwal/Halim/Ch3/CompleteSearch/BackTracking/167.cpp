#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif



const int NAX = 8;
int board[NAX][NAX];
int Col[NAX], Dleft[2 * NAX + 1], Dright[2 * NAX + 1];

bool Valid(int row, int col) {
	return (!Col[col] && !Dleft[NAX + col - row] && !Dright[row + col]);
}

int ans;

void Solve(int row, int sum) {
	if(row == 8) {
		ans = max(ans, sum);
		return;
		
	} else {
		for(int col = 0; col < 8; ++col) {
			if(Valid(row, col)) {
				Col[col] = Dleft[NAX + col - row] = Dright[row + col] = 1;
				Solve(row + 1, sum + board[row][col]);
				Col[col] = Dleft[NAX + col - row] = Dright[row + col] = 0;
			}
		}
	
	}
}

void Clean() {
	ans = 0;
	memset(Col, 0, sizeof(Col));
	memset(Dleft, 0, sizeof(Dleft));
	memset(Dright, 0, sizeof(Dright));
}

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		for(int i = 0; i < 8; ++i) {
			for(int j = 0; j < 8; ++j) {
				scanf("%d", &board[i][j]);
			}
		}
		Solve(0, 0);
		printf("%5d\n", ans);
		Clean();
	}
		
	return 0;
}
	
