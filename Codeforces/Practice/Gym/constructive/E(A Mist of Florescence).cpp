#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

void solve(){
	array<int, 4> ar ;
	for(int i = 0; i < 4; ++i){
		scanf("%d", &ar[i]);
	}
	vector<vi> ans(50, vi(50, 100));
	
	for(int i = 0; i < 50; ++i){
		for(int j = i&1 ; j < 50; j += (i & 1 ? 2 : 1)){
			if(i < 25) ans[i][j] = 0;
			else ans[i][j] = 1;
		}
	}
	
	ar[0]--;
	ar[1]--;
	
	auto Valid = [&](int x, int row, int col){
		if(row && ans[row - 1][col] == x) return false;
		if(col && ans[row][col - 1] == x) return false;
		if(row < 50 && ans[row + 1][col] == x) return false;
		if(col <50 && ans[row][col + 1] == x) return false;
		return true;
	}; 
	
	
	for(int i = 0; i < 50; ++i){
		for(int j = 0; j < 50; ++j){
			if(ans[i][j] != 100) continue;
			int curr = -1;
			for(int color = 0; color < 4; ++color){
				if(ar[color] > 0 && Valid(color,i, j)){
					--ar[color];
					curr = color;
					break;
				}
			}
			if(curr == -1) break;		
			ans[i][j] = curr;
		}
	}
	
	for(int i = 0; i < 50; ++i){
		for(int j = 0; j < 50; ++j){
			if(i < 25 && ans[i][j] == 100) ans[i][j] = 0;
			else if(ans[i][j] == 100) ans[i][j] = 1;
		}
	}			
	for(int i = 0; i < 4; ++i){
		if(ar[i] != 0) assert(false);
	}
	
	puts("50 50");
	for(int i  = 0; i < 50; ++i){
		for(int x : ans[i]){
			printf("%c", x + 'A');
		}
		puts("");
	}
}
	
	

int main(){
	int tt;
	tt = 1;
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
