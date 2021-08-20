#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Think about swap sort , with one temp variable we can sort the whole sequence how ? well let's say a b c are at some way we can get any permutation of
 * it using b let's say. Think ?. (**Note** Keep this idea in mind most of the constructive problem on sorting can be simplified with this).
 */

void solve(){	
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	bool one = false, zero = false;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x) one = true;
		else zero = true;
	}
	
	if(is_sorted(arr, arr + n)){
		puts("Yes");
		
	} else {
		puts((one && zero ?  "Yes" : "No"));
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
