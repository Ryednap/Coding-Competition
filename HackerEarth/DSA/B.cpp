#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

template<class T>
using ordered_set = tree < T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main() {
	ordered_set<int> st;
	for(int i = 0; i  < 10; ++i) {
		st.insert(i);
	}
	printf("%d\n", is_sorted(st.begin(), st.begin() + 2);
	return 0;
}