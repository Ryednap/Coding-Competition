#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;

vvi edges;
vi indeg, used;
vector<string> ans;
unordered_map<string, int> mapper;
unordered_map<int, string> flapper;

void generate (void){
	for (int i = 0; i < (int) edges.size(); ++i) {
		if (indeg[i] == 0 && !used[i]) {
			used[i] = true;
			ans.push_back(flapper[i]);
			for (int child : edges[i]) {
				indeg[child]--;
			}
			generate ();
		}
	}
}

int main () {
	int n, tt = 0;
	while (scanf ("%d", &n) != EOF) {
		edges = vvi(n);
		indeg = used = vi(n);
		ans = vector<string> ();

		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			mapper[s] = i;
			flapper[i] = s;
		}

		int m;
		scanf ("%d", &m);
		for (int i = 0; i < m; ++i) {
			string a, b;
			cin >> a >> b;
			int u = mapper[a];
			int v = mapper[b];
			edges[u].push_back(v);
			indeg[v]++;
		}
		generate();
		printf ("Case #%d: Dilbert should drink beverages in this order:", ++tt);
		for (string str : ans) {
			printf (" %s", str.c_str());
		}
		puts(".\n");
	}
	return 0;
}