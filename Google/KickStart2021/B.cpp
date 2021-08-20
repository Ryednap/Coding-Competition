#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

//0 0 2 6
//2 6 5 4
//6 3 3 2

using vi = vector<int>;

void Solve() {
	int r, c;
	scanf("%d %d", &r, &c);
	int grid[r][c];
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	
	vector<vi> A(r, vi(c, 0));
	vector<vi> B(r, vi(c, 0));
	vector<vi> C(r, vi(c, 0));
	vector<vi> D(r, vi(c, 0));
	
	for(int i = 0; i < r; ++i) {
		int cnt = 0;
		for(int j = c - 1; j >= 0; --j) {
			if(grid[i][j]) ++cnt;
			else cnt = 0;
			A[i][j] = cnt;
		}
		cnt = 0;
		for(int j = 0; j < c;  ++j) {
			if(grid[i][j]) ++cnt;
			else cnt = 0;
			B[i][j] = cnt;
		}
	}

	
	for(int i = 0; i < c; ++i) {
		int cnt = 0; 
		for(int j = r - 1; j >= 0; --j) {
			if(grid[j][i]) ++cnt;
			else cnt = 0;
			C[j][i] = cnt;
		}
		cnt = 0 ;
		for(int j = 0; j < r; ++j) {
			if(grid[j][i]) ++cnt;
			else cnt = 0;
			D[j][i] = cnt;
		}
	}
	
	//debug() << owo(A);
	//debug() << owo(B);
	//debug() << owo(C);
	//debug() << owo(D);
	
	int answer = 0 ;
	
	auto Check = [&] (int x, int y) {
		if(x < 2 || y < 2) return 0;
		return min(y / 2 - 1, x - 1) + min(x / 2 - 1, y - 1);
	};
	
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			answer += (Check(B[i][j], C[i][j])) ;
			answer += (Check(A[i][j], C[i][j]));
			answer += (Check(B[i][j], D[i][j])) ;
			answer += (Check(A[i][j], D[i][j])) ;
		}
	}
	
	printf("%d\n", answer);
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
