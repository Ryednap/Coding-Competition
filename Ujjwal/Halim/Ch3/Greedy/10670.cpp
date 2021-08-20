#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Greedy strategy

// Subtraction should only be done at later stage:

// Reason suppose after kth turn we are subtracting, then we get 
// (x / (2 ^ k)) - 1 which is equal to (x - 2 ^ k) / 2 ^ k in just k + 1 operation.
// If we have done first subtraction then it would have taken 2 ^ k + 2 ^ k operation.
// Hence proved.

int a, b;

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while (qq--) {
		int x, n, m;
		scanf("%d %d %d", &x, &m, &n);
		printf("Case %d\n", ++tt);
		vector<pair<int, string>> ans;
		
		for(int i = 0; i < n; ++i) {
			//dp = vector<int> (x + 1, -1);
			string s;
			cin >> s;
			stringstream ss1(s);
			string name, INT;
			getline(ss1, name, ':');
			getline(ss1, INT, ':');
			
			string p;
			stringstream ss2(INT);
			getline(ss2, p, ','); a = stoi(p);
			getline(ss2, p, ','); b = stoi(p);
			
			
			
			int curr = x, cost = 0;
			while (curr != m) {
				 int next = curr >> 1;
				 if(next >= m) {
					 int d = curr - next;
					 if(d * a < b) {
						 cost += d * a;
						 
					 } else cost += b;
				 	curr = next;
				 	
				 } else {
					 cost += (curr - m) * a;
					 curr = m;
				 }
			}
			
			ans.emplace_back(cost, name);
		
		}
		sort(ans.begin(), ans.end());
		
		for(auto p : ans) {
			printf("%s %d\n", p.second.c_str(), p.first);
		}
	}
			
		
		
	return 0;
}
