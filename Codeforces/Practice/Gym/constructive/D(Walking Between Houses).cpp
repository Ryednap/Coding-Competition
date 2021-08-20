#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

void solve(){
	int n, k;
	long long s;
	scanf("%d %d %lld", &n, &k, &s);
	
	long long maxi = (n - 1) * (long long)k;
	long long mini = 1 * k;
	if(s > maxi || s < mini) puts("NO");
	else {
		puts("YES");
		int q = (s + k - 1)/k ;
		int p = s / k ;
		int r = s % k;
		
		long long total = 0;
		int curr = 1;
		for(int i = 0; i < r; ++i){
			total += q;
			if(curr + q <= n){
				printf("%d " , curr += q);
			} else {
				printf("%d " , curr -= q);
			}
		}
	
		for(int i = 0; i < k - r; ++i){
			total += p;
			if(curr + p <= n) {
				printf("%d " , curr += p);
			} else {
				printf("%d ", curr -= p);
			}
		}
		
		//debug() << owo(total);
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
