#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Direct problem
// No need to binary search.


int main() {
	string str;
	bool ok = true;
	while (ok) {
		int leak = 0, consume = 0, prev = 0;
		double total = 0, ans = 0;
		while(getline(cin, str)) {
			
			stringstream ss(str);
			int a = -1, b = -1;
			string buff;
			ss >> a >> buff;

			total += (a - prev) * leak + (a - prev) / 100.0 * consume;
						//debug() << owo(a) owo(buff) owo(leak) owo(consume) owo(total);
			prev = a;
		
			if(buff == "Fuel") ss >> buff;
			if(buff == "Goal") break;
			if(buff == "Mechanic") leak = 0;
			if(buff == "Leak") ++leak;
			if(buff == "consumption") {
				ss >> b;
				consume = b;
			} 
			if(buff == "Gas") {
				ans = max(ans, total);
				total = 0;
			}
			
			if(a == 0 && b == 0) {
				ok = false;
				break;
			}
		}
		ans = max(ans, total);
		if(ok) printf("%.3f\n", ans);
	}	
	return 0;
}
