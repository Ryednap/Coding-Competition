#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace  __gnu_pbds;

using ordered_set = tree < int, null_type, less<int>, rb_tree_tag,
				   tree_order_statistics_node_update
				 >;

// O(N * log(N)) implementation at worst.

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		ordered_set Set;
		vector<string> arr(n, "-1");
		for(int i = 0; i < n; ++i) {
			Set.insert(i);
		}

		for(int i = 0, curr = 0; i < n; ++i) {
			std :: string a, b;
			std :: cin >> a >> b;
			int x = (int)b.length() - 1;
			curr = (curr + x) % (int)Set.size();
			auto pos = Set.find_by_order(curr);
			assert(arr[*pos] == "-1");
			arr[*pos] = a;
			Set.erase(pos);
		}

		printf("%s", arr[0].c_str());
		for(int i = 1; i < n; ++i) {
			printf(" %s", arr[i].c_str());
		}
		puts("");
	}
	return 0;
}