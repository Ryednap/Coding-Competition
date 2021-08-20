#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Same Queen's problem different type of approach

const int NAX = 8;
int arr[NAX];
int Row[NAX], diaLeft[2 * NAX + 1], diaRight[2 * NAX + 1];
int answer = (int)1e9;
int where[NAX];

void Solve(int col) {
	if(col == NAX) { // A faster approach cold be to check this will adding queen and pass it as parameter.
		int count = 0;
		for(int i = 0; i < NAX; ++i) {
			if(arr[i] != where[i]) ++count;
		}
		answer = min(answer, count);
		return;
	}
	
	for(int row = 0; row < NAX; ++row) {
		if(!Row[row] && !diaLeft[NAX + row - col] && !diaRight[row + col]) {
			where[col] = row + 1;
			Row[row] = diaLeft[NAX + row - col] = diaRight[row + col] = true;
			Solve(col + 1);
			Row[row] = diaLeft[NAX + row - col] = diaRight[row + col] = false;
		}
	}
}

void Clear() {
	memset(Row, false, sizeof(Row));
	memset(diaRight, false, sizeof(diaRight));
	memset(diaLeft, false, sizeof(diaLeft));
	answer = (int)1e9;
}

int main() {
	int x, tt = 0;
	while(scanf("%d", &x) != EOF) {
		arr[0] = x;
		for(int i = 1; i < NAX; ++i) {
			scanf("%d", &arr[i]);
		}
		Clear();
		Solve(0);
		printf("Case %d: %d\n", ++tt, answer);
	}
	
	return 0;
}
