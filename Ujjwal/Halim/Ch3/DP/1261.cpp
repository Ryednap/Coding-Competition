#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

/*
	A very nice demonstration of unusual usage of data structre in dp.
	The complexity is same, but storing the state like this requires
	additional n factor in memory complexity
	so if Time complexity is T(n) then our memory complexity will be n * T(n)
	where n is the length of the string.
*/

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		//debug() << owo(min(make_pair(1, 2), make_pair(1, 1)));
		string s;
		cin >> s;
		
		unordered_map <string, bool> dp;
		
		
		function < bool (string) > Brute = [&] (string str) {
			//debug() << owo(str);
			const int n = (int)str.length();
			if(n == 0) return true;
			if(n == 1) return false;
			
			if(dp.find(str) != dp.end()) return dp[str];
			
			bool & ans = dp[str];
			

			
			for(int i = 0; i < n; ++i) {
				int j = i; 
				while (str[i] == str[j]) ++j;
				if(j == i + 1) continue;
				string left = str.substr(0, i);
				string right = str.substr(j, n);
				//debug() << owo(left) owo(right) owo(i) owo(j);
				ans |= Brute(left + right);
			}
			return ans;
		};
		
		bool answer = Brute(s);
		if(answer) puts("1");
		else puts("0");
	}
			
	return 0;
}
