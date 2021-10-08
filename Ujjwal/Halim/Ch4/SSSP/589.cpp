#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define owo(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// implementation heaby problem
// state needs to be reduced with the help of shoretest path
// some bug due to which mine is producing even smaller cost answer.

using pii = pair<int, int>;
using piii = pair<int, pii>;
constexpr int OO = (int)1e7;
unordered_map<char, pii> dir = {
	{'N', pii(-1, 0)},
	{'S', pii(1, 0)},
	{'W', pii(0, -1)},
	{'E', pii(0, 1)}
};

unordered_map<char, char> oppo = {
	{'N', 'S'},
	{'S', 'N'},
	{'W', 'E'},
	{'E', 'W'}
};

struct State {
	pii pos, engine;
	int cost;
	string moves;
	State () {moves = "";}
	State (pii a, pii b, int c, string s = "") : pos(a), engine(b), cost(c), moves(s) {}
	bool operator < (const State & rhs) const {
		return cost > rhs.cost;
	}
};

#define FOR(i, a) for (int i = 0; i < a; ++i)

int main () {
	int n, m;
	int tt = 0;
	while (scanf ("%d %d", &n, &m)) {
		if (!n && !m) break;
		printf ("Maze #%d\n", ++tt);
		vector<string> mat(n);
		for (string & s : mat) cin >> s;
		pii dest, src, me;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == 'S') me = make_pair(i, j);
				if (mat[i][j] == 'B') src = make_pair(i, j);
				if (mat[i][j] == 'T') dest = make_pair(i, j);
			}
		}

		auto valid = [&] (int x, int y) -> bool {
			if (x < 0 || y < 0 || x >= n || y >= m) return false;
			return mat[x][y] != '#';
		};
	
		auto bfs_util = [&] (pii s, pii t, pii other) -> pair<string, int> {
			queue<State> q;
			vector<vector<int>> vis(n, vector<int> (m, false));
			q.push(State(s, pii(-1, -1), 0));
			vis[s.first][s.second] = true;
			vis[other.first][other.second] = true; // cannot move through box
			while (!q.empty()) {
				auto v = q.front(); q.pop();
				pii node = v.pos;
				int cost = v.cost;
				string move = v.moves;
				if (node == t) {
					return make_pair(move, cost);
				}

				for (char ch : {'N', 'S', 'W', 'E'}) {
					int rr = node.first + dir[ch].first;
					int cc = node.second + dir[ch].second;
					if (valid(rr, cc) && !vis[rr][cc]) {
						char c = tolower(ch);
						q.push(State(pii(rr, cc), pii(-1, -1), cost + 1, move + c));
						vis[rr][cc] = true;
					}
				}

			}
			return make_pair("", OO);
		};

		priority_queue<State> pq;
		int dist[n][m][n][m];
		FOR(i, n) FOR(j, m) FOR(k, n) FOR(l, m) dist[i][j][k][l] = OO;
		dist[src.first][src.second][me.first][me.second] = 0;
		pq.push(State(src, me, 0));
		bool found = false;
		while (!pq.empty()) {
			auto v = pq.top(); pq.pop();
			int cost = v.cost;
			pii node = v.pos, engine = v.engine;
			string moves = v.moves;
			if (cost > dist[node.first][node.second][engine.first][engine.second]) continue; // some other state reached better
			//debug() << owo(node) owo(engine) owo(cost) owo(cost) owo(dist[4][4][4][4]); 
			if (node == dest) {
				found = true;
				puts(moves.c_str());
				break;
			}

			for (auto & p : dir) {
				int dx = p.second.first, dy = p.second.second; // direction to move
				int dX = dir[oppo[p.first]].first, dY = dir[oppo[p.first]].second; // direction opposite
				if (valid(node.first + dx, node.second + dy) && valid(node.first + dX, node.second + dY)) {	
					pii target = make_pair(node.first + dX, node.second + dY); // opposite target
					auto req = bfs_util(engine, target, node); // cost and moves requried to move the object 
					int value = cost + req.second + 1; // new value after move
					if (value < dist[node.first + dx][node.second + dy][node.first][node.second]) {
						dist[node.first + dx][node.second + dy][node.first][node.second] = value;
						string newMove = moves + req.first;
						pq.push(State(pii(node.first + dx, node.second + dy), node, value, newMove + p.first));
					}
				}
			}
		}
		if (!found) puts("Impossible.");
		puts("");
	}
}