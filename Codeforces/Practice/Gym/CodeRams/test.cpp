#include <bits/stdc++.h>

using namespace std;

long long rand (long long a, long long b) {
	return rand() % (b - a + 1);
}

int main(int argv, char ** argc) {
	srand(atoi(argc[1]));
	printf("%lld\n", rand(1e6 + 10, 1e12L));
	return 0;
}
	
	
		
