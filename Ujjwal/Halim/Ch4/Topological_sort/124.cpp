#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;
using vvi = vector<vi>;

vvi edges;
vi indeg, used;
set <string> ans;
unordered_map<string, int> mapper;
unordered_map<int, string> flapper;

void generate (string s){
	bool completed = true;
	for (int x : used) {	
		if (x == false)
			completed = false;
	}
	if (completed) {
		ans.insert (s);
		return;
	}

	for (int i = 0; i < (int) edges.size(); ++i) {
		if (indeg[i] == 0 && !used[i]) {
			used[i] = true;
			for (int child : edges[i]) {
				indeg[child]--;
			}
			generate (s + flapper[i]);
			used[i] = false;
			for (int child : edges[i]) {
				indeg[child]++;
			}
		}
	}
}

int main () {
	string s;
	getline (cin, s);
	while (true) {
		std :: stringstream ss(s);
		std :: string in;

		int j = 0;
		while (ss >> in) {
			mapper[in] = j;
			flapper[j++] = in;
		}

		getline (std :: cin, s);
		ss = stringstream (s);
		edges = vvi (j);
		used = indeg = vi(j);
		while (ss >> in) {
			int u = mapper[in];
			ss >> in;
			int v = mapper[in];
			edges[u].push_back(v);
			indeg[v]++;
		}	

		generate ("");
		for (string x : ans) {
			puts (x.c_str());
		}
		if (!getline(cin, s))
			return 0;
		puts ("");
		mapper.clear();
		flapper.clear();
		ans = set<string> ();
	}
	return 0;
}