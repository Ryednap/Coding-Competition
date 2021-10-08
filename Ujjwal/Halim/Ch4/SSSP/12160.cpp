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


int main () {
  int l, r, n;
  int tt = 0;
  while (scanf ("%d %d %d", &l, &r, &n)) {
    if (!l && !r && !n) break;
    printf ("Case %d: ", ++tt);
    vector<int> a(n);
    for (int & x : a) scanf ("%d", &x);
    const int nax = (int)1e4;
    vector<int> vis(nax, false);

    queue<pair<int, int>> q;
    q.push(make_pair(0, l));
    vis[l] = true;

    bool found = false;
    while (!q.empty()) {
      auto node = q.front(); q.pop();
      if (node.second == r) {
        found = true;
        printf ("%d\n", node.first); break;
      }
      for (int & x : a) {
        int value = (x + node.second) % nax;
        if (!vis[value]) q.push(make_pair(node.first + 1, value)), vis[value] = true;
      }
    }
    if (!found) puts("Permanently Locked");
  }
}