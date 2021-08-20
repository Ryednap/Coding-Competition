#include <bits/stdc++.h>
using namespace std;


int main() {
	int qq;
	scanf("%d", &qq);
	while( qq -- ) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int cnt = 0;
		for(int i = 1; i < n - 1; ++i) {
			bool mark = 0;
			if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) mark = 1;
			if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) mark = 1;
			cnt += mark;
		}
		
		auto Calc = [&](int pos) {
			int res = 0;
			for(int i = max(pos - 3, 1); i < min(pos + 3, n - 1); ++i) {
				if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ++res;
				if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) ++res;
			}
			return res;
		};
		
		int ans = cnt;
		for(int i = 1; i < n - 1; ++i) {
			int temp = arr[i];
			int a = Calc(i);
			arr[i] = arr[i - 1];
			int b = Calc(i);
			ans = min(ans, cnt - a + b);
			arr[i] = arr[i + 1];
			b = Calc(i);
			ans = min(ans, cnt - a + b);
			arr[i] = temp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
		
		
