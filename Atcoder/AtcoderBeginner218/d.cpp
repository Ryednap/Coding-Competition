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
    int n;
    scanf ("%d",&n);
    vector<pair<int, int>> a(n);
    set<pair<int, int>> s;
    for (auto & [x, y] : a) scanf ("%d %d",&x, &y), s.insert({x, y});

    debug() << owo(a);
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].first == a[j].first) continue;
            if (a[i].second == a[j].second) continue;
            pair<int, int> f = {a[j].first, a[i].second};
            pair<int, int> b = {a[i].first, a[j].second};
            bool ok = (s.find(f) != s.end()) && (s.find(b) != s.end());
            debug() << owo(a[i]) owo(a[j]) owo(f) owo(b) owo(ok);
            if (ok) answer++;
        }
    }
    printf("%d\n", answer >> 1);
    return 0;
}