#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL 
#include "uj.h"
#endif 

using pii = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pii>;

#define f first
#define s second
#define sz(x) ((int)x.size())


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	map<int, int> mapper;
	int answer = 0;
	int arr[n];

	// sliding window technique over map
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		arr[i] = x;
		mapper[x]++;
		if(i >= k) {
			int y = arr[i - k];
			if(mapper.find(y) != mapper.end()) {
				mapper[y]--;
			}
			if(mapper[y] == 0)
				mapper.erase(y);
		}
		answer = max(answer, sz(mapper));
	}
	printf("%d\n", answer);
	return 0;
}