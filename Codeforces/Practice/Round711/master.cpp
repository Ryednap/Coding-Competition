#include <bits/stdc++.h>

using pii = std :: pair<int, int>;

const int nax = 3e5 + 10;
int parent[nax];
int s[nax];
int xp[nax], grpxp[nax];

int find(int a) {
	return (parent[a] == a ? a : find(parent[a]));
}

int getExp(int a) {
	if(a == parent[a]) return grpxp[a];
	return grpxp[a] + getExp(parent[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a != b) {
		if(s[a] > s[b]) {
			std :: swap(a, b);
		}
		s[a] += s[b];
		grpxp[b] -= grpxp[a];
		parent[b] = a;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; ++i) {
		parent[i] = i;
		grpxp[i] = xp[i] = 0;
	}
	for(int i = 0; i < m; ++i) {
		std :: string command;
		std :: cin >> command;
		if (command == "add") {
			int a, b; scanf ("%d %d", &a, &b);
			a = find(a);
			grpxp[a] += b;

		} else if(command == "join") {
			int a, b; scanf("%d %d", &a, &b);
			unite(a, b);

		} else {
			int a; scanf("%d", &a);
			printf("%d\n", getExp(a));
		}
	}	
	return 0;
}
