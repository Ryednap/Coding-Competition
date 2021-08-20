#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	string s, inp;
	while (getline(cin, s)) {
		stringstream ss(s);
		vector<int> w;
		
		while( ss >> inp) {
			int x = 0;
			for(char ch : inp) {
				x <<= 5;
				x += (ch - 'a' + 1);
			}
			w.push_back(x);
		}
		
		vector<int> c;
		for(int i = 1; i < OO; ++i) {
			for(int j = 0; j < n; ++j) {
				
	}
	return 0;
}
