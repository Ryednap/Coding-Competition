#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


// complexity is O(qq + N^2)

using pii = pair<int, int>;
template<class T>
using ordered_set = tree < T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int main() {
	string s ;
	cin >> s;
	ordered_set<pii> v;
	int pq = 0;
	for(char ch : s) {
		v.insert(make_pair(pq++, ch - '0'));
	}

	debug() << owo(s.length());

	vector<pair<int, pii>> Query;
	int qq;
	scanf("%d", &qq);
	for(int i = 0; i < qq; ++i) {
		int k, l;
		scanf("%d %d", &k, &l);
		Query.emplace_back(k,make_pair(l, i));
	}
	sort(Query.begin(), Query.end());
	reverse(Query.begin(), Query.end());
	int answer[qq];

	for(int i = 0; i < qq; ++i) {
		int k = Query[i].first;
		int l = Query[i].second.first;
		int index = Query[i].second.second;
		while ((int)v.size() != k) {
			int lo = 0, hi = (int)v.size() - 1;
			int maybe = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				std::vector<int> arr;
				for(int j = max(0, lo - 1); j <= mid; ++j) {
					arr.push_back(v.find_by_order(j) -> second);
				}
				if(is_sorted(arr.begin(), arr.end(), greater<int>())) {
					lo = mid + 1;
					maybe = mid;
				} else hi = mid - 1;
			}

			v.erase(v.find_by_order(maybe));
		}
		int digit = v.find_by_order(l - 1) -> second;
		answer[index] = digit;

	}


	for(int i = 0; i < qq; ++i) {
		printf("%d\n", answer[i]);
	}
	puts("");
	return 0;
}