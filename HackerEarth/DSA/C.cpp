#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = std::vector<int>;
using pi = std::pair<int, int>;
using ppi = std::pair<int, pi>;
using vppi = std::vector<ppi>;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree < T, null_type, std::less<T>, rb_tree_tag,tree_order_statistics_node_update>;

class SegmentTree {
public:
	SegmentTree(vi a) {
		arr = a;
		const int n = (int)arr.size();
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1);
		init(1, 0, n - 1);
	}

	int Query(int l, int r) {
		return Query(1, l, r);
	}

	void Update(int a) {
		Update(1, a);
	}

private:
	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) {
			st[i] = arr[a];
			return;
		}

		int mid = (a + b) >> 1;
		init(2 * i, a, mid);
		init(2 * i + 1, mid + 1, b);
		st[i] = st[2 * i] + st[2 * i + 1];
	}

	int Query(int i, int a, int b) {
		if(lo[i] > b || hi[i] < a) return 0;
		if(lo[i] >= a && hi[i] <= b) return st[i];

		return Query(2 * i, a, b) + Query(2 * i + 1, a, b);
	}

	void Update(int i, int a) {
		if(lo[i] > a || hi[i] < a) return;
		if(lo[i] >= a && hi[i] <= a) {
			st[i]--;
			return;
		}
		Update(2 * i, a);
		Update(2 * i + 1, a);
		st[i] = st[2 * i] + st[2 * i + 1];
	}

private:
	vi lo, hi;
	vi st, arr;
};



int main() {
	std :: string str;
	std :: cin >> str;

	ordered_set<ppi> arr;
	vi a;
	int prev = str[0] - '0';
	int count = 1, pogi = 0;
	for(int i = 1; i < (int)str.length(); ++i) {
		int ch = str[i] - '0';
		if(ch != prev) {
			arr.insert({pogi++, {prev, count}});
			count = 1;
			prev = ch;
		} else {
			++count;
		}
	}
	arr.insert({pogi++, {prev, count}});
	for(auto el : arr) {
		a.push_back(el.second.second);
	}


	int qq; scanf("%d", &qq);
	vppi Query(qq);
	for(int i = 0; i < qq; ++i) {
		int k, l;
		scanf("%d %d", &k, &l);
		Query[i] = make_pair(k, make_pair(l, i));
	}

	sort(Query.begin(), Query.end());
	reverse(Query.begin(), Query.end());


	vi answer(qq);
	SegmentTree st(a);

	const int n = (int)a.size();
	for(int i = 0; i < qq; ++i) {
		int k = Query[i].first;
		auto [l, index] = Query[i].second;

		while (k != st.Query(0, n - 1)) {
			int maybe = -1;
			for(int i = 1; i < min(11, (int)arr.size()); ++i) {
				int x = arr.find_by_order(i - 1)->second.first;
				int y = arr.find_by_order(i)->second.first;
				if(y > x) {
					maybe = i - 1;
					break;
				}
			}
			if(maybe == -1) {
				maybe = min(11, (int)arr.size()) - 1;
			}
			//debug() << owo(maybe) owo(Query[i]) owo(arr);
			auto ptr = arr.find_by_order(maybe);
			ppi p = *ptr;
			arr.erase(ptr);
			p.second.second--;
			st.Update(p.first);

			if(p.second.second != 0) {
				arr.insert(p);
			}
		}
		int lo = 0, hi = (int)arr.size() - 1;
		int maybe = -1;
		
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int r = arr.find_by_order(mid)->first;
			assert(r >= 0 && r < (int)a.size());
			if(st.Query(0, r) < l) {
				maybe = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		maybe++;

		int digit = arr.find_by_order(maybe)->second.first;
		//debug() << owo(Query[i]) owo(maybe) owo(digit);
		answer[index] = digit;
	}

	for(int i = 0; i < qq; ++i) {
		printf("%d\n", answer[i]);
	}
	puts("");
	return 0;
}