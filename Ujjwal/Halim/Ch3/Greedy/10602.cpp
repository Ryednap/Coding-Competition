#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int Cost (string s, string t) {
	const int a = (int)s.length();
	const int b = (int)t.length();
	int i = 0;
	for(i = 0; i < min(a, b); ++i) {
		if(s[i] != t[i]) break;
	}
			
	return (int)t.length() - i;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		vector<string> arr(n);
		
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		sort(arr.begin(), arr.end());
		int ans = 0;
		ans += (int)arr[0].length();
	
		for(int i = 1; i < n; ++i) {
			ans += Cost(arr[i - 1], arr[i]);
		}
		printf("%d\n", ans);
		for(int i = 0; i < n; ++i) {
			puts(arr[i].c_str());
		}

	}
	return 0;
}
