#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 5460;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
// string s, t;
ll ans = 0;

const ll mx = 2e5 + 200;
bool prime[mx];
vector<ll> primes;
vector<ll> vals[mx];
ll vis[mx];
vector<pair<ll, ll>> dists; // (dist, vertex)
vector<ll> edges[200005];

void dfs(ll cur, ll par, ll dist, ll prime) {
	dists.push_back(make_pair(dist, cur));
	vis[cur] = prime;
	
	for (ll next: edges[cur]) {
		if (next != par) {
			if (a[next] % prime == 0) {
				dfs(next, cur, dist + 1, prime);
			}
		}
	}
}

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < mx; i++) prime[i] = 1;
	for (ll i = 2; i < mx; i++) {
		if (prime[i]) {
			primes.push_back(i);
			for (ll j = i * 2; j < mx; j += i) {
				prime[j] = 0;
			}
		}
	}
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		vals[a[i]].push_back(i);
	}
	
	for (ll i = 0; i < n - 1; i++) {
		ll u, v; cin >> u >> v;
		--u; --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	ll ans = 0;
	for (ll p: primes) {
		vector<ll> inc;
		
		for (ll i = p; i < mx; i += p) {
			for (ll j: vals[i]) {
				inc.push_back(j);
			}
		}
		
		for (ll x: inc) {
			if (vis[x] != p) {
				dists.clear();
				dfs(x, -1, 0, p);
				
				ll far = 0;
				for (ll i = 1; i < dists.size(); i++) {
					if (dists[i].f > dists[far].f) {
						far = i;
					}
				}
				
				ll ind = dists[far].s;
				
				dists.clear();
				dfs(ind, -1, 0, p);
				
				for (pair<ll, ll> x: dists) ans = max(ans, x.f + 1);
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 		
	cout << setprecision(12) << fixed;
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
} 
