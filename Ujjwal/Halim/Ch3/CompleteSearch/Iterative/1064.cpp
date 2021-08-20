#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using ar = array<int, 3>;

// Mistake for the first approach :- 
// Messages can pass the
// buffer in any order, but all packets from a single message must pass the buffer consecutively and in
// order (but not necessarily at the same time).

// This line means that at a single point of time the output tape can only accept one messages's packets until it is finished.

int main() {
	int n, m, tt = 0;
	while (scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		int size[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d\n", &size[i]);
		}
		
		vector<ar> packet(m);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < 3; ++j) {
				scanf("%d", &packet[i][j]);
			}
		}
		
		if(tt == 18) debug() << owo(packet);
		
		int curr[n];
		for(int i = 0; i < n; ++i) {
			curr[i] = i + 1;
		}
		
		int answer = (int)1e9;
		do {
			vector<ar> buffer;
			vector<ar> Q;
			for(int i = 0; i < n; ++i) {
				ar Message = {curr[i], 1, size[curr[i] - 1]};
				Q.push_back(Message);
			}
			
			int localMax = 0, idx = 0;
			
			auto getSize = [&] () {
				int sizeHere = 0;
				for(auto x : buffer) {
					sizeHere += (x[2] - x[1] + 1);
				}
				localMax = max(localMax, sizeHere);
			};
			
			for(int i = 0; i < m; ++i) {
				if(packet[i][0] == Q[idx][0]) {
					if(Q[idx][1] == packet[i][1]) {
						Q[idx][1] = packet[i][2] + 1;
						Q[idx][2] -= (packet[i][2] - packet[i][1] + 1);
						
					} else {
						buffer.push_back(packet[i]);
					}
					
				} else { // the head doesnot match with the current requirement
					buffer.push_back(packet[i]);
				}
				if(Q[idx][2] == 0) ++idx;
				if(idx == n) break;
				vector<ar> newBuffer;
				for(auto x : buffer) {
					if(Q[idx][0] == x[0]) {
						if(Q[idx][1] == x[1]) {
							Q[idx][1] = x[2] + 1;
							Q[idx][2] -= (x[2] - x[1] + 1);
							
						} else {
							newBuffer.push_back(x);
						}
					} else newBuffer.push_back(x);
					
					if(Q[idx][2] == 0) ++idx;
					if(idx == n) break;
				}
				buffer = newBuffer;
				getSize();
			}
				
			answer = min(answer, localMax);
				
		} while(next_permutation(curr, curr + n));
		
		
		
		printf("Case %d: %d\n", ++tt, answer);
		puts("");
		
	}
		
	return 0;
}
