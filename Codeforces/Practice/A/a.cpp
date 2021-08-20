#include <bits/stdc++.h>
using namespace std;

/* Mistakes
 * Misread the problem and then constructed the idea wasted min > 3
 * 
 * Time : 18 min
 */

int main() {
	
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		array<int, 4> ar;
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &ar[i]);
		}
		bool ok = false;
		
		auto Possible = [&] (auto a) {
			int o = 0;
			for(auto x : a) {
				if(x & 1) ++o;
			}
			if(o >= 2) return false;
			return true;
		};
		
		if(Possible(ar)) ok |= true;
		else {
			int mini = min({ar[0], ar[1], ar[2]});
			if(mini != 0) {
				for(int i = 0; i < 3; ++i) ar[i]--;
				ar[3] += 3;
				ok |= Possible(ar);
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;	
}
