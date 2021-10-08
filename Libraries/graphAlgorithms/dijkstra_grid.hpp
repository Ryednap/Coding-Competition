#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
constexpr int OO = (int)1e9;

template<typename T>
struct Edge {
	pii from, to;
	T cost;
	Edge () {}
	Edge (pii f, pii t, T c) : from(f), to(t), cost(c) {}
	bool operator < (const Edge & rhs) const {
		return cost > rhs.cost; // for priority_queue
	}
};

// debug & operator << (debug & d, cosnt Edge & e) { d << "{ " << from << ", " << to << ", " << cost << " }"; return d;}

array<int, 4> dx = {-1, 1, 0, 0};  
array<int, 4> dy = {-1, 1, 0, 0};

/*
	type T :- type for storing distance
	Assuming cost function is given other modify the * place

*/
template<typename T>
vector<vector<T>> dijkstra (const vector<vi> & grid, const vector<vi> & cost, pii src = 0) {
	vector<vector<T>> dist(grid.size(), OO);
	dist[src.first][src.second] = 0;
	using et = Edge<T>;
	priority_queue<et> pq;
	pq.push(et(pii(-1, -1), src, 0));

	auto valid = [&] (int x, int y) -> bool {
		if (x < 0 || y < 0 | x >= (int)grid.size() || y >= (int)grid[0].size()) return false;
		// other constraints;
		return true;
	};

	while (!pq.empty()) {
		auto v = pq.top(); pq.pop();
		int w = v.cost;
		pii to = v.to;

		if (w > dist[to.first][to.second]) continue; // some other state reached better
		for (size_t i = 0; i < dx.size(); ++i) {
			int rr = dx[i] + to.first;
			int cc = dy[i] + to.second;
			if (valid(rr, cc)) {
				int c = w + cost[to.first][to.second]; //*
				if (c < dist[rr][cc]) { 
					dist[rr][cc] = c; pq.push(et(to, pii(rr, cc), c));
				}
			}
		}
	}
	return dist;
}