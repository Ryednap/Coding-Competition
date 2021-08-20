#include<bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Well we can not any O(n^2) solution . Maybe an O(n) solution based on some mathematical formula. But note that we can always create a stragtegy to pick
 * always the leftmost valid zero and I am sure that any mathematical forumula that would be deducued will take this thing into account. So Now to check
 * the validy For each 0 we need to check the index of 1 just left and right . For the left just maintain a variable that keeps record for right store all
 * the ones in set and use binary search. This completes the task in O(nLogn) .
 */

void solve(){	
	int n, k;
	scanf("%d %d",&n, &k);
	char table[n];
	scanf("%s", table);
	set<int> s;
	for(int i = 0; i < n; ++i){
		if( table[i] == '1') s.insert(i);
	}
	
	int answer = 0, last = -1;
	for(int i = 0; i < n; ++i){
		if(table[i] == '0'){
			auto a = s.lower_bound(i);
			bool ok = true;
			if(last != -1){
				if(i - last > k) ok &= true;
				else ok &= false;
			}
			if(a != s.end()){
				int j = *a;
				if(j - i > k) ok &= true;
				else ok &= false;
			}
			
			if(ok) {
				++answer;
				last = i;
			}
			
		} else last = i;
	}
	printf("%d\n", answer);
}


int main(){
	int tt;
	scanf("%d",&tt);
	for(int i = 0; i < tt; ++i){
		solve();
	}	
	return 0;	
}
