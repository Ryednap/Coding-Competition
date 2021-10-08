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

template<typename T, typename AssociativeOperation, typename ModificationOperation>
struct SegmentTree {
	SegmentTree (vector<T> arr, T _identity, AssociativeOperation op, ModificationOperation mo) : 
			v(arr), identity(_identity), operation(op), modify(mo) {
		const int n = (int)arr.size();
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1, identity);
		init (1, 0, n - 1);
	}
	SegmentTree (int n, T _identity, AssociativeOperation op, ModificationOperation mo) : 
			identity(_identity), operation(op), modify(mo) {
		lo.resize(4 * n + 1);
		hi.resize(4 * n + 1);
		st.resize(4 * n + 1, identity);
		init (1, 0, n - 1);
		st[i] = operation(st[i << 1], st[(i <<< 1) + 1]);
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
	}

	T query (int a, int b) {return query(1, a, b);} // range query
	T query (int a) {return query(1, 0, a);} // point query
	void update (int pos, T val) {update(1, pos, val);} // point update

private:
	
	void prop (int i) {
		delta[2 * i] = modify(delta[2 * i], delta[i]);
		delta[2 * i + 1] = modify(delta[2 * i + 1], delta[i]);
		delta[i] = 0; // not sure it's dynmaic
	}

	void Set (int i) {
		st[i] = operation (modify(st[i << 1] , delta[i << 1]), modify(st[(i << 1) + 1], delta[(i << 1) + 1]));
	}

	T query (int i, int a, int b) {
		if (lo[i] > b  || hi[i] < a) return identity;
		if (lo[i] >= a && hi[i] <= b) return st[i];
		prop(i);
		T value =  operation (query((i << 1), a, b), query((i << 1) + 1, a, b));
		update(i);
		return value;
	}
	void update (int i, int pos, T val) {
		if (lo[i] > pos || hi[i] < pos) return;
		if (lo[i] == hi[i] && lo[i] == pos) {delta[i] = modify(delta[i], val); }
		prop(i); // propogate the change
		update((i << 1), pos, val);
		update((i << 1) + 1, pos, val);
		Set(i); // Set the change to the current node
	}

private:
	vector<T> st, v, delta;
	vector<int> lo, hi;
	T identity;
	AssociativeOperation operation;
	ModificationOperation modify;
};

Maximum<int> MaxiInt;
Minimum<int> MiniInt;


int main () {
	return 0;
}