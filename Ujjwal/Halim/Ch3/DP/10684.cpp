#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int OO = (int)1e9;
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int answer = -OO;
		int curr = 0, mini = 0;
		
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			curr += x;
			answer = max(answer, curr - mini);
			mini = min(mini, curr);
		}
		
		if(answer > 0) printf("The maximum winning streak is %d.\n", answer);
		else puts("Losing streak.");
	}
	return 0;
}
