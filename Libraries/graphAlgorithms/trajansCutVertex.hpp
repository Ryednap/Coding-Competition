#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer = 0;

void CUTPOINT (int node) {
    // function to process the CUTPOINT
}

void dfs (int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = ++timer;
    int c = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            // no low[to] because our ancestor may form back-edge ans still be cut-point
            low[v] = std :: min (low[v], tin[to]);  
        } else {
            ++c;
            dfs(to, v);
            low[v] = std :: min (low[v], low[to]);
            if (tin[v] <= low[to] && p != -1) // not the root vertex
                CUTPOINT(v);
        }
    }

    if (p == -1 && c > 1) CUTPOINT(v); // root vertex
}