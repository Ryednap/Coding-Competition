#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
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


#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const ll OO = 1e8;

const double EPS = (1e-7);
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

#define pb          push_back
#define MP          make_pair
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;


struct edge {
  int from, to, w, index;
  edge(int from, int to, int w, int in): from(from), to(to), w(w), index(in) {}

  bool operator < (const edge & e) const {
    return w > e.w;
  }
};

pair<int, vector<int>> Dijkstra(vector< vector< edge > > adjList, int src, int dest, int neg) // O(E logV)
{
  int n = sz(adjList);
  vi dist(n, OO);
  vector<int> prev(n);
  dist[src] = 0;

  priority_queue<edge> q;
  q.push( edge(-1, src, 0, -1) );

  while( !q.empty() ) {
    edge e = q.top(); q.pop();

    if(e.w > dist[e.to])  continue; // some other state reached better

    prev[ e.to ] = e.from;

    rep(j, adjList[e.to]) {
      edge ne = adjList[e.to][j];
      if (ne.index == neg) continue;
      if( dist[ne.to] > dist[ne.from] + ne.w ) {
        ne.w = dist[ne.to] = dist[ne.from] + ne.w;
        q.push( ne );
      }
    }
  }
  int value = dist[dest];
  vector<int> path;
  int ref = dest;
  while (ref != -1) {

     path.push_back(ref);
          ref = prev[ref];
   
  }
  return make_pair(value,path);
}






int main () {
    int n, m;
    scanf ("%d %d", &n, &m);
    vector<vector<edge>> graph(n);
    map<pair<int, int>, int> mapper;
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf ("%d %d", &a, &b);
      --a, --b;
      graph[a].push_back(edge(a, b, 1, i));
      mapper[make_pair(a, b)] = i;
    }

    auto [distance, path] = Dijkstra(graph, 0, n - 1, -2);
    reverse(path.begin(), path.end());
    vector<int> edges, present(m);
    for (int i = 1; i < (int)path.size(); ++i) {
        edges.emplace_back(mapper[make_pair(path[i - 1], path[i])]);
        present[edges.back()] = 1;
    }
    debug() << owo(distance) owo(path) owo(edges);
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
      if (!present[i]) ans[i] = distance;
    }

    for (auto & ii : edges) {
        auto [val, temp] = Dijkstra(graph, 0, n - 1, ii);
        ans[ii] = val;
    }

    for (auto & x : ans) {
      if (x >= (int)1e6) puts("-1");
      else printf ("%d\n", x);
    }
}