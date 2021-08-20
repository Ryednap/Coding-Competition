#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = 100;
int n;
string arr[nax];


auto Obtain(bool a, bool b, int i) {
	string s = arr[i];
	if(s == "AND") return a & b;
	else return a | b;
}

auto Solve(int lo,  bool input) {
	array<long long, 2> result = {0, 0};
	int m = n / 4;
	for(int i = 0; i < (1LL << m); ++i) {
		bool val = false;

		for(int j = 0; j < m; ++j) {
			int bit = i & (1LL << j);
			if(j == 0) val = Obtain(bit, input, lo + j);
			else val = Obtain(val, bit, lo + j);
		}
		result[val]++;
	}
	return result;
}

long long answer = 0;

void Brute(int val, bool sig , int i, const auto & range) {
	if(i == 4) {
		answer += sig ? val : 0;
		return ;
	}
	
	for(int curr : {0, 1}) {
		auto ar = Solve(range[i], curr);
		ar[0] *= val;
		ar[1] *= val;
		debug() << owo(i) owo(curr) owo(sig) owo(ar);
		Brute(ar[0], false, i + 1,  range);
		Brute(ar[1], true, i + 1, range);
	}

}
	
	

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	array<int, 4> range = {0, n/4, n/2, (3 * n)/4};
	Brute(1, 1, 0, range);
	Brute(1, 0, 0, range);
	debug() << owo(range);
	printf("%lld", answer);
	return 0;
}
