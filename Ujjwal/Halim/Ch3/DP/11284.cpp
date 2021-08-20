#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*	PROBLEM DESCRIPTION IN SHORT

It says that we start from a position and then we have number of stores. Some of them has DVD which we need to get. 
Now we have two options we can either go and buy those DVD from the store or buy it online from amazon at some rate.
Our task is to determine the minium total cost of the purchase.

This problem has 3 concepts included :-
1)- All pair shortest path DP
2)- Choice DP problem 
3)- TSP DP problem


we have to do the first one before doing the rest. And the way that I have handled 2 and 3 is that I have always given option
at each iteration to either move to the next store with dvd or return home.

All the test cases on Udebug and discussions has passed but IDK what's the error 6 submission so far but all WA.

*/


#define f first
#define s second

using vi = vector<int>;
using pid = pair<int, double>;
using vpid = vector<pid>;
using vd = vector<double>;

const double OO = 1e18;
const double THRESHOLD = 1e-6;
#define f first
#define s second


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n, m;
		scanf("%d %d", &n, &m);
		n = n + 2;
		vector<vpid> edges(n);
		for(int i = 0; i < m; ++i) {
			int a, b;
			double c;
			scanf("%d %d %lf", &a, &b, &c);
			//debug() << owo(a) owo(b) owo(c);
			edges[a].emplace_back(b, c);
			edges[b].emplace_back(a, c);
		}
		
	
		vector<vd> dist(n, vd(n, OO));
		
		for(int i = 0; i < n; ++i) {
			for(auto & child : edges[i]) {
				dist[i][child.f] = min(dist[i][child.f], child.s);
			}
			dist[i][i] = 0;
		}
		

		// All pair shortest path Flyod Warshall 
		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					if(dist[i][k] < OO && dist[k][j] < OO) {
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		
		//debug() << owo(dist);
		
		int p;
		scanf("%d", &p);
		++p;
		vpid arr(p);
		
		// seperating the nodes with dvd as we need to focus only on that else the graph is too big to be included
		// in TSP

		arr[0] = {0, 0};
		for(int i = 1; i < p; ++i) {
			scanf("%d %lf", &arr[i].f, &arr[i].s);
		}
		
		vector<vd> dp(p + 10, vd((1 << p) + 10, -OO));
		
		function < double(int, int) > Solve = [&] (int i, int j) {
			
			double & ans = dp[i][j];
			if(ans > -OO) return ans;
			

			double a = -OO, b = -dist[arr[i].f][0];
			for(int k = 1; k < p; ++k) {
				if(!(j & (1 << k))) {
					int where = arr[k].f;
					int from = arr[i].f;
					double cost = arr[k].s; // the fucking mistake was here which cause a lot of time wastage error.
					// here it was int before. :<
					
					a = max(a, Solve(k, j | (1 << k)) + cost - dist[from][where]);
					//if(from == 0 && where == 1) debug() << owo(a) owo(cost - dist[from][where]) owo(cost) owo(dist[from][where]);
				}
			}
			//debug() << owo(a) owo(i) owo(j);
			return ans = max(a, b);
		};
		
		double answer = Solve(0, 0);
		if(answer > 0) printf("Daniel can save $%.2f\n", answer + THRESHOLD);
		else puts("Don't leave the house");
	}
		
	return 0;
}
