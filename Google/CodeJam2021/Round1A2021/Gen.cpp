#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int rand(int a, int b) {
	return rand() % (b - a + 1);
}

int main(int argv, char ** argc) {
	srand(stoi(argc[1]));
	
	int qq = rand(1, 10);
	set<array<int, 3>> v(qq);
	 while ((int)v.size() != qq) {
		int l = rand(1, 1e4);
		int r = rand(1, 1e4);
		if(l > r) swap(l, r);
		int c = rand(1, 1e3);
		array<int, 3> ar = {l, r, c};
		v[i] = ar;
	 }
	 
	 for(auto a : v) [
	 
		
	puts("");
	return 0;
}
