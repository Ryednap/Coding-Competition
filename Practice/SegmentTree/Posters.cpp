#include <bits/stdc++.h>

class SegmentTree {
	using vi = std :: vector<int>;
public:
	const int n = (int)1e7;
	SegmentTree() {
		st = vi(4 * n + 1, -1);
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		init(1, 0, n - 1);
	}

	int query(int a) {
		return query(1, a);
	}
	void update(int a, int b, int c) {
		update(1, a, b, c);
	}

private:
	void init(int i,int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if(a == b)
			return;
		int m = (a + b) >> 1;
		init(2 * i, a, m);
		init(2 * i + 1, m + 1, b);
	}
	void prop(int i) {
		if(st[i] == -1)
			return;
		st[2 * i] = st[i];
		st[2 * i + 1] = st[i];
		st[i] = -1;
	}
	int query(int i, int a) {
		if(lo[i] > a || hi[i] < a)
			return -1;
		if(lo[i] >= a && hi[i] <= a)
			return st[i];

		prop(i);
		int left = query(2 * i, a);
		int right = query(2 * i + 1, a);
		if(left != -1)
			return left;
		return right;
	}
	void update(int i, int a, int b, int val) {
		
		if(lo[i] > b || hi[i] < a)
			return;
		if(lo[i] >= a && hi[i] <= b) {
			st[i] = val;
			return;
		}
		prop(i);
		update(2 * i, a, b, val);
		update(2 * i + 1, a, b, val);
	}
private:
	vi lo, hi;
	vi st;
};

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq--) {
		int n;
		scanf("%d", &n);
		SegmentTree st;
		for(int i = 0; i < n; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			--l, --r;
			st.update(l, r, i);
		}
		std :: set<int> answer;
		for(int i = 0 ; i < st.n; ++i) {
			int value = st.query(i);
			if(value != -1)
				answer.insert(value);
		}
		printf("%d\n", (int)answer.size());
	}
	return 0;
}