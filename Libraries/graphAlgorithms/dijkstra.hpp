#include <bits/stdc++.h>
using namespace std;

constexpr int OO = (int)1e9;
using pii = pair<int, int>;
template<typename T> 
vector <int> dijkstra (const vector<vector<pii>> & adj, int src = 0) {
 	const int n = adj.size();
 	vector<int> dist(n, OO);
 	dist[0] = 0;
 	priority_queue<pii> pq;
 	pq.push(make_pair(0, 0));
 	while (!pq.empty()) {
 		auto v = pq.top(); pq.pop();
 		int w = v.first, node = v.second;
 		if (w > dist[node]) continue; // some other state reached better
 		for (auto & u : adj[node]) {
 			int c = w + u.first;
 			if (dist[u.second] > c) {
 				dist[u.second] = c; pq.push(make_pair(c, u.second));
 			}
 		}
 	}
 	return dist;
}