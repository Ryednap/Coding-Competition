#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Just sort the strings because the largest that we can get is from consecutive becuase it gives 2 ^ |length|.

void solve(){
	int n;
	scanf("%d",&n);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	puts(str.c_str());
}


int main(){
	int tt;
	scanf("%d", &tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}
	return 0;	
}
