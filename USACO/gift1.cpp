/*
ID: ujjwal.9
TASK: gift1
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
// C++14


int main(){
	freopen("gift1.in", "rt", stdin);
	freopen("gift1.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	string name[n];
	for(int i = 0; i < n; ++i) {
		cin >> name[i];
	}
	map<string, int> m;
	for(int i = 0; i < n; ++i) { 
		string from;
		cin >> from;
		int amount, k;
		scanf("%d%d",&amount, &k);
		if(k != 0){
			m[from] -= amount;
			m[from] += amount % k;
		}
		
		for(int j = 0;j < k; ++j) {
			string to;
			cin >> to;
			m[to] += (amount/k);
		}
	}
	
	for(int i = 0; i < n; ++i) {
		printf("%s %d\n", name[i].c_str(), m[name[i]]);
	}
	
	return 0;	
}
