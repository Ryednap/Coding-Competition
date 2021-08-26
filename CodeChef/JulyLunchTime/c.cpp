#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ll = long long;
using vi = std::vector<ll> ;
using pii = pair<ll, ll>;

#define f first
#define s second

vi tin, tout;
vector<vi> edges, up;
int timer = 0;

void dfs (int node, int par) {
    tin[node] = ++timer;
    up[node][0] = par;
    for (int i = 1; i < 32; ++i)  {
        up[node][i] = up[up[node][i - 1]][i -1];
    }

    for (int child : edges[node]) {
        if (tin[child] == -1)
            dfs (child, node);
    }
    tout[node] = ++timer;
}


int main () {
    int qq; scanf ("%d", &qq);
    for (int tt = 0; tt < qq; ++tt) {
        int n, k, s;
        scanf ("%d %d %d", &n, &k, &s);
        vi ar(n), pref(n);
        for (ll & x : ar ) {
            scanf ("%lld", &x);
        }
       std :: partial_sum (ar.begin(), ar.end(), pref.begin());
       edges = vector<vi>(n + 1);
       for (int i = 0; i < n; ++i) {
            int u = i;
            int v = std :: upper_bound(pref.begin(), pref.end(), s + (!i ? 0 : pref[i - 1])) - pref.begin();
            debug() << owo(v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        debug() << owo(edges);
        up = vector<vi> (n + 1, vi(32));
        tin = tout  = vi(n + 1, -1);
        timer = 0;
        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1)
                dfs (i, i);
        }
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int v = i;
            for (int j = 0; j < 31; ++j) {
                if ((k >> j) & 1)
                    v = up[v][j];
            }
            debug() << owo(v);
            ans = max(ans, i - v);
        }
        printf ("%d\n", ans);
    }
    return 0;
}


