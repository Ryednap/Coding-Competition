#include <vector>
#include <algorithm>

using std::vector;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer = 0;

void BRIDGE (int from, int to) {
    // function to process the BRIDGE
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
            if (tin[v] < low[to]) 
                BRIDGE(v, to);
        }
    }

}