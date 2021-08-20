#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

bool isPrime(int n) {
	if(n == 2 || n == 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;

	for(int i = 5; i <= sqrt(n); i += 2) {
		if(n % i == 0) return false;
	}
	return true;
}

const int nax = 1300;

using vi = vector<long long>;

int main() {
	vector<int> primes;
	for(int i = 2; i < nax; ++i) {
		if(isPrime(i)) primes.push_back(i);
	}
		
	int n, m;
	while (scanf("%d %d", &n, &m) && n) {
		const int p = (int)primes.size();
		//debug() << owo(p);
		// Don't over assign variable here I made p = p + 10 and that restulted in WA
		vector<vector<vi>> dp(p, vector<vi> (m + 10, vi(n + 100, -1)));
		function < long long (int , int, int) > Brute = [&] (int i, int j, int k) {
			if(j == m) return (k == n) ? 1LL : 0LL;
			if(i >= p) return 0LL;
			if(k > n) return 0LL;
			assert(i < p);
			assert(j < m + 10);
			assert(k < n + 100);
			assert(i >= 0 && j >= 0 && k >= 0);
			long long & ans = dp[i][j][k];
			if(ans != -1) return ans;
			
			long long a = Brute(i + 1, j, k);
			long long b = Brute(i + 1, j + 1, k + primes[i]);
			assert(a >= 0 && b >= 0);
			return ans = a + b;
		};
		
		long long answer = Brute(0, 0, 0);
		printf("%lld\n", answer);
	}
		
	return 0;
}
