#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
    Dinic's Algorithm : Source : https://cp-algorithms.com/graph/dinic.html
    Tested on : 
        https://www.spoj.com/problems/FASTFLOW/ 0.29 s
        https://cses.fi/problemset/task/1694 0.1s



*/


using std::vector;
using std::queue;
using i64 = int64_t;
constexpr i64 OO = 1e18;
struct FlowEdge {
    int from, to;
    i64 cap, flow = 0;
    FlowEdge (int v, int u, int c) : from(v), to(u), cap(c) {}
};

struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int src, sink;
    vector<int> level, ptr;
    queue<int> Q;

    Dinic (int N, int s, int t): n(N), src(s), sink(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge (int v, int u, i64 c) {
        edges.emplace_back(v, u, c); // flow edge
        edges.emplace_back(u, v, 0); // residual edge
        adj[v].push_back(m); // store the location of edge corresponding to v -- u flow edge
        adj[u].push_back(m + 1); // store the location of edge corresponding to u -- v residual edge
        m += 2;
    }

    // to find level graph 
    bool bfs () {
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int ii : adj[v]) { // for all edges from node v
                if (edges[ii].cap - edges[ii].flow <= 0) continue;
                if (level[edges[ii].to] != -1) continue;
                level[edges[ii].to] = level[v] + 1;
                Q.push(edges[ii].to);
            }
        }
        return level[sink] != -1;
    }

    // find an augmenting path
    i64 dfs (int from, i64 pushed) {
        if (pushed == 0) return 0;
        if (from == sink) return pushed;
        for (int & ii = ptr[from]; ii < (int)adj[from].size(); ++ii) {
            int jj = adj[from][ii];
            int to = edges[jj].to;
            if (level[from] + 1 != level[to] || edges[jj].cap - edges[jj].flow <= 0) continue;
            i64 tr = dfs (to, std :: min (pushed, edges[jj].cap - edges[jj].flow));
            if (tr == 0) continue;
            edges[jj].flow += tr; // flow value
            edges[jj ^ 1].flow -= tr; // residual value
            return tr;
        }
        return 0;
    }

    i64 flow () {
        i64 f = 0;
        while (true) {
            level.assign(n, -1);
            level[src] = 0;
            Q.push(src);
            if(!bfs()) break; // no more level graph posible
            ptr.assign(n, 0);
            while (i64 pushed = dfs(src, OO))   {
                f += pushed;
            }
        }
        return f;
    }
};
