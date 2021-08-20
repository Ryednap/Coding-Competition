//You are given two matrices A and B. Each matrix contains exactly n rows and m columns. Each element of A is either 0 or 1; each element of B is initially 0.
//You may perform some operations with matrix B. During each operation, you choose any submatrix of B having size 2×2, and replace every element in the chosen submatrix with 1. In other words, you choose two integers x and y such that 1≤x<n and 1≤y<m, and then set Bx,y, Bx,y+1, Bx+1,y and Bx+1,y+1 to 1.
//Your goal is to make matrix B equal to matrix A. Two matrices A and B are equal if and only if every element of matrix A is equal to the corresponding element of matrix B.
//Is it possible to make these matrices equal? If it is, you have to come up with a sequence of operations that makes B equal to A. Note that you don't have to minimize the number of operations.
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * It's an obivious implementation based problem the constructive lies in choosing the answer. For that it's causes no harm to choose any submatrix is it's
 * all zero's also the question is not about minimising it.
 */

using pii = pair<int,int>;
using vi = vector<int> ;

int dx[] = {0,0,1,1};
int dy[] = {0,1,0,1};

void solve(){
	int n, m;
	scanf("%d%d",&n,&m);

	vector<vi> A(n, vi(m));
	vector<vi> B(n, vi(m));
	for(int i = 0;i < n; ++i){
		for(int j =0 ; j< m; ++j){
			scanf("%d",&A[i][j]);
		}
	}
	
	vector<pii> ans;
	
	
	auto Set = [&](int x, int y){
		if(x + 1 == n || y + 1 == m) return;
		
		for(int i = 0; i < 4; ++i){
			if(!A[dx[i] + x][dy[i] + y]) return;
		}
		for(int i = 0; i < 4; ++i){
			B[dx[i] + x][dy[i] + y] = 1;
		}
		ans.push_back(make_pair(x + 1,y + 1));
	};
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(A[i][j] == 1){
				Set(i,j);
			}
		}
	}
	for(int i = 0; i < n;++i){
		for(int j = 0; j < m; ++j){
			if(A[i][j] != B[i][j]) {
				puts("-1");
				return;
			}
		}
	}
	
	
	printf("%d\n", (int)ans.size());
	for(auto x : ans) printf("%d %d\n", x.first, x.second);
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
