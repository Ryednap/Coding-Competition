#include <bits/stdc++.h>

using vi = std::vector<int>;
vi Edges[1100];
vi tin(1100, -1), low(1100), tout(1100, -1);
int timer = 0;

// low stores the information about ancestor.
// tin store the visting time value of the node
// In undirected graph we only have tree and back edge.
// so for either bridges or cut vertex we just need to check if there is some way
// that if I remove my current vertex/edge is there any way it's subtree(dfs tree) can esape it.

// O(V + E) algorithm
void dfs (int v, int p = -1) {
	tin[v] = low[v] = ++timer;
	for (int to : Edges[v])  {
		if (to == p)
			continue;
		if (tin[to] == -1) { // tree edge
			dfs (to, v);
			low[v] = std::min(low[v], low[to]);
			if(low[v] < low[to]) { // bride for articulation change this to <=
				/* 
					BRIDGE FOUND
				*/
			}

		} else if (tout[to] == -1) { // back edge
			low[v] = std::min(low[v], tin[to]);
		}
	}
	tout[v] = ++timer;
}

int main() {

}