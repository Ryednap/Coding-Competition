#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Mistake :- Of so i got the dp solution O(N^2) and got coded in less than 3 min but idk TLE lol.
// Actually the answer is the (sum of) maximum prefix sum of both lol.

int n, m;
const int nax = 110;
void Solve(){
	scanf("%d", &n);
	int maxi = 0;
	vector<int> R(nax, 0), B(nax, 0);
	for(int i = 0;i < n; ++i){
		int x;
		scanf("%d",&x);
		R[i + 1] = R[i] + x;
		maxi = max(R[i + 1] , maxi);
	}

	scanf("%d", &m);
	int b = 0;
	for(int i = 0;i < m; ++i){
		int x;
		scanf("%d",&x);
		B[i + 1] = B[i] + x;
		b = max(b, B[i + 1]);
	}
	printf("%d\n", maxi + b);
	
}

int main(){
	int tt;
	scanf("%d",&tt);	
	for(int i = 0; i < tt; ++i){
		Solve();
	}
	return 0;
}
