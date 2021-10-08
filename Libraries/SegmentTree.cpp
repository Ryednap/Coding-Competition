#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Minimum {
	T operator () (const T & lhs, const T & rhs) const {
		return std :: min (lhs, rhs);
	}
};

template<typename T>
struct Maximum {
	T operator () (const T & lhs, const T & rhs) const {
		return std :: max(lhs, rhs);
	}
};

template<typename T, typename AssociativeOperation>
struct SegmentTree {
	SegmentTree (vector<T> arr, T _identity, AssociativeOperation op) : 
			v(arr), identity(_identity), operation(op) {
		const int n = (int)arr.size();
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1, identity);
		init (1, 0, n - 1);
	}
	SegmentTree (int n, T _identity, AssociativeOperation op) : 
			identity(_identity), operation(op) {
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1, identity);
		init (1, 0, n - 1);
	}

	void init (int i, int a, int b) {
		lo[i] = a; hi[i] = b;
		if (a == b) {
			if (!v.empty()) st[i] = v[a];
			return;
		}
		int m = (a + b) >> 1;
		init ((i << 1), a, m);
		init ((i << 1) + 1, m + 1, b); 
		st[i] = operation (st[i << 1], st[(i << 1) + 1]);
	}

	T query (int a, int b) {return query(1, a, b);} // range query
	T query (int a) {return query(1, 0, a);} // point query
	void update (int pos, T val) {update(1, pos, val);} // point update

private:
	T query (int i, int a, int b) {
		if (lo[i] > b  || hi[i] < a) return identity;
		if (lo[i] >= a && hi[i] <= b) return st[i];
		return operation (query((i << 1), a, b), query((i << 1) + 1, a, b));
	}
	void update (int i, int pos, T val) {
		if (lo[i] > pos || hi[i] < pos) return;
		if (lo[i] == hi[i] && lo[i] == pos) {st[i] = val;return;}
		update((i << 1), pos, val);
		update((i << 1) + 1, pos, val);
		st[i] = operation (st[i << 1], st[(i << 1) + 1]);
	}

private:
	vector<T> st, v;
	vector<int> lo, hi;
	T identity;
	AssociativeOperation operation;
};

Maximum<int> MaxiInt;
Minimum<int> MiniInt;


int main () {
	return 0;
}