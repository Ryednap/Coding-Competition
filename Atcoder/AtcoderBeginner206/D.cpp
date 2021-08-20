#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)2e5 + 10;

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> Edges(nax);
	int arr[n];
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < n / 2; ++i) {

		int a = arr[i];
		int b = arr[n - i - 1];
		Edges[a].push_back(b);
		Edges[b].push_back(a);
	}

	vector<int> used(nax, false);
	function < int (int) > Dfs = [&] (int node) {
		//debug() << owo(node);
		used[node] = true;
		int here = 0;

		for(auto & child : Edges[node]) {
			if(!used[child]) {
				here += 1 + Dfs(child);
			}
		}

		return here;
	};

	int answer = 0;
	for(int i = 1; i < nax; ++i) {
		if((int)Edges[i].size() == 1) answer += Dfs(i);
	}
	for(int i = 1; i < nax;  ++i) {
		answer += Dfs(i);
	}
	printf("%d\n", answer);

	return 0;
}

void main() {
	return 0;
}

Hello World;
