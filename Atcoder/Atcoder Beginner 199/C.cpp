#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second



int main() {
	int n;
	scanf("%d", &n);
	n <<= 1;
	string s;
	cin >> s;
	
	int q;
	scanf("%d", &q);
	int turn = 0;
	
	auto Get = [&] (int index, int x) {
		if(!x) return index - 1;
		index = (index + (n >> 1)) % n;
		if(index == 0) index = n;
		return index - 1;
	};
	
	while (q--) {
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if(t == 2) turn ^= 1;
		else {
			int i = Get(a, turn);
			int j = Get(b, turn);
			//debug() << owo(i) owo(j);
			swap(s[i], s[j]);
		}
	}
	//debug() << owo(s);
	if(turn) {
		string a = s.substr(0, n >> 1);
		string b = s.substr(n >> 1, n);
		printf("%s%s\n", b.c_str(), a.c_str());
	} else puts(s.c_str());
			
		
	return 0;
}
