#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int answer = 0;
	long long prev = 0;

	for(int i = 1; i <= n; ++i) {
		long long x; scanf("%lld", &x);
		if(x > prev + m) x = prev + m, ++answer;
		prev = x;
	}
	printf("%d\n", answer);
	return 0;
}	
