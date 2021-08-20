#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int, int>;
using ll = long long;

#define f first
#define s second
#define mp(a, x) make_pair(a, x);
#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

struct edge {
	pii from, to;
	int w;
	edge(pii f, pii t, int we): from(f), to(t), w(we) {}
	bool operator < (const edge & e) const {
		return w > e.w;
	}
};


const int OO = (int)1e9;

int dx [] = {0, 0, -1, 1};
int dy [] = {-1, 1, 0, 0};


int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	vector<string> mat = vector<string> (n);
	for (int i = 0; i < n; ++i) {
		cin >> mat[i];
	}

	pii src = {0, 0};

	vvi dist(n + 1, vi(m + 1, OO));
	priority_queue<edge> pq;
	pq.push(edge(pii(-1, -1), src, 0));
	dist[src.f][src.s] = 0;

	auto valid = [&] (int x, int y) {
		if(x < 0 || y < 0 || x >= n || y >= m)
			return false;
		return true;
	};

	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		if(e.w > dist[e.to.f][e.to.s])	continue;	// some other state reached better
		for (int i = 0; i < 4; ++i) { // normal option
			int rr = e.to.f + dx[i];
			int cc = e.to.s + dy[i];
			if(!valid(rr, cc))
				continue;
			if(mat[rr][cc] == '#')
				continue;
			if (dist[rr][cc] > dist[e.to.f][e.to.s]) {
				dist[rr][cc] = dist[e.to.f][e.to.s];
				pq.push(edge(e.to, pii(rr, cc), dist[rr][cc]));
			}
		}
		for (int i = -2; i <= 2; ++i) {
			for (int j = -2; j <= 2; ++j) {
				if(abs(i) == 2 && abs(j) == 2)
					continue;
				int rr = e.to.f + i;
				int cc = e.to.s + j;
				if(rr == cc)
					continue;
				if (!valid(rr, cc))
					continue;
				if (dist[rr][cc] > dist[e.to.f][e.to.s] + 1) {
					dist[rr][cc] = dist[e.to.f][e.to.s] + 1;
					pq.push(edge(e.to, pii(rr, cc), dist[rr][cc]));
				}
			}
		}
		
	}
	printf ("%d\n", dist[n - 1][m - 1]);
	return 0;
}