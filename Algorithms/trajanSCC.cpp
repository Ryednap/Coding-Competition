#include <bits/stdc++.h>

// note that it's mostly same as finding bridges in undirected graph
// but this begin directed we additionally have forwarda nd cross edge
// which kinda spoil the low link values. so wee need to avoid those
// we maintain stack.


using vi = std::vector<int>;
vi edges[1100];
vi tin, inStack, low;
std::stack <int> stk;

int timer = 0;


// O(V + E) algorithm
void trajan (int v) {
	tin[v] = low[v] = ++timer;
	inStack[v] = 1; // mark that current node is in stack
	stk.push(v); // push into stack

	for (int to : edges[v]) {
		if (tin[to] == -1) { // tree edge
			trajan (to);
			low[v] = std::min (low[v], low[to]);
		} else if (inStack[v]) { // back edge found
			low[v] = std::min (low[v], low[to]);
		}
		// other than above we have visited nodes but they are either cross or forward
	}

	if (tin[v] == low[v]) { // this is the root of one of SCC
		vi SCC;
		while (true) { // until we hit the current node
			int node = stk.top(); stk.pop();
			SCC.push_back (node);
			inStack[node] = 0;
			if (node == v)
				break;
		}
	}
}