#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * A tough problem in terms the amount of floating data given and rounding errors and all.
 * Level 4:
 * Solvable in one go :- NO 
 * At this level of mine :- Will take more than 1 hr to solve this problem. :<
 */

const double OO = 1e9L;
const int nax = 60;

double dist[nax], cost[nax];
double c, r, init, d;
int n;

double answer = OO;

vector<int> where; // Just for debugging

double Future(double src, double dest, double fuel) {
	double req = (dest - src) / r;
	return fuel - req;
}

void Solve(int i, double f, double total) {
	double here = i >= 0 ? dist[i] : 0;
	if(Future(here, d, f) >= 0) {
		//debug() << owo(where);
		answer = min(answer, total);
		return;
	}
	
	for(int j = i + 1; j < n; ++j) {
		double next = Future(here, dist[j], f);
		double nextAfter = 0;
		if(j + 1 < n) nextAfter = Future(here, dist[j + 1], f);
		if(next < 0) break; // Damn this if should be here
		else if(next <= c / 2.0 || nextAfter < 0) {
			where.push_back(j);
			Solve(j, c, total + round((c - next) * cost[j]) + 200); // The round here is important.
			where.pop_back();
			
		}
	}
} 

int main() {
	int tt = 0;
	while (scanf("%lf", &d) != EOF) {
		if(d < 0) break;
		scanf("%lf %lf %lf %d", &c, &r, &init, &n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf %lf", &dist[i], &cost[i]); // Don't put round here for the cost it will lead to some value loss.
		}
		
		Solve(-1, c, 0); // initial :- 0th locatn, c tank, 0 total cost
		assert(answer != OO);		
		printf("Data Set #%d\n", ++tt);
		printf("minimum cost = $%.2f\n", answer / 100 + init);
		answer = OO;
	}
	return 0;	
}
