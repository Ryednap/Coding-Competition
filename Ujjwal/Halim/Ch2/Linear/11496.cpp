#include <bits/stdc++.h>

using namespace std;

/*
	# Attempts = 1
	Reading Time = 3 min
	Thinking Time = 1 min
	Coding Time = 3 min
	Total Time = 7 min

	Easy level Problem :- Just have a mod function and compare the local maxima/minima
*/

int main() {
	int n;
	while  ( scanf("%d", &n) && n ) {

		auto Mod = [&] (int a) {
			return (a + n) % n;
		};

		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}

		int answer = 0;
		for(int i = 0; i < n; ++i) {
			int left = arr[Mod(i - 1)];
			int right = arr[Mod(i + 1)];

			if(arr[i] > left && arr[i] > right) ++answer;
			else if(arr[i] < left && arr[i] < right) ++answer;
		}
		printf("%d\n", answer);
	}
}