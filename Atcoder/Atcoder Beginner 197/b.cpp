#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	--x, --y;
	
	string mat[n];
	for(int i = 0; i < n; ++i) {
		cin >> mat[i];
	}
	
	int answer = 0;
	for(int i = x; i >= 0; --i) {
		if(mat[i][y] == '#') break; 
		++answer;	
	}
	for(int i = x; i < n; ++i) {
		if(mat[i][y] == '#') break;
		++answer;
	}
	
	for(int j = y; j >= 0; --j) {
		if(mat[x][j] == '#') break;
		++answer;
	}
	
	for(int j = y; j < m; ++j) {
		if(mat[x][j] == '#') break;
		++answer;
	}
	if(mat[x][y] != '#') answer -= 3;
	printf("%d\n", answer);
	
	return 0;
}
