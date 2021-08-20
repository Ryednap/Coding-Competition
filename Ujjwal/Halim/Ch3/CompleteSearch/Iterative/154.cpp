#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A very nice and cute problem
// O(n ^ 2 logn)

const int OO = (int)1e9 + 10;
int main() {
	string str;
	while( true ) {
		getline(cin, str);
		if(str == "#") break;
		vector<map<char, char> > v;
		while (true) {
			map<char, char> mapper;
			if(str[0] == 'e') break;
			stringstream ss(str);
			string inp;
			while (getline(ss, inp, ',')) {
				mapper[inp[0]] = inp[2];
			}
			v.push_back(mapper);
			getline(cin, str);
		}
		int total = OO;
		int ans = -1;
		for(int i = 0; i < (int)v.size(); ++i) {
			int cnt = 0;
			for(int j = 0; j < (int)v.size(); ++j) {
				auto a = v[i];
				auto b = v[j];
				for(auto p : a) {
					if(p.second != b[p.first]) ++cnt;
				}
			}
			if(cnt < total) {
				total = cnt;
				ans = i;
			}
		}
		printf("%d\n", ans + 1);
	}
	
		
	return 0;
}
