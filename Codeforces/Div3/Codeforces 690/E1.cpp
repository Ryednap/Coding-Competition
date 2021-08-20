#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

/*
 * An easy combinatorics problem. I could'nt do it because i had faced a similar problem on GP of tuple but that approach was not possible here . Actually that problem's 
 * in real was based on this fact only just it was hidden. So I am going to label a nice fact on nCk. When we have some items and we can choose k things suppose we chose
 * a set of k things. Now there are k! configuration in which we can arrange the items , however out this only one configuration is sorted so nCk is same as choosing sorted order
 * Also in some problem this fact helps in which we are required to do the reverse thing , like we need to count and what we can do to simply the process is to sort the data
 * before only. there was a Topcoder Problem which explains this fact very nicely.
 */

long long nC2(int n){
	return ( (long long)n * (n - 1))/2;
}

long long nC3(int n){
	return ( (long long) n * (n - 1) * (n - 2))/6;
}
	

void solve(){
	int n;
	scanf("%d",&n);
	

	vector<int> cnt(n + 10);
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}

	long long answer = 0;
	for(int i = 1; i <= n; ++i){
		if(cnt[i] == 0 ) continue;
		answer += (long long) cnt[i] * cnt[i + 1] * cnt[i + 2];
		answer += nC2(cnt[i]) * cnt[i + 1];
		answer += nC2(cnt[i]) * cnt[i + 2];
		answer += nC3(cnt[i]);
		answer += cnt[i] * nC2(cnt[i + 1]);
		answer += cnt[i] * nC2(cnt[i + 2]);
	}
	
	printf("%lld\n",answer);
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}	
	
	return 0;
}
