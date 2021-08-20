#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Easy constructivness is that we can replace one of the digit from whole grid with something other from 1 to 9.
 */
	

void solve(){	
	vector<string> grid(9);
	
	for(int i = 0; i < 9;  ++i){
		cin >> grid[i];
		for(int j = 0; j < 9; ++j){
			if(grid[i][j] == '9') grid[i][j] = '1';
		}
	}
	
	for(int i = 0; i < 9; ++i){
		puts(grid[i].c_str());
	}
}

int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}	
	return 0;	
}
