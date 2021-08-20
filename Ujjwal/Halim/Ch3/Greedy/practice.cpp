#include <iostream>
#include <cstdio>
#include <map>

using mp = std::map<std::pair<int, int>, int>;

int main() {
	int n;
	while (scanf("%d",&n) && n) {
		mp mapper;
		for(int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(a > b)
				mapper[{b, a}]--;
			else 
				mapper[{a, b}]++;
		}
		bool ok = true;
		for (auto p : mapper)
			if(p.second) {
				ok = false;
				break;
			}
		puts(ok ? "YES" : "NO");
	}
}