#include <bits/stdc++.h>

using namespace std;

struct QueryForm {
	int k;
	int l, r;
	int index;
	QueryForm() {}
	QueryForm(int a, int b, int c, int d):
	k(a), l(b), r(c), index(d) {}
};

class SegmentTree {
	using vi = vector<int>;
	vi lo, hi;
	vi st;

	public: SegmentTree(int n) {
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1);
		init(1, 0, n - 1);
	}

	public: void update(int x) {
		update(1, x);
	}

	public: int query(int l, int r) {
		return query(1, l, r);
	}

	void init(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;

		if(a == b) {
			st[i] = 1;
			return;
		}
		int mid = (a + b) >> 1;
		init(2 * i, a, mid);
		init(2 * i + 1, mid + 1, b);
		st[i] = st[2 * i] + st[2 * i + 1];
	}


	void update(int i, int a) {
		if(lo[i] > a || hi[i] < a)
			return;
		if(lo[i] == a && hi[i] == a) {
			st[i] = 0;
			return;
		}

		update(2 * i, a);
		update(2 * i + 1, a);
		st[i] = st[2 * i] + st[2 * i + 1];
	}

	int query(int i, int a, int b) {
		if(lo[i] > b || hi[i] < a) 
			return 0;
		if(lo[i] >= a && hi[i] <= b) 
			return st[i];

		return query(2 * i, a, b) + query(2 * i + 1, a, b);
	}
};


int main() {
	int n;
	scanf("%d", &n);
	pair<int, int> arr [n];
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		arr[i] = make_pair(x, i);
	}
	sort(arr, arr + n);
	int qq; scanf("%d", &qq);
	QueryForm query [qq];

	for(int i = 0; i < qq; ++i) {
		scanf("%d %d %d", &query[i].l, &query[i].r, &query[i].k);
		query[i].index = i;
	}
	sort(query, query + qq, [&] (QueryForm & a, QueryForm &b){
		return a.k < b.k;
	});	

	int answer [qq];
	SegmentTree st(n);

	
	for(int i = 0, j = 0; i < qq; ++i) {
		int k = query[i].k;
		int l = query[i].l - 1;
		int r = query[i].r - 1;
		int index = query[i].index;
		while (j < n && arr[j].first <= k) {
			st.update(arr[j].second);
			++j;
		}
		answer[index] = st.query(l, r);
	}

	for(int i = 0 ; i < qq; ++i) {
		printf("%d\n", answer[i]);
	}
	return 0;
}