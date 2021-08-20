#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Watchout : The problem statement is wrong where they claim the 2 command produces x without error.


int main( ) {
	int n;
	while (scanf("%d", &n) != EOF) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		
		array<int, 3> ar = {1, 1, 1};
		bool ok = true;
		for(int i = 0 ; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(a == 1) {
				s.push(b);
				q.push(b);
				pq.push(b);
				
			} else if(!s.empty()){
				int x = s.top(); 	s.pop();
				if(x != b) ar[0] = false;
				x = q.front(); 	q.pop();
				if(x != b) ar[1] = false;
				x = pq.top();  pq.pop();
				if(x != b) ar[2] = false;
			} else ok = false;
		}
		
		vector<int> ans;
		for(int i = 0; i < 3; ++i) {
			if(ar[i]) ans.push_back(i);
		}
		if((int)ans.size() == 0 || ok == false) puts("impossible");
		else if((int)ans.size() > 1) puts("not sure");
		else {
			if(ans[0] == 0) puts("stack");
			else if(ans[0] == 1) puts("queue");
			else if(ans[0] == 2) puts("priority queue");
			
		}
	}
	return 0;	
}
