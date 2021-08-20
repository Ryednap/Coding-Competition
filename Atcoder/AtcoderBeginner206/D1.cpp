#include <bits/stdc++.h>

using namespace std;

const int nax = (int)2e5 + 10;

int parent[nax];
int sizee[nax];

int get(int a) {
	if(a == parent[a]) return a;
	return parent[a] = get(parent[a]);
}

void unite(int a, int b) {
	a = get(a);
	b = get(b);

	if(a != b) {
		if(sizee[a] > sizee[b]) swap(a, b);
		sizee[a] += sizee[b];
		parent[b] = a;
	}
}

int main() {
	for(int i = 0; i < nax; ++i) {
		parent[i] = i;
		sizee[i] = 1;
	}

	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < n / 2; ++i) {
		int a = arr[i];
		int b = arr [n - i - 1];
		unite(a, b);
	}

	int answer = 0;
	for(int i = 0; i < nax; ++i) {
		if(parent[i] == i) {
			answer += sizee[i] - 1;
		}
	}

	printf("%d\n", answer);
	return 0;
}