#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;


int main () {
  int n;
  scanf ("%d", &n);
  vi values(n);
  vvi edges(n);
  for (int & x : values) scanf ("%d", &x);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf ("%d %d", &a, &b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  ordered_set st;
  function < int(int, int, int)> dfs = [&] (int node, int par, int turn) -> int {
    st.insert(pii(values[node], node));
    if ((int)edges[node].size() == 1 && node) {
      const int m = (int)st.size();
      int value = st.find_by_order(m >> 1)->first;
      if (!(m & 1)) value = (value + st.find_by_order((m >> 1) - 1)->first) >> 1;
      debug() << owo(node) owo(st) owo(value);
      st.erase(pii(values[node], node)); 
      return value;
    }

    int maxi = 0, mini = INT_MAX;
    st.insert(pii(values[node], node));
    for (int child : edges[node]) {
      if (child != par) {
          int got = dfs(child, node, turn ^ 1);
          maxi = max (maxi, got);
          mini = min (mini, got);
      }
    }
    debug() << owo(node) owo(maxi) owo(mini);
    st.erase(pii(values[node], node)); 
    return turn ? mini : maxi;
   };

  printf ("%d\n", dfs(0, -1, 0));
  return 0;
}