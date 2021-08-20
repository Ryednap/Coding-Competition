#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d",&qq);
	while (qq--) {
		int n;
		scanf("%d",&n);
		string words[n];
		for(int i = 0; i < n; ++i) {
			cin >> words[i];
		}
		
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				string a = words[i];
				string b = words[j];
				
			}
		}
						
		printf("%d\n", answer);
	}

	return 0;
}
