#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * First Approach :-
 * I thought that making 1 is always true and similary if C1, C2 such that C1 > C2 then 2 is always possible
 * C1, C2, C3 such that C1 > C2 > C3, then C1 > C2 + C3, C2 > C3
 * C1, C2, C3, C4 then C1 > C2 + C3 + C4, C2 > C3 + C4, C3 > C4
 * ..
 * ..
 * ..
 * C1, C2, ... Cn then Ci > Sum(Cj) for 0 < j < i
 * 
 * Upto here my approach was correct
 * But later I thought this 
 * 
 * Now from Above conclusion we will always pick An which is the largest one
 * For A(n - 1) we have option to pick or to not pick
 * We will only do so if It's optimal.
 * 
 * i.e Suppose We chooose A(n - 1) then all the sum after this must be less than A(n) - A(n - 1).
 * If I don't Choose A(n - 1) then all the sum after this must be less than A(n - 1). ? Because if not then we can Choose A(n - 1) and that will disturb the order
 * 
 * So Here i will decide to pick or to not pick if Withdraw(A(n - 1)) < Withdraw(A(n) - A(n - 1))
 * The idea upto here was also correct. But using Withdraw as direct comparison was wrong. When i looked at the real solution. I recognised that
 * I was doing the same thing just in the reverse order.
 * 
 * 
 * Actually the correct solution is to pick or not pick if (current_sum + arr[i] < arr[i + 1]). and it's same meaning. if want to pick arr[i] then 
 * the remaining sum from (i - 1 ... 0) must be less than arr[i + 1] - arr[i].
 */


int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		
		long long curr = 0;
		int ans = 1;
		
		for(int i = 0; i < n - 1; ++i) {
			if(curr + arr[i] < arr[i + 1]) {
				++ans;
				curr += arr[i];
			}
		}
			
		
		printf("%d\n", ans);
	}
	return 0;
}
