#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int rand(int a, int b) {
	return rand()%(b - a + 1);
}



int main() {
	string s1, s2;
	 for(int i = 0; i < 100; ++i) {
		 s1 += 'z';
	 }
	 for(int i = 0; i < 50; ++i) {
		 s2 += 'a';
	 }
	 
	int n = 1000, m = 500;
	printf("%d %d\n", n, m);
	for(int i = 0; i < n; ++i) {
		puts(s1.c_str());
	}
	for(int j = 0; j < m; ++j) {
		puts(s2.c_str());
	}
	return 0;
}
