#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vector<int> arr(n);
		arr[0] = 0;
		for(int i = 1; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		vector<int> pref(n);
		for(int i = 1; i < n; ++i) {
			pref[i] += pref[i - 1] + arr[i];
		}
		
		int answer = 0, mini = 0, last = 0;
		pair<int, int> where = {0, -1};
		
		for(int i = 1; i < n; ++i) {
			int value = pref[i] - mini;
			if(value > answer) {
				answer = value;
				where = make_pair(last, i);
				
			} else if(value == answer) {
				//debug() << owo(where) owo(last) owo(i);
				if(where.s - where.f < i - last) {
					where = make_pair(last, i);
				}
			}
			
			if(mini > pref[i]) {
				last = i;
				mini = pref[i];
			}

		}
		
		if(where.second == -1) printf("Route %d has no nice parts\n", ++tt);
		else printf("The nicest part of route %d is between stops %d and %d\n", ++tt, where.first +1, where.second + 1);
	}
	
	return 0;
}
