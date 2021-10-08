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


const int dx [] = {+1, -1, +1, -1, +2, -2, +2, -2, +2, +2, -2, -2};
const int dy [] = {+2, +2, -2, -2, +1, +1, -1, -1, -2, +2, -2, +2};

using pii = pair<int, int>;
struct Move {
  pii cor;
  char type;
  int value;
  Move () {}
  Move (pii a, char b, int c) : cor(a), type(b), value (c) {}
};

int main () {
   int n;
   while (scanf ("%d", &n) && n) {
    n *= 2;
    pii src, dest;
    scanf ("%d %d %d %d", &src.first, &src.second, &dest.first, &dest.second);
    --src.first, --src.second;
    --dest.first, --dest.second;
    vector<vector<int>> vis(n, vector<int> (n, false));
    int r, c;
    while (scanf ("%d %d", &r, &c)) {
      if (!r && !c) break;
      --r, --c;
      vis[r][c] = true;
    }
    queue<Move> q;
    q.push(Move(src, 'N', 0));
    vis[src.first][src.second] = true;

    bool found = false;
    const pair<int, int> sym = {n / 2 - 1, n / 2};
    while (!q.empty()) {
      auto v = q.front(); q.pop();
      int value = v.value;
      pii node = v.cor;
      char type = v.type;
      if (node == dest) {
          found = true;
          printf ("Result : %d\n", value); break;
      }
      for (int i = 0; i < 12; ++i) {
        int rr = dx[i] + node.first;
        int cc = dy[i] + node.second;
        char here = i < 8 ? 'K' : 'B';
        if (rr >= 0 && cc >= 0 && rr < n && cc < n && !vis[rr][cc] && type != here){
          vis[rr][cc] = true;
          q.push(Move(pii(rr, cc), 'K', value + 1));
        }
      }

      auto special_move = [&] (int x) -> int {
        int a = sym.first, b = sym.second;
        if (x <= a) {
          swap (a, b);
        }
        return b + a - x;
      };

      int x = special_move(node.first);
      int y = special_move(node.second);
      if (x >= 0 && x < n && !vis[x][node.second] && type != 'T') {
        vis[x][node.second] = true;
        q.push(Move(pii(x, node.second), 'T', value + 1));
      }
      if (y >= 0 && y < n && !vis[node.first][y] && type != 'T') {
        vis[node.first][y] = true;
        q.push(Move(pii(node.first, y), 'T', value + 1));
      }
    }
    if (!found) puts("Solution doesn't exist");
   }
}

