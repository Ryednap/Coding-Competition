#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		ll l, r;
		int k;
		scanf("%lld %lld %d", &l, &r,&k);

		
		string L = bitset<64>(l).to_string();
		string R = bitset<64>(r).to_string();
		const int n = R.length();
		vector<vvvi> dp(n + 1, vvvi(k + 1, vvi(2, vi(2, -1))));
		function < int(int, int, int, int)> brute = [&] (int i, int j, int lower, int upper) {
			if(j > k)
				return 0;
			if(i == n)
				return j == k ? 1 : 0;

			if(dp[i][j][upper][lower] != -1)
				return  dp[i][j][upper][lower];

			int bitL = L[i] - '0';
			int bitR = R[i] - '0';
			int ans = 0;


			if(bitL == 0 && bitR == 0) {
				ans |= brute(i + 1, j, lower, upper);
				if(upper == 1) {
					ans |= brute(i + 1, j + 1, 1, upper);
				}

			} else if(bitL == 0 && bitR == 1) {
				ans |= brute(i + 1, j, lower, 1);
				ans |= brute(i +1, j + 1, 1, upper);

			} else if(bitL == 1 && bitR == 0) {
				if(lower == 1) ans |= brute(i + 1, j, lower, upper);
				if(upper == 1) ans |= brute(i + 1, j + 1, lower, upper);

			} else {
				if(lower == 1) ans |= brute(i + 1, j, lower, 1);
				ans |= brute(i + 1, j + 1, lower, upper);
			}
			return dp[i][j][upper][lower] = ans;
		};

		string answer = "";
		function < void (int, int, int, int)> build = [&] (int i, int j, int lower, int upper) {
			if(i == n)
				return;
			int here = brute(i, j, lower, upper);

		    int bitL = L[i] - '0';
			int bitR = R[i] - '0';
			
			if(bitL == 0 && bitR == 0) {
				if(here == brute(i + 1, j, lower, upper)) {
					answer.push_back('0');
					build(i + 1, j , lower, upper);
					return;
				}
				if(upper == 1) {
					answer.push_back('1');
					build(i + 1,j + 1, 1, upper);
					return;
				}

			} else if(bitL == 0 && bitR == 1) {
				if(here == brute(i + 1, j, lower, 1)) {
					answer.push_back('0');
					build(i + 1, j , lower, 1);
					return;
				}
				if(here == brute(i + 1, j + 1, 1, upper)) {
					answer.push_back('1');
					build(i + 1,j + 1, 1, upper);
					return;
				}

			} else if(bitL == 1 && bitR == 0) {

				if(lower == 1) if(here == brute(i + 1, j, lower, upper)) {
					answer.push_back('0');
					build(i + 1, j, lower, upper);
					return;
				}
				if(upper == 1) if(here == brute(i + 1, j + 1, lower, upper)) {
					answer.push_back('1');
					build(i + 1, j + 1, lower, upper);
					return;
				}

			} else {
				if(lower == 1) if(here == brute(i + 1, j, lower, 1)) {
					answer.push_back('0');
					build(i + 1,j , lower, 1);
					return;
				}

				if(here == brute(i + 1, j + 1, lower, upper)) {
					answer.push_back('1');
					build(i + 1,j + 1, lower, upper);
					return;
				}
			}
		};

		bool possible = brute(0, 0, 0, 0);
		//debug() << owo(L) owo(R);
		if(possible) {
			build(0, 0, 0, 0);
			printf("%lld\n", bitset<64>(answer).to_ulong());
		} else puts("-1");
	}
}