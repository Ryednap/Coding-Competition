	#include <bits/stdc++.h>

	using namespace std;

	#ifdef LOCAL
	#include "uj.h"
	#endif

	#define f first
	#define s second

	using vi = vector<int>;
	const int OO = (int)1e9;

	// A trivial TSP problem

	int main() {
		int qq;
		scanf("%d", &qq);
		while (qq--) {
			int n, m;
			scanf("%d %d", &n, &m);
			int a, b;
			scanf("%d %d", &a, &b);
			int p;
			scanf("%d", &p);
			++p;
			vi X(p), Y(p);
			X[0] = a, Y[0] = b;
			for(int i = 1; i < p; ++i) {
				scanf("%d %d", &X[i], &Y[i]);
			}
			
			vector<vi> dp(p + 1, vi((1 << p) + 10, -1));
			
			// Manhattan Distance
			auto dist = [&] (int i, int j) {
				return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
			};
			
			
			function < int (int, int) > Brute = [&] (int i, int  j) {
				if(__builtin_popcount(j) == p) {
					return dist(0, i);
				}
				
				int & ans = dp[i][j];
				if(ans != -1) return ans;
				//debug() << owo(i) owo(__builtin_popcount(j)) owo(p);
				ans = OO;
				for(int k = 1; k < p; ++k) {
					if(!(j & (1 << k))) {
						ans = min(ans, Brute(k, j | (1 << k)) + dist(i, k));
					}
				}
				return ans;
			};
			
			int answer = Brute(0, 1);
			printf("The shortest path has length %d\n", answer);
		}
		
		return 0;
	}
