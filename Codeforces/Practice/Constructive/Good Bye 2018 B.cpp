#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * First solution is based on brute force i.e a simple trick of bi-partite matching. 
 * Second solution is based on math formula. Note that for all n - pairs the sum is n *(Tx, Ty) . Now summing all the co-ordinates simplifies to even simpler
 * formula.
 */

using pii = pair<int,int>;

#define F first
#define S second

//void solve(){
	//int n;
	//scanf("%d",&n);
	
	//pii A[n], B[n];
	//for(int i = 0; i < n; ++i){
		//scanf("%d %d",&A[i].F, &A[i].S);
	//}
	//for(int i = 0; i < n; ++i){
		//scanf("%d %d",&B[i].F, &B[i].S);
	//}
	
	//map<pii, vector<pii>> m;
	
	//for(int i = 0; i < n; ++i){
		//auto [x,y] = A[i];
		//for(int j = 0; j < n; ++j){
			//auto [a,b] = B[j];
			//int p = a + x, q = b + y;
			//m[{p,q}].push_back(make_pair(i,j));
		//}
	//}
	
	
	//for(auto p : m){
		//map<int,bool> x, y;
		//int cnt = 0;
		//for(int i = 0; i < (int)p.S.size() ; ++i){
			//auto [a, b] = p.S[i];
			//if(!x[a] && !y[b]){
				//x[a] = y[b] = true;
				//++cnt;
			//}
		//}
		//if(cnt == n){
			//printf("%d %d\n",p.F.F, p.F.S);
		//}
	//}
//}


void solve(){
	int n;
	scanf("%d",&n);
	vector<pii> A(n), B(n);
	
	long long a = 0, b = 0;
	for(auto &p : A){
		scanf("%d %d",&p.F,&p.S);
		a += p.F;
		b += p.S;
	}
	long long x = 0, y = 0;
	for(auto &p : B){
		scanf("%d %d",&p.F,&p.S);
		x += p.F;
		y += p.S;
	}
	
	printf("%lld %lld\n", (a + x)/n , (b + y)/n);
}
	

int main(){
	int tt;
	//scanf("%d",&tt);
	tt = 1;
	for(int _ = 1;_ <=tt;++_ ){
		solve();
	}
#ifndef ONLINE_JUDGE
 	cerr << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
	return 0;
}
