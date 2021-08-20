#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

const int NAX = 64000 + 1;
using vi = vector<int>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n,m;
		scanf("%d", &n);
		vi arr(n);
		
		for(int & x : arr) {
			scanf("%d", &x);
		}
		
		scanf("%d", &m);
		vector<vi> dp(n, vi(NAX, -1));
		
		auto Hash = [&] (int x) {
			if(x >= 0) return x;
			else return NAX + x; // actually it's NAX - x but x is already negative.
		};
		
		function < int (int, int) > Brute = [&] (int i, int j) {
			if(j > 32000 || j < -32000) return 0;
			if(i == n) {
				//if(j == m) debug() << owo(j);
				return j == m ? 1 : 0;
			}
				//debug() << owo(i) owo(j) owo(Hash(j));
				int & ans = dp[i][Hash(j)];
				if(ans != -1) return ans;
			
				bool ok = false;
				ok |= Brute(i + 1, (j + arr[i]));
				ok |= Brute(i + 1, (j - arr[i]));
				ok |= Brute(i + 1, (j * arr[i]));
				if(j % arr[i] == 0) ok |= Brute(i + 1, (j / arr[i]));
				return ans = ok;
		};
		
		
		bool res = Brute(1, arr[0]);
		string ans = to_string(arr[0]);
		int total = arr[0];
		
		function < void (int, int) > Build = [&] (int i, int j) {
			if(i == n) {
				ans += "=" + to_string(m);
				return;
			}
			string s = to_string(arr[i]);
			if(Brute(i + 1, j + arr[i])) {
				ans += "+" + s ;
				total += arr[i];
				Build(i + 1, j + arr[i]);
				return;
			}
			if(Brute(i + 1, j - arr[i])) {
				ans += "-" + s;
				total -= arr[i];
				Build(i + 1, j - arr[i]);
				return;
			} 
			if(Brute(i + 1, j * arr[i])) {
				ans += "*" + s;
				total *= arr[i];
				Build(i + 1, j * arr[i]);
				return;
			}
			
			if(j % arr[i] == 0 && Brute(i + 1, j / arr[i])) {
				ans += "/" + s;
				total /= arr[i];
				Build(i + 1, j / arr[i]);
				return;
			}
		};

		if(res) {
			Build(1, arr[0]);
			puts(ans.c_str());
			assert(total == m);
		} else puts("NO EXPRESSION");
		
	}
	return 0;
}

// Issue :- In solving this kind of problem remember to pass the first number as the parameter the mistake was that 
// only i was starting from 0 this is the main issue.
