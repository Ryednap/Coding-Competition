#include <vector>
#include <algorithm>


/* 
    This algorithm is based from https://cp-algorithms.com/graph/strongly-connected-components.html
    Read the proof there.
    The algorithm in nutshell is
    1):- sort all the vertices based on the exit time in decreasing order
    2):- run dfs from each vertex to the transposed graph to find the scc's
    3):- remove the vertices from the scc's

*/

using std::vector;
vector<vector<int>> adj, rev_adj;
vector<bool> vis;
vector<int> order, component;

// much like topological sort
void dfs1 (int v) {
    vis[v] = true;
    for (int to : adj[v]) if (!vis[to]) dfs1(to);
    order.push_back(v);
}

void dfs2 (int v) {
    vis[v] = true;
    component.push_back(v);
    for (int to : rev_adj[v]) if (!vis[to]) dfs2(to);
}


int main () {
    int n;
    // graph assignment

    vis.assign(n, false);
    for (int i = 0; i < n; ++i) {if (!vis[i]) dfs1(i); }
    vis.assign(n, false);
    std::reverse(order.begin(), order.end());
    for (const auto & v : order) {
        if (!vis[v]) {
            dfs2(v);

            // process the component;
            component.clear();
        }
    }

    // CONDENSATION GRAPH IMPLEMENTATION

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n);
    for (const auto & v : order) {
        if (!vis[v]) {
            dfs2(v);

            int root = component.front();
            root_nodes.push_back(root);
            for (auto & x : component) roots[x] = root;

            component.clear();
        }
    }

    for (int ii = 0 ; ii < n; ++ii) {
        for (int jj : adj[ii]) {
            int v = roots[ii];
            int u = roots[jj];
            if (v != u) adj_scc[v].push_back(u);
        }
    }
}




