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

using pii = pair<int, int>;

const int dx [] = {-1, 1, 0, 0};
const int dy [] = {0, 0, -1, 1};

int main () {
  int r, c;
  while (scanf ("%d %d", &r, &c)) {
    if (!r && !c) break;
    vector<vector<int>> grid(r, vector<int> (c, true));
    int n; scanf ("%d", &n);
    while (n--) {
        int row, m;
        scanf ("%d %d", &row, &m);
        while (m--) {
          int col;
          scanf ("%d", &col);
          grid[row][col] = false;
        }
    }
    pii src, dest;
    scanf ("%d %d %d %d", &src.first, &src.second, &dest.first, &dest.second);

    queue<pair<int, pii>> Q;
    Q.push(make_pair(0, src));
    grid[src.first][src.second] = false;
    bool found = false;
    while (!Q.empty()) {
      auto v = Q.front(); Q.pop();
      int value = v.first;
      pii node = v.second;
      if (node == dest) {
        printf ("%d\n", value);
        found = true; break;
      }
      for (int i = 0; i < 4; ++i) {
        int rr = dx[i] + node.first;
        int cc = dy[i] + node.second;
        if (rr >= 0 && cc >= 0 && rr < r && cc < c && grid[rr][cc]) {
          grid[rr][cc] = false;
          Q.push(make_pair(value + 1, pii(rr, cc)));
        }
      }
    }
    assert (found);
  }
	return 0;
}