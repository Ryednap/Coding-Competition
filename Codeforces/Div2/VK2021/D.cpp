#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		map<int, set<int>> mapper;
		vi arr(n + 1), brr(n + 1);
		set<int> rem;
		for(int i = 1; i <= n; ++i) {
			rem.insert(i);
		}

		for( int i = 1; i <= n; ++i ) {
			scanf("%d", &arr[i]);
			mapper[arr[i]].insert(i);
			if(rem.find(arr[i]) != rem.end())
				rem.erase(arr[i]);	
		}

		if((int)mapper.size() == n) {
			printf("%d\n",n);
			for(int i = 1; i <= n; ++i) {
				printf("%d ", arr[i]);
			}
			puts("");

		} else {
			brr = arr;
			vi del;
			for(auto p : mapper) {
				if(p.second.size() == 1)
					del.push_back(p.first);
			}
			for(auto x : del)
				mapper.erase(x);

			while ((int)rem.size()) {
				int here = *rem.begin();
				rem.erase(here);
				int major = -1;
				int where = -1;
				for(pair<const int, set<int>> & p : mapper) {
					for(auto x : p.second) {
						if(x != here) {
							where = x;
							break;
						}
					}
					if(where != -1) {
						p.second.erase(where);
						if(p.second.size() == 1)
							major = p.first;
						break;
					}
				}

				assert(where != -1);
				brr[where] = here;
				if(major != -1) mapper.erase(major);
			}
			int answer = 0;
			for(int i = 1; i <= n; ++i) {
				if(arr[i] == brr[i]) ++answer;
			}
			printf("%d\n", answer);
			for(int i = 1; i <= n; ++i) {
				assert(brr[i] != i);
				printf("%d ", brr[i]);
			}
			puts("");
		}
	}
	return 0;
}