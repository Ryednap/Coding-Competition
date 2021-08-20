#include <bits/stdc++.h>

using namespace std;


int main() {
	long long N;
	scanf("%lld", &N);
	int turn = 0;
	
	auto Valid = [&] ( ) {
		string s = to_string(N);
		for(auto ch : s) {
			if(ch != '9') return true;
		}
		return !((int)s.length() & 1);
	};
	
	auto Magic = [&] ( ) {
		string s = to_string(N);
		const int n = (int)s.length();
		if(n & 1) return false;
		string fh, lh;
		for(int i = 0; i < n; ++i) {
			if(i < n / 2) fh += s[i];
			else lh += s[i];
		}
		return lh == fh;
	};
	
	while( Valid( ) ) {
		if(Magic()) {
			string s = to_string(N), f;
			const int n = (int)s.length() >> 1;
			for(int i = 0; i < n; ++i) {
				f += s[i];
			}
			N = stoll(f);
		} else N++;
		++turn;
	}
	printf("%d\n", turn);
	return 0;
}
