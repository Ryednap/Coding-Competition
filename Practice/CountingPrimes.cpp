#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <set>

using vi = std :: vector<int>;

vi primes;

bool isPrime(int n) {
	if(n == 2 || n == 3)return true;
	if(n % 2 == 0|| n % 3 == 0) return false;
	for(int i = 5; i <= sqrt(n); ++i) 
		if(n % i == 0)
			return false;

	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int rating[n], range[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &rating[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &range[i]);
	}
	for(int i = 2; i <= 100; ++i) {
		if(isPrime(i))
			primes.push_back(i);
	}
	int ans[n];

	for(int i = 0; i < n; ++i) {
		std :: set<int> unique;
		for(int j = i - 1; j >= i - range[i]; --j) {
			for(auto x : primes)
				if(rating[i] % x == 0 && rating[j] %x == 0)
					unique.insert(x);
		}
		ans[i] = unique.size();
	}

	for(int i = 0 ; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}