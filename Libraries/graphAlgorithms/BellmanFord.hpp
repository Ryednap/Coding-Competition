#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

/*
	return :- boolean (presence of -ve cycles)
	prameters :- edgeList, reference to distance

	Assumption :- distance vector has been properly initialized.
*/
const int OO = (int)1e9;
bool bellmanFord (int n, const vector<piii> & adj, vector<int> & d) {
	int last;
	for (int i = 0; i < n; ++i) {
		last = -1;
		for (auto & edges : adj) {
			int w = edges.first;
			auto p = edges.second;
			if (d[p.first] < OO && d[p.second] > d[p.first] + w) {
				d[p.second] = d[p.first] + w;
				last = p.second;
			}
		}
	}
	return (last == -1);
}

/*
	Overloaded bellman ford to generate negaitve cycle in the graph.
*/

bool bellmanFord (int n, const vector<piii> & adj, vector<int> & d, vector<int> & path) {
	int last;
	vector<int> par(n);
	for (int i = 0; i < n; ++i) {
		last = -1;
		for (auto & edges : adj) {
			int w = edges.first;
			auto p = edges.second;
			if (d[p.first] < OO && d[p.second] > d[p.first] + w) {
				d[p.second] = d[p.first] + w;
				par[p.second] = p.first;
				last = p.second;
			}
		}
	}
	if (last != -1) return false;
	for (int i = 0; i < n; ++i) {
		last = par[last];
	}

	for (int curr = last; ; curr = par[curr]) {
		path.push_back(curr);
		if (curr == last && path.size() > 1) break;
	}
	reverse(path.begin(), path.end());
	return true;
}

