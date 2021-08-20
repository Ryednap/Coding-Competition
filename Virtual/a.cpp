#include <bits/stdc++.h>

using namespace std; 


int main() {
	int n;
	scanf("%d", &n);
	vector<string> v(n);
	
	
	
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
	for(int i = n - 1; i>= 0; --i) {
		cout << v[i] << endl;
	}
	return 0;
	
}